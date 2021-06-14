#include <iostream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int main() {
    int n;
    string in, name, tmp;
    while (true) {
        cin >> n;
        if (n == 0) break;
        getline(cin, in);

        map<string, set<string>> mp;

        for (int i = 0; i < n; ++i) {
            getline(cin, in);
            stringstream s;
            s << in;
            s >> name;
            while (s >> tmp) {
                if (mp.count(tmp) == 0) {
                    mp.insert({tmp, set<string>()});
                }
                mp[tmp].insert(name);
            }
        }

        for (auto& m : mp) {
            cout << m.first;
            for (auto& n : m.second) {
                cout << " " << n;
            }
            cout << endl;
        }
        cout << endl;
    }
}