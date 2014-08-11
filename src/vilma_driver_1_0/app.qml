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
import QtQuick 1.1
import VilmaControlerQtSide 1.0
//Item {
//    id: vilma_interface
//    width: 600; height: 500
//    visible: true
//    scale: 1
//    Component.onCompleted:
//    {
//        controler.reset_state();
//        steering_slider.value=1;
//        console.log("Model should have been reseted to regular state, if not probably a bug.");
//    }
//    Component.onDestruction:
//    {
//        if(controler.hand_brake_joint<0.5)
//        {
//            controler.use_hand_brake();
//        }
//    }

    VilmaControlerQtSide {
        id: controler
        focus: true
        x: 0
        y: 0
        anchors.leftMargin: 0
        width: 600; height: 500
        bl_wheel_speed: ""
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        Component.onCompleted:
    {
        controler.reset_state();
        steering_slider.value=1;
        console.log("Model should have been reseted to regular state, if not probably a bug.");
    }
    Component.onDestruction:
    {
        if(controler.hand_brake_joint<0.5)
        {
            controler.use_hand_brake();
        }
    }


        Text {
            id:gasvalue
            x: 0
            y: 189
            width: 165
            height: 35
            anchors {
            bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 276 }
            text: "Gas joint Value: 0.00" ;
            style: Text.Normal
            font.strikeout: false
            font.underline: true
            font.italic: false
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenterOffset: -201

        }
        Text {
            id:brakevalue
            x: 0
            y: 155
            width: 133
            height: 35
            anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 310 }
            text: "Brake Value: 0.00" ;
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: -207

        }
        Text {
            id:steeringvalue
            x: 0
            y: 13
            width: 195
            height: 35
            anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; bottomMargin: 452 }
            text: "Steering joint Value: 0.00" ;
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            anchors.horizontalCenterOffset: 53
        }


        Text {
            id: br_wheel_speed
            x: 6
            y: 376
            text: qsTr("Back Right Wheel Speed:")
            font.pixelSize: 12
        }

        Text {
            id: bl_wheel_speed
            x: 8
            y: 407
            text: qsTr("Front Right Wheel Speed:")
            font.pixelSize: 12
        }

        Text {
            id: fr_wheel_speed
            x: 6
            y: 439
            text: ("Back Left Wheel Speed:")
            font.pixelSize: 12
        }

        Text {
            id: fl_wheel_speed
            x: 6
            y: 470
            text: ("Front Left Wheel Speed:")
            font.pixelSize: 12
        }
        Text {
            id: xposition
            x: 200
            y: 376
            text: ("X world position:")
            font.pixelSize: 12
        }
        Text {
            id: yposition
            x: 200
            y: 407
            text: ("Y world position:")
            font.pixelSize: 12
        }
        Text {
            id: zposition
            x: 200
            y: 439
            text: ("Z world position:")
            font.pixelSize: 12
        }
        Text {
            id: twistxposition
            x: 200
            y: 470
            text: ("X twist world position:")
            font.pixelSize: 12
        }        Text {
            id: twistyposition
            x: 330
            y: 376
            text: ("Y twist world position:")
            font.pixelSize: 12
        }
        Text {
            id: twistzposition
            x: 330
            y: 407
            text: ("Z twist world position:")
            font.pixelSize: 12
        }
        Text {
            id: xorientation
            x: 330
            y: 439
            text: ("X orientation:")
            font.pixelSize: 12
        }
        Text {
            id: yorientation
            x: 355
            y: 470
            text: ("Y orientation:")
            font.pixelSize: 12
        }
        Text {
            id: zorientation
            x: 488
            y: 376
            text: ("Y orientation:")
            font.pixelSize: 12
        }
        Text {
            id: worientation
            x: 488
            y: 407
            text: ("W orientation:")
            font.pixelSize: 12
        }

        Rectangle{
            property color onHoverColor: "gold"
            property color borderColor: "lightblue"
            color: "grey"
            border.color: borderColor
            visible: true
            width: 100; height: 35
            x: 283
            y: 97

            MouseArea {
                id: gearsbutton
                anchors.fill: parent

                Text{
                    id:gearsbuttontext
                    anchors.centerIn: parent
                    text: "Direction"
                    font.bold: true

                }
                onClicked:controler.change_gears();
                //onEntered: parent.border.color = parent.onHoverColor
                //onExited:  parent.border.color = parent.borderColor
                hoverEnabled: true


            }

        }




        onGas_jointChanged: gasvalue.text="Gas joint Value: "+controler.gas_joint;
        onBrake_jointChanged:brakevalue.text= "Brake joint Value: "+controler.brake_joint;
        onHand_brake_jointChanged:
        {
            if (controler.hand_brake_joint>0.1)
            {
                hand_brake_usebuttontext.text="Hand Brake ON "+controler.hand_brake_joint;

            }
            else
            {
                hand_brake_usebuttontext.text="Hand Brake OFF "+controler.hand_brake_joint;
            }

        }
        onX_positionChanged: xposition.text="X world position:"+controler.xposition;
        onY_positionChanged: yposition.text="Y world position:"+controler.yposition;
        onZ_positionChanged: zposition.text="Z world position:"+controler.zposition;
        onXtwistChanged: twistxposition.text="X twist world position:"+controler.xtwist;
        onYtwistChanged: twistyposition.text="Y twist world position:"+controler.ytwist;
        onZtwistChanged: twistzposition.text="Z twist world position:"+controler.ztwist;
        onXorientationChanged: xorientation.text="X orientation:"+controler.xorientation;
        onYorientationChanged: yorientation.text="Y orientation:"+controler.yorientation;
        onZorientationChanged: zorientation.text="Z orientation:"+controler.zorientation;
        onWorientationChanged: worientation.text="W orientation:"+controler.worientation;

        onSteering_jointChanged: steeringvalue.text="Steering joint Value: "+controler.steering_joint;
        onBr_wheel_speedChanged: br_wheel_speed.text="Back Right Wheel Speed: "+controler.br_wheel_speed+"rad/s";
        onBl_wheel_speedChanged: bl_wheel_speed.text="Back Left Wheel Speed: "+controler.bl_wheel_speed+"rad/s";
        onFr_wheel_speedChanged: fr_wheel_speed.text="Front Right Wheel Speed: "+controler.fr_wheel_speed+"rad/s";
        onFl_wheel_speedChanged: fl_wheel_speed.text="Front Left Wheel Speed: "+controler.fl_wheel_speed+"rad/s";
        onGearsChanged:
        {
            if (controler.gears>0.5)
            {
                gearsbuttontext.text = "Forward"
            }
            else if(controler.gears<0.3&&controler.gears>-0.3)
            {

                gearsbuttontext.text = "Neutral"

            }else
            {gearsbuttontext.text = "Backwards"}



        }


        Rectangle{
            property color onHoverColor: "gold"
            property color borderColor: "lightblue"
            color: "grey"
            border.color: borderColor
            visible: true
            width: 118; height: 35
            x: 17
            y: 16
            MouseArea {
                id: gas_increase
                enabled: true
                anchors.fill: parent
                onClicked:
                {
                    controler.accelerate();
                }
                //onEntered: parent.border.color = parent.onHoverColor
                //onExited:  parent.border.color = parent.borderColor
                hoverEnabled: true

                Text{
                    text: "increase Gas"
                    font.bold: true
                    anchors.centerIn: parent
                }
            }
        }
        Rectangle{
            property color onHoverColor: "gold"
            property color borderColor: "lightblue"
            color: "grey"
            border.color: borderColor
            visible: true
            width: 115; height: 35
            x: 19
            y: 54
            MouseArea {
                id: gas_decrease
                anchors.fill: parent

                onClicked:
                {
                    controler.deaccelerate();
                }
                //onEntered: parent.border.color = parent.onHoverColor
                //onExited:  parent.border.color = parent.borderColor
                hoverEnabled: true

                Text{
                    text: "Decrease Gas"
                    font.bold: true
                    anchors.centerIn: parent
                }
            }}
        Rectangle{
            property color onHoverColor: "gold"
            property color borderColor: "lightblue"
            color: "grey"
            anchors.left: parent.left
            anchors.leftMargin: 137
            anchors.top: parent.top
            anchors.topMargin: 17
            border.color: borderColor
            visible: true
            width: 115; height: 35
            MouseArea {
                id: brake_increase

                anchors.fill: parent
                Text{
                    text: "Increase Brake"
                    font.bold: true
                    anchors.centerIn: parent
                }
                onClicked:
                {
                    controler.use_brake_push();
                }
                hoverEnabled: true
                //onEntered: parent.border.color = parent.onHoverColor
                //onExited:  parent.border.color = parent.borderColor

            }}

        Rectangle{
            property color onHoverColor: "gold"
            property color borderColor: "lightblue"
            color: "grey"
            border.color: borderColor
            visible: true
            width: 126; height: 35
            x: 136
            y: 55
            MouseArea {
                id: brake_decrease
                anchors.rightMargin: -1
                anchors.bottomMargin: 0
                anchors.leftMargin: 1
                anchors.topMargin: 0

                anchors.fill: parent
                Text{
                    text: "Decrease Brake"
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    anchors.centerIn: parent

                }
                onClicked:
                {
                    controler.use_brake_release();
                }
                hoverEnabled: true
                //onEntered: parent.border.color = parent.onHoverColor
                //onExited:  parent.border.color = parent.borderColor
            }}
        Rectangle{
            property color onHoverColor: "gold"
            property color borderColor: "lightblue"
            color: "grey"
            border.color: borderColor
            visible: true
            width: 146; height: 35
            x: 22
            y: 94

            MouseArea {
                id: hand_brake_usebutton
                anchors.fill: parent
                Text{ id:hand_brake_usebuttontext
                    text: "Hand Brake ON 000"
                    font.bold: true
                    anchors.centerIn: parent
                }
                onClicked:{
                    controler.use_hand_brake();
                }
                hoverEnabled: true
                //onEntered: parent.border.color = parent.onHoverColor
                //onExited:  parent.border.color = parent.borderColor
            }

        }
        Rectangle{
            property color onHoverColor: "gold"
            property color borderColor: "lightblue"
            color: "grey"
            border.color: borderColor
            visible: true
            width: 139; height: 35
            x: 447
            y: 16
            MouseArea {
                id: reset_state
                anchors.fill: parent
                Text{
                    text: "RESET CAR STATE"
                    font.bold: true
                    anchors.centerIn: parent
                }

                onClicked:{
                    controler.reset_state();
                    steering_slider.value=1;

                }
                //onEntered: parent.border.color = parent.onHoverColor
                //onExited:  parent.border.color = parent.borderColor
                hoverEnabled: true

            }}
        Rectangle{
            property color onHoverColor: "gold"
            property color borderColor: "lightblue"
            color: "grey"
            border.color: borderColor
            visible: true
            width: 166; height: 35
            x: 424
            y: 87
            MouseArea {
                id: maintain_speed
                anchors.fill: parent
                Text{
                    text: "MAINTAIN CAR SPEED"
                    font.bold: true
                    anchors.centerIn: parent
                }

                onClicked:{
                    controler.maintain_speed();

                }
                //onEntered: parent.border.color = parent.onHoverColor
                //onExited:  parent.border.color = parent.borderColor
                hoverEnabled: true

            }}

        Keys.onPressed: {
            if (event.key === Qt.Key_W)
            {
                if(controler.brake_joint>0.005)
                {
                    controler.use_brake_release();
                }
                else
                {
                    controler.accelerate();
                }
            }
            if (event.key === Qt.Key_S)
                if(controler.gas_joint>0.005)
                {
                    controler.deaccelerate();
                }
                else
                {
                    controler.use_brake_push();
                }
            if (event.key === Qt.Key_A)
            {
                if(steering_slider.value>0)
                    steering_slider.value=steering_slider.value-0.1;
            }
            if (event.key === Qt.Key_D)
            {
                if(steering_slider.value<2)
                    steering_slider.value=steering_slider.value+0.1;
            }
            if (event.key === Qt.Key_H)
            {
                controler.use_hand_brake();
            }
            if (event.key === Qt.Key_R)
            {
                controler.reset_state();
                steering_slider.value=1;
            }
            if (event.key === Qt.Key_G)
            {
                controler.change_gears();
            }
        }

        Item  { //Code from http://qt-project.org/doc/qt-4.7/demos-declarative-flickr-common-slider-qml.html
            id: steering_slider; width: 146
            height: 29

            x: 282
            y: 50

            // value is read/write.
            property real value: 1
            property real maximum: 2
            property real minimum: 0
            onValueChanged:
            {
                updatePos();
                if (value>1)
                {
                    controler.use_Steering(-(value-1)*3.14)
                    steering_joint_exported_value.text="Value being published to the steering: "+(-(value-1)*3.14)
                }
                else
                {
                    steering_joint_exported_value.text="Value being published to the steering: "+(-(value-1)*(3.14))
                    controler.use_Steering(-(value-1)*(3.14))
                }
            }

            property int xMax: width - handle.width - 4
            onXMaxChanged: updatePos();
            onMinimumChanged: updatePos();

            function updatePos()  {
                if (maximum > minimum)  {
                    var pos = 2 + (value - minimum) * steering_slider.xMax / (maximum - minimum);
                    pos = Math.min(pos, width - handle.width - 2);
                    pos = Math.max(pos, 2);
                    handle.x = pos;
                } else  {
                    handle.x = 2;
                }
            }

            Rectangle  {
                anchors.fill: parent
                border.color: "white"; border.width: 0; radius: 8
                gradient: Gradient  {
                    GradientStop  { position: 0.0; color: "#66333333" }
                    GradientStop  { position: 1.0; color: "#66000000" }
                }
            }

            Rectangle  {
                id: handle; smooth: true
                y: 2; width: 30; height: steering_slider.height-4; radius: 6
                gradient: Gradient  {
                    GradientStop  { position: 0.0; color: "lightgray" }
                    GradientStop  { position: 1.0; color: "gray" }
                }

                MouseArea  {
                    id: mouse
                    anchors.fill: parent; drag.target: parent
                    drag.axis: Drag.XAxis; drag.minimumX: 2; drag.maximumX: steering_slider.xMax+2
                    onPositionChanged:  { steering_slider.value = (steering_slider.maximum - steering_slider.minimum) * (handle.x-2) / steering_slider.xMax + steering_slider.minimum; }
                }
            }

        }





        Text {

            id: steering_joint_exported_value
            x: 16
            y: 235
            text: ("Value being published to the steering: ")
            font.pixelSize: 12
        }


    }
//}
//![0]
