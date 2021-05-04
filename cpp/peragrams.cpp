#include <iostream>
#include <map>

using namespace std;

int main() {
    string in;
    cin >> in;
    map<char, int> s;
    for (auto ch : in) {
        if (s.count(ch) == 0) s.insert({ch, 0});
        s[ch] += 1;
    }

    int odd = 0;
    for (auto kv : s) {
        if (kv.second % 2 == 1) odd++;
    }
    if (odd > 0) odd--;
    cout << odd << endl;
}