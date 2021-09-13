#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string in;
    unordered_map<string, string> m;

    while (getline(cin, in)) {
        if (in.size() == 0) break;
        auto sp = in.find(' ');
        m.insert({in.substr(sp+1), in.substr(0, sp)});
    }
    while (getline(cin, in)) {
        if (m.count(in) > 0) {
            cout << m[in] << endl;
        } else {
            cout << "eh\n";
        }
    }
}