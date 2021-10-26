#include <iostream>
#include <iomanip>

using namespace std;
using ll = long long;

constexpr ll conv[7] = { 1000, 12, 3, 22, 10, 8, 3 };

int to_index(const string& s) {
    if (s == "thou" || s == "th") return 0;
    else if (s == "inch" || s == "in") return 1;
    else if (s == "foot" || s == "ft") return 2;
    else if (s == "yard" || s == "yd") return 3;
    else if (s == "chain" || s == "ch") return 4;
    else if (s == "furlong" || s == "fur") return 5;
    else if (s == "mile" || s == "mi") return 6;
    else if (s == "league" || s == "lea") return 7;
    return -1;
}

int main() {
    ll d;
    string source, tmp, dest;
    cin >> d >> source >> tmp >> dest;
    
    int s = to_index(source);
    int t = to_index(dest);
    ll mod = 1.0;
    for (int i = min(s, t); i < max(s, t); ++i) {
        mod *= conv[i];
    }

    if (s < t) {
        cout << fixed << setprecision(20) << ((long double)d/(long double)mod) << endl;
    } else {
        cout << (d*mod) << endl;
    }
}
