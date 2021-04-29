#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int precincts, districts;
    cin >> precincts >> districts;
    cout << fixed << setprecision(10);

    vector<pair<int,int>> dists(districts);
    for (auto& d : dists) {
        d = {0,0};
    }

    for (int i = 0; i < precincts; ++i) {
        int d, a, b;
        cin >> d >> a >> b;

        dists[d-1].second += b;
        dists[d-1].first += a;
    }

    int wA = 0;
    int wB = 0;
    int votes = 0;
    for (auto d : dists) {
        int A = d.first;
        int B = d.second;
        int T = A + B;

        int needed = (A + B) / 2 + 1;
        int wastedA = 0, wastedB = 0;
        if (A > B) {
            wastedB = B;
            wastedA = A - needed;
        } else {
            wastedA = A;
            wastedB = B - needed;
        }

        wA += wastedA;
        wB += wastedB;
        votes += T;
        cout << (d.first > d.second ? "A" : "B") << " " << wastedA << " " << wastedB << endl;
    }

    double eff = abs((double)wA - (double)wB) / (double)(votes);
    cout << eff << endl;
}