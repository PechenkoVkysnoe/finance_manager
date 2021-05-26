#include "formcalculate.h"
#include "ui_formcalculate.h"

FormCalculate::FormCalculate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCalculate)
{
    ui->setupUi(this);
}

FormCalculate::~FormCalculate()
{
    delete ui;
}

