public class SalaryCalculator {
    public double salaryMultiplier(int daysSkipped) {
        double salaryMultiplier = daysSkipped < 5 ? 1.0 : 0.85;
        return salaryMultiplier;
    }

    public int bonusMultiplier(int productsSold) {
        int bonusMultiplier = productsSold < 20 ? 10 : 13;
        return bonusMultiplier;
    }

    public double bonusForProductsSold(int productsSold) {
        return productsSold * bonusMultiplier(productsSold);
    }

    public double finalSalary(int daysSkipped, int productsSold) {
        double finalSalary = 1000.0 * salaryMultiplier(daysSkipped) + bonusForProductsSold(productsSold);
        return finalSalary < 2000.00 ? finalSalary : 2000.00;
    } 
}
