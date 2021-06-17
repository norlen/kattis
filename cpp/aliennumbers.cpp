#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string snum, source, target;
        cin >> snum >> source >> target;

        unordered_map<char, int> sm;
        for (int i = 0; i < source.length(); ++i) {
            sm.insert({source[i], i});
        }
        int source_base = source.length();

        ll num = 0;
        for (int i = 0; i < snum.length(); ++i) {
            int d = sm[snum[i]];
            int o = snum.length() - i - 1;
            num += d * round(pow(source_base, o));
        }

        int target_base = target.length();
        string ans;
        while (num > 0) {
            int d = num % target_base;
            num /= target_base;
            ans = target[d] + ans;
        }

        cout << "Case #" << i+1 << ": " << ans << endl;
    }
}