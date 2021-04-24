#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int CALORIES = 400;
    for (int i = 0; i < n; ++i) {
        int target;
        cin >> target;
        cout << target / CALORIES + (target % CALORIES > 0 ? 1 : 0) << endl;
    }
}