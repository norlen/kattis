#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> t(n), q(m);
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < m; ++i) cin >> q[i];

    sort(t.rbegin(), t.rend());
    sort(q.rbegin(), q.rend());
    
    int can_complete = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (t[i] <= q[j]) {
            can_complete++;
            i++;
            j++;
        } else {
            i++;
        }
    }
    cout << can_complete << endl;
}