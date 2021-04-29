#include <iostream>
#include <set>

using namespace std;

int main() {
    string word, alph;
    cin >> word >> alph;
    set<char> s;
    for (auto ch : word) {
        s.insert(ch);
    }

    int left = 10;
    for (int i = 0; i < alph.length() && left > 0; ++i) {
        char ch = alph[i];
        if (s.count(ch) > 0) {
            s.erase(ch);
        } else {
            left--;
        }
    }

    cout << (s.size() == 0 ? "WIN" : "LOSE") << endl;
}