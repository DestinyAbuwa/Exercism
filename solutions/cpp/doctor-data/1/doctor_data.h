// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#pragma once
#include <string>


namespace star_map{
    enum class System{
        Sol, BetaHydri, EpsilonEridani, AlphaCentauri, DeltaEridani, Omicron2Eridani
    };
}

namespace heaven{
    class Vessel{
        public:
        star_map::System current_system;
        std::string name;
        int generation;
        int busters = 0;
    
        Vessel(std::string name_, int gen, star_map::System sys = star_map::System::Sol);
        Vessel replicate (std::string name);
        bool shoot_buster();
        void make_buster();
    };

    std::string get_older_bob(const Vessel& v1, const Vessel& v2);
    bool in_the_same_system(const Vessel& v1, const Vessel& v2);
}


