#include <iostream>

using namespace std;

int main() {
    string ss;
    cin >> ss;

    int pos[3] = { 1, 0, 0};
    for (const auto ch : ss) {
        switch (ch) {
            case 'A': swap(pos[0], pos[1]); break;
            case 'B': swap(pos[1], pos[2]); break;
            case 'C': swap(pos[0], pos[2]); break;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (pos[i] == 1) {
            cout << i+1 << endl;
        }
    }
}