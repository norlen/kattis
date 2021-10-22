#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string in, who, cutter;
    cin >> n;

    // Initial line.
    list<string> l;
    for (int i = 0; i < n; ++i) {
        cin >> in;
        l.push_back(in);
    }

    // Changes.
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> in;
        if (in == "leave") {
            cin >> who;
            l.remove(who);
        } else if (in == "cut") {
            cin >> cutter >> who;
            auto it = find(l.begin(), l.end(), who);
            l.insert(it, cutter);
        }
    }

    for (auto& s : l) {
        cout << s << endl;
    }
}