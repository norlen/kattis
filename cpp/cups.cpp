#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    string in;
    cin >> t;
    getline(cin, in);
    int num;
    string color;

    vector<pair<int, string>> out;
    for (int i = 0; i < t; ++i) {
        getline(cin, in);
        size_t p = in.find(' ');
        string left = in.substr(0, p);
        string right = in.substr(p+1, in.length());
        bool left_dig = all_of(left.begin(), left.end(), ::isdigit);
        if (left_dig) out.push_back({stoi(left)/2, right});
        else out.push_back({stoi(right), left});
    }

    sort(out.begin(), out.end());
    for (auto o : out) {
        cout << o.second << endl;
    }
}