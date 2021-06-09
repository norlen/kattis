#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

pair<int,int> find_indexes(const string& line, int count) {
    int start = 0;
    for (int i = 0; i < count; ++i) {
        start = line.find(' ', start) + 1;
    }
    int end = line.find(' ', start);
    if (end == string::npos) end = line.length();
    return {start, end};
}

int main() {
    string first, in;
    getline(cin, first);

    // Initial column listing.
    unordered_map<string, int> m;
    size_t s = 0;
    int idx = 0;
    while (true) {
        size_t e = first.find(' ', s);
        if (e == string::npos) {
            m.insert({first.substr(s, first.length()-s), idx});
            break;
        }
        m.insert({first.substr(s, e-s), idx});
        s = e+1;
        idx++;
    }
    
    // All rows.
    int n, n1;
    cin >> n;
    getline(cin, in);
    vector<string> lines(n);
    for (int i = 0; i < n; ++i) getline(cin, lines[i]);

    // Which fields to sort by.
    cin >> n1;
    vector<int> sorts(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> in;
        sorts[i] = m[in];
    };

    // Sort and display.
    for (int k = 0; k < sorts.size(); ++k) {
        int i = sorts[k];
        stable_sort(lines.begin(), lines.end(), [i](const string& lhs, const string& rhs) {
            auto ai = find_indexes(lhs, i);
            auto bi = find_indexes(rhs, i);

            string a = lhs.substr(ai.first, ai.second-ai.first);
            string b = rhs.substr(bi.first, bi.second-bi.first);
            return a < b;
        });

        cout << first << endl;
        for (auto& l : lines) {
            cout << l << endl;
        }
        if (k != sorts.size()-1) cout << endl;
    }
}