#ifndef CALCULATORGAVE_H
#define CALCULATORGAVE_H

#include <QDialog>

namespace Ui {
class CalculatorGave;
}

class CalculatorGave : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorGave(QWidget *parent = nullptr);
    ~CalculatorGave();

private:
    Ui::CalculatorGave *ui;
public slots:
    void onIdGave(int id);
signals:
    void resultGave(double result);
    void resultGot(double result);
    void idSignal(int);
private slots:
    void digitsNum();
    void on_pushButton_t_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_AC_clicked();
    void operation();
    void on_pushButton_clicked();
};

#endif // CALCULATORGAVE_H
