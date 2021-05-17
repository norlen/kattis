#include <iostream>
#include <cmath>
#include <iomanip>
#include <array>
#include <algorithm>

using namespace std;

constexpr int NUM_DIGITS = 9;
using pos = pair<int,int>;

int main() {
    array<pair<int,pos>, NUM_DIGITS> digits;
    for (int i = 0; i < NUM_DIGITS; ++i) {
        int d;
        cin >> d;
        digits[i] = {d, {i / 3, i % 3}};
    }
    sort(digits.begin(), digits.end());

    double distance = 0.0;
    for (int i = 1; i < NUM_DIGITS; ++i) {
        auto c = digits[i].second;
        auto p = digits[i-1].second;
        double dx = p.first - c.first;
        double dy = p.second - c.second;
        distance += sqrt(pow(dx, 2.0) + pow(dy, 2.0));
    }
    cout << fixed << setprecision(10) << distance << endl;
}