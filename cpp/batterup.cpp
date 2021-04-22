#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    int points = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a != -1) {
            count++;
            points += a;
        }
    }

    cout << static_cast<double>(points) / static_cast<double>(count) << endl;
}