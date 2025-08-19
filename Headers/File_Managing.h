#pragma once
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "Headers/Slime.h"
#include "Headers/TextMsgs.h"


bool loadSaveFile(Slime* currSlime, std::string filepath);
bool createSaveFile(Slime* currSlime);
bool updateSaveFile(Slime* currSlime, std::string filepath);