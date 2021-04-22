#include <iostream>

bool is_valid(int n) {
    int sum = 0;
    int nn = n;
    while (nn > 0) {
        sum += nn % 10;
        nn /= 10;
    }
    return n % sum == 0;
}

int main() {
    int n;
    std::cin >> n;
    while (true) {
        if (is_valid(n)) {
            std::cout << n << std::endl;
            break;
        }
        n++;
    }
}