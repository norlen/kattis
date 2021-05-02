#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        long long c, n;
        cin >> c >> n;
        
        cout << c << " " << n*(n+1)/2 << " " << n*n << " " << n*(n+1) << endl;
    }
}