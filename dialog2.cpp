#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    this->setStyleSheet("background-color: rgb(245,255,250);");
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::onResultGot(double result)
{
    ui->label->setText(QString::number(result));
}

void Dialog2::on_pushButton_clicked()
{
    emit id(1);
    this->close();
}

void Dialog2::on_pushButton_2_clicked()
{
    emit id(2);
    this->close();
}

void Dialog2::on_pushButton_3_clicked()
{
    emit id(3);
    this->close();
}

void Dialog2::on_pushButton_4_clicked()
{
    emit id(4);
    this->close();
}
