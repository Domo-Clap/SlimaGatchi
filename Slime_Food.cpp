#include "Headers/Slime_Food.h"

int Slime_Food::getFoodRegenValu()
{
    return 0;
}

std::string Slime_Food::getFoodName()
{
    return std::string();
}

void Slime_Food::setFoodName(std::string name)
{

    foodName = name;


}

void Slime_Food::setFoodRegenValu(int value)
{

    foodRegenValue = value;

}

Slime_Food::Slime_Food(std::string name, int value)
{

    foodName = name;
    foodRegenValue = value;

}

Slime_Food::Slime_Food()
{

    foodName = "";
    foodRegenValue = 0;

}
