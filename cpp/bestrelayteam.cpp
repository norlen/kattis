#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, pair<double,double>>> runners(n);
    for (int i = 0; i < n; ++i) {
        cin >> runners[i].first >> runners[i].second.first >> runners[i].second.second;
    }

    vector<pair<double, string>> first(4);
    sort(runners.begin(), runners.end(), [](const pair<string, pair<double,double>>& lhs, const pair<string, pair<double,double>>& rhs) {
        return lhs.second.first < rhs.second.first;
    });
    for (int i = 0; i < 4; ++i) {
        first[i] = {runners[i].second.first, runners[i].first};
    }
    
    vector<pair<double, string>> others(4);
    sort(runners.begin(), runners.end(), [](const pair<string, pair<double,double>>& lhs, const pair<string, pair<double,double>>& rhs) {
        return lhs.second.second < rhs.second.second;
    });
    for (int i = 0; i < 4; ++i) {
        others[i] = {runners[i].second.second, runners[i].first};
    }

    double lowest = 10000000.0;
    vector<string> team;
    for (int i = 0; i < 4; ++i) {
        vector<string> r;
        r.push_back(first[i].second);
        double t = first[i].first;

        int j = 0, chosen = 0;
        while (chosen < 3) {
            if (others[j].second != first[i].second) {
                r.push_back(others[j].second);
                t += others[j].first;
                chosen++;
            }
            j++;
        }

        if (t < lowest) {
            lowest = t;
            team = r;
        }
    }

    cout << fixed << setprecision(10) << lowest << endl;
    for (auto& r : team) {
        cout << r << endl;
    }
}