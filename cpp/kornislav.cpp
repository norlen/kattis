#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    auto sides = vector<int>(4);
    cin >> sides[0] >> sides[1] >> sides[2] >> sides[3];
    sort(sides.begin(), sides.end());
    cout << sides[0]*sides[2] << endl;
}