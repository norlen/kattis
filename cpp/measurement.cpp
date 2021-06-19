#include <iostream>
#include <iomanip>

using namespace std;
using ll = long long;

constexpr int conv[7] = { 1000, 12, 3, 22, 10, 8, 3 };
int toidx(const string& s) {
    if (tolower(s[0]) == 'f' && tolower(s[1]) == 'u') {
        return 5;
    }

    switch (tolower(s[0])) {
        case 't': return 0;
        case 'i': return 1;
        case 'f': return 2;
        case 'y': return 3;
        case 'c': return 4;
        //case 'f': return 5;
        case 'm': return 6;
        case 'l': return 7;
    }
    return -1;
}

int main() {
    ll d;
    string source, tmp, dest;
    cin >> d >> source >> tmp >> dest;
    
    int s = toidx(source);
    int t = toidx(dest);
    int mod = 1;
    for (int i = min(s, t); i < max(s, t); ++i) {
        mod *= conv[i];
    }

    if (s < t) {
        cout << fixed << setprecision(14) << ((double)d/(double)mod) << endl;
    } else {
        cout << (d*mod) << endl;
    }
}