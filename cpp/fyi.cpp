#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;

    int conseqfives = 0;
    while (num > 0) {
        if (num % 10 == 5) conseqfives++;
        else conseqfives = 0;
        num /= 10;
    }
    cout << (conseqfives >= 3 ? "1\n" : "0\n");
}