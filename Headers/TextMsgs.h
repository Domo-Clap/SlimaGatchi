#pragma once

#include <iostream>
#include "Slime.h"

void DisplayHeader();
void DisplayOpenAppOptions();
void DisplaySlimeMenu(Slime* currSlime);
void DisplaySlimeDetails(Slime* currSlime);
void DisplayActionOptions();

void DisplayFoodOptions(std::vector<Slime_Food> allFoods);
void DisplaySleepOptions();