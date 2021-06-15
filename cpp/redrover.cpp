#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> memo;
int len(const string& m, const string& s) {
    if (memo.count(m) > 0) {
        return memo[m];
    }

    int l = m.length();
    for (int i = 0; i < s.length(); ++i) {
        l++;
        if (s[i] == m[0]) {
            int j = i+1;
            int k = 1;
            while (k < m.length() && j < s.length()) {
                if (s[j] != m[k]) break;
                k++;
                j++;
            }
            if (k == m.length()) {
                i += m.length()-1;
            }
        }
    }

    memo.insert({m, l});
    return memo[m];
}

int main() {
    string s;
    cin >> s;

    int low = s.length();
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i+1; j < s.length(); ++j) {
            string ss = s.substr(i, j-i);
            low = min(low, len(ss, s));
        }
    }
    cout << low << endl;
}