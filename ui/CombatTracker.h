#ifndef COMBATTRACKER_H
#define COMBATTRACKER_H

#include <QWidget>

namespace Ui {
class CombatTracker;
}

class CombatTracker : public QWidget
{
    Q_OBJECT

public:
    explicit CombatTracker(QWidget *parent = 0);
    ~CombatTracker();

private:
    Ui::CombatTracker *ui;
};

#endif // COMBATTRACKER_H
