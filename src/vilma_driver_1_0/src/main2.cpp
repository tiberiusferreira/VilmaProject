
#include "VilmaControler_QtSide.h"
#include <QtDeclarative/QDeclarativeView>
#include <QtGui/QApplication>


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Vilma_drive_cmd_publisher"); //Inializing ROS basic, needed for basically anything
    qmlRegisterType<VilmaControler_QtSide>("VilmaControlerQtSide", 1, 0, "VilmaControlerQtSide");

    QApplication app(argc, argv);


    QDeclarativeView view;
    view.setMaximumHeight(801);
    view.setMinimumHeight(800);
    view.setMaximumWidth(601);
    view.setMinimumWidth(600);
    view.setResizeMode(QDeclarativeView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///app.qml"));
    view.show();


    return app.exec();
}
