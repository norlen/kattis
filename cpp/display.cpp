#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const array<string, 7> zero = {
    "+---+",
    "|   |",
    "|   |",
    "+   +",
    "|   |",
    "|   |",
    "+---+",
};
const array<string, 7> one = {
    "    +",
    "    |",
    "    |",
    "    +",
    "    |",
    "    |",
    "    +",
};
const array<string, 7> two = {
    "+---+",
    "    |",
    "    |",
    "+---+",
    "|    ",
    "|    ",
    "+---+",
};
const array<string, 7> three = {
    "+---+",
    "    |",
    "    |",
    "+---+",
    "    |",
    "    |",
    "+---+",
};
const array<string, 7> four = {
    "+   +",
    "|   |",
    "|   |",
    "+---+",
    "    |",
    "    |",
    "    +",
};
const array<string, 7> five = {
    "+---+",
    "|    ",
    "|    ",
    "+---+",
    "    |",
    "    |",
    "+---+",
};
const array<string, 7> six = {
    "+---+",
    "|    ",
    "|    ",
    "+---+",
    "|   |",
    "|   |",
    "+---+",
};
const array<string, 7> seven = {
    "+---+",
    "    |",
    "    |",
    "    +",
    "    |",
    "    |",
    "    +"
};
const array<string, 7> eight = {
    "+---+",
    "|   |",
    "|   |",
    "+---+",
    "|   |",
    "|   |",
    "+---+"
};
const array<string, 7> nine = {
    "+---+",
    "|   |",
    "|   |",
    "+---+",
    "    |",
    "    |",
    "+---+"
};

const array<array<string, 7>, 10> numbers = {zero, one, two, three, four, five, six, seven, eight, nine};

const array<string, 7> colon = {
    " ",
    " ",
    "o",
    " ",
    "o",
    " ",
    " ",
};

int main() {
    string in;

    while (getline(cin, in)) {
        if (in == "end") break;
        vector<string> d(7);

        for (int i = 0; i < in.size(); ++i) {
            if (i != 0) {
                for (int j = 0; j < 7; ++j) {
                    d[j].append("  ");
                }
            }
            char ch = in[i];
            if (ch == ':') {
                for (int j = 0; j < colon.size(); ++j) {
                    d[j].append(colon[j]);
                }
            } else {
                int v = ch - '0';
                auto& repr = numbers[v];
                for (int j = 0; j < repr.size(); ++j) {
                    d[j].append(repr[j]);
                }
            }
        }

        for (int i = 0; i < d.size(); ++i) {
            cout << d[i] << endl;
        }
        cout << endl << endl;
    }
    cout << "end" << endl;
}