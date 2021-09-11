#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int k, new_student;
        cin >> k;

        vector<int> s;
        constexpr size_t n = 20;
        int moves = 0;
        for (int i = 0; i < n; ++i) {
            cin >> new_student;
            int j = 0;
            for (; j < s.size(); ++j) {
                if (new_student < s[j]) break;
            }
            moves += s.size() - j;
            s.insert(s.begin()+j, new_student);
        }

        cout << k << " " << moves << endl;
    }
}