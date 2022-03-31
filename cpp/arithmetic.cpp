#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string to_hex(int num) {
    string ans;
    for (int i = 2; i >= 0; --i) {
        int d = (num >> (4*i)) & 0xF;
        if (d <= 9) {
            ans.push_back(d + '0');
        } else {
            ans.push_back(d - 10 + 'A');
        }
    }
    return ans;
}

int from_oct(const string& s, int start, int count) {
    int num = 0;
    for (int i = 0; i < count; ++i) {
        int shift = (count - i - 1) * 3;
        int n = (s[start+i] - '0');
        int nshifted = n << shift;
        num |= nshifted;
    }
    return num;
}

int main() {
    string in;
    cin >> in;

    // Octals are represented by 3 bits, hexadecimal by 4 bits.
    // If we store 4 octal numbers we git 24 bits, same as 3 hexadecimal numbers.

    int iters = in.size() / 4;
    int rem = in.size() % 4;

    string ans = "";
    if (rem > 0) {
        int h = from_oct(in, 0, rem);
        ans = to_hex(h);
    }

    for (int i = 0; i < iters; ++i) {
        int start = i * 4 + rem;
        int h = from_oct(in, start, 4);
        ans += to_hex(h);
    }

    for (int i = 0; i < ans.size(); ++i) {
        if (i == ans.size()-1 || ans[i] != '0') {
            cout << ans.substr(i) << endl;
            break;
        }
    }
}