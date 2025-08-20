#include "Headers/Slime.h"
#include <iostream>
#include <algorithm>


//#################################################################################
//#################################################################################
//###                        Basic Setter Functions                             ###
//#################################################################################
//#################################################################################
void Slime::SetSlimeName(std::string newName)
{

	if (newName.length() < 0) {

		return;

	}
	if (newName.length() > 15) {

		return;

	}
		
	SlimeName = newName;
	

}

void Slime::SetSlimeAge(int newAge)
{

	if (newAge < 0 || newAge > 1000 && aliveStatus == true) {

		return;

	}

	SlimeAge = newAge;

}

void Slime::SetSlimeType(SlimeType newType)
{

	type = newType;

}

void Slime::SetSlimeHungerVal(int newVal)
{

	if (newVal > 0 && newVal <= 100 && aliveStatus == true) {

		slimeHungerVal = newVal;

	}

}

void Slime::SetSlimeHealthVal(int newVal)
{

	if (newVal > 0 && newVal <= 100 && aliveStatus == true) {

		slimeHealthVal = newVal;

	}

}

void Slime::SetSlimeEnergyVal(int newVal)
{

	if (newVal > 0 && newVal <= 100 && aliveStatus == true) {

		slimeEnergyVal = newVal;

	}

}

void Slime::SetSlimeHappinessVal(int newVal)
{

	if (newVal > 0 && newVal <= 100 && aliveStatus == true) {

		slimeHappinessVal = newVal;

	}

}

void Slime::SetSlimeMood(Mood newMood)
{

	if (aliveStatus == true) {

		SlimeMood = newMood;

	}

	

}

void Slime::SetIsSleeping(bool sleeping)
{

	if (aliveStatus == true) {

		isSleeping = sleeping;

	}


}

void Slime::SetLastSeen(time_t timestamp)
{

	lastSeen = timestamp;

}

void Slime::SetAliveStatus(bool newStatus)
{

	aliveStatus = newStatus;

}

void Slime::SettimeWentToSleep(time_t currTime)
{

	timeWentToSleep = currTime;

}

void Slime::SetSleepDuration(int hrs)
{

	sleepDurationHrs = hrs;

}



void Slime::SetFavoriteFoods(std::vector<Slime_Food>& allFoods)
{

	likedFoods.clear();

	// We want to basically have a switch statement that checks the sliem's type
	// Then we will create food objects for the slime that they like

	//Electric, Pyro, Water, Ice, Earth, Light, Dark

	switch (type) {

		case SlimeType::Pyro:

			likedFoods.push_back(allFoods[0]);
			likedFoods.push_back(allFoods[1]);
			break;

		case SlimeType::Electric:

			likedFoods.push_back(allFoods[2]);
			likedFoods.push_back(allFoods[3]);
			break;

		case SlimeType::Water:

			likedFoods.push_back(allFoods[4]);
			likedFoods.push_back(allFoods[5]);
			break;

		case SlimeType::Ice:

			likedFoods.push_back(allFoods[6]);
			likedFoods.push_back(allFoods[7]);
			break;

		case SlimeType::Earth:

			likedFoods.push_back(allFoods[8]);
			likedFoods.push_back(allFoods[9]);
			break;

		case SlimeType::Light:

			likedFoods.push_back(allFoods[10]);
			likedFoods.push_back(allFoods[11]);
			break;

		case SlimeType::Dark:

			likedFoods.push_back(allFoods[12]);
			likedFoods.push_back(allFoods[13]);
			break;

	}


}

void Slime::SetDislikedFoods(std::vector<Slime_Food>& allFoods)
{

	dislikeFoods.clear();

	switch (type) {

		case SlimeType::Pyro:

			dislikeFoods.push_back(allFoods[4]);
			dislikeFoods.push_back(allFoods[5]);
			break;

		case SlimeType::Electric:

			dislikeFoods.push_back(allFoods[8]);
			dislikeFoods.push_back(allFoods[9]);
			break;

		case SlimeType::Water:

			dislikeFoods.push_back(allFoods[2]);
			dislikeFoods.push_back(allFoods[3]);
			break;

		case SlimeType::Ice:

			dislikeFoods.push_back(allFoods[0]);
			dislikeFoods.push_back(allFoods[1]);
			break;

		case SlimeType::Earth:

			dislikeFoods.push_back(allFoods[6]);
			dislikeFoods.push_back(allFoods[7]);
			break;

		case SlimeType::Light:

			dislikeFoods.push_back(allFoods[12]);
			dislikeFoods.push_back(allFoods[13]);
			break;

		case SlimeType::Dark:

			dislikeFoods.push_back(allFoods[10]);
			dislikeFoods.push_back(allFoods[11]);
			break;

	}

}


//#################################################################################
//#################################################################################
//###                        Basic Getter Functions                             ###
//#################################################################################
//#################################################################################
std::string Slime::getSlimeName()
{
	return SlimeName;
}

int Slime::getSlimeAge()
{
	return SlimeAge;
}

SlimeType Slime::getType()
{
	return type;
}

int Slime::getSlimeHungerVal()
{
	return slimeHungerVal;
}

int Slime::getSlimeHealthVal()
{
	return slimeHealthVal;
}

int Slime::getSlimeEnergyVal()
{
	return slimeEnergyVal;
}

int Slime::getSlimeHappinessVal()
{
	return slimeHappinessVal;
}

Mood Slime::getSlimeMood()
{
	return SlimeMood;
}

bool Slime::getAliveStatus()
{
	return aliveStatus;
}

bool Slime::getIsSleeping()
{
	return isSleeping;
}

time_t Slime::getLastSeen()
{
	return lastSeen;
}

time_t Slime::getTimeWentToSleep()
{
	return timeWentToSleep;
}

int Slime::getSleepDuration()
{
	return sleepDurationHrs;
}







Slime::Slime(std::string name, SlimeType newType, Mood mood, std::vector<Slime_Food> liked, std::vector<Slime_Food> disliked)
{

	SlimeName = name;
	SlimeAge = 1;
	type = newType;
	SlimeMood = mood;

	likedFoods = liked;
	dislikeFoods = disliked;
	
	aliveStatus = true;
	isSleeping = false;

	slimeHealthVal = 100;
	slimeHappinessVal = 100;
	slimeEnergyVal = 100;
	slimeHungerVal = 100;
	lastSeen = time(NULL);
	sleepDurationHrs = 0;
	timeWentToSleep = time(NULL);

}

Slime::Slime()
{

	SlimeName = "";
	SlimeAge = 1;
	type = SlimeType::Pyro;
	SlimeMood = Mood::Happy;

	dislikeFoods = {};
	likedFoods = {};

	aliveStatus = true;
	isSleeping = false;

	slimeHealthVal = 100;
	slimeHappinessVal = 100;
	slimeEnergyVal = 100;
	slimeHungerVal = 100;
	lastSeen = time(NULL);

	sleepDurationHrs = 0;
	timeWentToSleep = time(NULL);

}


void Slime::FeedSlime(Slime_Food selectedFood)
{

	int hungerIncrease = selectedFood.getFoodRegenValu();

	for (int i = 0; i < likedFoods.size(); i++) {

		if (selectedFood.getFoodName() == likedFoods[i].getFoodName()) {

			std::cout << "Found a liked Food! Adding to the total increase of the hunger val!" << std::endl;

			hungerIncrease = selectedFood.getFoodRegenValu() + 5;
			break;

		}

	}

	for (int j = 0; j < dislikeFoods.size(); j++) {

		if (selectedFood.getFoodName() == dislikeFoods[j].getFoodName()) {

			std::cout << "Found a disliked food! Subtracting from the total increase of hunger val!" << std::endl;

			hungerIncrease = selectedFood.getFoodRegenValu() - 5;
			break;

		}

	}

	int newValue = slimeHungerVal + hungerIncrease;

	int max = 100, min = 0;

	newValue = std::clamp(newValue, min, max);

	SetSlimeHungerVal(newValue);

}

// Fuinction to call when the user chooses to play with their slime.
void Slime::PlayWithSlime()
{

	slimeEnergyVal -= 10;
	slimeHappinessVal += 8;
	
	int max = 100, min = 0;


	// Need to clamp values to make sure do not go above or below 0 - 100
	slimeEnergyVal = std::clamp(slimeEnergyVal, min, max);
	slimeHappinessVal = std::clamp(slimeHappinessVal, min, max);

}

// Need to build a timer that tracks when isSleeping will move to false.
void Slime::RestSlime(int timeToSleep)
{

	if (isSleeping) {

		std::cout << "Slime is current sleeping already!" << std::endl;

		return;

	}

	isSleeping = true;
	timeWentToSleep = time(NULL);
	sleepDurationHrs = timeToSleep;
	

}


void Slime::SlimeStatDecay()
{

	time_t currentTime = time(NULL);

	// Time passed in hours
	double timePassed = difftime(currentTime, lastSeen) / 3600;


	// Hunger decrease
	slimeHungerVal = slimeHungerVal - (timePassed * 5);


	// Energy decrease
	if (!isSleeping) {

		slimeEnergyVal = slimeEnergyVal - (timePassed * 3);

	}

	if (slimeHungerVal < 70 && slimeEnergyVal < 70) {

		slimeHappinessVal = slimeHappinessVal - (timePassed * 2);

	}

	if (slimeHungerVal < 10 || slimeEnergyVal < 10 || slimeHappinessVal < 25) {

		slimeHealthVal = slimeHealthVal - (timePassed * 2);

	}

	int max = 100, min = 0;

	slimeHungerVal = std::clamp(slimeHungerVal, min, max);
	slimeEnergyVal = std::clamp(slimeEnergyVal, min, max);
	slimeHappinessVal = std::clamp(slimeHappinessVal, min, max);
	slimeHealthVal = std::clamp(slimeHealthVal, min, max);

	if (slimeHealthVal == 0) {

		aliveStatus = false;

	}

}


/*
SDL_Texture* Slime::getSlimeTexture()
{

	return slimeTexture;

}*/





