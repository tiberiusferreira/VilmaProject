#include "plotui.h"
#include "ui_plotui.h"

PlotUI::PlotUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlotUI)
{
    ui->setupUi(this);
    //timer2 = new QTimer();
    //connect(timer2, SIGNAL(timeout()), this, SLOT(initiate()));
    //ui->QPlotUI->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    //ui->QPlotUI->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->QPlotUI->xAxis->setAutoTickStep(false);
    ui->QPlotUI->xAxis->setTickStep(2);
    ui->QPlotUI->axisRect()->setupFullAxesBox();


}

void PlotUI::initiate(){

    // generate some data:

//    QVector<double> x(101), y(101); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]*x[i];  // let's plot a quadratic function
//    }
//    // create graph and assign data to it:
//    ui->QPlotUI->addGraph();
//    ui->QPlotUI->graph(0)->setData(x, y);
//    // give the axes some labels:
//    ui->QPlotUI->xAxis->setLabel("x");
//    ui->QPlotUI->replot();

//    ui->QPlotUI->yAxis->setLabel("y");
//    // set axes ranges, so we see all data:
//    ui->QPlotUI->xAxis->setRange(-1, 1);
//    ui->QPlotUI->yAxis->setRange(0, 1);
//    ui->QPlotUI->xAxis->setLabel("xAAA");
//    this->show();


}

PlotUI::~PlotUI()
{
    delete ui;
}
