#include "power_of_troy.h"

namespace troy {
    
void give_new_artifact(human& h, std::string str){
    h.possession = std::make_unique<artifact>(str);
}

void exchange_artifacts(std::unique_ptr<artifact>& ptr1, std::unique_ptr<artifact>& ptr2){
    std::swap(ptr1, ptr2);
}

void manifest_power(human& h, std::string str){
    h.own_power = std::make_shared<power>(str);
}

void use_power(human& caster, human& target){
    target.influenced_by = caster.own_power;
}

int power_intensity(human& h){
    if (h.own_power == nullptr) {
        return 0;
    }
    return h.own_power.use_count();
}
    
}  // namespace troy
