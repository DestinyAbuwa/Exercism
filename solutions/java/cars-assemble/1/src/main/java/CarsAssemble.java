public class CarsAssemble {
private final static int PRODUCTIONRATE = 221;
    
    public double productionRatePerHour(int speed) {
        double productionRatePerHour = 0.0;
        if (speed >= 1 && speed <=4){
            productionRatePerHour = PRODUCTIONRATE * speed;
        }
        else if (speed >= 5 && speed <=8){
            productionRatePerHour = PRODUCTIONRATE * speed * 0.9;
        }
        else if (speed == 9){
            productionRatePerHour = PRODUCTIONRATE * speed * 0.8;
        }
        else if (speed == 10){
            productionRatePerHour = PRODUCTIONRATE * speed * 0.77;
        }
        return productionRatePerHour;
    }

    public int workingItemsPerMinute(int speed) {
        return (int)(productionRatePerHour(speed) / 60);
    }
}
