#include <iostream>

using namespace std;

int main() {
    string b, k, a;
    cin >> b >> k;

    for (int i = 0; i < k.length() && i < b.length(); ++i) {
        a.push_back((b[i] - k[i] + 26) % 26 + 'A');
    }
    for (int i = k.length(); i < b.length(); ++i) {
        a.push_back((b[i] - a[i-k.length()] + 26) % 26 + 'A');
    }
    cout << a << endl;
}