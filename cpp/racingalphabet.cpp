#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int NUM_MARKS = 28;
const double RAD_PER_IND = 2.0 * M_PI / 28.0;
const double PICKUP_TIME = 1.0;
const double SPEED = 15.0;
const double DIST_PER_RAD = 30.0;

int get_ind(char ch) {
    if (ch == ' ') return 26;
    if (ch == '\'') return 27;
    return ch - 'A';
}

int main() {
    int n;
    cin >> n;
    string in;
    getline(cin, in);

    for (int i = 0; i < n; ++i) {
        string in;
        getline(cin, in);

        double distance = 0.0;
        int prev = get_ind(in[0]);
        for (int j = 1; j < in.length(); ++j) {
            int curr = get_ind(in[j]);
            int diff = abs(prev - curr);
            if (diff > 14) diff = NUM_MARKS - diff;

            double ran = DIST_PER_RAD * (RAD_PER_IND * (double)diff);
            prev = curr;
            distance += ran;
        }
        double time = in.length() * PICKUP_TIME + distance / SPEED;
        cout << fixed << setprecision(10) << time << endl;
    }
}