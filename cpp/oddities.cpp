#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int d;
        std::cin >> d;
        if (d % 2 == 0) {
            std::cout << d << " is even" << std::endl;
        } else {
            std::cout << d << " is odd" << std::endl;
        }
    }
}