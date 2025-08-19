#include "Headers/File_Managing.h"


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
		currSlime->SettimeWentToSleep(inputData["timeWentToSleep"].get<time_t>());
		currSlime->SetSleepDuration(inputData["sleepDuration"].get<int>());

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
	newData["sleepDuration"] = currSlime->getSleepDuration();
	newData["timeWentToSleep"] = currSlime->getTimeWentToSleep();


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
		newData["sleepDuration"] = currSlime->getSleepDuration();
		newData["timeWentToSleep"] = currSlime->getTimeWentToSleep();

		fileToSave << newData.dump(4);


		fileToSave.close();

		return true;


	}

	else {

		std::cout << "Error saving file! File does not exist! Exiting save file process!" << std::endl;

	}

}