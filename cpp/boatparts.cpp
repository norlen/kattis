#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int p, n;
    cin >> p >> n;

    unordered_set<string> s;
    int out = 0;
    for (int i = 1; i <= n; ++i) {
        string part;
        cin >> part;
        s.insert(part);
        if (s.size() >= p) {
            out = i;
            break;
        }
    }
    
    if (out > 0) {
        cout << out << endl;
    } else {
        cout << "paradox avoided\n";
    }
}