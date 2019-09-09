#ifndef WINGAMEDIALOG_H
#define WINGAMEDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class WinGameDialog;
}

class WinGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinGameDialog(QWidget *parent = nullptr);
    ~WinGameDialog();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WinGameDialog *ui;
};

#endif // WINGAMEDIALOG_H
