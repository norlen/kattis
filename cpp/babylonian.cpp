#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string in;
    getline(cin, in);

    for (int i = 0; i < n; ++i) {
        vector<ll> nums;
        getline(cin, in);
        stringstream ss;
        ss << in;

        int num = 0;
        char ch;
        while (ss >> ch) {
            if (ch == ',') {
                nums.push_back(num);
                num = 0;
            } else {
                int d = ch - '0';
                num *= 10;
                num += d;
            }
        }
        nums.push_back(num);

        ll ans = 0;
        ll mul = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            ans += nums[i] * mul;
            mul *= 60;
        }
        cout << ans << endl;
    }
}
