#ifndef COMBATCARD_H
#define COMBATCARD_H

#include <QWidget>

namespace Ui {
class CombatCard;
}

class CombatCard : public QWidget
{
    Q_OBJECT

public:
    explicit CombatCard(QWidget *parent = 0);
    ~CombatCard();

private:
    Ui::CombatCard *ui;
};

#endif // COMBATCARD_H
