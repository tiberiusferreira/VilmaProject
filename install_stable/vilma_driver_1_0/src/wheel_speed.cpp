#include "wheel_speed.h"

wheel_speed::wheel_speed()
{
    wheel_speed_sub = rosNode.subscribe<std_msgs::Float64MultiArray>("/wheelspeed",1,&wheel_speed::receive_wheel_speed,this);
}


wheel_speed::~wheel_speed()
{

}

void wheel_speed::receive_wheel_speed(std_msgs::Float64MultiArray new_wheel_speed)
{
    this->wheel_speed_data=new_wheel_speed;
}
double wheel_speed::getFLspeed(){
    if(!wheel_speed_data.data.empty()){
        return (wheel_speed_data.data.at(0));
    }else{
        return 0;
    }
}

double wheel_speed::getFRspeed(){
    if(!wheel_speed_data.data.empty()){
        return (wheel_speed_data.data.at(1));
    }else{
        return 0;
    }
}

double wheel_speed::getRLspeed(){
    if(!wheel_speed_data.data.empty()){
        return (wheel_speed_data.data.at(2));
    }else{
        return 0;
    }
}

double wheel_speed::getRRspeed(){
    if(!wheel_speed_data.data.empty()){
        return (wheel_speed_data.data.at(3));
    }else{
        return 0;
    }
}
