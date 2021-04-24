#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> m;

    for (int i = 0; i < 5; ++i) {
        string in;
        cin >> in;

        if (m.count(in[0]) == 0) m.insert({in[0], 0});
        m[in[0]] += 1;
    }

    int highest = 0;
    for (const auto kv : m) {
        highest = max(highest, kv.second);
    }
    cout << highest << endl;
}