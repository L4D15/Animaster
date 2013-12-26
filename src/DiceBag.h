#ifndef DICEBAG_H
#define DICEBAG_H

#include <string>
#include <list>

typedef struct
{
    std::string roll;
    int         result;
}DiceRoll;

class DiceBag
{
public:
    DiceBag();
    DiceBag(int randomSeed);

    int             roll(std::string description);

    std::string     getRollHistory();

protected:
    int             rollDice(unsigned int amount, unsigned int faces);

private:
    std::list<DiceRoll>  rollHistory;
};

#endif // DICEBAG_H
