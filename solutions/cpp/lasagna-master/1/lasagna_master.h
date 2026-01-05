#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int avgPrepTimePerLayer = 2);
lasagna_master::amount quantities(std::vector<std::string> layers);
void addSecretIngredient (std::vector<std::string>& myRecipe, const std::vector<std::string>& friendList);
void addSecretIngredient (std::vector<std::string>& myRecipe, std::string whisper);
std::vector<double> scaleRecipe(const std::vector<double> amount, int numOfPortions);
    
}  // namespace lasagna_master
