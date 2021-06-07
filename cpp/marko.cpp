#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    string in;
    unordered_map<string, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> in;
        string num;
        for (auto ch : in) {
            char c = 0;
            if (ch <= 'c') {
                c = '2';
            } else if (ch <= 'f') {
                c = '3';
            } else if (ch <= 'i') {
                c = '4';
            } else if (ch <= 'l') {
                c = '5';
            } else if (ch <= 'o') {
                c = '6';
            } else if (ch <= 's') {
                c = '7';
            } else if (ch <= 'v') {
                c = '8';
            } else {
                c = '9';
            }
            num.push_back(c);
        }

        if (m.count(num) == 0) {
            m.insert({num, 0});
        }
        m[num] += 1;
    }
    cin >> in;
    if (m.count(in) > 0) {
        cout << m[in] << endl;
    } else {
        cout << "0\n";
    }
}