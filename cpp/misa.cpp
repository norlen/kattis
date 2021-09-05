#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c;
    cin >> r  >> c;
    string tmp;
    getline(cin, tmp);

    vector<string> g(r);
    for (int i = 0; i < r; ++i) {
        getline(cin, g[i]);
    }

    pair<int,int> offsets[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    pair<int,int> offsets2[] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    
    int max_handshakes_on_empty = 0;
    int handshakes = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (g[i][j] == '.') {
                int shakes = 0;
                for (auto o : offsets) {
                    int ti = i + o.first;
                    int tj = j + o.second;
                    if (ti < 0 || ti >= r || tj < 0 || tj >= c) continue;
                    if (g[ti][tj] == 'o') {
                        shakes++;
                    }
                }
                max_handshakes_on_empty = max(max_handshakes_on_empty, shakes);
            } else {
                for (auto o : offsets2) {
                    int ti = i + o.first;
                    int tj = j + o.second;
                    if (ti < 0 || ti >= r || tj < 0 || tj >= c) continue;
                    if (g[ti][tj] == 'o') {
                        handshakes++;
                    }
                }
            }
        }
    }
    cout << max_handshakes_on_empty + handshakes << endl;
}