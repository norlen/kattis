#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int num_guests, curr;
        cin >> num_guests;
        int c = 0;
        for (int j = 0; j < num_guests; ++j) {
            cin >> curr;
            c ^= curr;
        }
        cout << "Case #" << i + 1 << ": " << c << endl;
    }
}