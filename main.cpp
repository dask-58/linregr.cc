#include <iostream>
#include <vector> 
#include <utility>

std::pair<double, double> f(std::vector<double>& hrs, std::vector<double>& scr, double slope, double c) {
    double n = hrs.size();
    double dm = 0.0, db = 0.0;
    for (int i = 0; i < n; i++) {
        double pre = slope * hrs[i] + c;
        dm += -2.0 * hrs[i] * (scr[i] - pre);
        db += -2.0 * (scr[i] - pre);
    }
    dm /= n;
    db /= n;
    return {dm, db};
}

int main() {
    double H;
    std::cout << "Enter no of hrs you studied\n";
    std::cin >> H;
    double learning_rate = 0.01;
    double slope = 0.0, c = 0.0;
    std::vector<double> hrs = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0,
                           1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
    std::vector<double> scr = {50.0, 60.0, 70.0, 75.0, 80.0, 85.0, 90.0, 92.0, 95.0, 98.0,
                           55.0, 65.0, 72.0, 78.0, 82.0, 87.0, 91.0, 93.0, 96.0, 99.0};
    for (int i = 0; i < 1000; i++) {
        std::pair<double, double> A = f(hrs, scr, slope, c);
        slope -= A.first * learning_rate;
        c -= A.second * learning_rate;
    }
    double ans = slope * H + c;
    std::cout << "Expected marks : \n" << ans << '\n';
    return 0;
}
