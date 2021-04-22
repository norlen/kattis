#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    for (int i = 0; i < n; ++i) {
        int b;
        double p;
        std::cin >> b >> p;

        std::cout << (b-1)*60.0/p << " " << b*60.0/p << " " << (b+1)*60.0/p << std::endl;
    }
}