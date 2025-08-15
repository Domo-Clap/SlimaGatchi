#pragma once

#include <string>

class Slime_Food
{

public:

	int getFoodRegenValu();
	std::string getFoodName();

	void setFoodName(std::string name);
	void setFoodRegenValu(int value);

	Slime_Food(std::string name, int value);
	Slime_Food();

private:

	std::string foodName;
	int foodRegenValue;



};

