#pragma once

#include <string>
#include "Slime_Food.h"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>

enum SlimeType { Electric, Pyro, Water, Ice, Earth, Light, Dark };

enum Mood { Upset, Hungry, Happy, Tired,  };


class Slime
{

public:

	// Setter Functions
	void SetSlimeName(std::string newName);
	void SetSlimeAge(int newAge);
	void SetSlimeType(SlimeType newType);
	void SetSlimeHungerVal(int newVal);
	void SetSlimeHealthVal(int newVal);
	void SetSlimeEnergyVal(int newVal);
	void SetSlimeHappinessVal(int newVal);
	void SetSlimeMood(Mood newMood);
	void SetIsSleeping(bool sleeping);
	void SetLastSeen(time_t timestamp);
	void SetFavoriteFoods(std::vector<Slime_Food>& allFoods);
	void SetDislikedFoods(std::vector<Slime_Food>& allFoods);
	void SetAliveStatus(bool newStatus);


	// Getter Functions
	std::string getSlimeName();
	int getSlimeAge();
	SlimeType getType();
	int getSlimeHungerVal();
	int getSlimeHealthVal();
	int getSlimeEnergyVal();
	int getSlimeHappinessVal();
	Mood getSlimeMood();
	bool getAliveStatus();
	bool getIsSleeping();
	time_t getLastSeen();

	// Constructors
	Slime(std::string name, SlimeType newType, Mood mood, std::vector<Slime_Food> liked, std::vector<Slime_Food> disliked);
	Slime();

	void FeedSlime(Slime_Food selectedFood);
	void PlayWithSlime();
	void RestSlime();
	void SlimeStatDecay();

	//SDL_Texture* getSlimeTexture();
	//void setSlimeTexture(SDL_Texture* texture);

private:

	std::string SlimeName;
	int SlimeAge;
	SlimeType type;
	
	std::vector<Slime_Food> likedFoods;
	std::vector<Slime_Food> dislikeFoods;


	int slimeHungerVal;
	int slimeHealthVal;
	int slimeEnergyVal;
	int slimeHappinessVal;

	time_t lastSeen;

	//SDL_Texture *slimeTexture;

	Mood SlimeMood;

	bool aliveStatus;
	bool isSleeping;

};

