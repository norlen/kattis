#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int num_marks = 28;
double mark_rad = M_PI * 2.0 / (double)(num_marks);
double radius = 30.0;
double pickup_time = 1.0;
double speed = 15.0;
double diam = radius*2*M_PI;

int get_ind(char ch) {
    if (ch == ' ') return 26;
    if (ch == '\'') return 27;
    return ch - 'A';
}

double char_to_rad(char ch) {
    double rad = (double)get_ind(ch) * mark_rad;
    return rad;
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
        double prev = char_to_rad(in[0]);
        for (int j = 1; j < in.length(); ++j) {
            double curr = char_to_rad(in[j]);
            double rad_diff = abs(curr - prev);
            double d = diam * rad_diff / (2*M_PI);
            cout << "in[p]=" << in[j-1] << " r=" << prev << " in[c]=" << in[j] << " r=" << curr << " diff=" << rad_diff << " dist=" << d << endl;
            prev = curr;
            distance += d;
        }
        double time = in.length() * pickup_time + distance / speed;
        cout << time << endl;
    }
}