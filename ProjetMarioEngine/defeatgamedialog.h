#ifndef DEFEATGAMEDIALOG_H
#define DEFEATGAMEDIALOG_H

#include <QDialog>

namespace Ui {
class DefeatGameDialog;
}

class DefeatGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DefeatGameDialog(QWidget *parent = nullptr);
    ~DefeatGameDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DefeatGameDialog *ui;
};

#endif // DEFEATGAMEDIALOG_H
