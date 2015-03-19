#-------------------------------------------------
#
# Project created by QtCreator 2014-08-23T01:03:33
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

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
-lrosconsole_backend_interface -lcontrol_toolbox

LIBS += -lboost_thread

LIBS += -lboost_system

LIBS += -lgazebo_math

TARGET = vilma_driver_widget_qtBuilt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vilma_self_driver.cpp \
    points.cpp \
    gps.cpp \
    imu.cpp \
    morse_receiver.cpp \
    morse_transmiter.cpp \
    qcustomplot.cpp \
    plotui.cpp

HEADERS  += mainwindow.h \
    vilma_self_driver.h \
    points.h \
    gps.h \
    imu.h \
    morse_receiver.h \
    morse_transmiter.h \
    qcustomplot.h \
    plotui.h

FORMS    += mainwindow.ui \
    plotui.ui
