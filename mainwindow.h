#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void onResultGot(double result);

    void onResultGave(double result);

    void on_pushButton_percent_clicked();

    void on_pushButton_salary_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_other1_clicked();

    void on_pushButton_clothes_clicked();

    void on_pushButton_food_clicked();

    void on_pushButton_freetime_clicked();

    void on_pushButton_health_clicked();

    void on_pushButton_other2_clicked();

    void on_pushButton_present_clicked();

    void on_pushButton_telephone_clicked();

    void on_pushButton_transport_clicked();

    void onIdGot(int id);

    void onIdGave(int id);

private:
    Ui::MainWindow *ui;
    double currentBalance=0,got=0,gave=0;
    double tmpResultGot=0,tmpResultGave=0, sumPercent=0,sumSalary=0, sumSave=0, sumOther1=0, sumFood=0, sumClothes=0,
            sumFreetime=0, sumHealth=0,sumOther2=0,sumPresent=0,sumTelephone=0,sumTransport=0;
protected:
    double sum;
};
#endif // MAINWINDOW_H
