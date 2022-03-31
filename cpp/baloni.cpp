#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int arrow_count = 0;
    unordered_map<int,int> arrows;
    for (int i = 0; i < heights.size(); ++i) {
        int h = heights[i];
        if (arrows[h] > 0) {
            arrows[h]--;
        } else {
            arrow_count++;
        }
        arrows[h-1]++;
    }

    cout << arrow_count << endl;
}
