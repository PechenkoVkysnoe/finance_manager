#include "calculatorcategories.h"
#include "ui_calculatorcategories.h"

double numFirst3, numSecond3;

CalculatorCategories::CalculatorCategories(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculatorCategories)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digitsNum()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(operation()));
    connect(ui->pushButton_dev,SIGNAL(clicked()),this,SLOT(operation()));

    ui->pushButton_dev->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

    ui->label->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
}

CalculatorCategories::~CalculatorCategories()
{
    delete ui;
}

void CalculatorCategories::digitsNum()
{
    QPushButton *button=(QPushButton *)sender();
    double num;
    QString strLable;
    if(ui->label->text().contains(".")&&button->text()=="0")
    {
        strLable=ui->label->text()+button->text();
    }
    else
    {
        num=(ui->label->text()+button->text()).toDouble();
        strLable=QString::number(num,'g',15);
    }
    ui->label->setText(strLable);
}

void CalculatorCategories::on_pushButton_t_clicked()
{
    if(!ui->label->text().contains('.'))
    {
        ui->label->setText(ui->label->text()+".");
    }
}

void CalculatorCategories::operation()
{
    QPushButton *button=(QPushButton *)sender();
    numFirst3=ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);
}

void CalculatorCategories::on_pushButton_equal_clicked()
{
    double labelNum;
    QString strLable;
    numSecond3 = ui->label->text().toDouble();
    if(ui->pushButton_plus->isChecked())
    {
        labelNum=numFirst3+numSecond3;
        strLable=QString::number(labelNum,'g',15);
        ui->label->setText(strLable);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNum=numFirst3-numSecond3;
        strLable=QString::number(labelNum,'g',15);
        ui->label->setText(strLable);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_dev->isChecked())
    {
        if(numSecond3==0)
        {
            ui->label->setText("0");
        }
        else
        {
            labelNum=numFirst3/numSecond3;
            strLable=QString::number(labelNum,'g',15);
            ui->label->setText(strLable);
            ui->pushButton_dev->setChecked(false);
        }
    }
    else if(ui->pushButton_mult->isChecked())
    {
        labelNum=numFirst3*numSecond3;
        strLable=QString::number(labelNum,'g',15);
        ui->label->setText(strLable);
        ui->pushButton_mult->setChecked(false);
    }
}

void CalculatorCategories::on_pushButton_AC_clicked()
{
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_dev->setChecked(false);
    ui->label->setText("0");
}

void CalculatorCategories::on_pushButton_clicked()
{

    emit resultGot(ui->label->text().toDouble());
    this->close();
}
