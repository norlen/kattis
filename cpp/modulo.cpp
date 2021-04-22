#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> m;
    for (int i = 0; i < 10; ++i) {
        int n;
        std::cin >> n;
        m.insert({n % 42, 1});
    }
    std::cout << m.size() << std::endl;
}