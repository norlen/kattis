#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> cards;
    string input;
    cin >> input;

    bool error = false;
    int p = 13, k = 13, h = 13, t = 13;
    for (int i = 0; i < input.length(); i += 3) {
        if (input[i] == 'P') p--;
        if (input[i] == 'K') k--;
        if (input[i] == 'H') h--;
        if (input[i] == 'T') t--;
        string s = input.substr(i, 3);
        if (cards.count(s) > 0) {
            error = true;
            break;
        }
        cards.insert(s);
    }

    if (error) {
        cout << "GRESKA\n";
    } else {
        cout << p << " " << k << " " << h << " " << t << endl;
    }
}