#include <iostream>
#include <array>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

// 0-9, +
constexpr size_t w = 5, h = 7;
constexpr size_t NUMS = 11;
const char* numsdef[NUMS] = {
    "xxxxxx...xx...xx...xx...xx...xxxxxx",
    "....x....x....x....x....x....x....x",
    "xxxxx....x....xxxxxxx....x....xxxxx",
    "xxxxx....x....xxxxxx....x....xxxxxx",
    "x...xx...xx...xxxxxx....x....x....x",
    "xxxxxx....x....xxxxx....x....xxxxxx",
    "xxxxxx....x....xxxxxx...xx...xxxxxx",
    "xxxxx....x....x....x....x....x....x",
    "xxxxxx...xx...xxxxxxx...xx...xxxxxx",
    "xxxxxx...xx...xxxxxx....x....xxxxxx",
    ".......x....x..xxxxx..x....x......."
};

int main() {
    // Tranpose nums and add checkup both ways.
    unordered_map<string, int> mp;
    unordered_map<int, string> mp2;
    for (int n = 0; n < NUMS; ++n) {
        string num;
        for (int c = 0; c < w; ++c) {
            for (int r = 0; r < h; ++r) {
                size_t idx = r * w + c;
                num.push_back(numsdef[n][idx]);
            }
        }
        mp.insert({num, n});
        mp2.insert({n, num});
    }

    // Get and parse input.
    array<string, h> input;
    for (int i = 0; i < h; ++i) {
        cin >> input[i];
    }

    ll n[2] = {0, 0};
    int curr = 0;
    for (int c = 0; c < (input[0].length()+1)/(w+1); ++c) {
        string s;
        for (int i = 0; i < w; ++i) {
            for (int r = 0; r < h; ++r) {
                s.push_back(input[r][(w+1)*c + i]);
            }
        }
        int digit = mp[s];
        if (digit == 10) {
            curr++;
        } else {
            n[curr] *= 10;
            n[curr] += digit;
        }
    }

    // Perform addition and get all digits.
    ll res = n[0] + n[1];
    vector<int> digits;
    while (res > 0) {
        digits.push_back(res % 10);
        res /= 10;
    }

    // Create output.
    array<string, h> out;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < digits.size()*(w+1)-1; ++j) {
            out[i].push_back('.');
        }
    }

    curr = 0;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        string& s = mp2[*it];
        int n = 0;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                out[j][curr * (w+1) + i] = s[n++];
            }
        }
        curr++;
    }
    
    for (auto& s : out) {
        cout << s << endl;
    }
}