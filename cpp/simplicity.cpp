#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string in;
    cin >> in;

    vector<int> letters(26, 0);
    for (auto ch : in) {
        letters[ch - 'a']++;
    }

    int simplicity = 0;
    vector<int> counts;
    for (int i = 0; i < 26; ++i) {
        if (letters[i] > 0) {
            counts.push_back(letters[i]);
            simplicity++;
        }
    }
    sort(counts.rbegin(), counts.rend());

    int ans = 0;
    while (simplicity > 2) {
        ans += counts.back();
        counts.pop_back();
        simplicity--;
    }

    cout << ans << endl;
}
