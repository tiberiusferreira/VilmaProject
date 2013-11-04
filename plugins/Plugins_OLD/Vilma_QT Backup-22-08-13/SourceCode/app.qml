/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
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
import Charts 1.0
import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
Item {
    id: vilma_interface
    width: 400; height: 500

    Vilma_controler {
        id: controler
        x: 0
        y: 0
        anchors.centerIn: parent
        width: 400; height: 500
        color: "red"
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0



        Text {
            id:gasvalue
            x: 17
            y: 45
            width: 133
            height: 35
            anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 420 }
            text: gasvalue.text="Gas joint Value: " ;
            anchors.horizontalCenterOffset: -116

        }
        Text {
            id:brakevalue
            x: 17
            y: 131
            width: 133
            height: 35
            anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 334 }
            text: "Brake Value: " ;
            anchors.horizontalCenterOffset: -116

        }
        Text {
            id:handbrakevalue
            x: 17
            y: 209
            width: 133
            height: 35
            anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 256 }
            text: text="Hand Brake Value: " ;
            anchors.horizontalCenterOffset: -116

        }
        Text {
            id:steeringvalue
            x: 17
            y: 297
            width: 133
            height: 35
            anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 168 }
            text: text="Wheel Position: " ;
            anchors.horizontalCenterOffset: -116
        }


        onGas_jointChanged: gasvalue.text="Gas joint Value: "+controler.gas_joint;
        onBrake_jointChanged:brakevalue.text= "Brake joint Value: "+controler.brake_joint;
        onHand_brake_jointChanged:handbrakevalue.text="Hand Brake joint Value: "+controler.hand_brake_joint;
        onSteering_jointChanged: steeringvalue.text="Steering joint Value: "+controler.steering_joint;
    }

    /*  MouseArea {
        x: 279
        y: 317
        width: 121
        height: 183
        anchors.leftMargin: 279
        anchors.topMargin: 317
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.fill: parent
        onClicked:
        {
        controler.update_vilma_info();
        gasvalue.text="Gas joint Value: "+controler.gas_joint;
        brakevalue.text="Brake joint Value: "+controler.brake_joint;
        handbrakevalue.text="Hand Brake joint Value: "+controler.hand_brake_joint;
        steeringvalue.text="Steering joint Value: "+controler.steering_joint;
        }
    }*/

    Button {
        id: gas_increase
        x: 130
        y: 17
        text: "+"
        width: 92
        tooltip:"This is an interesting tool tip"
        onClicked:
        {
            controler.accelerate();
        }
    }

    Button {
        id: gas_decrease
        x: 130
        y: 61
        width: 92
        text: "-"
        tooltip: "This is an interesting tool tip"
        onClicked:
        {
            controler.deaccelerate();
        }
    }

    Button {
        id: brake_increase
        x: 130
        y: 110
        width: 92
        text: "+"
        tooltip: "This is an interesting tool tip"
        onClicked:
        {
            controler.use_brake_push();
        }
    }


    Button {
        id: brake_decrease
        x: 130
        y: 153
        width: 92
        text: "-"
        tooltip: "This is an interesting tool tip"
        onClicked:
        {
            controler.use_brake_release();
        }
    }
    Button {
        id: hand_brake_use
        x: 235
        y: 209
        width: 92
        text: "ON-OFF"
        tooltip: "This is an interesting tool tip"
        onClicked: controler.use_hand_brake()
    }

    Slider {
        id: steering_slider
        x: 205
        y: 290
        width: 146
        height: 29
        z: 0
        rotation: 0
        scale: 1
        opacity: 1
       // height: 28
        minimumValue: 0
        maximumValue: 2

        onValueChanged: {
            if (value>1)
            {
           controler.use_Steering(-(value-1)*3.14)
           steering_joint_exported_value.text="Value being published to the steering: "+(-value+1)*3.14
            }
            else
            {
            steering_joint_exported_value.text="Value being published to the steering: "+(-value+1)*(3.14)
            controler.use_Steering(-(value-1)*(3.14))
        }}
    }

    Text {
        id: steering_joint_exported_value
        x: 18
        y: 356
        text: ("Value being published to the steering: ")
        font.pixelSize: 12
    }

}
//![0]
