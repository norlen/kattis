#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T, n;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        cin >> n;
        vector<int> votes(n);

        int sum = 0;
        int max_votes = 0;
        int num_max_votes = 0;
        int max_idx = -1;
        for (int i = 0; i < n; ++i) {
            cin >> votes[i];
            sum += votes[i];
            if (votes[i] > max_votes) {
                max_votes = votes[i];
                num_max_votes = 1;
                max_idx = i;
            } else if (votes[i] == max_votes) {
                num_max_votes += 1;
            }
        }
        int half = sum / 2;

        if (num_max_votes > 1) {
            cout << "no winner\n";
        } else {
            if (max_votes > half) {
                cout << "majority winner " << max_idx+1 << endl;
            } else {
                cout << "minority winner " << max_idx+1 << endl;
            }
        }
    }
}