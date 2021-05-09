//#ifndef DING_IK_THREE_PARALLAL_H
//#define DING_IK_THREE_PARALLAL_H

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <vicon_bridge/Markers.h>

//#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/frames.hpp>
#include <Eigen/Dense>
#include <Eigen/src/Geometry/Quaternion.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>
#include <fstream>
#include <std_msgs/Float32MultiArray.h>
#include "../include/Angle.h"
#include "../include/ik_three_parallel.h"

using namespace std;

double cur_imu_w_,cur_imu_x_,cur_imu_y_,cur_imu_z_;
double euler_x=0,euler_y=0,euler_z=0,h=105;  //实际h 220
double euler_x_start=0,euler_y_start=0;
//double euler_x_original=0,euler_y_original=0;

double marker1_x,marker1_y,marker1_z ,marker2_x, marker2_y,marker2_z, marker3_x,marker3_y,marker3_z,marker4_x,marker4_y,marker4_z;
void subvicondataCB(vicon_bridge::Markers msg){
    marker1_x = msg.markers[0].translation.x;
    marker1_y= msg.markers[0].translation.y;
    marker1_z= msg.markers[0].translation.z;


    marker2_x= msg.markers[1].translation.x;
    marker2_y= msg.markers[1].translation.y;
    marker2_z= msg.markers[1].translation.z;

    marker3_x= msg.markers[2].translation.x;
    marker3_y= msg.markers[2].translation.y;
    marker3_z= msg.markers[2].translation.z;

    marker4_x= msg.markers[3].translation.x;
    marker4_y= msg.markers[3].translation.y;
    marker4_z= msg.markers[3].translation.z;
}

void subimudataCB(sensor_msgs::Imu msg) {
    cur_imu_w_ = msg.orientation.w;
    cur_imu_x_ = msg.orientation.x;
    cur_imu_y_ = msg.orientation.y;
    cur_imu_z_ = msg.orientation.z;

    std::cout << " ........ " << std::endl;
//    KDL::Rotation imu_rot;
    Eigen::Quaterniond Q(cur_imu_w_,cur_imu_x_,cur_imu_y_,cur_imu_z_);
    Q = Q.normalized();
    Eigen::Vector3d eulerAngle4 = Q.matrix().eulerAngles(2,1,0);
    eulerAngle4=eulerAngle4.transpose();
    euler_z=eulerAngle4[0];euler_y=eulerAngle4[1];euler_x=eulerAngle4[2];
//    euler_y_original=euler_y;euler_x_original=euler_x;
    if (fabs(euler_y) >1.04)
    {
        euler_y = euler_y_start;
//        euler_y_original=euler_y;
    }
    else {
        euler_y=euler_y_start*0.8+euler_y*0.2;
        euler_y_start=euler_y;
    }
    if (fabs(euler_y) > 1.04)
    {
        euler_x = euler_x_start;
//        euler_x_original=euler_x;
    } else {
        euler_x=euler_x_start*0.8+euler_x*0.2;
        euler_x_start=euler_x;
    }

    cout << "yaw(z) pitch(y) roll(x) = " << euler_z << " "<< euler_y << " " << euler_x << endl;
    cout << "yaw(z) pitch(y) roll(x) = " << euler_z*180/pi << " "<< euler_y*180/pi << " " << euler_x*180/pi << endl;

//    imu_rot = KDL::Rotation::Quaternion(Q.x(),Q.y(),Q.z(),Q.w());
//    imu_rot.GetEulerZYX(euler_z,euler_y,euler_x); //单位是弧度

}

int main(int argc, char **argv)
{
    double angle_start[3]={0,0,0};
    double angle[3];
    double angle_change[3]={0,0,0};
    ros::init(argc, argv, "servo_control");
    ros::NodeHandle n;
    std_msgs::Float32MultiArray servo_pulse;
    ros::Subscriber sub_imu = n.subscribe("/imu", 1, &subimudataCB );
    ros::Subscriber sub_vicon = n.subscribe("/vicon/markers", 1, &subvicondataCB );
    ros::Publisher pub = n.advertise<std_msgs::Float32MultiArray>("/servo_angle", 1);
    ros::Rate loop_rate(40);

    std::ofstream file;
    std::ostringstream oss;
    std::string filename = "imu_control_y_10";
    std::string file_ ="/home/lzw/ding/src/record_2/" + filename + ".txt";
    uint64_t nsec0 = ros::Time::now().toNSec();

    while (ros::ok())
    {
        ros::spinOnce();
//        cal_thetas(euler_x,euler_y,h,angle); //x_change y_change是动平台的欧拉角 angle是每个电机的转角,单位是弧度
        cal_thetas(euler_x,euler_y,h,angle);

        uint64_t time_now = ros::Time::now().toNSec() - nsec0;
        double time_now_d = time_now / 1e9;
        file.open(file_.c_str(), std::ios::app);
        file << time_now_d << " ";
//        file << euler_x  << " " << euler_y << " " << euler_x_original << " " << euler_y_original;
//        file << " "<< euler_x_original*180/pi <<" "<< euler_y_original*180/pi;
//        file << std::endl;
        file << euler_x  << " " << euler_y << " " << marker1_x << " " << marker1_y << " " << marker1_z;
        file <<" " << marker2_x << " " << marker2_y << " " << marker2_z;
        file <<" " << marker3_x << " " << marker3_y << " " << marker3_z;
        file <<" " << marker4_x << " " << marker4_y << " " << marker4_z;
        file << std::endl;
        file.close();

//        cout<<"angle[0]  angle[1]    angle[2]  = "<< angle[0]<<"  " <<angle[1]<<"  " <<angle[2]<<"  "<< endl;
        angle_change[0]=angle[0]-angle_start[0];
        angle_change[1]=angle[1]-angle_start[1];
        angle_change[2]=angle[2]-angle_start[2];
        if( fabs(angle_change[0]) < 0.008 ) //小于0.45度去掉
        {
            angle_change[0]=0;
        }
        if( fabs(angle_change[1]) < 0.008 )
        {
            angle_change[1]=0;
        }
        if( fabs(angle_change[2]) < 0.008 )
        {
            angle_change[2]=0;
        }

        servo_pulse.data.push_back(33600/pi*angle_change[0]) ;
        servo_pulse.data.push_back(33600/pi*angle_change[1]) ;
        servo_pulse.data.push_back(33600/pi*angle_change[2]) ;

        cout<< "电机1脉冲数："<< long(33600/pi*angle_change[0]) <<"  电机2脉冲数："<< long(33600/pi*angle_change[1]) << "  电机3脉冲数："<< long(33600/pi*angle_change[2])<<endl;
        pub.publish(servo_pulse);
        angle_start[0]=angle[0];angle_start[1]=angle[1];angle_start[2]=angle[2];

        servo_pulse.data.pop_back();servo_pulse.data.pop_back();servo_pulse.data.pop_back();
        loop_rate.sleep();
    }

//    std::ofstream file;
//    std::ostringstream oss;
//    std::string filename = "serco_control_imu_";
//    std::string file_ ="/home/lzw/ding/src/record" + filename + ".txt";
//    uint64_t nsec0 = ros::Time::now().toNSec();

//    uint64_t time_now = ros::Time::now().toNSec() - nsec0;
//    double time_now_d = time_now / 1e9;
//    file.open(file_.c_str(), std::ios::app);
//    file << time_now_d << " ";
//    file << euler_x  << " " << euler_y ;
//    file << std::endl;
//    file.close();
    return 0;
}

//#endif //DING_IK_THREE_PARALLAL_H