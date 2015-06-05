#ifndef GPS_H
#define GPS_H
#include <sensor_msgs/NavSatFix.h>
#include <ros/ros.h>
#include <stdio.h>


class gps
{
private:
    sensor_msgs::NavSatFix car_gps_state;
    ros::Subscriber gps_sub;
    ros::NodeHandle rosNode;
    void receive_gps_state(sensor_msgs::NavSatFix gps_state);


public:
    gps();
    ~gps();
    sensor_msgs::NavSatFix getAsNavSatFix();
    double getLatitude();
    double getLongitude();
    double getAltitude();

};

#endif // GPS_H
