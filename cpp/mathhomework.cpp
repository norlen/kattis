#include <iostream>

using namespace std;

int main() {
    int b, c, d, l;
    cin >> b >> c >> d >> l;
    
    bool sol = false;
    for (int i = 0; i <= l/b+1; ++i) {
        for (int j = 0; j <= l/c+1; ++j) {
            for (int k = 0; k <= l/d+1; ++k) {
                if (i*b+j*c+k*d == l) {
                    sol = true;
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    if (!sol) {
        cout << "impossible\n";
    }
}