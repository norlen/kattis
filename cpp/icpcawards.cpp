#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> s;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        string t, n;
        cin >> t >> n;
        if (s.count(t) == 0) {
            s.insert(t);
            cout << t << " " << n << endl;
            c++;
            if (c == 12) break;
        }
    }
}