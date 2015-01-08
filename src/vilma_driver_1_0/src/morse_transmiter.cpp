#include "morse_transmiter.h"

morse_transmiter::morse_transmiter()
{
    ackermann_pub = rosNode.advertise<ackermann_msgs::AckermannDrive>("ackermann_cmd", 1000);
//    ackermann_msg.steering_angle=1;
//    ackermann_msg.steering_angle_velocity=100;
//    ackermann_msg.acceleration=200;
//    ackermann_msg.speed=1;
//    ackermann_msg.jerk=0;

}

morse_transmiter::~morse_transmiter()
{

}

void morse_transmiter::setAckermannDrive(ackermann_msgs::AckermannDrive AckermannState){
    this->ackermann_msg=AckermannState;

    this->ackermann_pub.publish(ackermann_msg);
    ros::spinOnce();
}

void morse_transmiter::setSteeringAngle(float rad){
    this->ackermann_msg.steering_angle=rad;
    this->ackermann_msg.acceleration=100.0;
    this->ackermann_msg.speed=200.0;
    this->ackermann_pub.publish(this->ackermann_msg);
    printf("Changed!\n%f\n",rad);
    ros::spinOnce();

}

void morse_transmiter::setSteeringAngleChangeVelocity(float rads_per_sec){
    this->ackermann_msg.steering_angle_velocity=rads_per_sec;

    this->ackermann_pub.publish(ackermann_msg);
    ros::spinOnce();
}

void morse_transmiter::setSpeed(float meters_per_sec){
    this->ackermann_msg.speed=meters_per_sec;

    this->ackermann_pub.publish(ackermann_msg);
    ros::spinOnce();
}

void morse_transmiter::setAcceleration(float meter_per_sec_sec){
    this->ackermann_msg.acceleration=meter_per_sec_sec;

    this->ackermann_pub.publish(ackermann_msg);
    ros::spinOnce();
}

void morse_transmiter::setJerk(float meter_per_sec_sec_sec){
    this->ackermann_msg.jerk=meter_per_sec_sec_sec;

    this->ackermann_pub.publish(ackermann_msg);
    ros::spinOnce();
}



