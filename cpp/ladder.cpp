#include <iostream>
#include <cmath>

int main() {
    int h, v;
    std::cin >> h >> v;
    std::cout << ceil(static_cast<float>(h)/sin(v*M_PI/180.f)) << std::endl;
}