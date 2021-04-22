#include <iostream>

int main() {
    std::string s;
    int d;
    std::cin >> s >> d;
    if ((s == "OCT" && d == 31) || (s == "DEC" && d == 25)) {
        std::cout << "yup\n";
    } else {
        std::cout << "nope\n";
    }
}