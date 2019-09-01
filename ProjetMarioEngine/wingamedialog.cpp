#include "wingamedialog.h"
#include "ui_wingamedialog.h"
#include <QProcess>

WinGameDialog::WinGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinGameDialog)
{
    ui->setupUi(this);
}

WinGameDialog::~WinGameDialog()
{
    delete ui;
}

void WinGameDialog::on_pushButton_clicked(){

//    qApp->quit();
//    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

}

void WinGameDialog::on_pushButton_2_clicked(){

    qApp->quit();
}
