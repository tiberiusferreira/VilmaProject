#include "gps.h"
gps::gps()
{
    gps_sub = rosNode.subscribe<sensor_msgs::NavSatFix>("/gps",1,&gps::receive_gps_state,this);
}


gps::~gps()
{

}

void gps::receive_gps_state(sensor_msgs::NavSatFix gps_state)
{
    this->car_gps_state=gps_state;
}
sensor_msgs::NavSatFix gps::getAsNavSatFix(){
    return this->car_gps_state;
}

