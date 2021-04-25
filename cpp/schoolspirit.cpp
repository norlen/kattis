#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double calc_score(vector<int>& scores, int skip) {
    int pow = 0;
    double score = 0.0;
    for (int i = 0; i < scores.size(); ++i) {
        if (i != skip) {
            score += static_cast<double>(scores[i]) * powf64(0.8, static_cast<double>(pow));
            pow++;
        }
    }
    score /= 5.0;
    return score;
}

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(8);

    auto scores = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> scores[i];

    double avgscore = 0.0;
    for (int skip = 0; skip < n; ++skip) {
        avgscore += calc_score(scores, skip);
    }
    avgscore /= static_cast<double>(n);

    cout << calc_score(scores, -1) << endl;
    cout << avgscore << endl;
}