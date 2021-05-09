#include <Arduino_FreeRTOS.h>
#include <ros.h>
#include <queue.h>  //队列在这里很重要，串口接收的控制指令会分配给队列，其他任务再从队列里获取，避免多任务同时访问一个数据
/************定义4个任务，一个串口收发任务，3个电机任务**************/
void TaskSerial( void *pvParameters );//任务名称可以自己定
void Task_servo1( void *pvParameters );
void Task_servo2( void *pvParameters );
void Task_servo3( void *pvParameters );

QueueHandle_t  a_dir, a_num,  //定义servo1的指令的队列，a_dir是控制电机方向，a_num是控制电机步数
               b_dir, b_num, 
               c_dir, c_num;

void setup()
{
  Serial.begin(115200, SERIAL_8N1);
/************定义各电机的控制指令队列**************/
  a_dir = xQueueCreate( 1, sizeof( char ) );//队列数据类型定义，1是队列长度，char是Yc的数据类型
  a_num = xQueueCreate( 1, sizeof( long ) );
  b_dir = xQueueCreate( 1, sizeof( char ) );
  b_num = xQueueCreate( 1, sizeof( long ) );
  c_dir = xQueueCreate( 1, sizeof( char ) );
  c_num = xQueueCreate( 1, sizeof( long ) );
  
/************创建4个任务（也可以在任务中创建任务），一个串口收发任务，3个电机任务**************/
  xTaskCreate(TaskSerial, "Serial" , 256 , NULL, 2 , NULL );//“Serial”是任务名称，256是该任务分配的存储空间，优先级为2（数字越大优先级越高）
  xTaskCreate(Task_servo1, "a_servo" , 128 , NULL, 1 , NULL );
  xTaskCreate(Task_servo2, "b_servo" , 128 , NULL, 1 , NULL );
  xTaskCreate(Task_servo3, "c_servo" , 128 , NULL, 1 , NULL );
 
  vTaskStartScheduler(); //启动任务调度
}

void loop()
{}

/*---------------------- Tasks Serial---------------------*/
void TaskSerial(void *pvParameters)
{
  (void) pvParameters;
  char buffer1[22] = " ";//这个用来储存串口数据
  char data1 = ' ';//这个用来储存电机判断指令
  char data2 = ' ';//这个用来储存电机方向判断指令
  long number = 0;//这个用来储存电机运行步数
  
  for (;;)
  {
    /*---------------------接收数据---------------------*/
    if (Serial.available() > 0) //说明串口接收到数据
    {
      data1 = Serial.read();//串口接收指令，将第一个字符给data1,(用来判断需要控制哪电机)
      data2 = Serial.read();//串口接收指令，将第2个字符给data2,(用来判断电机方向)
    
      Serial.readBytes(buffer1, 22);//串口接收指令，将剩余字符数组buffer1,(用来储存电机运行步数),22是读取的字节数是22


      /****servo1****/
      if (data1 == 'a')
      {
        
        data1= ' ';
        number = atol(buffer1);//将数组buffer1的值强制转换为long型，把buffer1储存的步数给number
        xQueueSend( a_num, &number, 1);//把步数发给a_num
        number = 0;
        xQueueSend( a_dir, &data2, 1);//把方向发给a_dir
        data2= ' ';
      }

      /****servo2****/
      if (data1 == 'b')
      {
        data1= ' ';
        number = atol(buffer1);
        xQueueSend( b_num, &number, 1);
        number = 0;
        xQueueSend( b_dir, &data2, 1);
        data2= ' ';
      }

      /****servo3****/
      if (data1 == 'c')
      {
        data1= ' ';
        number = atol(buffer1);
        xQueueSend( c_num, &number, 1);
        number = 0;
        xQueueSend( c_dir, &data2, 1);
        data2 = ' ';
      }

      /****清空缓冲****/
      for (int k = 0; k < 22; k++)
      {
        buffer1[k] = ' ';
      }
    }
    vTaskDelay(3); // 等待1ms,避免任务拥挤
  }
  
}

/*------------------------------------------servo1----------------------------------------- */
void Task_servo1(void *pvParameters)  
{
  (void) pvParameters;
    /*----------- servo1电机任务初始化配置 -----------*/
  char a_data = ' ';//这是电机方向数据，它会去队列中获取方向数据
  long a_number = 0;//这是电机步数数据，它会去队列中获取步数数据
  long a_cp = 0;//这个是电机步数对比值，它与a_number对比  

  /*-----------servo1引脚接线-----------*/
  pinMode(22, OUTPUT);    //DIR，电机驱动器DIR接Arduino 2560的D22，后面接线照着接
  pinMode(23, OUTPUT);    //CP
  pinMode(24, OUTPUT);    //EN
  digitalWrite(24, HIGH);  //EN     为了使电机不发热，先脱机
  
  for (;;)
  {
    if (xQueueReceive(a_dir,&a_data,3) )//判断队列a-dir是否有数据进来,并获取数据（方向数据）给a_data
    {
      xQueueReceive( a_num, &a_number, 3);//获取电机步数a_num的数据给a_number，因为串口任务里先发送a_num数据，再发送a_dir数据，所以用a_dir判断数据是否进来，a-dir数据进来，则a_num数据已进来
      if (a_data == 'f')//电机顺时针
      {
        digitalWrite(24, HIGH);     //电机使能
        digitalWrite(22, LOW);      //电机顺时针
        while (a_cp < a_number)//电机走Ynumber个步数
        {
          digitalWrite(23, HIGH);
          vTaskDelay( 10 / portTICK_PERIOD_MS );
          digitalWrite(23, LOW);
          vTaskDelay( 10 / portTICK_PERIOD_MS  );
          a_cp++;
        }
        a_cp = 0;//对比数据清零
      }
      
      if (a_data == 'i')//电机逆时针
      {
        digitalWrite(24, HIGH);     
        digitalWrite(22, HIGH);      //电机逆时针
        while (a_cp < a_number)
        {
          digitalWrite(23, HIGH);
          vTaskDelay(10 / portTICK_PERIOD_MS);
          digitalWrite(23, LOW);
          vTaskDelay(10 / portTICK_PERIOD_MS);
          a_cp++;
        }
        a_cp = 0;
      }
    }
    vTaskDelay( 3 / portTICK_PERIOD_MS ); // 等待3ms
  }
}

/*------------------------------------------servo2-----------------------------------------*/
void Task_servo2(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  char b_data = ' ';
  long b_number = 0;
  long b_cp = 0;

  /*----------- servo2引脚接线 -----------*/
  pinMode(26, OUTPUT);    //DIR
  pinMode(27, OUTPUT);    //CP
  pinMode(28, OUTPUT);    //EN
  digitalWrite(28, HIGH);  //EN OFF

  for (;;)
  {
    if (xQueueReceive( b_dir, &b_data, 3) )
    {
      xQueueReceive( b_num, &b_number, 3);

      if (b_data == 'f')
      {
        digitalWrite(28, HIGH);     //EN
        digitalWrite(26, LOW);      //电机顺时针
        while (b_cp < b_number)
        {
          digitalWrite(27, HIGH);
          vTaskDelay( 10 / portTICK_PERIOD_MS  );
          digitalWrite(27, LOW);
          vTaskDelay( 10 / portTICK_PERIOD_MS );
          b_cp++;
        }
        b_cp = 0;
      }
      
      if (b_data == 'i')
      {
        digitalWrite(28, HIGH);     //EN
        digitalWrite(26, HIGH);      //电机逆时针
        while (b_cp < b_number)
        {
          digitalWrite(27, HIGH);
          vTaskDelay( 10 / portTICK_PERIOD_MS );
          digitalWrite(27, LOW);
          vTaskDelay( 10 / portTICK_PERIOD_MS );
          b_cp++;
        }
        b_cp = 0;

      }
    }
    vTaskDelay( 3 / portTICK_PERIOD_MS ); // 等待3ms
  }
}

/*------------------------------------------servo3-----------------------------------------*/
void Task_servo3(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  char c_data = ' ';
  long c_number = 0;
  long c_cp = 0;
   
  /*----------- servo3引脚接线 -----------*/
  pinMode(30, OUTPUT);    //DIR
  pinMode(31, OUTPUT);    //CP
  pinMode(32, OUTPUT);    //EN
  digitalWrite(32, HIGH);  //EN OFF

  for (;;)
  {
    if (xQueueReceive( c_dir, &c_data, 3) )
    {
      xQueueReceive( c_num, &c_number, 3);

      if (c_data == 'f')
      {
        digitalWrite(32, HIGH);     //EN
        digitalWrite(30, LOW);      //远离电机端
        while (c_cp < c_number)
        {
          digitalWrite(31, HIGH);
          vTaskDelay( 10 / portTICK_PERIOD_MS );
          digitalWrite(31, LOW);
          vTaskDelay( 10 / portTICK_PERIOD_MS );
          c_cp++;
        }
        c_cp = 0;
      }
      if (c_data == 'i')
      {
        digitalWrite(32, HIGH);     //EN
        digitalWrite(30, HIGH);      //靠近电机端
        while (c_cp < c_number)
        {
          digitalWrite(31, HIGH);
          vTaskDelay( 10 / portTICK_PERIOD_MS );
          digitalWrite(31, LOW);
          vTaskDelay( 10 / portTICK_PERIOD_MS );
          c_cp++;
        }
        c_cp = 0;
      }
    }
    vTaskDelay(3 / portTICK_PERIOD_MS); // 等待2ms
  }
}
