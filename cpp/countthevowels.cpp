#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in;
    getline(cin, in);

    array<bool, 26> is_vowel;
    for (int i = 0; i < 26; ++i) is_vowel[i] = false;
    is_vowel['a' - 'a'] = true;
    is_vowel['e' - 'a'] = true;
    is_vowel['i' - 'a'] = true;
    is_vowel['o' - 'a'] = true;
    is_vowel['u' - 'a'] = true;

    int count = 0;
    for (auto ch : in) {
        if (isalpha(ch) && is_vowel[tolower(ch) - 'a']) {
            count++;
        }
    }

    cout << count << endl;
}
