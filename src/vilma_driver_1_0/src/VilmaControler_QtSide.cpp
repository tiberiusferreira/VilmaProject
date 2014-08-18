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
#include "VilmaControler_QtSide.h"



VilmaControler_QtSide::VilmaControler_QtSide() //Constructor
{
    VilmaControler_ROS_Object.init();
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update_vilma_info()));
    timer->start(600);
}

QString VilmaControler_QtSide::gas_joint() const
{
    return QString::number(VilmaControler_ROS_Object.gas_pedal_state.data,'f',2);
}

QString VilmaControler_QtSide::brake_joint() const
{
    return QString::number(VilmaControler_ROS_Object.brake_pedal_state.data,'f',2);
}

QString VilmaControler_QtSide::hand_brake_joint() const
{
    return QString::number(VilmaControler_ROS_Object.hand_brake_state.data,'f',2);
}

QString VilmaControler_QtSide::steering_joint() const
{
    return QString::number(VilmaControler_ROS_Object.hand_wheel_state.data,'f',2);
}

QString VilmaControler_QtSide::bl_wheel_speed() const
{
    return QString::number(VilmaControler_ROS_Object.bl_wheel_speed.data,'f',2);
}

QString VilmaControler_QtSide::br_wheel_speed() const
{
    return QString::number(VilmaControler_ROS_Object.br_wheel_speed.data,'f',2);
}

QString VilmaControler_QtSide::fl_wheel_speed() const
{
    return QString::number(VilmaControler_ROS_Object.fl_wheel_speed.data,'f',2);
}

QString VilmaControler_QtSide::fr_wheel_speed() const
{
    return QString::number(VilmaControler_ROS_Object.fr_wheel_speed.data,'f',2);
}

QString VilmaControler_QtSide::gears() const
{
    return QString::number(VilmaControler_ROS_Object.gears.data,'f',2);
}

void VilmaControler_QtSide::change_gears()
{
    VilmaControler_ROS_Object.change_gears();
}

QString VilmaControler_QtSide::xposition() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.pose.position.x,'f',3);
}

QString VilmaControler_QtSide::yposition() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.pose.position.y,'f',3);
}

QString VilmaControler_QtSide::zposition() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.pose.position.z,'f',3);
}

QString VilmaControler_QtSide::readXlinear_vel() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.twist.linear.x,'f',3);
}

QString VilmaControler_QtSide::readYlinear_vel() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.twist.linear.y,'f',3);
}

QString VilmaControler_QtSide::readZlinear_vel() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.twist.linear.z,'f',3);
}
QString VilmaControler_QtSide::readXangular_vel() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.twist.angular.x,'f',3);
}

QString VilmaControler_QtSide::readYangular_vel() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.twist.angular.y,'f',3);
}

QString VilmaControler_QtSide::readZangular_vel() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.twist.angular.z,'f',3);
}

QString VilmaControler_QtSide::readXorientation() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.pose.orientation.x,'f',3);
}


QString VilmaControler_QtSide::readYorientation() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.pose.orientation.y,'f',3);
}

QString VilmaControler_QtSide::readZorientation() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.pose.orientation.z,'f',3);
}

QString VilmaControler_QtSide::readWorientation() const
{
    return QString::number(VilmaControler_ROS_Object.modelstate.pose.orientation.w,'f',3);
}

QString VilmaControler_QtSide::readLatitude() const
{
    return QString::number(VilmaControler_ROS_Object.car_gps_state.latitude,'f',9);
}

QString VilmaControler_QtSide::readLongitude() const
{
    return QString::number(VilmaControler_ROS_Object.car_gps_state.longitude,'f',9);
}

void VilmaControler_QtSide::maintain_speed()
{
    this->VilmaControler_ROS_Object.maintain_speed();
}

void VilmaControler_QtSide::update_vilma_info()
{
    ros::spinOnce();
    emit gas_jointChanged();
    emit brake_jointChanged();
    emit hand_brake_jointChanged();
    emit steering_jointChanged();
    emit bl_wheel_speedChanged();
    emit br_wheel_speedChanged();
    emit fl_wheel_speedChanged();
    emit fr_wheel_speedChanged();
    emit x_positionChanged();
    emit y_positionChanged();
    emit z_positionChanged();
    emit xlinear_velChanged();
    emit ylinear_velChanged();
    emit zlinear_velChanged();
    emit xangular_velChanged();
    emit yangular_velChanged();
    emit zangular_velChanged();
    emit xorientationChanged();
    emit yorientationChanged();
    emit zorientationChanged();
    emit worientationChanged();
    emit gearsChanged();
    emit latitudeChanged();
    emit longitudeChanged();
    VilmaControler_ROS_Object.receive_model_physical_state();
}

void VilmaControler_QtSide::accelerate()
{

    std_msgs::Float64 accelerate;
    accelerate.data=VilmaControler_ROS_Object.gas_pedal_state.data+0.01;
    VilmaControler_ROS_Object.gas_pedalpub.publish(accelerate);
}
void VilmaControler_QtSide::deaccelerate()
{

    std_msgs::Float64 deaccelerate;
    deaccelerate.data=VilmaControler_ROS_Object.gas_pedal_state.data-0.01;
    VilmaControler_ROS_Object.gas_pedalpub.publish(deaccelerate);
}
void VilmaControler_QtSide::use_brake_push()
{    
    std_msgs::Float64 use_brake;
    use_brake.data=VilmaControler_ROS_Object.brake_pedal_state.data+0.01;
    VilmaControler_ROS_Object.brake_pedalpub.publish(use_brake);
}
void VilmaControler_QtSide::use_brake_release()
{

    std_msgs::Float64 use_brake;
    use_brake.data=VilmaControler_ROS_Object.brake_pedal_state.data-0.01;
    VilmaControler_ROS_Object.brake_pedalpub.publish(use_brake);
}
void VilmaControler_QtSide::use_hand_brake()
{
    VilmaControler_ROS_Object.use_hand_brake();
}
void VilmaControler_QtSide::use_Steering(float value)
{
    std_msgs::Float64 steering_value;
    steering_value.data=value;
    VilmaControler_ROS_Object.hand_wheelpub.publish(steering_value);

}

void VilmaControler_QtSide::reset_state()
{
    VilmaControler_ROS_Object.reset_state();
}


//![0]
