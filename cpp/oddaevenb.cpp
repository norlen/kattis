#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    constexpr ll MOD = 1000000007;

    vector<pair<ll, ll>> dp(n+3, {0, 0});
    dp[1] = {1, 0};
    dp[2] = {0, 1};

    // All ways we can generate the strings.
    //     a -> bb
    //       -> aa
    //    bb -> bb
    //       -> a
    for (int i = 3; i <= n; ++i) {
        dp[i].first += dp[i-2].first + dp[i-1].second; // Add either a, or aa.
        dp[i].second += dp[i-2].first + dp[i-2].second; // Add bb to both ways.
        dp[i].first %= MOD;
        dp[i].second %= MOD;
    }
    
    cout << (dp[n].first + dp[n].second) % MOD << endl;
}
