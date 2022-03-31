#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in, person;
    int value;

    int day = 0;
    while (cin >> in) {
        while (in != "OPEN") {
            cin >> in;
        }
        day += 1;

        double PER_MIN = 0.1;

        unordered_map<string, int> enter;
        map<string, double> pay;

        while (cin >> in) {
            if (in == "CLOSE") break;

            if (in == "ENTER") {
                cin >> person >> value;
                enter[person] = value;
            }
            if (in == "EXIT") {
                cin >> person >> value;
                double diff = value - enter[person];
                pay[person] += diff * PER_MIN;
            }
        }

        cout << "Day " << day << endl;
        for (auto kv : pay) {
            cout << kv.first << " $" << fixed << setprecision(2) << pay[kv.first] << endl;
        }
        cout << endl;
    }


}
