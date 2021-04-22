#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 's' && s[i-1] == 's') {
            std::cout << "hiss\n";
            return 0;
        }
    }
    std::cout << "no hiss\n";
}