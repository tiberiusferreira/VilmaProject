#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT( update()));
    timer->start(250);
    ui->Set_wheel_direction_x_input->setValidator(new QDoubleValidator(this));
    ui->Set_wheel_direction_y_input->setValidator(new QDoubleValidator(this));
    ui->Enter_new_constant_speed->setValidator(new QDoubleValidator(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update()
{
    ros::spinOnce(); //update ros side values
    ui->steering_slider->setSliderPosition((float) -morse_transmiter_obj.getSteering()*523.23); //steering slider pose update
    QString acel_text = QString("Current Power: %1").arg(QString::number(morse_transmiter_obj.getPowerAmount(),'f',3));
    QString max_speed_text = QString("Max Speed %1 m/s").arg(QString::number(morse_transmiter_obj.getVelocity(),'f',3));
    QString morse_x_text = QString("X : %1").arg(QString::number(morse_receiver_obj.getPosX(),'f',3));
    QString morse_y_text = QString("Y : %1").arg(QString::number(morse_receiver_obj.getPosY(),'f',3));
    QString morse_z_text = QString("Z : %1").arg(QString::number(morse_receiver_obj.getPosZ(),'f',3));
    QString latitude_text = QString("Z : %2").arg(QString::number(gps_obj.getLatitude(),'f',9));
    QString longitude_text = QString("Z : %2").arg(QString::number(gps_obj.getLongitude(),'f',9));
    QString quaternion_morse_x_text = QString("X : %1").arg(QString::number(morse_receiver_obj.getOrientationX(),'f',3));
    QString quaternion_morse_y_text = QString("Y : %1").arg(QString::number(morse_receiver_obj.getOrientationY(),'f',3));
    QString quaternion_morse_z_text = QString("Z : %1").arg(QString::number(morse_receiver_obj.getOrientationZ(),'f',3));
    QString quaternion_morse_w_text = QString("W : %1").arg(QString::number(morse_receiver_obj.getOrientationW(),'f',3));
    QString quaternion_imu_x_text = QString("X : %1").arg(QString::number(imu_obj.getOrientationX(),'f',3));
    QString quaternion_imu_y_text = QString("Y : %1").arg(QString::number(imu_obj.getOrientationY(),'f',3));
    QString quaternion_imu_z_text = QString("Z : %1").arg(QString::number(imu_obj.getOrientationZ(),'f',3));
    QString quaternion_imu_w_text = QString("Z : %1").arg(QString::number(imu_obj.getOrientationW(),'f',3));
    QString imu_ang_speed_x_text = QString("X : %1").arg(QString::number(imu_obj.getAngularVelX(),'f',3));
    QString imu_ang_speed_y_text = QString("Y : %1").arg(QString::number(imu_obj.getAngularVelY(),'f',3));
    QString imu_ang_speed_z_text = QString("Z : %1").arg(QString::number(imu_obj.getAngularVelZ(),'f',3));
    QString imu_lin_acel_x_text = QString("X : %1").arg(QString::number(imu_obj.getLinearAcelX(),'f',3));
    QString imu_lin_acel_y_text = QString("Y : %1").arg(QString::number(imu_obj.getLinearAcelY(),'f',3));
    QString imu_lin_acel_z_text = QString("Z : %1").arg(QString::number(imu_obj.getLinearAcelZ(),'f',3));
    QString morse_lin_vel_x_text = QString("X : %1").arg(QString::number(morse_receiver_obj.getLinearVelX(),'f',3));
    QString morse_lin_vel_y_text = QString("Y : %1").arg(QString::number(morse_receiver_obj.getLinearVelY(),'f',3));
    QString morse_lin_vel_z_text = QString("Z : %1").arg(QString::number(morse_receiver_obj.getLinearVelZ(),'f',3));
    QString morse_lin_vel_avg_text = QString("AVG : %1").arg(QString::number(morse_receiver_obj.getLinearVelAVG(),'f',3));
    QString morse_ang_vel_x_text = QString("X : %1").arg(QString::number(morse_receiver_obj.getAngularVelX(),'f',3));
    QString morse_ang_vel_y_text = QString("Y : %1").arg(QString::number(morse_receiver_obj.getAngularVelY(),'f',3));
    QString morse_ang_vel_z_text = QString("Z : %1").arg(QString::number(morse_receiver_obj.getAngularVelZ(),'f',3));
    QString imu_euler_rot_z = QString("Z : %1").arg(QString::number(imu_obj.getOrientationZAsEuler(),'f',3));
    ui->current_acel_text->setText(acel_text);
    ui->current_max_speed_text->setText(max_speed_text);
    ui->morse_x_text->setText(morse_x_text);
    ui->morse_y_text->setText(morse_y_text);
    ui->morse_z_text->setText(morse_z_text);
    ui->latitude_text->setText(latitude_text);
    ui->longitude_text->setText(longitude_text);
    ui->morse_quaternion_x_text->setText(quaternion_morse_x_text);
    ui->morse_quaternion_y_text->setText(quaternion_morse_y_text);
    ui->morse_quaternion_z_text->setText(quaternion_morse_z_text);
    ui->morse_quaternion_w_text->setText(quaternion_morse_w_text);
    ui->imu_quaternion_w_text->setText(quaternion_imu_w_text);
    ui->imu_quaternion_x_text->setText(quaternion_imu_x_text);
    ui->imu_quaternion_y_text->setText(quaternion_imu_y_text);
    ui->imu_quaternion_z_text->setText(quaternion_imu_z_text);
    ui->imu_ang_speed_x_text->setText(imu_ang_speed_x_text);
    ui->imu_ang_speed_y_text->setText(imu_ang_speed_y_text);
    ui->imu_ang_speed_z_text->setText(imu_ang_speed_z_text);
    ui->imu_lin_acel_x_text->setText(imu_lin_acel_x_text);
    ui->imu_lin_acel_y_text->setText(imu_lin_acel_y_text);
    ui->imu_lin_acel_z_text->setText(imu_lin_acel_z_text);
    ui->morse_lin_vel_x_text->setText(morse_lin_vel_x_text);
    ui->morse_lin_vel_y_text->setText(morse_lin_vel_y_text);
    ui->morse_lin_vel_z_text->setText(morse_lin_vel_z_text);
    ui->morse_lin_vel_avg_text->setText(morse_lin_vel_avg_text);
    ui->morse_ang_vel_x_text->setText(morse_ang_vel_x_text);
    ui->morse_ang_vel_y_text->setText(morse_ang_vel_y_text);
    ui->morse_ang_vel_z_text->setText(morse_ang_vel_z_text);
    ui->imu_euler_z_rotation_text->setText(imu_euler_rot_z);

    if(plot==1){
    this->PlotUI_obj.ui->QPlotUI->graph(0)->addData(this->morse_receiver_obj.getPosX(),this->morse_receiver_obj.getPosY());
    if(this->morse_receiver_obj.getPosX()>this->PlotUI_obj.maxx){
        this->PlotUI_obj.maxx=this->morse_receiver_obj.getPosX();
    }
    if(this->morse_receiver_obj.getPosX()<this->PlotUI_obj.minx){
        this->PlotUI_obj.minx=this->morse_receiver_obj.getPosX();
    }
    if(this->morse_receiver_obj.getPosY()>this->PlotUI_obj.maxy){
        this->PlotUI_obj.maxy=this->morse_receiver_obj.getPosY();
    }
    if(this->morse_receiver_obj.getPosY()<this->PlotUI_obj.miny){
        this->PlotUI_obj.miny=this->morse_receiver_obj.getPosY();
    }
    this->PlotUI_obj.ui->QPlotUI->xAxis->setRange(this->PlotUI_obj.minx-1, this->PlotUI_obj.maxx+1);
    this->PlotUI_obj.ui->QPlotUI->yAxis->setRange(this->PlotUI_obj.miny-1, this->PlotUI_obj.maxy+1);
    this->PlotUI_obj.ui->QPlotUI->replot();

    }
    //    if(ui->Set_new_speed->isEnabled() && ui->Set_new_speed->isChecked()){
    //        bool ok;
    //        ui->Enter_new_constant_speed->text().toDouble(&ok);
    //        if(ok==1){
    //        vilma_self_driver_obj.maintainSpeed(ui->Enter_new_constant_speed->text().toDouble());
    //        }
    //    }
    if(ui->Set_wheel_direction_button->isChecked()){
        if(!ui->Set_wheel_direction_from_table->isChecked() && ui->Set_wheel_direction_x_input->text()!=""
                && ui->Set_wheel_direction_y_input->text()!=""){
            vilma_self_driver_obj.reorientate_to_pose(ui->Set_wheel_direction_x_input->text().toDouble(),ui->Set_wheel_direction_y_input->text().toDouble());
        }
        if(ui->Set_wheel_direction_from_table->isChecked())
        {
            double current_row;
            int ok;
            QTableWidgetItem *current_item = ui->Set_wheel_direction_table->item(0,4);
            if(current_item!=0){
                current_row= current_item->text().toDouble();
            }
            QTableWidgetItem *X_item = ui->Set_wheel_direction_table->item(current_row-1,0);
            QTableWidgetItem *Y_item = ui->Set_wheel_direction_table->item(current_row-1,1);
            if(X_item==0 || Y_item==0){ //reached end of X Y list
                morse_transmiter_obj.setSteering(0);
                morse_transmiter_obj.setPowerAmount(0);

                return;
            }
            ok=vilma_self_driver_obj.reorientate_to_pose(X_item->text().toDouble(),Y_item->text().toDouble());
            if(ok==-1){ //check if the X Y is behind the car already
                current_item->setText(QString ("%1").arg(current_item->text().toDouble()+1));
            }

        }
    }
}



void MainWindow::on_Set_wheel_direction_from_table_toggled(bool checked)
{
    if(checked)
    {
        ui->Set_wheel_direction_table->setEnabled(1);
    }else
    {
        ui->Set_wheel_direction_table->setEnabled(0);
    }
}


void MainWindow::on_steering_slider_sliderMoved(int position)
{
    morse_transmiter_obj.setSteering(((float) -position/100)*0.191); //*0.191 so it stays as +-0.6 rad
    //and not +-3.14 rad
}


void MainWindow::on_SmoothTrajectoryButton_clicked()
{
    std::deque<one_point> points_from_table;
    std::deque<one_point> points_to_table;
    QTableWidgetItem *X_item;
    QTableWidgetItem *Y_item;
    double current_row=0;
    int ok=0;
    while(ok==0){
        X_item = ui->Set_wheel_direction_table->item(current_row,0);
        Y_item = ui->Set_wheel_direction_table->item(current_row,1);
        if(X_item==0 || Y_item==0){ //reached end of X Y list
            ok =-1;
            break;
        }
        points_from_table.push_back(one_point (X_item->text().toFloat(),Y_item->text().toFloat()));
        current_row++;
    }
    points_to_table=vilma_self_driver_obj.generate_smooth_path(points_from_table);
    current_row=0;
    for(current_row=0;current_row<points_to_table.size();current_row++){
        X_item = ui->Set_wheel_direction_table->item(current_row,0);
        Y_item = ui->Set_wheel_direction_table->item(current_row,1);
        X_item->setText(QString ("%5").arg(points_to_table.at(current_row).x));
        Y_item->setText(QString ("%5").arg(points_to_table.at(current_row).y));
    }
}







void MainWindow::on_Maintain_current_speed_toggled()
{
    if(ui->Set_new_speed->isChecked()){
        ui->Set_new_speed->setChecked(0);
        ui->Maintain_current_speed->setChecked(0);
        return;
    }
}



void MainWindow::on_Set_new_speed_toggled(bool checked)
{
    if(checked==1){
    if(ui->Maintain_current_speed->isChecked()){
        ui->Maintain_current_speed->setChecked(0);
        ui->Set_new_speed->setChecked(0);
        return;
    }
    bool ok;
    ui->Enter_new_constant_speed->text().toDouble(&ok);
    if(ok==1){
        printf(" New Speed entered\n");
        vilma_self_driver_obj.maintainSpeed(ui->Enter_new_constant_speed->text().toDouble());
        ui->Enter_new_constant_speed->setEnabled(0);
    }else{
        ui->Set_new_speed->setChecked(0);
    }
    return;
    }else{
    vilma_self_driver_obj.SetMaintainSpeedOFF();
    ui->Enter_new_constant_speed->setEnabled(1);
    }
}




void MainWindow::on_PlotTrajectory_clicked()
{
    plot=1;
    this->PlotUI_obj.ui->QPlotUI->clearPlottables();
    this->PlotUI_obj.ui->QPlotUI->clearGraphs();

    this->PlotUI_obj.ui->QPlotUI->addGraph();
    QCPCurve *fermatSpiral1 = new QCPCurve(this->PlotUI_obj.ui->QPlotUI->xAxis, this->PlotUI_obj.ui->QPlotUI->yAxis);
    this->PlotUI_obj.ui->QPlotUI->addPlottable(fermatSpiral1);
    // give the axes some labels:
    this->PlotUI_obj.ui->QPlotUI->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    this->PlotUI_obj.ui->QPlotUI->xAxis->setLabel("x");
    this->PlotUI_obj.ui->QPlotUI->addGraph();
    this->PlotUI_obj.ui->QPlotUI->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    this->PlotUI_obj.ui->QPlotUI->graph(0)->setLineStyle(QCPGraph::lsNone);

    // create graph and assign data to it:

    if(this->ui->Set_wheel_direction_table->isEnabled()){
    QVector<double> x(101), y(101); // initialize with entries 0..100
    QTableWidgetItem *X_item = ui->Set_wheel_direction_table->item(0,0);
    QTableWidgetItem *Y_item = ui->Set_wheel_direction_table->item(0,1);
    int i=0;
    while(!(X_item==NULL || Y_item==NULL)){ //reached end of X Y list
        if(X_item->text().toDouble()>this->PlotUI_obj.maxx){
            this->PlotUI_obj.maxx=X_item->text().toDouble();
        }
        if(Y_item->text().toDouble()>this->PlotUI_obj.maxy){
            this->PlotUI_obj.maxy=Y_item->text().toDouble();
        }
        if(X_item->text().toDouble()<this->PlotUI_obj.minx){
            this->PlotUI_obj.minx=X_item->text().toDouble();
        }
        if(Y_item->text().toDouble()<this->PlotUI_obj.miny){
            this->PlotUI_obj.miny=Y_item->text().toDouble();
        }
        x.append(X_item->text().toDouble()); // x goes from -1 to 1
        y.append(Y_item->text().toDouble());  // let's plot a quadratic function
        i++;
        X_item = ui->Set_wheel_direction_table->item(i,0);
        Y_item = ui->Set_wheel_direction_table->item(i,1);
        this->PlotUI_obj.ui->QPlotUI->xAxis->setRange(this->PlotUI_obj.minx-1, this->PlotUI_obj.maxx+1);
        this->PlotUI_obj.ui->QPlotUI->yAxis->setRange(this->PlotUI_obj.miny-1, this->PlotUI_obj.maxy+1);
        fermatSpiral1->setData(x, y);
        fermatSpiral1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCrossCircle,Qt::red,Qt::white,5));
        fermatSpiral1->setLineStyle(QCPCurve::lsNone);
    }
    }

    this->PlotUI_obj.ui->QPlotUI->replot();
    this->PlotUI_obj.show();


}

void MainWindow::on_InputFromFile_clicked()
{
    if(!ui->Set_wheel_direction_table->isEnabled()){
       ui->Set_wheel_direction_table->setEnabled(1);
   }
   QString filename = QFileDialog::getOpenFileName();

   QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

   QString content = file.readAll();
   file.close();
   int column=0;
   int row=0;
   foreach( QString numStr, content.split(QRegExp("[\\s]"), QString::SkipEmptyParts) )
   {
       bool check = false;
       float val = numStr.toFloat(&check);
       if( !check )
           continue;
       else{
           if(column==0){
           ui->Set_wheel_direction_table->setItem(row,column,new QTableWidgetItem());
           ui->Set_wheel_direction_table->item(row,column)->setText(QString ("%5").arg(val));
           column=1;
           }else if(column==1){
           ui->Set_wheel_direction_table->setItem(row,column,new QTableWidgetItem());
           ui->Set_wheel_direction_table->item(row,column)->setText(QString ("%5").arg(val));
           row++;
           column=0;
           }
       }
           //do something with "val"
   }

}

void MainWindow::on_GeneratePoints_clicked()
{
    std::deque<one_point> points_from_table;
    std::deque<one_point> points_to_table;
    QTableWidgetItem *X_item;
    QTableWidgetItem *Y_item;
    double current_row=0;
    int ok=0;
    while(ok==0){
        X_item = ui->Set_wheel_direction_table->item(current_row,0);
        Y_item = ui->Set_wheel_direction_table->item(current_row,1);
        if(X_item==0 || Y_item==0){ //reached end of X Y list
            ok =-1;
            break;
        }
        points_from_table.push_back(one_point (X_item->text().toFloat(),Y_item->text().toFloat()));
        current_row++;
    }
    points_to_table=vilma_self_driver_obj.generate_points(points_from_table);
    current_row=0;
    qDebug() << points_to_table.size();
    for(current_row=0;current_row<points_to_table.size();current_row++){
        if(ui->Set_wheel_direction_table->item(current_row,0)==NULL){
        ui->Set_wheel_direction_table->setItem(current_row,0,new QTableWidgetItem());
        }
        if(ui->Set_wheel_direction_table->item(current_row,1)==NULL){
        ui->Set_wheel_direction_table->setItem(current_row,1,new QTableWidgetItem());
        }
        X_item = ui->Set_wheel_direction_table->item(current_row,0);
        Y_item = ui->Set_wheel_direction_table->item(current_row,1);
        X_item->setText(QString ("%5").arg(points_to_table.at(current_row).x));
        Y_item->setText(QString ("%5").arg(points_to_table.at(current_row).y));
    }
}
