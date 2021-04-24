#include <iostream>

using namespace std;

int dsum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int nsum = dsum(n);
        int t = 11;
        while (true) {
            int a = dsum(t * n);
            if (nsum == a) break;
            t++;
        }
        cout << t << endl;
    }
}