#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

const string keyboard[3] = {
    "qwertyuiop",
    "asdfghjkl",
    "zxcvbnm",
};

int main() {
    unordered_map<char, pair<int,int>> keys;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < keyboard[i].length(); ++j) {
            keys.insert({keyboard[i][j], {i, j}});
        }
    }

    int p, n;
    cin >> p;

    for (int i = 0; i < p; ++i) {
        string word, curr;
        cin >> word >> n;

        vector<pair<int,int>> ds(word.length());
        for (int j = 0; j < word.length(); ++j) {
            ds[j] = keys[word[j]];
        }

        vector<pair<int, string>> words(n);
        for (int j = 0; j < n; ++j) {
            cin >> curr;
            int md = 0;
            for (int k = 0; k < curr.length(); ++k) {
                pair<int,int> pos = keys[curr[k]];
                md += abs(pos.first - ds[k].first) + abs(pos.second - ds[k].second);
            }

            words[j] = {md, curr};
        }

        sort(words.begin(), words.end());

        for (pair<int, string>& w : words) {
            cout << w.second << " " << w.first << endl;
        }
    }
}