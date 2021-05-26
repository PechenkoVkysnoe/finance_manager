#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    this->setStyleSheet("background-color: rgb(245,255,250);");
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::onResultGave(double result)
{
    ui->label->setText(QString::number(result));
}

void Dialog3::on_pushButton_clicked()
{
    emit id(1);
    this->close();
}

void Dialog3::on_pushButton_2_clicked()
{
    emit id(2);
    this->close();
}

void Dialog3::on_pushButton_3_clicked()
{
    emit id(3);
    this->close();
}

void Dialog3::on_pushButton_4_clicked()
{
    emit id(4);
    this->close();
}

void Dialog3::on_pushButton_5_clicked()
{
    emit id(5);
    this->close();
}

void Dialog3::on_pushButton_6_clicked()
{
    emit id(6);
    this->close();
}

void Dialog3::on_pushButton_7_clicked()
{
    emit id(7);
    this->close();
}

void Dialog3::on_pushButton_8_clicked()
{
    emit id(8);
    this->close();
}
