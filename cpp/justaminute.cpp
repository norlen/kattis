#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    double mm, ss;
    for (int i = 0; i < n; ++i) {
        double m, s;
        cin >> m >> s;
        mm += m;
        ss += s;
    }
    double t = ss/mm/60.0;
    if (t <= 1.0) {
        cout << "measurement error\n";
    } else {
        cout << fixed << setprecision(10) << t << endl;
    }
}