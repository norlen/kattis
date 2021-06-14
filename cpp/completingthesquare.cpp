#include <iostream>

using namespace std;

int distsq(pair<int,int> v) {
    return v.first*v.first + v.second*v.second;
}

int main() {
    pair<int,int> p[3];
    for (int i = 0; i < 3; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    pair<int,int> v[2];
    for (int i = 0; i < 2; ++i) {
        v[i].first = p[i+1].first - p[0].first;
        v[i].second = p[i+1].second - p[0].second;
    }

    if (distsq(v[0]) != distsq(v[1])) {
        if (distsq(v[0]) > distsq(v[1])) {
            v[1].first = -v[1].first;
            v[1].second = -v[1].second;
        } else {
            v[0].first = -v[0].first;
            v[0].second = -v[0].second;
        }
    }

    int x = p[0].first + v[0].first + v[1].first;
    int y = p[0].second + v[0].second + v[1].second;
    cout << x << " " << y << endl;
}