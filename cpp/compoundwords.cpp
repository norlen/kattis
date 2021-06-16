#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    string in;
    vector<string> words;
    while (cin >> in) {
        words.push_back(in);
    }

    set<string> s;
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words.size(); ++j) {
            if (i == j) continue;
            s.insert(words[i] + words[j]);
        }
    }

    for (auto& ss : s) {
        cout << ss << endl;
    }
}