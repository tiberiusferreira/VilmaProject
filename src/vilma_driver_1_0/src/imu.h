#ifndef IMU_H
#define IMU_H
#include <sensor_msgs/Imu.h>
#include <ros/ros.h>
#include <stdio.h>
#include <gazebo/math/Quaternion.hh>
class imu
{
private:
    imu();
    ~imu();
    sensor_msgs::Imu imu_received_data;
    ros::Subscriber imu_sub;
    ros::NodeHandle rosNode;
    void receive_imu_data(sensor_msgs::Imu data);
    gazebo::math::Quaternion imudata_to_euler();
public:
    sensor_msgs::Imu getAsImu();

    float getOrientationX();
    float getOrientationY();
    float getOrientationZ();
    float getOrientationW();

    float getLinearAcelX();
    float getLinearAcelY();
    float getLinearAcelZ();

    float getAngularVelX();
    float getAngularVelY();
    float getAngularVelZ();

    float getOrientationZAsEuler();

};

#endif // IMU_H
