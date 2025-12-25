public class ExperimentalRemoteControlCar implements RemoteControlCar{
    int totalDistance = 0;
    final int DISTANCE = 20;
    
    public void drive() {
        totalDistance += DISTANCE;
    }

    public int getDistanceTravelled() {
        return totalDistance;
    }
}
