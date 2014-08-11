/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
//![0]
#include "VilmaControler_QtSide.h"
#include <cstdio>
#include <cmath>
//////////////////////////////////// INIT AND RECEIVE STATE FUNCTION //////////////////////////////////////
void VilmaControler_ROS::init()
{
    this->thread_count=0;
    obstacle_ahead=0;
    ////////////////////////////////////GAS PEDAL //////////////////////////////////////
    gas_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/gas_pedal/cmd", 1);

    gas_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/gas_pedal/state",1,&VilmaControler_ROS::receive_gas_pedal_data,this);

    ////////////////////////////////////Brake Pedal //////////////////////////////////////

    brake_pedalpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/brake_pedal/cmd", 1);

    brake_pedalsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/brake_pedal/state",1, &VilmaControler_ROS::receive_brake_pedal_data,this);
    ////////////////////////////////////Hand Brake //////////////////////////////////////


    hand_brakepub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_brake/cmd", 1);

    hand_brakesub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_brake/state",1,&VilmaControler_ROS::receive_hand_brake_data,this);

    ////////////////////////////////////Hand Wheel //////////////////////////////////////

    hand_wheelpub = rosNode.advertise<std_msgs::Float64>("/vilma_vehicle/hand_wheel/cmd", 1);

    hand_wheelsub = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/hand_wheel/state",1,&VilmaControler_ROS::receive_hand_wheel_data,this);

    ////////////////////////////////////Wheel Velocity //////////////////////////////////////

    bl_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/blWheel",1,&VilmaControler_ROS::receive_back_left_wheel_speed,this);
    br_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/brWheel",1,&VilmaControler_ROS::receive_back_right_wheel_speed,this);
    fl_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/flWheel",1,&VilmaControler_ROS::receive_front_left_wheel_speed,this);
    fr_wheel = rosNode.subscribe<std_msgs::Float64>("/vilma_vehicle/wheelspeed/frWheel",1,&VilmaControler_ROS::receive_front_right_wheel_speed,this);
    points_sub = rosNode.subscribe<sensor_msgs::PointCloud>("vilma_vehicle/lidar",1,&VilmaControler_ROS::receive_points,this);
    ////////////////////////////////////Gears State //////////////////////////////////////

    gears_pub = rosNode.advertise<std_msgs::Int8>("/vilma_vehicle/direction/cmd", 1);

    gears_sub = rosNode.subscribe<std_msgs::Int8>("/vilma_vehicle/direction/state",1,&VilmaControler_ROS::receive_gears_state,this);
    ////////////////////////////////////GPS State //////////////////////////////////////
    modelstatesub = rosNode.subscribe<sensor_msgs::NavSatFix>("vilma_vehicle/ideal_gps",1,&VilmaControler_ROS::receive_gps_state,this);
    ////////////////////////////////////IMU State //////////////////////////////////////
    imu_sub = rosNode.subscribe<sensor_msgs::Imu>("vilma_vehicle/imu",1,&VilmaControler_ROS::receive_imu_data,this);

}
void VilmaControler_ROS::receive_gps_state(sensor_msgs::NavSatFix gps_state){
    this->car_gps_state=gps_state;
}
void VilmaControler_ROS::receive_imu_data(sensor_msgs::Imu data){
    this->imu_data=data;
}


void VilmaControler_ROS::callback1()
{
    float acceleration, speed_t1,speed_t2, target_speed, diff_vel, time_diff=0.01;
    target_speed=(this->bl_wheel_speed.data+this->br_wheel_speed.data)/2;
    for(;1;){
        try
        {
            boost::this_thread::interruption_point();
        }
        catch(boost::thread_interrupted&)
        {
            return;
        }
        speed_t1=(this->bl_wheel_speed.data+this->br_wheel_speed.data)/2;
        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
        speed_t2=(this->bl_wheel_speed.data+this->br_wheel_speed.data)/2;
        while(speed_t1==speed_t2){
            boost::this_thread::sleep(boost::posix_time::milliseconds(10));
            speed_t2=(this->bl_wheel_speed.data+this->br_wheel_speed.data)/2;
            time_diff=time_diff+0.01;
        }
        acceleration=(speed_t2-speed_t1)/time_diff;
        time_diff=0.01;
        printf("BACK Wheel Aceleration %f\n",acceleration);
        printf("Target speed: %f\n",target_speed);
        printf("Actual speed: %f\n",speed_t2);
        diff_vel=target_speed-speed_t2;
        printf("DIFF = %f\n",diff_vel);

        if(diff_vel>0){ //target_speed >speed_t2, need to speed up!
            if(acceleration>0){
                if(acceleration<=(diff_vel/2)){
                    //do nothing
                    // printf("\n1\n");
                }
                if(acceleration>(diff_vel/2)){
                    this->deaccelerate(0.03);
                    //printf("\n2\n");

                }
            }else if(acceleration<0)
            {
                //printf("\n3\n");

                this->accelerate(0.01);
            }
        }else if(diff_vel<0){ //speed_t2>target_speed need to slow down!
            printf("Acceleration= %f \n",acceleration);
            if(acceleration<0){
                if(acceleration>=(diff_vel/2))
                {
                    //printf("\n4\n");

                    //do nothing
                }
                if(acceleration<(diff_vel/2)){
                    this->accelerate(0.01);
                    // printf("Acceleration = %f. Diff_vel = %f.\n",acceleration,diff_vel);

                }
            }else
            {
                this->deaccelerate(0.03);
                //printf("\n6\n");

            }
        }
    }
}
void VilmaControler_ROS::receive_points(sensor_msgs::PointCloud cloud){
    int i,detected=0,virar_direita=0;
    float maior_y=0,menor_y=0;
    FILE * pFile;
    for(i=0;i<3072;i++){
        if(cloud.points[i].x>3 && cloud.points[i].x<15 && cloud.points[i].z>-0.5){
            detected=1;
            break;
        }
    }
    for(i=0;i<3072 && detected==1;i++){
        if(cloud.points[i].x>16 && cloud.points[i].z>-0.5){
            if(cloud.points[i].y>maior_y){
                maior_y=cloud.points[i].y;
            }
            if(cloud.points[i].y<menor_y){
                menor_y=cloud.points[i].y;
            }
        }
    }
    if(detected){
        printf("menor y %f maior y %f\n",menor_y,maior_y);
        if(abs(maior_y)>abs(menor_y)){
            virar_direita=0;
        }else{
            virar_direita=1;
        }
        if(this->obstacle_ahead==1){
            return;
        }
        printf("Obstacle ahead!\n");
        this->obstacle_ahead=1;
        pFile = fopen ("car_state.txt","w+");
        if (pFile!=NULL)
        {
            fprintf (pFile,"Just after acknowledging the obstacle\n");
            fprintf (pFile,"Front Left Wheel Speed %f rad/s.\n",this->fl_wheel_speed.data);
            fprintf (pFile,"Front Right Wheel Speed %frad/s.\n",this->fr_wheel_speed.data);
            fprintf (pFile,"Back Left Wheel Speed %frad/s.\n",this->bl_wheel_speed.data);
            fprintf (pFile,"Back Right Wheel Speed %frad/s.\n",this->br_wheel_speed.data);
            fprintf (pFile,"Model latitude %f.\n",this->car_gps_state.latitude);
            fprintf (pFile,"Model longitude %f.\n",this->car_gps_state.longitude);
            fprintf (pFile,"Model X pose %f.\n",this->modelstate.pose.position.x);
            fprintf (pFile,"Model Y pose %f.\n",this->modelstate.pose.position.y);
            fprintf (pFile,"Model Z pose %f.\n",this->modelstate.pose.position.z);
            fprintf (pFile,"Model X linear velocity %f.\n",this->modelstate.twist.linear.x);
            fprintf (pFile,"Model Y linear velocity %f.\n",this->modelstate.twist.linear.y);
            fprintf (pFile,"Model Z linear velocity %f.\n",this->modelstate.twist.linear.z);
            fprintf (pFile,"Model X angular velocity %f.\n",this->modelstate.twist.angular.x);
            fprintf (pFile,"Model Y angular velocity %f.\n",this->modelstate.twist.angular.y);
            fprintf (pFile,"Model Z angular velocity %f.\n",this->modelstate.twist.angular.z);
            fclose (pFile);
        }
        if(virar_direita==1){
            use_Steering(-3.14);
        }
        if(virar_direita==0){
            use_Steering(3.14);
        }
        return;
    }
    else{
        if(this->obstacle_ahead==1){
            printf("Obstacle no longer ahead!\n");
            this->obstacle_ahead=0;
            pFile = fopen ("car_state.txt","a");
            if (pFile!=NULL)
            {
                fprintf (pFile,"\nJust after no longer detecting the obstacle\n");
                fprintf (pFile,"Front Left Wheel Speed %f rad/s.\n",this->fl_wheel_speed.data);
                fprintf (pFile,"Front Right Wheel Speed %frad/s.\n",this->fr_wheel_speed.data);
                fprintf (pFile,"Back Left Wheel Speed %frad/s.\n",this->bl_wheel_speed.data);
                fprintf (pFile,"Back Right Wheel Speed %frad/s.\n",this->br_wheel_speed.data);
                fprintf (pFile,"Model latitude %f.\n",this->car_gps_state.latitude);
                fprintf (pFile,"Model longitude %f.\n",this->car_gps_state.longitude);
                fprintf (pFile,"Model X pose %f.\n",this->modelstate.pose.position.x);
                fprintf (pFile,"Model Y pose %f.\n",this->modelstate.pose.position.y);
                fprintf (pFile,"Model Z pose %f.\n",this->modelstate.pose.position.z);
                fprintf (pFile,"Model X linear velocity %f.\n",this->modelstate.twist.linear.x);
                fprintf (pFile,"Model Y linear velocity %f.\n",this->modelstate.twist.linear.y);
                fprintf (pFile,"Model Z linear velocity %f.\n",this->modelstate.twist.linear.z);
                fprintf (pFile,"Model X angular velocity %f.\n",this->modelstate.twist.angular.x);
                fprintf (pFile,"Model Y angular velocity %f.\n",this->modelstate.twist.angular.y);
                fprintf (pFile,"Model Z angular velocity %f.\n",this->modelstate.twist.angular.z);
                fclose (pFile);
            }
            use_Steering(0);
        }else{
            this->obstacle_ahead=0;
        }
    }

    return;
}
void VilmaControler_ROS::receive_model_physical_state()
{
    gazebo_msgs::GetModelState getmodelstate;
    ros::ServiceClient gmscl = rosNode.serviceClient<gazebo_msgs::GetModelState>("/gazebo/get_model_state");
    ros::spinOnce();
    ((getmodelstate).request).model_name ="vilma_vehicle";
    gmscl.call((getmodelstate));
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
void VilmaControler_ROS::receive_gas_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    if(msg->data!=gas_pedal_state.data)
    {
        gas_pedal_state.data=msg->data;
    }

}
void VilmaControler_ROS::receive_brake_pedal_data(const std_msgs::Float64::ConstPtr& msg)
{
    brake_pedal_state.data=msg->data;
}
void VilmaControler_ROS::receive_hand_brake_data(const std_msgs::Float64::ConstPtr& msg)
{
    hand_brake_state.data=msg->data;
}
void VilmaControler_ROS::receive_hand_wheel_data(const std_msgs::Float64::ConstPtr& msg)
{
    hand_wheel_state.data=msg->data;
}
void VilmaControler_ROS::receive_back_left_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    bl_wheel_speed.data=msg->data;
}
void VilmaControler_ROS::receive_back_right_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    br_wheel_speed.data=msg->data;
}
void VilmaControler_ROS::receive_front_left_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    fl_wheel_speed.data=msg->data;
}
void VilmaControler_ROS::receive_front_right_wheel_speed(const std_msgs::Float64::ConstPtr& msg)
{
    fr_wheel_speed.data=msg->data;
}
void VilmaControler_ROS::receive_gears_state(const std_msgs::Int8::ConstPtr& msg)
{
    gears.data=msg->data;
}
//////////////////////////////////// FUNCTION FOR CONTROLLING THE CAR //////////////////////////////////////

void VilmaControler_ROS::change_gears(){
    std_msgs::Int8 gears_value;

    if (this->gears.data<0.3&&this->gears.data>-0.3)
    {
        gears_value.data=1;
        this->gears_pub.publish(gears_value);
    }
    else if (this->gears.data<-0.5)
    {
        gears_value.data=0;
        this->gears_pub.publish(gears_value);
    }
    else if (this->gears.data>0.5)
    {
        gears_value.data=-1;
        this->gears_pub.publish(gears_value);
    }
}
void VilmaControler_ROS::use_Steering(float value)
{
    std_msgs::Float64 steering_value;
    steering_value.data=value;
    hand_wheelpub.publish(steering_value);

}
void VilmaControler_ROS::accelerate(float amount_to_increase){
    std_msgs::Float64 accelerate;
    if(this->brake_pedal_state.data>0.01){
        accelerate.data=0;
        this->brake_pedalpub.publish(accelerate);
        return;
    }
    accelerate.data=this->gas_pedal_state.data+amount_to_increase;
    this->gas_pedalpub.publish(accelerate);
}
void VilmaControler_ROS::deaccelerate(float amount_to_decrease){
    std_msgs::Float64 deaccelerate;
    if(this->gas_pedal_state.data>0.005){
        deaccelerate.data=this->gas_pedal_state.data-amount_to_decrease;
        this->gas_pedalpub.publish(deaccelerate);
        return;
    }
    deaccelerate.data=this->brake_pedal_state.data+amount_to_decrease;
    this->brake_pedalpub.publish(deaccelerate);
}
void VilmaControler_ROS::use_hand_brake(){
    std_msgs::Float64 hand_brake;
    if(this->hand_brake_state.data>0.05)//turn to OFF
    {
        for(hand_brake.data=this->hand_brake_state.data-0.09; this->hand_brake_state.data>=0.05; hand_brake.data=this->hand_brake_state.data-0.1)
        {
            this->hand_brakepub.publish(hand_brake);
            ros::spinOnce();
        }
    }
    else
        if(this->hand_brake_state.data<=0.1)// TURN TO ON
        {
            for(hand_brake.data=this->hand_brake_state.data+0.1; this->hand_brake_state.data<=0.88; hand_brake.data=this->hand_brake_state.data+0.1)
            {
                this->hand_brakepub.publish(hand_brake);
                ros::spinOnce();
            }
        }
}
void VilmaControler_ROS::reset_state(){
        ros::spinOnce();
        std_msgs::Float64 reset_gas;
        std_msgs::Float64 reset_brake;
        std_msgs::Float64 reset_hand_brake;
        std_msgs::Float64 reset_steering;
        std_msgs::Int8 reset_gears;
        reset_gas.data=0;
        reset_steering.data=0;
        reset_brake.data=0;
        reset_gears.data=1;
        this->gas_pedalpub.publish(reset_gas);
        this->hand_wheelpub.publish(reset_steering);
        this->brake_pedalpub.publish(reset_brake);
        this->gears_pub.publish(reset_gears);
        if(this->hand_brake_state.data<=0.1)
        {
            for(reset_hand_brake.data=this->hand_brake_state.data+0.1; this->hand_brake_state.data<=0.88; reset_hand_brake.data=this->hand_brake_state.data+0.1)
            {
                this->hand_brakepub.publish(reset_hand_brake);
                ros::spinOnce();
            }
        }

}
void VilmaControler_ROS::maintain_speed(){
    if(this->thread_count>0){
        this->tgroup.interrupt_all();
        this->tgroup.join_all();
        this->thread_count=0;
        return;
    }
    this->tgroup.create_thread( boost::bind(&VilmaControler_ROS::callback1,this) );
    this->thread_count=thread_count+1;
}

//![0]




















