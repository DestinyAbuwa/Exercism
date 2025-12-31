
const int OVENTIME = 40;
const int LASAGNALAYERPREPTIME = 2;

int ovenTime() {
    return OVENTIME;
}


int remainingOvenTime(int actualMinutesInOven) {
    return OVENTIME - actualMinutesInOven;
}

int preparationTime(int numberOfLayers) {
    return numberOfLayers * LASAGNALAYERPREPTIME;
}

int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}
