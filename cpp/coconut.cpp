#include <iostream>
#include <list>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;

    list<pair<int,int>> p;
    for (int i = 0; i < n; ++i) p.push_back({0, i});

    auto it = p.begin();
    while (p.size() > 1) {
        for (int i = 0; i < s-1; ++i) {
            ++it;
            if (it == p.end()) it = p.begin();
        };

        if (it->first == 0) {
            // Split.
            it->first = 1;
            it = p.insert(it, {1, it->second});
        } else {
            // Add.
            it->first += 1;
            if (it->first == 3) {
                // Remove if out.
                p.erase(it++);
            } else {
                ++it;
            }
            if (it == p.end()) it = p.begin();
        }
    }
    cout << (p.begin()->second) + 1 << endl;
}