#pragma once

#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

int uv_light_heuristic(std::vector<int>* data_array);

bool connection_check(pillar_men_sensor* ptr);

int activity_counter(pillar_men_sensor arr[], int capacity);

bool alarm_control(pillar_men_sensor* ptr);

bool uv_alarm(pillar_men_sensor* ptr);

}  // namespace speedywagon
