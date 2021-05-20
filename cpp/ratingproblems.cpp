#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, k, c;
    cin >> n >> k;

    double r = 0;
    for (int i = 0; i < k; ++i) {
        cin >> c;
        r += c;
    }
    double m = n - k;
    cout << setprecision(10) << (r - m*3.0)/(double)n << " " << (r + m*3.0)/(double)n << endl;
}