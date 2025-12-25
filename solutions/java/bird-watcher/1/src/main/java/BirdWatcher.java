
class BirdWatcher {
    private final int[] birdsPerDay;

    public BirdWatcher(int[] birdsPerDay) {
        this.birdsPerDay = birdsPerDay.clone();
    }

    public int[] getLastWeek() {
        int[] lastWeekBirds = {0, 2, 5, 3, 7, 8, 4};
        return lastWeekBirds;
    }

    public int getToday() {
        return birdsPerDay[birdsPerDay.length - 1];  
    }

    public void incrementTodaysCount() {
        birdsPerDay[birdsPerDay.length - 1] = 1 + birdsPerDay[birdsPerDay.length - 1];
        
    }

    public boolean hasDayWithoutBirds() {
        boolean noBird = false;
        for (int bird : birdsPerDay)
            {
                if (bird == 0)
                    noBird = true;
            }
        return noBird;
    }

    public int getCountForFirstDays(int numberOfDays) {
        int sum = 0;
        for(int i = 0; i < numberOfDays; i++)
            {
                if (i < birdsPerDay.length)
                    sum +=birdsPerDay[i];
            }
        return sum;
    }

    public int getBusyDays() {
        int busyDayCount = 0;
        for(int birds : birdsPerDay)
            {
                if (birds >= 5)
                {
                    busyDayCount++;
                }
            }

        return busyDayCount;
    }
}
