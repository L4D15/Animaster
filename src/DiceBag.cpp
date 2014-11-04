#include "DiceBag.h"
#include <sstream>
#include <cstdlib>

DiceBag::DiceBag()
{
    srand(time(NULL));
}

DiceBag::DiceBag(int randomSeed)
{
    // Seed for random numbers
    srand(randomSeed);
}

int DiceBag::roll(std::string description)
{
    int result;
    bool containsRoll;
    bool containsOperation;

    containsRoll = (description.find_first_of("d") != description.npos);
    containsOperation = ((description.find_first_of("+") != description.npos) || (description.find_first_of("-") != description.npos));

    // If there is no 'd' or an operation, it should be a single number
    if (containsRoll == false && containsOperation == false)
    {
        // Parse number
        std::istringstream buffer(description);
        buffer >> result;
        return result;
    }

    // If it is only a roll, make it and return the result
    if (containsRoll == true && containsOperation == false)
    {
        // Parse left and right operands
        int numberOfDicesPos;

        numberOfDicesPos = description.find_first_of("d");

        std::string leftOperand;
        std::string rightOperand;

        leftOperand = description.substr(0, numberOfDicesPos);
        rightOperand = description.substr(numberOfDicesPos + 1, description.size() - 1);

        // Parse numbers
        int numberOfDices;
        int numberOfFaces;

        std::istringstream *parseBuffer;
        parseBuffer = new std::istringstream(leftOperand);

        *parseBuffer >> numberOfDices;

        delete parseBuffer;

        parseBuffer = new std::istringstream(rightOperand);

        *parseBuffer >> numberOfFaces;

        result = rollDice(numberOfDices, numberOfFaces);

        return result;
    }

    // If it have reached these far, there must be a operation
    bool sumOperation;
    bool subOperation;

    sumOperation = (description.find_first_of("+") != description.npos);
    subOperation = (description.find_first_of("-") != description.npos);

    if (sumOperation == true)
    {
        std::string leftOperand;
        std::string rightOperand;

        leftOperand = description.substr(0, description.find_first_of("+"));
        rightOperand = description.substr(description.find_first_of("+") + 1, description.size() - 1);

        int leftResult;
        int rightResult;

        leftResult = roll(leftOperand);
        rightResult = roll(rightOperand);

        return leftResult + rightResult;
    }
    else if(subOperation == true)
    {
        std::string leftOperand;
        std::string rightOperand;

        leftOperand = description.substr(0, description.find_first_of("-"));
        rightOperand = description.substr(description.find_first_of("-") + 1, description.size() - 1);

        int leftResult;
        int rightResult;

        leftResult = roll(leftOperand);
        rightResult = roll(rightOperand);

        return leftResult - rightResult;
    }

    return 0;
}

int DiceBag::rollDice(unsigned int amount, unsigned int faces)
{
    std::stringstream descriptor;

    descriptor << amount << "d" << faces;

    int result = 0;
    for (unsigned int roll = 0; roll < amount; ++roll)
    {
        result += rand()%faces + 1;
    }

    DiceRoll rolled;

    rolled.roll = descriptor.str();
    rolled.result = result;

    this->rollHistory. push_back(rolled);

    return result;
}

std::string DiceBag::getRollHistory()
{
    std::stringstream stream;

    for (std::list<DiceRoll>::iterator currentRoll = this->rollHistory.begin(); currentRoll != this->rollHistory.end(); ++currentRoll)
    {
        stream << currentRoll->roll << " => " << currentRoll->result << std::endl;
    }

    return stream.str();
}
