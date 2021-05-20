#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string in;
    cin >> in;
    unordered_map<char, int> m;
    bool ok = true;
    for (auto ch : in) {
        if (m.count(ch) == 1) {
            ok = false;
            break;
        }
        m.insert({ch, 1});
    }

    cout << (ok ? 1 : 0) << endl;
}