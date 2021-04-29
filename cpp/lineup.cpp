#include <iostream>
#include <cmath>

using namespace std;
int clamp(int c, int _min, int _max) {
    return min(_max, max(_min, c));
}

int main() {
    int n;
    cin >> n;

    string prev, curr;
    cin >> prev;
    cin >> curr;
    int dir = clamp(curr.compare(prev), -1, 1);
    prev = std::move(curr);
    for (int i = 2; i < n; ++i) {
        cin >> curr;
        int d = clamp(curr.compare(prev), -1, 1);
        if (d != dir) {
            dir = 0;
            break;
        }
        prev = std::move(curr);
    }

    switch (dir) {
        case -1: cout << "DECREASING\n"; break;
        case  0: cout << "NEITHER\n"; break;
        case  1: cout << "INCREASING\n"; break;
    }
}