#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) cin >> pos[i];

    for (int i = 0; i < q; ++i) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        // 1 C X, which means that company C moves its location to X, or
        // 2 A B, which is a query for the distance between companies A and B.
        if (cmd == 1) {
            pos[a-1] = b;
        } else {
            cout << abs(pos[a-1] - pos[b-1]) << endl;
        }
    }
}