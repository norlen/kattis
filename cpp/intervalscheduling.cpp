#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> is(n);
    for (int i = 0; i < n; ++i) {
        cin >> is[i].second >> is[i].first;
    }

    // Sort based on interval end, intervals are (end, start).
    sort(is.begin(), is.end());

    int non_overlap_count = 0;
    int ce = 0;
    for (int i = 0; i < is.size(); ++i) {
        if (is[i].second >= ce) {
            non_overlap_count++;
            ce = is[i].first;
        }
    }
    cout << non_overlap_count << endl;
}