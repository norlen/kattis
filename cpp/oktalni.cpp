#include <iostream>

using namespace std;

int main() {
    string in;
    cin >> in;
    while (in.length() % 3 != 0) {
        in = '0' + in;
    }
    
    int ans = 0;
    for (int i = 0; i < in.length()/3; ++i) {
        int n = 0;
        for (int j = 0; j < 3; ++j) {
            if (in[i*3+j] == '1') {
                n += (1 << (2-j));
            }
        }
        cout << n;
    }
    cout << endl;
}