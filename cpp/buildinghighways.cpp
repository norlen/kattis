#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> score(n);
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }
    sort(score.begin(), score.end());
    
    ll cost = 0;
    for (int i = 1; i < n; ++i) {
        cost += score[0] + score[i];
    }
    cout << cost << endl;
}
