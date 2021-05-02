#include <iostream>

using namespace std;

const char* mapping[] = {
    "2", // a
    "22", // b
    "222", // c
    "3", // d
    "33", // e
    "333", // f
    "4", // g
    "44", // h
    "444", // i
    "5", // j
    "55", // k
    "555", // l
    "6", // m
    "66", // n
    "666", // o
    "7", // p
    "77", // q
    "777", // r
    "7777", // s
    "8", // t
    "88", // u
    "888", // v
    "9", // w
    "99", // x
    "999", // y
    "9999", // z
    "0",
};

int main() {
    int t;
    cin >> t;
    string in;
    getline(cin, in);

    for (int i = 1; i <= t; ++i) {
        getline(cin, in);
        string out;
        for (auto ch : in) {
            int ind = ch - 'a';
            if (ch == ' ') ind = 'z' + 1 - 'a';

            if (out.length() > 0 && out[out.length()-1] == mapping[ind][0]) out += " ";
            out += mapping[ind];
        }
        cout << "Case #" << i << ": " << out << endl;
    }
}