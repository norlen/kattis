#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string morse[] = {
    ".-", "-...", "-.-.", "-..", ".", // A-E
    "..-.", "--.", "....", "..", ".---", // F-J
    "-.-", ".-..", "--", "-.", "---", // K-O
    ".--.", "--.-", ".-.", "...", "-", // P-T
    "..-", "...-", ".--", "-..-", "-.--", "--..", // U-Z
    "..--", // _
    ".-.-", // ,
    "---.", // .
    "----", // ?
};

int main() {
    unordered_map<string, char> rev;
    for (int i = 0; i < 26; ++i) {
        rev.insert({morse[i], 'A' + i});
    }
    rev.insert({"..--", '_'});
    rev.insert({".-.-", ','});
    rev.insert({"---.", '.'});
    rev.insert({"----", '?'});

    string in;
    while (cin >> in) {
        string m;
        vector<int> lens;

        for (auto ch : in) {
            int idx = 0;
            if (ch == '_') idx = 26;
            else if (ch == ',') idx = 27;
            else if (ch == '.') idx = 28;
            else if (ch == '?') idx = 29;
            else idx = ch - 'A';
            m += morse[idx];
            lens.push_back(morse[idx].length());
        }

        string out;
        int c = 0;
        for (auto it = lens.rbegin(); it != lens.rend(); ++it) {
            auto s = m.substr(c, *it);
            out.push_back(rev[s]);
            c += *it;
        }
        cout << out << endl;
    }
}