#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int d;
        std::cin >> d;

        int a = d--;
        for (; d > 0; --d) a *= d;
        std::cout << a % 10 << std::endl;
    }
}