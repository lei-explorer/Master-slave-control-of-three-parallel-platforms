//
// Created by lzw on 2021/4/3.
//

#ifndef DING_IK_THREE_PARALLAL_H
#define DING_IK_THREE_PARALLAL_H

#include "../include/Angle.h"
#include <math.h>
#include <vector>
using namespace std;

#define pi 3.1415926

double norm(std::vector<double> v);
double dot(std::vector<double> v1,std::vector<double> v2);
double dot(std::vector<double> v1,std::vector<double> v2);
void cal_thetas(double x,double y,double h ,double* thetas); //输入单位是毫米（mm）和度（°）;返回的是三个电机的转角，输出单位rad

double norm(std::vector<double> v)
{
    return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}

std::vector<double> cut(std::vector<double> v1,std::vector<double> v2)
{
    std::vector<double> y(3);
    y[0]=v1[0]-v2[0];y[1]=v1[1]-v2[1];y[2]=v1[2]-v2[2];
    return y;
}
double dot(std::vector<double> v1,std::vector<double> v2)
{
    double y;
    y=v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
    return y;
}

void cal_thetas(double x,double y,double h ,double* thetas)
{
//    float x = m/180*pi;
//    float y = n/180*pi;
//  输入平台参数和各个常向量

    double r = 40;
    float R = 90;
    float l1 = 100;
    float l2 = 110;
    float l3 = 74.5;

    std::vector<double> q(3);q[0]=0;q[1]=0;q[2]=1;
    std::vector<double> ab(3); ab[0]=0.5*sqrt(3);ab[1]=-0.5;ab[2]=0;
    std::vector<double> ac(3); ac[0]=0.5*sqrt(3);ac[1]=0.5;ac[2]=0;
//  求动平台三个顶点在动平台变化后相对于动平台原坐标系的坐标
    std::vector<double> A1(3); A1[0]=-R/2;A1[1]=0;A1[2]=0;
    std::vector<double> B1(3); B1[0]=R/4;B1[1]=sqrt(3)*R/4;B1[2]=0;
    std::vector<double> C1(3); C1[0]=R/4;C1[1]=-sqrt(3)*R/4;C1[2]=0;
    std::vector<double> Pa(3); Pa[0]=-r*cos(x);Pa[1]=0;Pa[2]=r*sin(x);
    std::vector<double> Pb(3); Pb[0]=(r*cos(x)+sqrt(3)*r*sin(y))/2;Pb[1]=sqrt(3)*r*cos(y)/2;Pb[2]=(-r*sin(x)+sqrt(3)*r*cos(x)*sin(y))/2;
    std::vector<double> Pc(3); Pc[0]=(r*cos(x)-sqrt(3)*r*sin(x)*sin(y))/2;Pc[1]=-(sqrt(3)*r*cos(y))/2;Pc[2]=(-r*sin(x)-sqrt(3)*r*cos(x)*sin(y))/2;
//   求λ
    float va = 0;
    double vb=pi/2 - acos((ab[0]*Pb[0]+ab[1]*Pb[1]+ab[2]*Pb[2]) / norm(Pb));
    double vc=pi/2 - acos((ac[0]*Pc[0]+ac[1]*Pc[1]+ac[2]*Pc[2]) / norm(Pc) );
//    % 求三个第三关节在静坐标系中的坐标
    std::vector<double> A03(3); A03[0]=-l3*cos(x)-r*cos(x);A03[1]=0;A03[2]=l3*sin(x)+r*sin(x)+h;
    std::vector<double> B03(3);
    B03[0]=(r*cos(x)-sqrt(3)*l3*sin(vb)*cos(x)-sin(x)*sin(y)+l3*cos(vb)*(cos(x)+sqrt(3)*sin(x)*sin(y))+sqrt(3)*r*sin(x)*sin(y))/2;
    B03[1]=(sqrt(3)*r*cos(y)+l3*cos(y)*sin(vb)+sqrt(3)*l3*cos(y)*cos(vb))/2;
    B03[2]=h-(r*sin(x)-sqrt(3)*l3*sin(vb)*sin(x)-cos(x)*sin(y)+l3*cos(vb)*(sin(x)-sqrt(3)*cos(x)*sin(y))-sqrt(3)*r*cos(x)*sin(y))/2;
//    std::vector<double> B03 {(r*cos(x)-sqrt(3)*l3*sin(vb)*cos(x)-sin(x)*sin(y)+l3*cos(vb)*(cos(x)+sqrt(3)*sin(x)*sin(y))+sqrt(3)*r*sin(x)*sin(y))/2,(sqrt(3)*r*cos(y)+l3*cos(y)*sin(vb)+sqrt(3)*l3*cos(y)*cos(vb))/2,h-(r*sin(x)-sqrt(3)*l3*sin(vb)*sin(x)-cos(x)*sin(y)+l3*cos(vb)*(sin(x)-sqrt(3)*cos(x)*sin(y))-sqrt(3)*r*cos(x)*sin(y))/2};
//    std::vector<double> C03 {(r*cos(x)+sqrt(3)*l3*sin(vc)*cos(x)+sin(x)+sin(y)+l3*cos(vc)*(cos(x)-sqrt(3)*sin(x)*sin(y))-sqrt(3)*r*sin(x)*sin(y))/2,(-sqrt(3)*r*cos(y)+l3*cos(y)*sin(vc)-sqrt(3)*l3*cos(y)*cos(vc))/2,h-(r*sin(x)+sqrt(3)*l3*sin(vc)*sin(x)+cos(x)*sin(y)+l3*cos(vc)*(sin(x)+sqrt(3)*cos(x)*sin(y))+sqrt(3)*r*cos(x)*sin(y))/2};
    std::vector<double> C03(3);
    C03[0]=(r*cos(x)+sqrt(3)*l3*sin(vc)*cos(x)+sin(x)+sin(y)+l3*cos(vc)*(cos(x)-sqrt(3)*sin(x)*sin(y))-sqrt(3)*r*sin(x)*sin(y))/2;
    C03[1]=(-sqrt(3)*r*cos(y)+l3*cos(y)*sin(vc)-sqrt(3)*l3*cos(y)*cos(vc))/2;
    C03[2]=h-(r*sin(x)+sqrt(3)*l3*sin(vc)*sin(x)+cos(x)*sin(y)+l3*cos(vc)*(sin(x)+sqrt(3)*cos(x)*sin(y))+sqrt(3)*r*cos(x)*sin(y))/2;
//    求三个第一关节第三关节连线在静坐标系中的坐标
    std::vector<double> A31(3); A31 = cut(A03,A1);
    std::vector<double> B31(3); B31 = cut(B03,B1);
    std::vector<double> C31(3); C31 = cut(C03,C1);
//     求一三关节夹角
    double kesaiA = acos( (l1*l1+pow(norm(A31),2)-l2*l2) / (2*l1*norm(A31) ));
    double kesaiB = acos( (l1*l1 +pow(norm(B31),2)-l2*l2) /(2*l1*norm(B31)));
    double kesaiC = acos( (l1*l1+ pow(norm(C31),2)-l2*l2)  /(2*l1*norm(C31)));
//    % 求一三关节连线和xoy平面法向量夹角
    double fiA=pi/2-acos(dot(A31,q)/norm(A31));
    double fiB=pi/2-acos(dot(B31,q)/norm(B31));
    double fiC=pi/2-acos(dot(C31,q)/norm(C31));
//    % 求电机转角
    double thetaA = fiA-kesaiA;
    double thetaB = fiB-kesaiB;
    double thetaC = fiC-kesaiC;

    thetas[0]=thetaA;
    thetas[1]=thetaB;
    thetas[2]=thetaC;
}

#endif //DING_IK_THREE_PARALLAL_H
