#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;
using ll = long long;

int main() {
    int m, n, a;
    string in;

    cin >> m >> n;
    
    unordered_map<string, ll> mp;
    for (int i = 0; i < m; ++i) {
        cin >> in >> a;
        mp.insert({in, a});
    }

    getline(cin, in);
    for (int i = 0; i < n; ++i) {
        ll tot = 0;
        while (getline(cin, in)) {
            if (in[0] == '.') break;
            stringstream s;
            s << in;
            string b;
            while (s >> b) {
                if (mp.count(b) > 0) {
                    tot += mp[b];
                }
            }

        }
        cout << tot << endl;
    }
}