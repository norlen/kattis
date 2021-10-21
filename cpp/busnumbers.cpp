#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(b.begin(), b.end());

    cout << b[0]; // n >= 1.
    bool skip = false;
    for (int i = 1; i < n; ++i) {
        // Lies in-between.
        if (b[i-1]+1 == b[i] && i < n-1 && b[i+1] == b[i]+1) {
            skip = true;
            continue;
        }
        cout << (skip ? "-" : " ");
        cout << b[i];
        skip = false;
    }
    cout << endl;
}