#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int lost = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j < s.length(); ++j) {
            if (s[j-1] == 'C' && s[j] == 'D') {
                lost++;
                break;
            }
        }
    }
    cout << (n - lost) << endl;
}
