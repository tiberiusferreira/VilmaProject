#-------------------------------------------------
#
# Project created by QtCreator 2014-10-14T00:45:15
#
#-------------------------------------------------

QT       -= core gui

TARGET = ros_talker
TEMPLATE = lib

DEFINES += ROS_TALKER_LIBRARY

SOURCES += ros_talker.cpp

HEADERS += ros_talker.h\
        ros_talker_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


INCLUDEPATH+=/usr/include/gazebo-1.8 \
/opt/ros/groovy/include \
/usr/include/gazebo-1.9 \
/usr/include/gazebo-1.9/gazebo \
/usr/include/gazebo-2.2 \
/usr/include/gazebo-2.2/gazebo \
/usr/include/gazebo-1.8/gazebo \ #Including path in case of using gazebo 1.9
/usr/include/gazebo-2.1 \
/opt/ros/hydro/include \
/opt/ros/indigo/include \
/usr/include/gazebo-2.1/gazebo \
/usr/include/sdformat-1.4

LIBS += -L/opt/ros/indigo/lib/ -lactionlib -lbondcpp -lclass_loader -lroscpp \
-lconsole_bridge -lcpp_common -lcv_bridge -ldynamic_reconfigure_config_init_mutex \
-limage_transport_plugins -limage_transport -lmessage_filters -lnodeletlib -lqt_gui_cpp \
-lrosconsole -lrostime -lroscpp_serialization -lxmlrpcpp -lrosconsole_log4cxx -lrosconsole \
-lrosconsole_backend_interface

LIBS += -lboost_thread

LIBS += -lboost_system

LIBS += -lgazebo_math
