#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    unordered_set<string> words;

    string in;
    while (getline(cin, in)) {
        int s = 0;
        while (true) {
            int e = in.find(' ', s);
            string word = in.substr(s, e-s);
            string lower;
            lower.resize(word.size());
            transform(word.begin(), word.end(), lower.begin(), ::tolower);

            if (words.count(lower) > 0) {
                cout << ".";
            } else {
                cout << word;
                words.insert(lower);
            }
            if (e == string::npos) break;
            cout << " ";
            s = e+1;
        }
        cout << endl;
    }
}