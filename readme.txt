这是三并联主动平台的控制代码，使用说明：

	插上imu 和arduino的usb接口，arduino是控制三个步进电机的;

	把servo_drive -> src下的servo_drive.ino烧录到arduino板子里面

	进入sensor_imu包内，在script下打开终端，执行  sudo ./udev.sh

	接着  roslaunch sensor_imu sensor_imu.launch

	roslaunch vicon_bridge-master vicon.launch  启动vicon捕捉4个marker点，先在rqt里看一下内不能识别出所有点，不能的话就要调整marker点的位置

	再执行 rosrun servo_drive servo_control  这个node还会记录当下imu的姿态角和4个marker点的坐标，具体看cpp代码

	这时平台还不会跟随IMU笔动，但是终端会打印imu的姿态，调整imu姿态到合适的初始位置

	然后执行 rosrun rosserial_python.node  /dev/ttyAOM1   ttyAOM1是arduino连接电脑的端口，在arduino软件里可以看到，按照实际输入

	执行完这条指令之后，三并联平台就会跟随IMU运动

