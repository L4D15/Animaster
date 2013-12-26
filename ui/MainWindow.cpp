#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ui/CombatCard.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // DiceBag configuration
    this->diceBag = new DiceBag();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_diceRollerInput_returnPressed()
{
    QString rollFormulae;

    rollFormulae = this->ui->diceRollerInput->text();

    int result;

    result = this->diceBag->roll(rollFormulae.toStdString());

    QString rollResult = QString("%1 = %2").arg(rollFormulae).arg(result);

    this->ui->rollFormulaeHistory->appendPlainText(rollResult);
}

void MainWindow::calculateAttack()
{
    QString finalResult;

    int attack;
    int defense;
    int armor;
    int damage;

    attack = this->ui->attackValue->value();
    defense = this->ui->defenseValue->value();
    armor = this->ui->armorValue->value();
    damage = this->ui->damageValue->value();

    int result;

    result = attack - defense;

    // If the result is lower than zero, a counter attack is possible
    if (result < 0)
    {
        int counterAttackBonus;

        counterAttackBonus = (static_cast<int>(result / 10)) * 5;
        finalResult = QString("+%1C").arg(counterAttackBonus);
    }
    else
    {
        int attackBonus;
        attackBonus = (attack - defense) - (armor + 2) * 10;

        int finalAttackBonus;
        finalAttackBonus = (static_cast<int>(attackBonus / 10) * 10);

        int finalDamage;
        finalDamage = (static_cast<float>(finalAttackBonus) / 100.0f) * damage;

        if (finalDamage < 0)
        {
            finalDamage = 0;
        }
        finalResult = QString("%1").arg(finalDamage);
    }

    // Show the result
    this->ui->resultValue->setText(finalResult);
}

void MainWindow::on_attackValue_valueChanged(int arg1)
{
    calculateAttack();
}

void MainWindow::on_defenseValue_valueChanged(int arg1)
{
    calculateAttack();
}

void MainWindow::on_armorValue_valueChanged(int arg1)
{
    calculateAttack();
}

void MainWindow::on_damageValue_valueChanged(int arg1)
{
    calculateAttack();
}
