#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int t = 0;
    int c = 0;
    int g = 0;
    for (int i = 0; i < s.length(); ++i) {
        switch (s[i]) {
            case 'T': t++; break;
            case 'C': c++; break;
            case 'G': g++; break;
        }
    }
    int m = min(t, min(c, g));
    cout << t*t + c*c + g*g + m*7 << endl;
}