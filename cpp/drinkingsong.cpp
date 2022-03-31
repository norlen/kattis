#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string in;
    getline(cin, in);
    getline(cin, in);

    for (int i = n; i > 2; --i) {
        cout << i << " bottles of " << in << " on the wall, " << i << " bottles of " << in << ".\n";
        cout << "Take one down, pass it around, " << i-1 << " bottles of " << in << " on the wall.\n";
        cout << endl;
    }
    if (n > 1) {
        cout << "2 bottles of " << in << " on the wall, 2 bottles of " << in << ".\n";
        cout << "Take one down, pass it around, 1 bottle of " << in << " on the wall.\n";
        cout << endl;
    }

    cout << "1 bottle of " << in << " on the wall, 1 bottle of " << in << ".\n";
    cout << "Take it down, pass it around, no more bottles of " << in << ".\n";
}
