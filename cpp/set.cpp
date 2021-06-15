#include <iostream>

using namespace std;

int main() {
    string s[12];
    for (int i = 0; i < 12; ++i) cin >> s[i];

    int found = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = i+1; j < 12; ++j) {
            for (int k = j+1; k < 12; ++k) {
                int same = 0;
                int all_diff = 0;
                for (int l = 0; l < 4; ++l) {
                    char a = s[i][l];
                    char b = s[j][l];
                    char c = s[k][l];
                    if (a == b && b == c) same++;
                    if (a != b && a != c && b != c) all_diff++;
                }
                if ((same+all_diff) == 4) {
                    cout << i+1 << " " << j+1 << " " << k+1 << endl;
                    found++;
                }
            }
        }
    }

    if (found == 0) {
        cout << "no sets\n";
    }
}