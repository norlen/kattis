#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in;
    cin >> in;

    unordered_map<char,char> counters;
    counters.insert({'R', 'S'});
    counters.insert({'B', 'K'});
    counters.insert({'L', 'H'});

    string out;
    int i = 0;
    while (i < in.size()) {
        int R_c = 0;
        int B_c = 0;
        int L_c = 0;
        for (int j = i; j < i+3 && j < in.size(); ++j) {
            if (in[j] == 'R') R_c++;
            if (in[j] == 'B') B_c++;
            if (in[j] == 'L') L_c++;
        }

        bool need_combo = R_c == 1 && B_c == 1 && L_c == 1;
        if (need_combo) {
            out.push_back('C');
            i += 3;
        } else {
            out.push_back(counters[in[i]]);
            i++;
        }
    }

    cout << out << endl;
}
