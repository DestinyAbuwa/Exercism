class ProductionRemoteControlCar implements RemoteControlCar, Comparable<ProductionRemoteControlCar>{
    int totalDistance = 0;
    final int DISTANCE = 10;
    int numOfVictories = 0;
    
    public void drive() {
        totalDistance += DISTANCE;
    }

    public int getDistanceTravelled() {
        return totalDistance;
    }

    public int getNumberOfVictories() {
        return numOfVictories;
    }

    public void setNumberOfVictories(int numberOfVictories) {
        numOfVictories = numberOfVictories;
    }
    
    @Override
    public int compareTo(ProductionRemoteControlCar o){
        return Integer.compare(o.numOfVictories, this.numOfVictories);
    }
}
