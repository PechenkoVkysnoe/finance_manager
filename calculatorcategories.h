#ifndef CALCULATORCATEGORIES_H
#define CALCULATORCATEGORIES_H

#include <QDialog>

namespace Ui {
class CalculatorCategories;
}

class CalculatorCategories : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorCategories(QWidget *parent = nullptr);
    ~CalculatorCategories();

private:
    Ui::CalculatorCategories *ui;
signals:
    void resultGot(double result);
private slots:
    void digitsNum();
    void on_pushButton_t_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_AC_clicked();
    void operation();
    void on_pushButton_clicked();
};

#endif // CALCULATORCATEGORIES_H
