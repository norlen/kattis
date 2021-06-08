#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    bool f = false;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        if (!f) {
            f = true;
        } else {
            cout << endl;
        }

        vector<string> names(n);
        vector<pair<string, int>> sorted_names(n);
        for (int i = 0; i < n; ++i) {
            cin >> names[i];
            sorted_names[i] = {names[i].substr(0, 2), i};
        }
        stable_sort(sorted_names.begin(), sorted_names.end());

        for (auto& name : sorted_names) {
            cout << names[name.second] << endl;
        }
    }
}