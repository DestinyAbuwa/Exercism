#include <cmath>

const int BILLABLEHRS = 8;
const int BILLABLEDAYS = 22;

double daily_rate(double hourly_rate) {
    return hourly_rate * BILLABLEHRS;
}

double apply_discount(double before_discount, double discount) {
    return before_discount * (100 - discount)/100;
}

int monthly_rate(double hourly_rate, double discount) {
    return ceil(apply_discount(daily_rate(hourly_rate) * BILLABLEDAYS, discount));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    // TODO: Implement a function that takes a budget, an hourly rate, and a
    // discount, and calculates how many complete days of work that covers.
    return floor(budget / apply_discount(daily_rate(hourly_rate), discount));
}
