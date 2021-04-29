#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;

int main() {
    string input;
    cin >> input;

    int zoom = input.length();
    ll w = (ll)pow(2, zoom);
    ll h = w;
    ll x = 0, y = 0;
    h /= 2;
    w /= 2;

    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];
        if (ch == '0') {
            // do nothing.
        } else if (ch == '1') {
            x += w;
        } else if (ch == '2') {
            y += h;
        } else {
            x += w;
            y += h;
        }
        h /= 2;
        w /= 2;
    }

    cout << zoom << " " << x << " " << y << endl;
}