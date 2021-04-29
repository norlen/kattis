#include <iostream>
#include <vector>

using namespace std;

int main() {
    int set = 0;
    while (true) {
        set++;
        int n;
        cin >> n;
        if (n == 0) break;
        cout << "SET " << set << endl;

        vector<string> names;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            names.emplace_back(s);
        }

        for (int i = 0; i < n; i += 2) {
            cout << names[i] << endl;
        }
        int odd = names.size() % 2;
        for (int i = names.size() - 1 - odd; i >= 0; i -= 2) {
            cout << names[i] << endl;
        }
    }
}