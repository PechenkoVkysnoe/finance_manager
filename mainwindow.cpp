#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog2.h"
#include "dialog3.h"
#include "calculatorgave.h"
#include "calculatorcategories.h"
#include <QPixmap>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    std::ifstream txt;
    txt.open("txt.txt");
    if(!txt.is_open())
    {
        return;
    }
    txt>>currentBalance>>got>>gave>>tmpResultGot>>tmpResultGave>>
      sumPercent>>sumSalary>>sumSave>>sumOther1>>sumFood>>
      sumClothes>>sumFreetime>>sumHealth>>sumOther2>>
      sumPresent>>sumTelephone>>sumTransport;
    ui->setupUi(this);
    ui->Got->setText(QString::number(got)+" р.");
    ui->balance->setText(" Баланс: " + QString::number(currentBalance)+" р.");
    ui->Gave->setText(QString::number(gave)+" р.");
    ui->label_clothes->setText(QString::number((int)(sumClothes*100/gave))+" %");
    ui->label_food->setText(QString::number((int)(sumFood*100/gave))+" %");
    ui->label_freetime->setText(QString::number((int)(sumFreetime*100/gave))+" %");
    ui->label_health->setText(QString::number((int)(sumHealth*100/gave))+" %");
    ui->label_other2->setText(QString::number((int)(sumOther2*100/gave))+" %");
    ui->label_present->setText(QString::number((int)(sumPresent*100/gave))+" %");
    ui->label_telephone->setText(QString::number((int)(sumTelephone*100/gave))+" %");
    ui->label_transport->setText(QString::number((int)(sumTransport*100/gave))+" %");
    this->setWindowTitle("Мои финансы");
    ui->pushButton_percent->setToolTip ("Депозиты");
    ui->pushButton_salary->setToolTip ("Зарплата");
    ui->pushButton_save->setToolTip ("Сбережения");
    ui->pushButton_other1->setToolTip ("Другое");
    ui->pushButton_food->setToolTip ("Еда");
    ui->pushButton_freetime->setToolTip ("Досуг");
    ui->pushButton_health->setToolTip ("Здоровье");
    ui->pushButton_transport->setToolTip ("Транспорт");
    ui->pushButton_telephone->setToolTip ("Связь");
    ui->pushButton_present->setToolTip ("Подарки");
    ui->pushButton_other2->setToolTip ("Другое");
    ui->pushButton_clothes->setToolTip ("Одежда");
    ui->label_persent->setText(QString::number((int)(sumPercent*100/got))+" %");
    ui->label_salary->setText(QString::number((int)(sumSalary*100/got))+" %");
    ui->label_save->setText(QString::number((int)(sumSave*100/got))+" %");
    ui->label_other1->setText(QString::number((int)(sumOther1*100/got))+" %");
    if(gave!=0)
    {
    ui->label_clothes->setText(QString::number((int)(sumClothes*100/gave))+" %");
    ui->label_food->setText(QString::number((int)(sumFood*100/gave))+" %");
    ui->label_freetime->setText(QString::number((int)(sumFreetime*100/gave))+" %");
    ui->label_health->setText(QString::number((int)(sumHealth*100/gave))+" %");
    ui->label_other2->setText(QString::number((int)(sumOther2*100/gave))+" %");
    ui->label_present->setText(QString::number((int)(sumPresent*100/gave))+" %");
    ui->label_telephone->setText(QString::number((int)(sumTelephone*100/gave))+" %");
    ui->label_transport->setText(QString::number((int)(sumTransport*100/gave))+" %");
    }
    else
    {
        ui->label_clothes->setText("0 %");
        ui->label_food->setText("0 %");
        ui->label_freetime->setText("0 %");
        ui->label_health->setText("0 %");
        ui->label_other2->setText("0 %");
        ui->label_present->setText("0 %");
        ui->label_telephone->setText("0 %");
        ui->label_transport->setText("0 %");
    }
    if(got!=0)
    {
        ui->label_persent->setText(QString::number((int)(sumPercent*100/got))+" %");
        ui->label_salary->setText(QString::number((int)(sumSalary*100/got))+" %");
        ui->label_save->setText(QString::number((int)(sumSave*100/got))+" %");
        ui->label_other1->setText(QString::number((int)(sumOther1*100/got))+" %");
    }
    else
    {
        ui->label_persent->setText("0 %");
        ui->label_salary->setText("0 %");
        ui->label_save->setText("0 %");
        ui->label_other1->setText("0 %");
    }
    ui->balance->setStyleSheet("background-color: rgb(100,210,100);color: white;border-radius: 20px;");
    ui->Got->setStyleSheet("color: rgb(100,210,100);");
    ui->Gave->setStyleSheet("color: rgb(250,100,100);");
    this->setStyleSheet("background-color: rgb(245,255,250);");
}

MainWindow::~MainWindow()
{
    std::ofstream txt;
    txt.open("txt.txt");
    qDebug()<<currentBalance;

    txt<<currentBalance<<"\n"<<got<<"\n"<<gave<<"\n"<<tmpResultGot<<"\n"<<tmpResultGave<<
      "\n"<<sumPercent<<"\n"<<sumSalary<<"\n"<<sumSave<<"\n"<<sumOther1<<"\n"<<sumFood<<
      "\n"<<sumClothes<<"\n"<<sumFreetime<<"\n"<<sumHealth<<"\n"<<sumOther2<<"\n"<<
      sumPresent<<"\n"<<sumTelephone<<"\n"<<sumTransport<<"\n";
    txt.close();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    Dialog window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGot(double)));
    connect(&window, SIGNAL(idSignal(int)), this, SLOT(onIdGot(int)));
    window.setModal(true);
    window.exec();
    show();
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    CalculatorGave window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGave(double)), this, SLOT(onResultGave(double)));
    connect(&window, SIGNAL(idSignal(int)), this, SLOT(onIdGave(int)));
    window.setModal(true);
    window.exec();
    show();
}

void MainWindow::onResultGave(double result)
{
    tmpResultGave=result;
    gave+=result;
    currentBalance-=result;
    ui->Gave->setText(QString::number(gave)+" р.");
    ui->balance->setText(" Баланс: " + QString::number(currentBalance)+" р.");
    if(currentBalance<0)
    {
        ui->balance->setStyleSheet("background-color: rgb(250,100,100);color: white; border-radius: 20px;");
    }
    update();
}

void MainWindow::onResultGot(double result)
{
    tmpResultGot=result;
    got+=result;
    currentBalance+=result;
    ui->Got->setText(QString::number(got)+" р.");
    ui->balance->setText(" Баланс: " + QString::number(currentBalance)+" р.");
    ui->statusbar->showMessage(QString::number(result)+" p. добавлено");
    if(currentBalance>0)
    {
        ui->balance->setStyleSheet("background-color: rgb(100,210,100);color: white; border-radius: 20px;");
    }
    update();
}

void MainWindow::on_pushButton_percent_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGot(double)));
    window.setModal(true);
    window.exec();
    onIdGot(1);
    show();
}

void MainWindow::on_pushButton_salary_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGot(double)));
    window.setModal(true);
    window.exec();
    onIdGot(2);
    show();
}

void MainWindow::on_pushButton_save_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGot(double)));
    window.setModal(true);
    window.exec();
    onIdGot(3);
    show();
}

void MainWindow::on_pushButton_other1_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGot(double)));
    window.setModal(true);
    window.exec();
    onIdGot(4);
    show();
}

void MainWindow::on_pushButton_clothes_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGave(double)));
    window.setModal(true);
    window.exec();
    onIdGave(1);
    show();
}

void MainWindow::on_pushButton_food_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGave(double)));
    window.setModal(true);
    window.exec();
    onIdGave(2);
    show();
}

void MainWindow::on_pushButton_freetime_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGave(double)));
    window.setModal(true);
    window.exec();
    onIdGave(3);
    show();
}

void MainWindow::on_pushButton_health_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGave(double)));
    window.setModal(true);
    window.exec();
    onIdGave(4);
    show();
}

void MainWindow::on_pushButton_other2_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGave(double)));
    window.setModal(true);
    window.exec();
    onIdGave(8);
    show();
}

void MainWindow::on_pushButton_present_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGave(double)));
    window.setModal(true);
    window.exec();
    onIdGave(6);
    show();
}

void MainWindow::on_pushButton_telephone_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGave(double)));
    window.setModal(true);
    window.exec();
    onIdGave(7);
    show();
}

void MainWindow::on_pushButton_transport_clicked()
{
    hide();
    CalculatorCategories window;
    window.setWindowTitle("Калькулятор");
    connect(&window, SIGNAL(resultGot(double)), this, SLOT(onResultGave(double)));
    window.setModal(true);
    window.exec();
    onIdGave(5);
    show();
}

void MainWindow::onIdGot(int id)
{
    if(id==1)
    {
        sumPercent+=tmpResultGot;
        ui->statusbar->showMessage("Депозиты: "+QString::number(tmpResultGot)+" p. получено");
    }
    else if(id==2)
    {
        sumSalary+=tmpResultGot;
        ui->statusbar->showMessage("Зарплата: "+QString::number(tmpResultGot)+" p. получено");
    }
    else if(id==3)
    {
        sumSave+=tmpResultGot;
        ui->statusbar->showMessage("Сбережения: "+QString::number(tmpResultGot)+" p. получено");
    }
    else if(id==4)
    {
        sumOther1+=tmpResultGot;
        ui->statusbar->showMessage("Другое: "+QString::number(tmpResultGot)+" p. получено");
    }
    if(got!=0)
    {
        ui->label_persent->setText(QString::number((int)(sumPercent*100/got))+" %");
        ui->label_salary->setText(QString::number((int)(sumSalary*100/got))+" %");
        ui->label_save->setText(QString::number((int)(sumSave*100/got))+" %");
        ui->label_other1->setText(QString::number((int)(sumOther1*100/got))+" %");
    }
    else
    {
        ui->label_persent->setText("0 %");
        ui->label_salary->setText("0 %");
        ui->label_save->setText("0 %");
        ui->label_other1->setText("0 %");
    }
}

void MainWindow::onIdGave(int id)
{
    if(id==1)
    {
        sumClothes+=tmpResultGave;
        ui->statusbar->showMessage("Одежда: "+QString::number(tmpResultGave)+" p. потрачено");
    }
    else if(id==2)
    {
        sumFood+=tmpResultGave;
        ui->statusbar->showMessage("Еда: "+QString::number(tmpResultGave)+" p. потрачено");
    }
    else if(id==3)
    {
        sumFreetime+=tmpResultGave;
        ui->statusbar->showMessage("Досуг: "+QString::number(tmpResultGave)+" p. потрачено");
    }
    else if(id==4)
    {
        sumHealth+=tmpResultGave;
        ui->statusbar->showMessage("Здоровье: "+QString::number(tmpResultGave)+" p. потрачено");
    }
    else if(id==5)
    {
        sumOther2+=tmpResultGave;
        ui->statusbar->showMessage("Транспорт: "+QString::number(tmpResultGave)+" p. потрачено");
    }
    else if(id==6)
    {
        sumPresent+=tmpResultGave;
        ui->statusbar->showMessage("Подарки: "+QString::number(tmpResultGave)+" p. потрачено");
    }
    else if(id==7)
    {
        sumTelephone+=tmpResultGave;
        ui->statusbar->showMessage("Связь: "+QString::number(tmpResultGave)+" p. потрачено");
    }
    else if(id==8)
    {
        sumTransport+=tmpResultGave;
        ui->statusbar->showMessage("Другое: "+QString::number(tmpResultGave)+" p. потрачено");
    }
    if(gave!=0)
    {
        ui->label_clothes->setText(QString::number((int)(sumClothes*100/gave))+" %");
        ui->label_food->setText(QString::number((int)(sumFood*100/gave))+" %");
        ui->label_freetime->setText(QString::number((int)(sumFreetime*100/gave))+" %");
        ui->label_health->setText(QString::number((int)(sumHealth*100/gave))+" %");
        ui->label_other2->setText(QString::number((int)(sumOther2*100/gave))+" %");
        ui->label_present->setText(QString::number((int)(sumPresent*100/gave))+" %");
        ui->label_telephone->setText(QString::number((int)(sumTelephone*100/gave))+" %");
        ui->label_transport->setText(QString::number((int)(sumTransport*100/gave))+" %");
    }
    else
    {
        ui->label_clothes->setText("0 %");
        ui->label_food->setText("0 %");
        ui->label_freetime->setText("0 %");
        ui->label_health->setText("0 %");
        ui->label_other2->setText("0 %");
        ui->label_present->setText("0 %");
        ui->label_telephone->setText("0 %");
        ui->label_transport->setText("0 %");
    }
}
