#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T;
    ll nums[2];
    cin >> T;
    string in;
    getline(cin, in);

    for (int t = 0; t < T; ++t) {
        for (int i = 0; i < 2; ++i) {
            nums[i] = 0;
            getline(cin, in);
            // these are only 9 digits so this is fine
            for (auto ch : in) {
                if (isdigit(ch)) {
                    nums[i] *= 10;
                    nums[i] += ch - '0';
                }
            }
        }

        ll n = nums[0] + nums[1];
        string s;
        while (n > 0) {
            int d = n % 10;
            s.push_back(d + '0');
            n /= 10;
        }
        
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i) {
            cout << s[i] << (i == s.size()-1 ? "" : " ");
        }
        cout << endl;
    }
}
