#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int p, m, g;
    cin >> p >> m >> g;
    
    pair<int,int> dogs[2] = {{a, b}, {c, d}};
    int mins[3] = {p, m, g};
    for (int j = 0; j < 3; ++j) {
        int attacks = 0;
        for (int i = 0; i < 2; ++i) {
            int t = dogs[i].first + dogs[i].second;
            int m = mins[j] % t;
            if (m > 0 && m <= dogs[i].first) {
                attacks++;
            }
        }

        if (attacks == 0) cout << "none\n";
        else if (attacks == 1) cout << "one\n";
        else cout << "both\n";
    }
}