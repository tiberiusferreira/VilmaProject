#ifndef MORSE_TRANSMITER_H
#define MORSE_TRANSMITER_H
#include <ros/ros.h>
#include <stdio.h>
#include <ackermann_msgs/AckermannDrive.h>
class morse_transmiter
{
private:
    ackermann_msgs::AckermannDrive ackermann_msg; //Holds the steering, speed and acceleration desired
    ros::Publisher ackermann_pub;
    ros::NodeHandle rosNode;

public:
    morse_transmiter();
    ~morse_transmiter();
    void setAckermannDrive(ackermann_msgs::AckermannDrive AckermannState);
    void setSteeringAngle(float rad);
    void setSteeringAngleChangeVelocity(float rads_per_sec);
    void setSpeed(float meters_per_sec);
    void setAcceleration(float meter_per_sec_sec);
    void setJerk(float meter_per_sec_sec_sec);

};

#endif // MORSE_TRANSMITER_H
