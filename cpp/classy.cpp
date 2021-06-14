#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int t = 0; t < cases; ++t) {
        int n;
        cin >> n;
        string name, classes, end;

        vector<pair<string, string>> people;
        for (int i = 0; i < n; ++i) {
            cin >> name >> classes >> end;

            int s = 0;
            string c = "";
            while (true) {
                int e = classes.find('-', s);
                string ss = classes.substr(s, e-s);
                int v = 3;
                if (ss == "upper") {
                    v = 1;
                } else if (ss == "middle") {
                    v = 2;
                }
                c.push_back('0' + v);
                if (e == string::npos) break;
                s = e + 1;
            }
            reverse(c.begin(), c.end());
            for (int j = c.length(); j < 20; ++j) {
                c.push_back('2');
            }
            people.push_back({c, name.substr(0, name.length()-1)});
        }

        sort(people.begin(), people.end());
        for (auto& kv : people) {
            cout << kv.second << endl;
        }
        for (int i = 0; i < 30; ++i) {
            cout << "=";
        }
        cout << endl;
    }
}