#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int k, m, c, r, tmp;
    while (true) {
        cin >> k;
        if (k == 0) break;
        cin >> m;

        vector<int> courses(k);
        vector<unordered_set<int>> cats(m);
        vector<int> needs(m);
        int cats_ok = 0;

        for (int i = 0; i < k; ++i) cin >> courses[i];
        for (int i = 0; i < m; ++i) {
            cin >> c >> r;
            for (int j = 0; j < c; ++j) {
                cin >> tmp;
                cats[i].insert(tmp);
            }
            needs[i] = r;
            if (r == 0) cats_ok++;
        }

        for (auto c : courses) {
            for (int i = 0; i < cats.size(); ++i) {
                if (needs[i] > 0 && cats[i].count(c) > 0) {
                    needs[i]--;
                    if (needs[i] == 0) cats_ok++;
                }
            }
        }

        cout << (cats_ok == m ? "yes\n" : "no\n");
    }
}