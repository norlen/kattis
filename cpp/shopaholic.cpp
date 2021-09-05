#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
    }
    sort(items.rbegin(), items.rend());

    long long discount = 0;
    for (int i = 2; i < n; i += 3) {
        discount += items[i];
    }
    cout << discount << endl;
}