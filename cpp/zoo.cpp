#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, t = 1;
    string in;
    while (true) {
        cin >> n;
        if (n == 0) break;
        getline(cin, in);

        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            getline(cin, in);
            auto l = in.find_last_of(' ');
            if (l != string::npos) {
                in = in.substr(l+1);
            }
            for (auto& ch : in) {
                ch = tolower(ch);
            }

            if (mp.count(in) == 0) {
                mp.insert({in, 1});
            } else {
                mp[in] += 1;
            }
        }

        cout << "List " << t++ << ":\n";
        for (auto& m : mp) {
            cout << m.first << " | " << m.second << endl;
        }
    }
}