
#include "piechart.h"
#include <QtQuick/QQuickView>
#include <QGuiApplication>


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "Vilma_drive_cmd_publisher"); //Inializing ROS basic, needed for basically anything

    QGuiApplication app(argc, argv);

    qmlRegisterType<VilmaControler_QtSide>("Charts", 1, 0, "VilmaControler_QtSide");
    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl::fromLocalFile("app.qml"));
    view.show();
    return app.exec();
}
