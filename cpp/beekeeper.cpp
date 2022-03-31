#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    vector<bool> is_vowel(26, 0);
    is_vowel['a' - 'a'] = true;
    is_vowel['e' - 'a'] = true;
    is_vowel['i' - 'a'] = true;
    is_vowel['o' - 'a'] = true;
    is_vowel['u' - 'a'] = true;
    is_vowel['y' - 'a'] = true;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int max_count = -1;
        string best = "";
        for (int j = 0; j < n; ++j) {
            string in;
            cin >> in;

            int count = 0;
            for (int i = 1; i < in.size(); ++i) {
                if (is_vowel[in[i] - 'a'] && in[i] == in[i-1]) {
                    count += 1;
                    ++i;
                }
            }

            if (count > max_count) {
                max_count = count;
                best = in;
            }
        }

        cout << best << endl;
    }
}
