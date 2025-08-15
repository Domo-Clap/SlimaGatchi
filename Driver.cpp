#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <nlohmann/json.hpp>
#include <windows.h>
#include <vector>
#include <fstream>
#include <filesystem>

#include "Headers/Game_Driver.h"
#include "Headers/Slime.h"
#include "Headers/TextMsgs.h"


using json = nlohmann::json;
namespace fs = std::filesystem;


bool loadSaveFile(Slime* currSlime, std::string filepath) {

	if (fs::exists(filepath)) {

		// We want to open the file in the filePath
		std::ifstream fileToOpen(filepath);

		if (!fileToOpen.is_open()) {

			std::cout << "Error opening the file!" << std::endl;

			return false;
		}

		json inputData;

		fileToOpen >> inputData;

		fileToOpen.close();

		currSlime->SetSlimeName(inputData["SlimeName"].get<std::string>());
		currSlime->SetSlimeAge(inputData["SlimeAge"].get<int>());
		currSlime->SetSlimeType(inputData["SlimeType"].get<SlimeType>());
		currSlime->SetSlimeHungerVal(inputData["Values"]["HungerVal"].get<int>());
		currSlime->SetSlimeHealthVal(inputData["Values"]["HealthVal"].get<int>());
		currSlime->SetSlimeEnergyVal(inputData["Values"]["EnergyVal"].get<int>());
		currSlime->SetSlimeHappinessVal(inputData["Values"]["HappinessVal"].get<int>());
		currSlime->SetSlimeMood(inputData["Mood"].get<Mood>());
		currSlime->SetAliveStatus(inputData["AliveStatus"].get<bool>());
		currSlime->SetIsSleeping(inputData["isSleeping"].get<bool>());
		currSlime->SetLastSeen(inputData["lastSeen"].get<time_t>());

		currSlime->SlimeStatDecay();

		currSlime->SetLastSeen(std::time(NULL));

		std::cout << "Save Data loaded successfully!" << std::endl;

		return true;

	}
	else {

		std::cout << "File does not exist. No slime to load!" << std::endl;
		return false;

	}


}

bool createSaveFile(Slime* currSlime) {

	json newData;

	newData["SlimeName"] = currSlime->getSlimeName();
	newData["SlimeAge"] = currSlime->getSlimeAge();
	newData["SlimeType"] = currSlime->getType();
	newData["Values"]["HungerVal"] = currSlime->getSlimeHungerVal();
	newData["Values"]["HealthVal"] = currSlime->getSlimeHealthVal();
	newData["Values"]["EnergyVal"] = currSlime->getSlimeEnergyVal();
	newData["Values"]["HappinessVal"] = currSlime->getSlimeHappinessVal();
	newData["Mood"] = currSlime->getSlimeMood();
	newData["AliveStatus"] = currSlime->getAliveStatus();
	newData["isSleeping"] = currSlime->getIsSleeping();
	newData["lastSeen"] = currSlime->getLastSeen();



	std::ofstream saveFile;
	std::string fileName = "SlimeSaveData.json";

	if (fs::exists(fileName)) {

		std::cout << "File already exists! Confirm whether file should be deleted and overwritten." << std::endl;

		std::cout << "Do you wish to delete your old Save File, and create a new one? (y/n)" << std::endl;

		char choice;

		std::cin >> choice;

		if (choice == 'y' || choice == 'Y') {

			if (fs::remove(fileName)) {

				std::cout << "Previous save file has been deleted!\n\n Making new save file now!" << std::endl;

				saveFile.open(fileName);

				if (!saveFile.is_open()) {


					std::cout << "Error creating file!" << std::endl;

					return false;

				}

				std::cout << "Save File created successfully!" << std::endl;

				saveFile << newData.dump(4);
				saveFile.close();

				return true;

			}
			else {

				std::cout << "Failed to delete old save file!" << std::endl;

				return false;

			}

		}
		else if (choice == 'n' || choice == 'N') {

			std::cout << "Previous save file has not been deleted!\n\n Exiting creation process now!" << std::endl;
			return false;

		}
		else {

			std::cout << "Invalid Response! Exiting create/overwrite process!" << std::endl;

		}

	}
	else {

		std::cout << "Save file does not already exist! Creating new file from scratch!" << std::endl;

		saveFile.open(fileName);

		if (!saveFile.is_open()) {


			std::cout << "Error creating file!" << std::endl;

			return false;


		}

		std::cout << "Save File created successfully!" << std::endl;

		saveFile << newData.dump(4);


		saveFile.close();

		return true;

	}

}


bool updateSaveFile(Slime* currSlime, std::string filepath) {

	std::ofstream fileToSave;

	if (fs::exists(filepath)) {

		fileToSave.open(filepath);

		if (!fileToSave.is_open()) {

			std::cout << "Error saving file!" << std::endl;

			return false;

		}

		json newData;

		newData["SlimeName"] = currSlime->getSlimeName();
		newData["SlimeAge"] = currSlime->getSlimeAge();
		newData["SlimeType"] = currSlime->getType();
		newData["Values"]["HungerVal"] = currSlime->getSlimeHungerVal();
		newData["Values"]["HealthVal"] = currSlime->getSlimeHealthVal();
		newData["Values"]["EnergyVal"] = currSlime->getSlimeEnergyVal();
		newData["Values"]["HappinessVal"] = currSlime->getSlimeHappinessVal();
		newData["Mood"] = currSlime->getSlimeMood();
		newData["AliveStatus"] = currSlime->getAliveStatus();
		newData["isSleeping"] = currSlime->getIsSleeping();
		newData["lastSeen"] = std::time(NULL);

		fileToSave << newData.dump(4);


		fileToSave.close();

		return true;


	}

	else {

		std::cout << "Error saving file! File does not exist! Exiting save file process!" << std::endl;

	}

}




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




int main(int argc, char* args[]) {

	std::vector<Slime_Food> foods = {};

	LoadAllFoods(foods);

	Game_Driver driver;
	Slime baseSlime;

	while (1) {


		DisplayHeader();

		DisplayOpenAppOptions();

		int mainChoice;

		std::cin >> mainChoice;

		// Load Save File
		if (mainChoice == 1) {

			if (loadSaveFile(&baseSlime, "SlimeSaveData.json")) {

				std::cout << "Slime Loaded Successfully!" << std::endl;

			}
			else {

				std::cout << "Could not find the save data!" << std::endl;
				return 0;

			}

		}
		// Create Save File
		else if (mainChoice == 2) {

			std::cout << "############################################################" << std::endl;
			std::cout << "############################################################" << std::endl;
			std::cout << "#          Please Enter the name of the Slime:             #" << std::endl;
			std::cout << "############################################################" << std::endl;
			std::cout << "############################################################" << std::endl;

			std::string name;
			std::getline(std::cin, name);


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


			if (type == 1) {

				selectedType = Pyro;

			}
			else if (type == 2) {

				selectedType = Water;

			}
			else if (type == 3) {

				selectedType = Ice;

			}
			else if (type == 4) {

				selectedType = Electric;

			}
			else if (type == 5) {

				selectedType = Earth;

			}
			else if (type == 6) {

				selectedType = Light;

			}
			else if (type == 7) {

				selectedType = Dark;

			}
			else {

				std::cout << "Bad input!" << std::endl;
				return 0;

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
			baseSlime.SetSlimeMood(Happy);
			baseSlime.SetLastSeen(now);
			baseSlime.SetFavoriteFoods(foods);
			baseSlime.SetDislikedFoods(foods);
			

			if (createSaveFile(&baseSlime)) {

				std::cout << "Created Slime successfully!" << std::endl;

			}
			else {

				std::cout << "Could not create the slime!!!" << std::endl;

				return 0;
			}

		}
		// Exit App
		else if (mainChoice == 3) {

			std::cout << "Selected Option: Exit App!\n\n Exiting Application. Thank you for playing!" << std::endl;
			exit(1);

		}
		else {

			std::cout << "Bad Input! Relooping" << std::endl;

		}


		// Now that we went through the load/create process, we need to display the main UI screen to the user
		DisplaySlimeMenu(&baseSlime);


		DisplayActionOptions();

		int actionChoice;

		std::cin >> actionChoice;

		if (actionChoice == 1) {

			//Display slime details

		}
		else if (actionChoice == 2) {

			//Feed the slime

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

			}

		}
		else if (actionChoice == 3) {

			baseSlime.PlayWithSlime();

		}
		else if (actionChoice == 4) {

			//slime rest

		}
		else if (actionChoice == 5) {

			//save and exit

			// Need to call the updateSaveFile function
			// Then ensure the save file was updated by printing out the json data that was saved down

			
			
			exit(1);


		}
		else {

			std::cout << "Bad Input!" << std::endl;
			return 0;

		}

	}

}


