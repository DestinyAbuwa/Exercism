#include "vehicle_purchase.h"

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    if (kind == "car" || kind == "truck"){
        return true;
    }
    else{
        return false;
    }
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    std::string better_choice = option1 < option2 ? option1 : option2;
    
    return better_choice + " is clearly the better choice.";
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    double discount = 1.0;
    if(age < 3){
        discount = 0.80;
    }
    else if (age >= 10){
        discount = 0.50;
    }
    else if(age >= 3 && age < 10){
        discount = 0.70;
    }
    return original_price * discount; 
}

}  // namespace vehicle_purchase
