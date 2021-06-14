#include <iostream>

using namespace std;

int main() {
    int p, t;
    cin >> p >> t;

    string in;
    int c = 0;
    for (int i = 0; i < p; ++i) {
        bool not_ok = false;
        for (int j = 0; j < t; ++j) {
            cin >> in;
            if (not_ok) continue;

            for (int k = 1; k < in.length(); ++k) {
                if (in[k] >= 'a' && in[k] <= 'z') continue;
                
                not_ok = true;
                break;
            }
        }
        if (!not_ok) c++;
    }

    cout << c << endl;
}