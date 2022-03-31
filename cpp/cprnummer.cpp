#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in;
    cin >> in;

    const int nums[11] = {4, 3, 2, 7, 6, 5, 0, 4, 3, 2, 1};
    int sum = 0;
    for (int i = 0; i < 11; ++i) {
        sum += (in[i] - '0') * nums[i];
    }

    cout << (sum % 11 == 0 ? "1" : "0") << endl;
}
