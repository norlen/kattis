#include <iostream>
#include <vector>

using namespace std;

const int NUM_LETTERS = ('Z' - 'A' + 1);

void rotate(vector<int>& v) {
    int sum = 0;
    for (auto e : v) sum += e;
    for (int i = 0; i < v.size(); ++i) {
        v[i] = (v[i] + sum) % NUM_LETTERS;
    }
}

int main() {
    string s;
    cin >> s;

    vector<int> l, r;
    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() / 2) {
            l.push_back(s[i] - 'A');
        } else {
            r.push_back(s[i] - 'A');
        }
    }
    rotate(l);
    rotate(r);

    string out;
    for (int i = 0; i < l.size(); ++i) {
        out.push_back((l[i] + r[i]) % NUM_LETTERS + 'A');
    }
    cout << out << endl;
}