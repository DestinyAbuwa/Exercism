class NeedForSpeed {
    public int speed_, batteryDrain_, totalDistance, percentage;
    
    NeedForSpeed(int speed, int batteryDrain) {
        speed_ = speed;
        batteryDrain_ = batteryDrain;
        percentage = 100;
    }

    public boolean batteryDrained() {
        return percentage < batteryDrain_;
    }

    public int distanceDriven() {
        return totalDistance;
    }

    public void drive() {
        if (!batteryDrained()){
            totalDistance += speed_;
            percentage -= batteryDrain_;
        }
        
    }

    public static NeedForSpeed nitro() {
        return new NeedForSpeed(50, 4);
    }
}

class RaceTrack {
    public int distance_;
    
    RaceTrack(int distance) {
        distance_ = distance;
    }

    public boolean canFinishRace(NeedForSpeed car) {
        return ((((double)distance_ / car.speed_) * car.batteryDrain_) <= car.percentage);
    }
}
