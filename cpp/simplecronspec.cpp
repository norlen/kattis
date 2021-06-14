#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> parse(const string& str) {
    vector<int> r;
    int s = 0;
    while (true) {
        int e = str.find(',', s);
        string ss = str.substr(s, e-s);
        int c = ss.find('-');
        if (c != string::npos) {
            int lhs = stoi(ss.substr(0, c));
            int rhs = stoi(ss.substr(c+1));
            for (int i = lhs; i <= rhs; ++i) r.push_back(i);
        } else {
            r.push_back(stoi(ss));
        }
        if (e == string::npos) break;
        s = e+1;
    }
    return r;
}

int main() {
    int n;
    cin >> n;

    vector<int> H(24);
    vector<int> MS(60);
    for (int i = 0; i < 24; ++i) H[i] = i;
    for (int i = 0; i < 60; ++i) MS[i] = i;

    unordered_set<int> secs;
    string h, m, s;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h >> m >> s;
        auto hh = h[0] == '*' ? H : parse(h);
        auto mm = m[0] == '*' ? MS : parse(m);
        auto ss = s[0] == '*' ? MS : parse(s);
        
        for (auto a : hh) {
            for (auto b : mm) {
                for (auto c : ss) {
                    total++;
                    secs.insert({a * 60*60 + b*60 + c});
                }
            }
        }
    }

    cout << secs.size() << " " << total << endl;
}