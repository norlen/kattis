#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "Alice\n1\n";
    } else {
        cout << "Bob\n";
    }
}