#include "Headers/TextMsgs.h"
#include <format>

void DisplayHeader() {

	std::cout << "###############################################" << std::endl;
	std::cout << "###############################################" << std::endl;
	std::cout << "#         SlimaGatchi - CLI Edition           #" << std::endl;
	std::cout << "###############################################" << std::endl;
	std::cout << "###############################################\n\n\n\n" << std::endl;

}


void DisplayOpenAppOptions() {

	std::cout << "###############################################" << std::endl;
	std::cout << "###############################################" << std::endl;
	std::cout << "#      Please Select One of the Following:    #" << std::endl << std::endl;
	std::cout << "#      1. Load Save File                      #" << std::endl;
	std::cout << "#      2. Create/Load Save File               #" << std::endl;
	std::cout << "#      3. Exit App                            #" << std::endl;
	std::cout << "###############################################" << std::endl;
	std::cout << "###############################################\n\n\n\n" << std::endl;
}


void DisplaySlimeMenu(Slime* currSlime) {

	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################" << std::endl;
	std::cout << "#                        .------.                          #" << std::endl;
	std::cout << "#                       / (o o) \\                         #" << std::endl;
	std::cout << "#                      \\_______/                          #" << std::endl;
	std::cout << "############################################################" << std::endl;

	std::cout << " Slime Name: " << currSlime->getSlimeName() << std::endl;
	std::cout << " Hunger: " << currSlime->getSlimeHungerVal() << std::endl;
	std::cout << " Health: " << currSlime->getSlimeHealthVal() << std::endl;
	std::cout << " Energy: " << currSlime->getSlimeEnergyVal() << std::endl;
	std::cout << " Happiness: " << currSlime->getSlimeHappinessVal() << std::endl;

	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################\n\n\n\n" << std::endl;


}


void DisplaySlimeDetails(Slime* currSlime) {

	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################" << std::endl;
	std::cout << " Slime Name: " << currSlime->getSlimeName() << std::endl;
	std::cout << " Slime Age: " << currSlime->getSlimeName() << std::endl;
	std::cout << " Slime Type: " << currSlime->getType() << std::endl;
	std::cout << " Slime Mood: " << currSlime->getSlimeMood() << std::endl;
	std::cout << " Slime Alive Status: " << currSlime->getAliveStatus() << std::endl;
	std::cout << " Slime Sleeping Stati: " << currSlime->getIsSleeping() << std::endl;
	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################\n\n\n\n" << std::endl;

}

void DisplayActionOptions() {

	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################" << std::endl;
	std::cout << "#            Please Select One of the Following:           #" << std::endl << std::endl;
	std::cout << "#            1. Check Slime Details                        #" << std::endl;
	std::cout << "#            2. Feed Slime                                 #" << std::endl;
	std::cout << "#            3. Play With Slime                            #" << std::endl;
	std::cout << "#            4. Put Slime to Bed                           #" << std::endl;
	std::cout << "#            5. Save and Exit                              #" << std::endl;
	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################\n\n\n\n" << std::endl;

}

void DisplayFoodOptions(std::vector<Slime_Food> allFoods)
{
	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################" << std::endl;

	for (int i = 0; i < allFoods.size(); i++) {

		std::cout << (i + 1) << ". " << allFoods[i].getFoodName() << std::endl;

	}

	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################\n\n\n\n" << std::endl;

}

void DisplaySleepOptions()
{
	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################" << std::endl;
	std::cout << "#   Please Select How long your Slime should sleep for:    #" << std::endl << std::endl;
	std::cout << "#   1. 1 hour                                              #" << std::endl;
	std::cout << "#   2. 3 hours                                             #" << std::endl;
	std::cout << "#   3. 6 hours                                             #" << std::endl;
	std::cout << "#   4. 12 hours                                            #" << std::endl;
	std::cout << "############################################################" << std::endl;
	std::cout << "############################################################\n\n\n\n" << std::endl;

}
