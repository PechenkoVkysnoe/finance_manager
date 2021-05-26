#ifndef FORMCALCULATE_H
#define FORMCALCULATE_H

#include <QWidget>

namespace Ui {
class FormCalculate;
}

class FormCalculate : public QWidget
{
    Q_OBJECT

public:
    explicit FormCalculate(QWidget *parent = nullptr);
    ~FormCalculate();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormCalculate *ui;
};

#endif // FORMCALCULATE_H
