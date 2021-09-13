#include <iostream>

using namespace std;

int main() {
    string in, text;
    while (getline(cin, in)) {
        getline(cin, text);
        int n = stoi(in);
        for (int i = 0; i < n; ++i) {
            string tmp;
            for (auto ch : text) {
                if ((ch >= '!' && ch <= '*') || (ch >= '[' && ch <= ']')) {
                    tmp.push_back('\\');
                }
                tmp.push_back(ch);
            }
            text = tmp;
        }
        cout << text << endl;
    }
}