// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#include <string>
#include "doctor_data.h"


namespace heaven{
        Vessel::Vessel(std::string name_, int gen, star_map::System sys){
            name = name_;
            generation = gen;
            current_system = sys;
        }
    
        Vessel Vessel::replicate (std::string name){
            return Vessel(name, generation + 1, current_system);
        }
    
        bool Vessel::shoot_buster(){
            if(busters > 0){
                --busters;
                return true;
            }
            else{
                return false;
            }
        }
    
        void Vessel::make_buster(){
            ++busters;
        }
    

    std::string get_older_bob(const Vessel& v1, const Vessel& v2){
        return v1.generation < v2.generation ? v1.name : v2.name;
    }
    
    bool in_the_same_system(const Vessel& v1, const Vessel& v2){
        return v1.current_system == v2.current_system;
    }
}


