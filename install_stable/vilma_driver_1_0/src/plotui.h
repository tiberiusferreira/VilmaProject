#ifndef PLOTUI_H
#define PLOTUI_H
#include <QWidget>
#include <unistd.h>
#include <QTimer>
#include "qcustomplot.h"
namespace Ui {
class PlotUI;
}

class PlotUI : public QWidget
{
    Q_OBJECT


public:
    QTimer *timer2;
    explicit PlotUI(QWidget *parent = 0);
    ~PlotUI();
public slots:
    void initiate();
public:
    Ui::PlotUI *ui;
    double maxx=-1000000000;
    double maxy=-1000000000;
    double minx= 1000000000;
    double miny= 1000000000;

};


#endif // PLOTUI_H
