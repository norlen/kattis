#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num, a;
        cin >> num;
        int sum = 0;
        for (int j = 0; j < num; ++j) {
            cin >> a;
            sum += a - 1;
        }
        cout << sum + 1 << endl;
    }
}