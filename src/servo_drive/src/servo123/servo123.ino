#include <Arduino_FreeRTOS.h>
#include <ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <queue.h>  //队列在这里很重要，串口接收的控制指令会分配给队列，其他任务再从队列里获取，避免多任务同时访问一个数据
/************定义4个任务，一个串口收发任务，3个电机任务**************/
void TaskSerial( void *pvParameters );//任务名称可以自己定
void Task_servo1( void *pvParameters );
void Task_servo2( void *pvParameters );
void Task_servo3( void *pvParameters );

char a_data = 'q';//这是电机方向数据，
long a_number = 0;//这是电机步数数据，
char b_data = 'q';
long b_number = 0;
char c_data = 'q';
long c_number = 0;

ros::NodeHandle  nh;

void servoCb( const std_msgs::Float32MultiArray &angle_msg)  //angle_msg其实是脉冲数
{
  Serial.println("进入回调函数");
  if (angle_msg.data[0] == 0)
  {
    a_data = 'q'; a_number = 0;
    }
  if (angle_msg.data[0] > 0)
  {
    a_data = 'i'; a_number = long(angle_msg.data[0]);
    }
  if (angle_msg.data[0] < 0)
  {
    a_data = 'f'; a_number = long(-angle_msg.data[0]);
    }
// ------------------------------------------------
  if (angle_msg.data[1] == 0)
  {
    b_data = 'q'; b_number = 0;
    }
  if (angle_msg.data[1] > 0)
  {
    b_data = 'i'; b_number = long(angle_msg.data[1]);
    }
  if (angle_msg.data[1] < 0)
  {
    b_data = 'f'; b_number = long(-angle_msg.data[1]);
    }
// ---------------------------------------------------------
  if (angle_msg.data[2] == 0)
  {
    c_data = 'q'; c_number = 0;
    }
  if (angle_msg.data[2] > 0)
  {
    c_data = 'i'; c_number = long(angle_msg.data[2]);
    }
  if (angle_msg.data[2] < 0)
  {
    c_data = 'f'; c_number = long(-angle_msg.data[2]);
    }

}


ros::Subscriber<std_msgs::Float32MultiArray> sub_angle("/servo_angle", servoCb);


void setup()
{
  Serial.begin(115200, SERIAL_8N1);
  nh.initNode();
  nh.subscribe(sub_angle);

/************创建4个任务（也可以在任务中创建任务），一个串口收发任务，3个电机任务**************/
  xTaskCreate(TaskSerial, "Serial" , 256 , NULL, 2 , NULL );
  xTaskCreate(Task_servo1, "a_servo" , 128 , NULL, 1 , NULL );
  xTaskCreate(Task_servo2, "b_servo" , 128 , NULL, 1 , NULL );
  xTaskCreate(Task_servo3, "c_servo" , 128 , NULL, 1 , NULL );
 
  vTaskStartScheduler(); //启动任务调度
 
}

void loop()
{}

void TaskSerial(void *pvParameters)
{
  (void) pvParameters;
  for(;;)
  {
    nh.spinOnce();
    vTaskDelay( 25 / portTICK_PERIOD_MS ); // 等待3ms
    }
  
  
}

/*------------------------------------------servo1----------------------------------------- */
void Task_servo1(void *pvParameters)  
{
  (void) pvParameters;
    /*----------- servo1电机任务初始化配置 -----------*/
 
  long a_cp = 0;//这个是电机步数对比值，它与a_number对比  

  /*-----------servo1引脚接线-----------*/
  pinMode(22, OUTPUT);    //DIR，电机驱动器DIR接Arduino 2560的D22，后面接线照着接
  pinMode(23, OUTPUT);    //CP
  pinMode(24, OUTPUT);    //EN
  digitalWrite(24, HIGH);  //EN  
  
  for (;;)
  {
    if (a_data == 'f')//电机顺时针
    {
    
      digitalWrite(22, LOW);      //电机顺时针
      while (a_cp < a_number)//电机走Ynumber个步数
      {
        digitalWrite(23, HIGH);
        vTaskDelay( 2 / portTICK_PERIOD_MS );
        digitalWrite(23, LOW);
        vTaskDelay( 2 / portTICK_PERIOD_MS  );
        a_cp++;
      }
      a_cp = 0;//对比数据清零
      a_data= 'q';
    }
    
    if (a_data == 'i')//电机逆时针
    {
      digitalWrite(24, HIGH);     
      digitalWrite(22, HIGH);      //电机逆时针
      while (a_cp < a_number)
      {
        digitalWrite(23, HIGH);
        vTaskDelay(2 / portTICK_PERIOD_MS);
        digitalWrite(23, LOW);
        vTaskDelay(2 / portTICK_PERIOD_MS);
        a_cp++;
      }
      a_cp = 0;
      a_data='q';
    }
    if (a_data == 'q')
    {
      digitalWrite(24, HIGH);  //EN
    }
    vTaskDelay( 3 / portTICK_PERIOD_MS ); // 等待3ms
  }
    
  
}

/*------------------------------------------servo2-----------------------------------------*/
void Task_servo2(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  
  long b_cp = 0;

  /*----------- servo2引脚接线 -----------*/
  pinMode(26, OUTPUT);    //DIR
  pinMode(27, OUTPUT);    //CP
  pinMode(28, OUTPUT);    //EN
  digitalWrite(28, HIGH);  //EN on

  for (;;)
  {
    if (b_data == 'f')
    {
      
      digitalWrite(26, LOW);      //电机顺时针
      while (b_cp < b_number)
      {
        digitalWrite(27, HIGH);
        vTaskDelay( 2 / portTICK_PERIOD_MS  );
        digitalWrite(27, LOW);
        vTaskDelay( 2 / portTICK_PERIOD_MS );
        b_cp++;
        b_data='q';
      }
      b_cp = 0;
    }
    
    if (b_data == 'i')
    {
      
      digitalWrite(26, HIGH);      //电机逆时针
      while (b_cp < b_number)
      {
        digitalWrite(27, HIGH);
        vTaskDelay( 2 / portTICK_PERIOD_MS );
        digitalWrite(27, LOW);
        vTaskDelay( 2 / portTICK_PERIOD_MS );
        b_cp++;
      }
      b_cp = 0;
      b_data='q';
    }

    if (b_data == 'q')
    {
      digitalWrite(28, HIGH);  //EN on
    }
  
  vTaskDelay( 3 / portTICK_PERIOD_MS ); // 等待3ms
  }
}

/*------------------------------------------servo3-----------------------------------------*/
void Task_servo3(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  
  long c_cp = 0;
   
  /*----------- servo3引脚接线 -----------*/
  pinMode(30, OUTPUT);    //DIR
  pinMode(31, OUTPUT);    //CP
  pinMode(32, OUTPUT);    //EN
  digitalWrite(32, HIGH);  //EN on

  for (;;)
  {
    if (c_data == 'f')
    {
      
      digitalWrite(30, LOW);      //远离电机端
      while (c_cp < c_number)
      {
        digitalWrite(31, HIGH);
        vTaskDelay( 2 / portTICK_PERIOD_MS );
        digitalWrite(31, LOW);
        vTaskDelay( 2 / portTICK_PERIOD_MS );
        c_cp++;
      }
      c_cp = 0;
      c_data='q';
    }
    if (c_data == 'i')
    {
    
      digitalWrite(30, HIGH);      //靠近电机端
      while (c_cp < c_number)
      {
        digitalWrite(31, HIGH);
        vTaskDelay( 2 / portTICK_PERIOD_MS );
        digitalWrite(31, LOW);
        vTaskDelay( 2 / portTICK_PERIOD_MS );
        c_cp++;
      }
      c_cp = 0;
      c_data='q';
    }

    if (c_data == 'q')
    {
      digitalWrite(32, HIGH);  //EN on
    }
  
  vTaskDelay(3 / portTICK_PERIOD_MS); // 等待2ms
  }
}
