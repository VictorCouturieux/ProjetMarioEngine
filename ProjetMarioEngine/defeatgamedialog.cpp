#include "defeatgamedialog.h"
#include "ui_defeatgamedialog.h"
#include <QProcess>

DefeatGameDialog::DefeatGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefeatGameDialog)
{
    ui->setupUi(this);
}

DefeatGameDialog::~DefeatGameDialog()
{
    delete ui;
}

void DefeatGameDialog::on_pushButton_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void DefeatGameDialog::on_pushButton_2_clicked()
{
    qApp->quit();
}
