#include "vilma_ros_talker.h"

vilma_ros_talker::vilma_ros_talker()
{
    //////////////////////////////////// INIT AND RECEIVE STATE FUNCTION //////////////////////////////////////
        //////////////////////////////////// GAS PEDAL //////////////////////////////////////
//        gas_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/gas_pedal/cmd", 1);
//        gas_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/gas_pedal/state",1, &vilma_ros_talker::receive_gas_pedal_data,this);
//        //////////////////////////////////// Brake Pedal //////////////////////////////////////
//        brake_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/brake_pedal/cmd", 1);
//        brake_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/brake_pedal/state",1, &vilma_ros_talker::receive_brake_pedal_data,this);
//        //////////////////////////////////// Hand Brake //////////////////////////////////////
//        hand_brakepub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_brake/cmd", 1);
//        hand_brakesub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_brake/state",1, &vilma_ros_talker::receive_hand_brake_data,this);
//        ////////////////////////////////////Hand Wheel //////////////////////////////////////
//        hand_wheelpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_wheel/cmd", 1);
//        hand_wheelsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_wheel/state",1,&vilma_ros_talker::receive_hand_wheel_data,this);
//        ////////////////////////////////////Wheel Velocity //////////////////////////////////////
//        bl_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/blWheel",1,&vilma_ros_talker::receive_back_left_wheel_speed,this);
//        br_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/brWheel",1,&vilma_ros_talker::receive_back_right_wheel_speed,this);
//        fl_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/flWheel",1,&vilma_ros_talker::receive_front_left_wheel_speed,this);
//        fr_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/frWheel",1,&vilma_ros_talker::receive_front_right_wheel_speed,this);
//        //points_sub = rosNode.subscribe<sensor_msgs::PointCloud>("vilma_vehicle/lidar",1,&vilma_ros_talker::receive_points,this);
//        ////////////////////////////////////Gears State //////////////////////////////////////
//        gears_pub = rosNode.advertise<std_msgs::Int8>("/vilma_vehicle/direction/cmd", 1);
//        gears_sub = rosNode.subscribe<std_msgs::Int8>("/vilma_vehicle/direction/state",1,&vilma_ros_talker::receive_gears_state,this);
//        ////////////////////////////////////GPS State //////////////////////////////////////
//        modelstatesub = rosNode.subscribe<sensor_msgs::NavSatFix>("vilma_vehicle/ideal_gps",1,&vilma_ros_talker::receive_gps_state,this);
          gps_sub = rosNode.subscribe<sensor_msgs::NavSatFix>("/gps",1,&vilma_ros_talker::receive_gps_state,this);
//        ////////////////////////////////////IMU State //////////////////////////////////////
          imu_sub = rosNode.subscribe<sensor_msgs::Imu>("/imu",1,&vilma_ros_talker::receive_imu_data,this);
          ackermann_pub = rosNode.advertise<ackermann_msgs::AckermannDrive>("ackermann_cmd", 1000);

        //((getmodelstate).request).model_name ="vilma_vehicle";
}
void vilma_ros_talker::receive_gps_state(sensor_msgs::NavSatFix gps_state)
{
    this->car_gps_state=gps_state;
}
void vilma_ros_talker::receive_imu_data(sensor_msgs::Imu data)
{
    this->imu_data=data;
}
void vilma_ros_talker::receive_model_physical_state()
{
    ros::spinOnce();
    ros_service.call((getmodelstate));
    modelstate.pose.position.x=getmodelstate.response.pose.position.x;
    modelstate.pose.position.y=getmodelstate.response.pose.position.y;
    modelstate.pose.position.z=getmodelstate.response.pose.position.z;
    modelstate.twist.linear.x=getmodelstate.response.twist.linear.x;
    modelstate.twist.linear.y=getmodelstate.response.twist.linear.y;
    modelstate.twist.linear.z=getmodelstate.response.twist.linear.z;
    modelstate.twist.angular.x=getmodelstate.response.twist.angular.x;
    modelstate.twist.angular.y=getmodelstate.response.twist.angular.y;
    modelstate.twist.angular.z=getmodelstate.response.twist.angular.z;
    modelstate.pose.orientation.x=getmodelstate.response.pose.orientation.x;
    modelstate.pose.orientation.y=getmodelstate.response.pose.orientation.y;
    modelstate.pose.orientation.z=getmodelstate.response.pose.orientation.z;
    modelstate.pose.orientation.w=getmodelstate.response.pose.orientation.w;
}
void vilma_ros_talker::receive_gas_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    gas_pedal_state.data=msg->data;
}
void vilma_ros_talker::receive_brake_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    brake_pedal_state.data=msg->data;
}
void vilma_ros_talker::receive_hand_brake_data(const std_msgs::Float64::ConstPtr& msg)
{
    hand_brake_state.data=msg->data;
}
void vilma_ros_talker::receive_hand_wheel_data(const std_msgs::Float64::ConstPtr& msg)
{
    hand_wheel_state.data=msg->data;
}
void vilma_ros_talker::receive_back_left_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    bl_wheel_speed.data=msg->data;
}
void vilma_ros_talker::receive_back_right_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    br_wheel_speed.data=msg->data;
}
void vilma_ros_talker::receive_front_left_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    fl_wheel_speed.data=msg->data;
}
void vilma_ros_talker::receive_front_right_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    fr_wheel_speed.data=msg->data;
}
void vilma_ros_talker::receive_gears_state(const std_msgs::Int8::ConstPtr& msg)
{
    //gears.data=msg->data;
}
//////////////////////////////////// FUNCTION FOR CONTROLLING THE CAR //////////////////////////////////////

void vilma_ros_talker::set_gears(int gear){
    morse_gears=gear;
//    std_msgs::Int8 gears_value;
//    gears_value.data=gear;
//    this->gears_pub.publish(gears_value);
}
void vilma_ros_talker::set_steering(float value)
{
    ackermann_msg.steering_angle=(value+0.0)/10;
    ackermann_pub.publish(ackermann_msg);


//    std_msgs::Float64 steering_value;
//    steering_value.data=value;
//    hand_wheelpub.publish(steering_value);
}
void vilma_ros_talker::accelerate(float amount_to_increase){
//    std_msgs::Float64 accelerate;
//    if(this->brake_pedal_state.data>0.01){
//        accelerate.data=0;
//        this->brake_pedalpub.publish(accelerate);
//        return;
//    }
//    accelerate.data=this->gas_pedal_state.data+amount_to_increase;
//    this->gas_pedalpub.publish(accelerate);
}
void vilma_ros_talker::set_gas_pedal(float value){
    ackermann_msg.speed = value*100.0;
    ackermann_msg.acceleration = value*100;

    this->ackermann_pub.publish(ackermann_msg);
    ros::spinOnce();
}
void vilma_ros_talker::set_brake_pedal(float value){
//    std_msgs::Float64 pub_msg;
//    pub_msg.data=value;
//    this->brake_pedalpub.publish(pub_msg);
}
void vilma_ros_talker::deaccelerate(float amount_to_decrease){
//    std_msgs::Float64 deaccelerate;
//    if(this->gas_pedal_state.data>0.005){
//        deaccelerate.data=this->gas_pedal_state.data-amount_to_decrease;
//        this->gas_pedalpub.publish(deaccelerate);
//        return;
//    }
//    deaccelerate.data=this->brake_pedal_state.data+amount_to_decrease;
//    this->brake_pedalpub.publish(deaccelerate);
}
void vilma_ros_talker::use_hand_brake(){

    ackermann_msg.speed = 0;
    ackermann_msg.acceleration = 0;

    this->ackermann_pub.publish(ackermann_msg);
    ros::spinOnce();
}
void vilma_ros_talker::reset_state(){
//    ros::spinOnce();
//    std_msgs::Float64 reset_gas;
//    std_msgs::Float64 reset_brake;
//    std_msgs::Float64 reset_hand_brake;
//    std_msgs::Float64 reset_steering;
//    std_msgs::Int8 reset_gears;
//    reset_gas.data=0;
//    reset_steering.data=0;
//    reset_brake.data=0;
//    reset_gears.data=1;
//    this->gas_pedalpub.publish(reset_gas);
//    this->hand_wheelpub.publish(reset_steering);
//    this->brake_pedalpub.publish(reset_brake);
//    this->gears_pub.publish(reset_gears);
//    if(this->hand_brake_state.data<=0.1)
//    {
//        for(reset_hand_brake.data=this->hand_brake_state.data+0.1; this->hand_brake_state.data<=0.88; reset_hand_brake.data=this->hand_brake_state.data+0.1)
//        {
//            this->hand_brakepub.publish(reset_hand_brake);
//            ros::spinOnce();
//        }
//    }
}
gazebo::math::Quaternion vilma_ros_talker::imudata_to_euler()
{
    gazebo::math::Quaternion temp;
    temp.x=this->imu_data.orientation.x;
    temp.y=this->imu_data.orientation.y;
    temp.z=this->imu_data.orientation.z;
    temp.w=this->imu_data.orientation.w;
    return temp;
}

//![0]




















