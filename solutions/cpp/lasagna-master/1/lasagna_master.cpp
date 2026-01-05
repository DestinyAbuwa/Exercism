#include "lasagna_master.h"
#include <string>
#include <vector>

namespace lasagna_master {


int preparationTime(std::vector<std::string> layers, int avgPrepTimePerLayer){
    return layers.size() * avgPrepTimePerLayer;
}

lasagna_master::amount quantities(std::vector<std::string> layers){
    const int gramsNoodlesPerLayer = 50;
    const double litersSaucePerLayer = 0.2;
    int countSauce = 0;
    int countNoodles = 0;
    
    for(std::string layer : layers){
        if(layer == "sauce"){
            ++countSauce;
        }
        else if(layer == "noodles"){
            ++countNoodles;
        }
    }
    
    return amount{countNoodles * gramsNoodlesPerLayer, countSauce * litersSaucePerLayer};  
}

void addSecretIngredient (std::vector<std::string>& myRecipe, const std::vector<std::string>& friendList){
    for(std::string& ingredient : myRecipe){
        if(ingredient == "?"){
            ingredient = friendList.back();
        }
    }
}

std::vector<double> scaleRecipe(const std::vector<double> amount, int numOfPortions){
    std::vector<double> scaled;
    for(double quantity : amount){
        scaled.push_back((quantity/2) * numOfPortions);
    }
    return scaled;
}

void addSecretIngredient (std::vector<std::string>& myRecipe, std::string whisper){
    for(std::string& ingredient : myRecipe){
        if(ingredient == "?"){
            ingredient = whisper;
        }
    }
}
}  // namespace lasagna_master
