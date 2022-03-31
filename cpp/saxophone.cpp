#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    unordered_map<char, vector<int>> fingers;

    // c: finger 2-4, 7-10
    fingers['c'] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 1};

    // d: finger 2-4, 7-9
    fingers['d'] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 0};

    // e: finger 2-4, 7, 8
    fingers['e'] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 0};

    // f: finger 2-4, 7
    fingers['f'] = {0, 1, 1, 1, 0, 0, 1, 0, 0, 0};

    // g: finger 2-4
    fingers['g'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0};

    // a: finger 2, 3
    fingers['a'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0};

    // b: finger 2
    fingers['b'] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0};

    // C: finger 3
    fingers['C'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};

    // D: finger 1-4, 7-9
    fingers['D'] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0};

    // E: finger 1-4, 7, 8
    fingers['E'] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0};

    // F: finger 1-4, 7
    fingers['F'] = {1, 1, 1, 1, 0, 0, 1, 0, 0, 0};

    // G: finger 1-4
    fingers['G'] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};

    // A: finger 1-3
    fingers['A'] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

    // B: finger 1-2
    fingers['B'] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

    int n;
    cin >> n;
    string in;
    getline(cin, in);

    for (int i = 0; i < n; ++i) {
        vector<int> changes(10, 0);

        getline(cin, in);
        if (in.size() > 0) {
            auto& first = fingers[in[0]];
            for (int i = 0; i < 10; ++i) {
                if (first[i] > 0) {
                    changes[i] += 1;
                }
            }

            char prev_ch = in[0];
            for (int k = 1; k < in.size(); ++k) {
                auto& prev = fingers[prev_ch];
                auto& curr = fingers[in[k]];

                for (int i = 0; i < 10; ++i) {
                    if (curr[i] && prev[i] == 0) {
                        changes[i] += 1;
                    }
                }
                prev_ch = in[k];
            }
        }

        for (auto n : changes) {
            cout << n << " ";
        }
        cout << endl;
    }
}
