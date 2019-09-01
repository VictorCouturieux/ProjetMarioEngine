#ifndef WINGAME_H
#define WINGAME_H

#include <QDialog>

namespace Ui {
class WinGame;
}

class WinGame : public QDialog
{
    Q_OBJECT
public:
    explicit WinGame(QWidget *parent = 0);
    ~WinGame();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WinGame *ui;

};

#endif // WINGAME_H
