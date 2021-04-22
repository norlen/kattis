#include <iostream>

using namespace std;

int main() {
    int hands;
    char dom_suit;
    cin >> hands >> dom_suit;

    int points = 0;
    for (int i = 0; i < 4*hands; ++i) {
        string s;
        cin >> s;

        switch (s[0]) {
            case 'A': points += 11; break;
            case 'K': points += 4; break;
            case 'Q': points += 3; break;
            case 'J': points += (s[1] == dom_suit ? 20 : 2); break;
            case 'T': points += 10; break;
            case '9': points += (s[1] == dom_suit ? 14 : 0); break;
            // 8, 7: no score
        }
    }

    cout << points << endl;
}