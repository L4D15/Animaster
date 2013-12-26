#include "CombatCard.h"
#include "ui_CombatCard.h"

CombatCard::CombatCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CombatCard)
{
    ui->setupUi(this);
}

CombatCard::~CombatCard()
{
    delete ui;
}
