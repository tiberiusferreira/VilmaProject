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
private:
    Ui::PlotUI *ui;
};

#endif // PLOTUI_H
