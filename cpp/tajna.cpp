#include <iostream>
#include <vector>

using namespace std;

int main() {
    string in;
    cin >> in;
    
    // find row/col such that r <= c and r*c == n.
    int r = 0, c = 0, n = in.size();
    for (r = n; r >= 1; --r) {
        c = n / r;
        if (r <= c && r*c == n) {
            break;
        }
    }

    vector<string> g(r);
    for (int i = 0; i < n; ++i) {
        g[i%r].push_back(in[i]);
    }
    for (auto s : g) {
        cout << s;
    }
    cout << endl;
}