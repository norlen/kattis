#include <iostream>
#include <vector>

using namespace std;

int main() {
    constexpr int n = 5;
    vector<string> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    int knights = 0;
    pair<int,int> moves[8] = {{2,1}, {-2,1}, {2,-1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j] == 'k') {
                knights++;
                for (pair<int,int> m : moves) {
                    int r = i + m.first;
                    int c = j + m.second;
                    if (r < 0 || r >= n || c < 0 || c >= n) continue;
                    if (b[r][c] == 'k') {
                        cout << "invalid\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << (knights == 9 ? "valid\n" : "invalid\n");
}