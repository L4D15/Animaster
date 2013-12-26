#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/DiceBag.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_diceRollerInput_returnPressed();

    void on_attackValue_valueChanged(int arg1);

    void on_defenseValue_valueChanged(int arg1);

    void on_armorValue_valueChanged(int arg1);

    void on_damageValue_valueChanged(int arg1);

private:
    void            calculateAttack();

private:
    Ui::MainWindow *ui;
    DiceBag*        diceBag;
};

#endif // MAINWINDOW_H
