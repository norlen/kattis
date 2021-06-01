#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    cout << fixed << setprecision(1);

    for (int t = 0; t < cases; ++t) {
        int r;
        double p, d;
        cin >> r >> p >> d;
        double s = d / p;

        vector<pair<string, double>> in;
        double w;
        for (int i = 0; i < r; ++i) {
            string n;
            double o, p;
            cin >> n >> o >> p;
            in.push_back({n, p / 100.0});
            if (p == 100) {
                w = o * s;
            }
        }

        cout << "Recipe # " << t + 1 << endl;
        for (pair<string, double>& kv : in) {
            cout << kv.first << " " << kv.second * w << endl;
        }
        cout << "----------------------------------------\n";
    }
}