#include <iostream>
#include <iomanip>

int main() {
    double c; // cost to sow one square meter
    int l; // num lawns
    std::cin >> c >> l;

    std::cout << std::fixed << std::setprecision(7);

    double area = 0.0;
    for (int i = 0; i < l; ++i) {
        double w, h;
        std::cin >> w >> h;
        area += w * h;
    }
    std::cout << area * c << std::endl;
}