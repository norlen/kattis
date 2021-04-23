#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<string> words;
    string s;
    getline(cin, s);

    size_t pos = 0;
    bool exists = false;
    while ((pos = s.find(' ')) != string::npos) {
        string ss = s.substr(0, pos);
        if (words.count(ss) > 0) {
            exists = true;
            break;
        }
        words.insert(ss);
        s = s.substr(pos + 1, s.length());
    }
    if (exists || words.count(s) > 0) {
        cout << "no\n";
    } else {
        cout << "yes\n";
    }
}