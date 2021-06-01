#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    string cmd, p;
    unordered_set<string> s;
    for (int i = 0; i < n; ++i) {
        cin >> cmd >> p;

        if (cmd == "entry") {
            bool anomaly = s.count(p) > 0;
            s.insert(p);
            cout << p << " entered" << (anomaly ? " (ANOMALY)" : "") << endl;
        } else {
            bool anomaly = s.count(p) == 0;
            s.erase(p);
            cout << p << " exited" << (anomaly ? " (ANOMALY)" : "") << endl;
        }
    }
}