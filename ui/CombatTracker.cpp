#include "CombatTracker.h"
#include "ui_CombatTracker.h"

CombatTracker::CombatTracker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CombatTracker)
{
    ui->setupUi(this);
}

CombatTracker::~CombatTracker()
{
    delete ui;
}
