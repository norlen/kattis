#include <iostream>

using namespace std;

bool is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool first(const string& s, const string& p) {
    return is_digit(s[0]) && s.substr(1) == p;
}

bool second(const string& s, const string& p) {
    auto l = s.size()-1;
    return is_digit(s[l]) && s.substr(0, l) == p;
}

bool third(const string&s, const string& p) {
    string rev;
    for (auto ch : s) {
        if (ch >= 'a' && ch <= 'z') rev.push_back(toupper(ch));
        else if (ch >= 'A' && ch <= 'Z') rev.push_back(tolower(ch));
        else rev.push_back(ch);
    }
    return rev == p;
}

int main() {
    string S, P;
    cin >> S >> P;

    bool ok = S == P || first(S, P) || second(S, P) || third(S, P);
    cout << (ok ? "Yes\n" : "No\n");
}