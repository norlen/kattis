#include <iostream>

int main() {
    int n, r, e, c;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> r >> e >> c;
        int a = e - c;
        if (a > r) {
            std::cout << "advertise\n";
        } else if (r == a) {
            std::cout << "does not matter\n";
        } else {
            std::cout << "do not advertise\n";
        }
    }
}