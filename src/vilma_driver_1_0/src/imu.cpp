#include "imu.h"
imu::imu()
{
    imu_sub = rosNode.subscribe<sensor_msgs::Imu>("/imu",1,&imu::receive_imu_data,this);

}

imu::~imu()
{

}

sensor_msgs::Imu imu::getAsImu(){
    return this->imu_received_data;
}

void imu::receive_imu_data(sensor_msgs::Imu data)
{
     this->imu_received_data=data;
}

float imu::getOrientationX(){
    return this->imu_received_data.orientation.x;
}

float imu::getOrientationY(){
    return this->imu_received_data.orientation.y;
}

float imu::getOrientationZ(){
    return this->imu_received_data.orientation.z;

}

float imu::getOrientationW(){
    return this->imu_received_data.orientation.w;
}

float imu::getLinearAcelX(){
    return this->imu_received_data.linear_acceleration.x;
}

float imu::getLinearAcelY(){
    return this->imu_received_data.linear_acceleration.y;
}

float imu::getLinearAcelZ(){
    return this->imu_received_data.linear_acceleration.z;
}

float imu::getAngularVelX(){
    return this->imu_received_data.angular_velocity.x;

}

float imu::getAngularVelY(){
    return this->imu_received_data.angular_velocity.y;
}

float imu::getAngularVelZ(){
    return this->imu_received_data.angular_velocity.z;
}

float imu::getOrientationZAsEuler(){
    gazebo::math::Quaternion temp;
    temp.x=this->imu_received_data.orientation.x;
    temp.y=this->imu_received_data.orientation.y;
    temp.z=this->imu_received_data.orientation.z;
    temp.w=this->imu_received_data.orientation.w;
    return (float) temp.GetYaw();

}
