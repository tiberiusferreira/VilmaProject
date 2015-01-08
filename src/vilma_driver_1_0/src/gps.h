#ifndef GPS_H
#define GPS_H
#include <sensor_msgs/NavSatFix.h>
#include <ros/ros.h>
#include <stdio.h>


class gps
{
private:
    gps();
    ~gps();
    sensor_msgs::NavSatFix car_gps_state;
    ros::Subscriber gps_sub;
    ros::NodeHandle rosNode;
    void receive_gps_state(sensor_msgs::NavSatFix gps_state);

public:
    sensor_msgs::NavSatFix getAsNavSatFix();
    float getLatitude();
    float getLongitude();
    float getAltitude();

};

#endif // GPS_H
