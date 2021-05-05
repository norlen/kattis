#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> done(k);
    vector<set<int>> cols_to_class(m);
    vector<set<int>> class_to_cols(k);
    
    for (int i = 0; i < n; ++i) {
        string in;
        cin >> in;
        for (int j = 0; j < m; ++j) {
            int c = in[j] - 'A';
            cols_to_class[j].insert(c);
            class_to_cols[c].insert(j);
        }
    }

    int num_colors = 0;
    for (int i = 0; i < k; ++i) {
        if (done[i]) continue;
        done[i] = true;
        num_colors++;

        auto& cols_this_class = class_to_cols[i];
        // All columns this class is a part of.
        for (auto& column : class_to_cols[i]) {
            // Other classes in these columns.
            for (auto& oclass : cols_to_class[column]) {
                done[oclass] = true;
            }
        }

    }
    cout << num_colors << endl;
}
