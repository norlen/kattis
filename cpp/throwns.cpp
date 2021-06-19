#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m;
    string in;

    vector<int> pos(m);
    int undo = 0;
    int curr = 0;
    for (int i = 0; i < m; ++i) {
        cin >> in;
        if (in[0] != 'u') {
            t = stoi(in) % n;
            curr = (curr + t + n) % n;
            pos[undo++] = curr;
        } else {
            cin >> t;
            undo -= t;
            curr = pos[undo-1];
        }
    }
    cout << curr << endl;
}