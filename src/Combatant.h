#ifndef COMBATANT_H
#define COMBATANT_H

#include <string>

class Combatant
{
public:
    Combatant();
    Combatant(std::string name);
    Combatant(std::string name, int turn, int attack, int defense, int maxHealth);

    inline void         setName(std::string name) { this->name = name; }
    inline void         setTurn(const int turn) { this->turn = turn; }
    inline void         setAttack(const int attack) { this->attack = attack; }
    inline void         setDefense(const int defense) { this->defense = defense; }
    inline void         setMaxHealth(const int maxHealth) { this->maxHealth = maxHealth; }
    inline void         setCurrentHealth(const int currentHealth) { this->currentHealth = currentHealth; }
    inline void         setNotes(const int notes) { this->notes = notes; }

    inline std::string  getName() { return this->name; }
    inline int          getTurn() { return this->turn; }
    inline int          getAttack() { return this->attack; }
    inline int          getDefense() { return this->defense; }
    inline int          getMaxHealth() { return this->maxHealth; }
    inline int          getCurrentHealth() { return this->currentHealth; }
    inline std::string  getNotes() { return this->notes; }

    inline void         damage(const int value) { this->currentHealth -= value; if (this->currentHealth < 0) this->currentHealth = 0; }
    inline void         heal(const int value) { this->currentHealth += value; if (this->currentHealth > this->maxHealth) this->currentHealth = this->maxHealth; }


protected:
    std::string         name;
    int                 turn;
    int                 attack;
    int                 defense;
    int                 currentHealth;
    int                 maxHealth;

    std::string         notes;

};

#endif // COMBATANT_H
