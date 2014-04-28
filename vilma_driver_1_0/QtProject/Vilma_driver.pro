QT += gui declarative
CONFIG += release

INCLUDEPATH+=/usr/include/gazebo-1.8 \
/opt/ros/groovy/include \
/usr/include/gazebo-1.9/ \
/usr/include/gazebo-1.9/gazebo \
/usr/include/gazebo-1.8/gazebo \ #Including path in case of using gazebo 1.9
/usr/include/gazebo-2.1 \
/opt/ros/hydro/include \
/usr/include/gazebo-2.1/gazebo \
/usr/include/sdformat-1.4







#For ros GROOVY compatibility:

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/release/ -lactionlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/debug/ -lactionlib
else:unix: LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/ -lactionlib

INCLUDEPATH += $$PWD/../../../../../../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/release/ -lbondcpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/debug/ -lbondcpp
else:unix: LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/ -lbondcpp

INCLUDEPATH += $$PWD/../../../../../../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/release/ -lclass_loader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/debug/ -lclass_loader
else:unix: LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/ -lclass_loader

INCLUDEPATH += $$PWD/../../../../../../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/release/ -lroscpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/debug/ -lroscpp
else:unix: LIBS += -L$$PWD/../../../../../../../../../../opt/ros/groovy/lib/ -lroscpp

INCLUDEPATH += $$PWD/../../../../../../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../../../../../../opt/ros/groovy/include


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lconsole_bridge
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lconsole_bridge
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lconsole_bridge

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lcpp_common
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lcpp_common
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lcpp_common

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lcv_bridge
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lcv_bridge
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lcv_bridge

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -ldynamic_reconfigure_config_init_mutex
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -ldynamic_reconfigure_config_init_mutex
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -ldynamic_reconfigure_config_init_mutex

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -limage_transport_plugins
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -limage_transport_plugins
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -limage_transport_plugins

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -limage_transport
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -limage_transport
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -limage_transport

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lmessage_filters
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lmessage_filters
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lmessage_filters

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lnodeletlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lnodeletlib
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lnodeletlib

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lqt_gui_cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lqt_gui_cpp
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lqt_gui_cpp

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lrosconsole
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lrosconsole
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lrosconsole

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lrostime
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lrostime
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lrostime

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lroscpp_serialization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lroscpp_serialization
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lroscpp_serialization

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/release/ -lxmlrpcpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/debug/ -lxmlrpcpp
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/groovy/lib/ -lxmlrpcpp

INCLUDEPATH += $$PWD/../../../../../opt/ros/groovy/include
DEPENDPATH += $$PWD/../../../../../opt/ros/groovy/include

#FOR ROS Hydro compatibility:

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/release/ -lactionlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/debug/ -lactionlib
else:unix: LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/ -lactionlib

INCLUDEPATH += $$PWD/../../../../../../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/release/ -lbondcpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/debug/ -lbondcpp
else:unix: LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/ -lbondcpp

INCLUDEPATH += $$PWD/../../../../../../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/release/ -lclass_loader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/debug/ -lclass_loader
else:unix: LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/ -lclass_loader

INCLUDEPATH += $$PWD/../../../../../../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/release/ -lroscpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/debug/ -lroscpp
else:unix: LIBS += -L$$PWD/../../../../../../../../../../opt/ros/hydro/lib/ -lroscpp

INCLUDEPATH += $$PWD/../../../../../../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../../../../../../opt/ros/hydro/include


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lconsole_bridge
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lconsole_bridge
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lconsole_bridge

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lcpp_common
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lcpp_common
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lcpp_common

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lcv_bridge
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lcv_bridge
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lcv_bridge

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -ldynamic_reconfigure_config_init_mutex
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -ldynamic_reconfigure_config_init_mutex
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -ldynamic_reconfigure_config_init_mutex

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -limage_transport_plugins
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -limage_transport_plugins
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -limage_transport_plugins

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -limage_transport
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -limage_transport
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -limage_transport

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lmessage_filters
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lmessage_filters
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lmessage_filters

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lnodeletlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lnodeletlib
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lnodeletlib

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lqt_gui_cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lqt_gui_cpp
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lqt_gui_cpp

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lrosconsole
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lrosconsole
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lrosconsole

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lrostime
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lrostime
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lrostime

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lroscpp_serialization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lroscpp_serialization
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lroscpp_serialization

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/release/ -lxmlrpcpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/debug/ -lxmlrpcpp
else:unix: LIBS += -L$$PWD/../../../../../opt/ros/hydro/lib/ -lxmlrpcpp

INCLUDEPATH += $$PWD/../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../opt/ros/hydro/include

unix:!macx: LIBS += -L$$PWD/../../../../../../opt/ros/hydro/lib/ -lrosconsole_log4cxx

INCLUDEPATH += $$PWD/../../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../../opt/ros/hydro/include

unix:!macx: LIBS += -L$$PWD/../../../../../../opt/ros/hydro/lib/ -lrosconsole

INCLUDEPATH += $$PWD/../../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../../opt/ros/hydro/include

unix:!macx: LIBS += -L$$PWD/../../../../../../opt/ros/hydro/lib/ -lrosconsole_backend_interface

INCLUDEPATH += $$PWD/../../../../../../opt/ros/hydro/include
DEPENDPATH += $$PWD/../../../../../../opt/ros/hydro/include

RESOURCES += \
    ../controlerresources.qrc

OTHER_FILES += \
    ../app.qml

SOURCES += \
    ../src/main.cpp \
    ../src/VilmaControler_QtSide.cpp \
    ../src/VilmaControler_RosSide.cpp

HEADERS += \
    ../src/VilmaControler_QtSide.h \
    ../src/VilmaControler_RosSide.h

unix:!macx: LIBS += -lboost_thread
