#include <iostream>

using namespace std;

constexpr const char* order = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
constexpr int num = 28;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        string in;
        cin >> in;

        for (int i = in.length()-1; i >= 0; --i) {
            int idx;
            if (in[i] >= 'A' && in[i] <= 'Z') {
                idx = in[i] - 'A';
            } else if (in[i] == '.') {
                idx = num - 1;
            } else { // _
                idx = num - 2;
            }
            cout << order[(idx + n) % num];
        }
        cout << endl;
    }
}