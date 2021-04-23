#include <iostream>

using namespace std;

int main() {
    int g, s, c;
    cin >> g >> s >> c;
    int bp = g * 3 + s * 2 + c;

    const char* ps[3] = { "Province", "Duchy", "Estate"};
    const char* ts[3] = { "Gold", "Silver", "Copper" };

    int p = -1;
    if (bp >= 8) p = 0;
    else if (bp >= 5) p = 1;
    else if (bp >= 2) p = 2;

    int t = 2;
    if (bp >= 6) t = 0;
    else if (bp >= 3) t = 1;

    if (p != -1) cout << ps[p] << " or ";
    cout << ts[t] << endl;
}