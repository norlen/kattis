#include <iostream>
#include <array>
#include <vector>

using namespace std;

// expects a list of e.g. "Ke1,Qd1,Ra1,Rh1,Bc1,Bf1,Nb1,a2,c2,d2,f2,g2,h2,a3,e4"
void parse(string s, array<array<char, 8>, 8>& pieces, bool black) {
    string slice;
    while (true) {
        int next_idx = s.find(",");
        if (next_idx == string::npos) {
            next_idx = s.length();
        }

        slice = s.substr(0, next_idx);
        if (slice.length() == 2) {
            pieces[8-(slice[1]-'0')][slice[0]-'a'] = black ? 'p' : 'P';
        } else {
            int r = 8-(slice[2]-'0');
            int c = slice[1]-'a';
            char cc = black ? tolower(slice[0]) : slice[0];
            pieces[8-(slice[2]-'0')][slice[1]-'a'] = black ? tolower(slice[0]) : slice[0];
        }

        if (next_idx+1 > s.length()) break;
        s = s.substr(next_idx+1, s.length());
    }
}

int main() {
    string in;
    getline(cin, in);

    array<array<char, 8>, 8> pieces;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            pieces[i][j] = 0;
        }
    }

    parse(in.substr(in.find(':')+2, in.length()), pieces, false);
    getline(cin, in);
    parse(in.substr(in.find(':')+2, in.length()), pieces, true);

    for (int i = 0; i < 8; ++i) {
        cout << "+---+---+---+---+---+---+---+---+\n|";
        for (int j = 0; j < 8; ++j) {
            bool white_tile = (i % 2 + j) % 2 == 1;
            char t = white_tile ? ':' : '.';
            char p = pieces[i][j];
            cout << t << (p == 0 ? t : p) << t << "|";
        }
        cout << endl;
    }
    cout << "+---+---+---+---+---+---+---+---+\n";
}