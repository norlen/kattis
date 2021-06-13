#include <iostream>

using namespace std;

using ll = long long;

pair<ll,int> parse_hex(const string& s, size_t start) {
    ll val = 0;
    size_t i = start;
    // at most 0xffffffff.
    for (; i < s.length() && (i-start) < 8; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            val <<= 4;
            val += s[i] - '0';
        } else if ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F')) {
            val <<= 4;
            val += (tolower(s[i]) - 'a') + 10;
        } else {
            break;
        }
    }
    return {val, i};
}

int main() {
    string in;
    while (getline(cin, in)) {
        for (int i = 1; i < in.length(); ++i) {
            if ((in[i] == 'x' || in[i] == 'X') && in[i-1] == '0') {
                pair<ll,int> v = parse_hex(in, i+1);
                cout << in.substr(i-1, v.second-(i-1)) << " " << v.first << endl;
                i = v.second;
            }
        }
    }
}