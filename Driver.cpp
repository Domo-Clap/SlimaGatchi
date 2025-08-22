#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <nlohmann/json.hpp>
#include <windows.h>
#include <vector>
#include <fstream>
#include <filesystem>
#include <conio.h>
#include <limits>


#include "Headers/Game_Driver.h"
#include "Headers/Slime.h"
#include "Headers/TextMsgs.h"
#include "Headers/File_Managing.h"


using json = nlohmann::json;
namespace fs = std::filesystem;


NLOHMANN_JSON_SERIALIZE_ENUM(SlimeType, {

	{SlimeType::Electric, "Electric"},
	{SlimeType::Pyro, "Pyro"},
	{SlimeType::Water, "Water"},
	{SlimeType::Ice, "Ice"},
	{SlimeType::Earth, "Earth"},
	{SlimeType::Light, "Light"},
	{SlimeType::Dark, "Dark"},
})

NLOHMANN_JSON_SERIALIZE_ENUM(Mood, {

	{Mood::Upset, "Upset"},
	{Mood::Hungry, "Hungry"},
	{Mood::Happy, "Happy"},
	{Mood::Tired, "Tired"},
})


void LoadAllFoods(std::vector<Slime_Food>& foods) {

	// Pyro foods
	Slime_Food food1("Spicy Tomato Pizza", 10);
	Slime_Food food2("Charcoal Burger", 15);

	foods.push_back(food1);
	foods.push_back(food2);

	// Lightning foods
	Slime_Food food3("Lightning Lemonade", 10);
	Slime_Food food4("Crispy Lemon Pepper Chicken", 15);

	foods.push_back(food3);
	foods.push_back(food4);

	// Water foods
	Slime_Food food5("Seaweed Salad", 10);
	Slime_Food food6("Savory Tuna Melt", 15);

	foods.push_back(food5);
	foods.push_back(food6);

	// Ice foods
	Slime_Food food7("Sherbet Shaved Ice", 10);
	Slime_Food food8("Chilled Udon Noodles", 15);

	foods.push_back(food7);
	foods.push_back(food8);

	// Earth foods
	Slime_Food food9("Crunchy Veggie Straws", 10);
	Slime_Food food10("Spicy Vegetable Ramen", 15);

	foods.push_back(food9);
	foods.push_back(food10);

	// Light foods
	Slime_Food food11("Bright Berry Tart", 10);
	Slime_Food food12("Strawberry Swiss Roll", 15);

	foods.push_back(food11);
	foods.push_back(food12);

	// Dark foods
	Slime_Food food13("Shadow Macarons", 10);
	Slime_Food food14("Midnight Mushroom Stew", 15);

	foods.push_back(food13);
	foods.push_back(food14);

}





void checkWakeup(Slime* currSlime) {

	if (!currSlime->getIsSleeping()) {

		return;

	}

	time_t now = time(NULL);

	double elapsedSeconds = difftime(now, currSlime->getTimeWentToSleep());

	// If the time that has passed since the slime went to sleep is greater than the set value by the user, then the slime wakes up and gains energy value
	if (elapsedSeconds >= currSlime->getSleepDuration() * 60 * 60) {

		currSlime->SetIsSleeping(false);

		int slimeEnergyGain = ((elapsedSeconds / 3600) / 60) * 5;

		int max = 100, min = 0;

		int newValue = slimeEnergyGain + currSlime->getSlimeEnergyVal();

		newValue = std::clamp(newValue, min, max);

		currSlime->SetSlimeEnergyVal(newValue);

	}

}


int main(int argc, char* args[]) {


	Game_Driver gameDriver;


	while (1) {

		gameDriver.initMainWindow();


	}

	


	return 1;

}


/*
int main(int argc, char* args[]) {

	std::vector<Slime_Food> foods = {};

	LoadAllFoods(foods);

	Game_Driver driver;
	Slime baseSlime;


	bool OUTER_LOOP = true;
	bool INNER_LOOP = false;

	while (OUTER_LOOP) {

		DisplayHeader();

		DisplayOpenAppOptions();

		int mainChoice;

		std::cin >> mainChoice;
		std::cin.clear();
		std::cin.ignore(10000, '\n');


		// Load Save File
		if (mainChoice == 1) {

			if (loadSaveFile(&baseSlime, "SlimeSaveData.json")) {

				std::cout << "Slime Loaded Successfully!" << std::endl;

			}
			else {

				std::cout << "Could not find the save data!" << std::endl;
				continue;

			}

			INNER_LOOP = true;

		}
		// Create Save File
		else if (mainChoice == 2) {

			std::cout << "############################################################" << std::endl;
			std::cout << "############################################################" << std::endl;
			std::cout << "#          Please Enter the name of the Slime:             #" << std::endl;
			std::cout << "############################################################" << std::endl;
			std::cout << "############################################################" << std::endl;

			std::string name;
			std::cin >> name;
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			std::cout << "############################################################" << std::endl;
			std::cout << "############################################################" << std::endl;
			std::cout << "#          Please Select the type of the Slime:            #" << std::endl << std::endl;
			std::cout << "#          1. Pyro                                         #" << std::endl;
			std::cout << "#          2. Water                                        #" << std::endl;
			std::cout << "#          3. Ice                                          #" << std::endl;
			std::cout << "#          4. Electric                                     #" << std::endl;
			std::cout << "#          5. Earth                                        #" << std::endl;
			std::cout << "#          6. Light                                        #" << std::endl;
			std::cout << "#          7. Dark                                         #" << std::endl;
			std::cout << "############################################################" << std::endl;
			std::cout << "############################################################" << std::endl;

			SlimeType selectedType;

			int type;
			std::cin >> type;
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			if (type == 1) {

				selectedType = SlimeType::Pyro;

			}
			else if (type == 2) {

				selectedType = SlimeType::Water;

			}
			else if (type == 3) {

				selectedType = SlimeType::Ice;

			}
			else if (type == 4) {

				selectedType = SlimeType::Electric;

			}
			else if (type == 5) {

				selectedType = SlimeType::Earth;

			}
			else if (type == 6) {

				selectedType = SlimeType::Light;

			}
			else if (type == 7) {

				selectedType = SlimeType::Dark;

			}
			else {

				std::cout << "Bad input!" << std::endl;
				continue;

			}

			time_t now = time(NULL);

			baseSlime.SetSlimeName(name);
			baseSlime.SetSlimeAge(1);
			baseSlime.SetAliveStatus(true);
			baseSlime.SetIsSleeping(false);
			baseSlime.SetSlimeType(selectedType);
			baseSlime.SetSlimeHungerVal(100);
			baseSlime.SetSlimeHealthVal(100);
			baseSlime.SetSlimeEnergyVal(100);
			baseSlime.SetSlimeHappinessVal(100);
			baseSlime.SetSlimeMood(Mood::Happy);
			baseSlime.SetLastSeen(now);
			baseSlime.SetFavoriteFoods(foods);
			baseSlime.SetDislikedFoods(foods);
			

			if (createSaveFile(&baseSlime)) {

				std::cout << "Created Slime successfully!" << std::endl;

			}
			else {

				std::cout << "Could not create the slime!!!" << std::endl;

				continue;
			}

			INNER_LOOP = true;

		}
		// Exit App
		else if (mainChoice == 3) {

			std::cout << "Selected Option: Exit App!\n\n Exiting Application. Thank you for playing!" << std::endl;
			exit(1);

		}
		else {

			std::cout << "Bad Input! Relooping" << std::endl;
			continue;

		}

		while (INNER_LOOP) {

			checkWakeup(&baseSlime);

			// Now that we went through the load/create process, we need to display the main UI screen to the user
			DisplaySlimeMenu(&baseSlime);

			DisplayActionOptions();

			int actionChoice;

			std::cin >> actionChoice;


			if (actionChoice == 1) {

				//Display slime details

				DisplaySlimeDetails(&baseSlime);
				_getch();

			}

			// Feed Slime Action
			else if (actionChoice == 2) {

				if (baseSlime.getIsSleeping()) {

					std::cout << "Slime is currently sleeping! Cannot perform this action!" << std::endl;
					continue;

				}

				// First, we print out all food options to user

				DisplayFoodOptions(foods);

				// Then we prompt them for what food they want to feed the slime

				std::cout << "Please select the food you wish to feed your slime:" << std::endl;

				std::string foodName;

				std::cin >> foodName;

				Slime_Food selectedFood;

				bool foundFood = false;

				for (int k = 0; k < foods.size(); k++) {

					if (foodName == foods[k].getFoodName()) {

						selectedFood.setFoodName(foods[k].getFoodName());
						selectedFood.setFoodRegenValu(foods[k].getFoodRegenValu());

						baseSlime.FeedSlime(selectedFood);

						foundFood = true;

						break;

					}

				}

				if (!foundFood) {

					std::cout << "Food is not valid!" << std::endl;
					continue;

				}

			}

			// Play with slime to increase happiness
			else if (actionChoice == 3) {

				if (baseSlime.getIsSleeping()) {

					std::cout << "Slime is currently sleeping! Cannot perform this action!" << std::endl;
					continue;

				}

				baseSlime.PlayWithSlime();

			}


			// Lets Slime rest for certain period of time to regen energy
			else if (actionChoice == 4) {

				if (baseSlime.getIsSleeping()) {

					std::cout << "Slime is already sleeping! Cannot undo this! Wait until it wakes up!" << std::endl;
					continue;

				}


				// Displays the sleep time options to console
				DisplaySleepOptions();

				int userSleepChoice = 0;
				int timeToSleep = 0;

				std::cin >> userSleepChoice;

				if (userSleepChoice == 1) {

					timeToSleep = 1;
					std::cout << "User selected 1 hours of sleep!" << std::endl;
					baseSlime.RestSlime(timeToSleep);

				}
				else if (userSleepChoice == 2) {

					timeToSleep = 3;
					std::cout << "User selected 3 hours of sleep!" << std::endl;
					baseSlime.RestSlime(timeToSleep);

				}
				else if (userSleepChoice == 3) {

					timeToSleep = 6;
					std::cout << "User selected 6 hours of sleep!" << std::endl;
					baseSlime.RestSlime(timeToSleep);

				}
				else if (userSleepChoice == 4) {

					timeToSleep = 12;
					std::cout << "User selected 12 hours of sleep!" << std::endl;
					baseSlime.RestSlime(timeToSleep);

				}
				else {

					std::cout << "Invalid sleep time option! Returning to main loop!" << std::endl;
					continue;

				}

			}

			else if (actionChoice == 5) {

				//save and exit
				updateSaveFile(&baseSlime, "SlimeSaveData.json");

				std::ifstream fileToOpen("SlimeSaveData.json");

				if (!fileToOpen.is_open()) {

					std::cout << "Error opening the file to check if it saved correctly!" << std::endl;

					return false;
				}

				json inputData;

				fileToOpen >> inputData;

				fileToOpen.close();


				std::cout << inputData["lastSeen"] << std::endl;

				exit(1);


			}
			else {

				std::cout << "Bad Input!" << std::endl;
				continue;

			}
		}
	}
}
*/

