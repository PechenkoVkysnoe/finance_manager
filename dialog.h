#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
public slots:
    void onIdGot(int id);
signals:
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

#endif
