#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void print_arr(const vector<pair<int,int>>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i].first == arr[i].second) {
            cout << arr[i].first;
        } else {
            cout << arr[i].first << "-" << arr[i].second;
        }
        if (i+2 == arr.size()) {
            cout << " and ";
        } else if (i+2 < arr.size()) {
            cout << ", ";
        }
    }
}

int main() {
    int c, n;
    cin >> c >> n;

    int prev_err = -1;
    int last_err = -10;
    int start = -1;
    int end = 0;
    vector<pair<int,int>> errs;
    vector<pair<int,int>> correct;
    for (int i = 0; i < n; ++i) {
        int line;
        cin >> line;
        if (start == -1) {
            if (line > 1) {
                correct.push_back({1, line-1});
            }
            start = line;
            end = line;
        } else {
            if (last_err + 1 == line) {
                end = line;
            } else {
                if (prev_err != -1) {
                    correct.push_back({prev_err+1, start-1});
                }
                errs.push_back({start, end});
                prev_err = end;
                start = line;
                end = line;
            }
        }
        last_err = line;
    }
    if (prev_err != -1) {
        correct.push_back({prev_err+1, start-1});
    }
    errs.push_back({start, end});
    if (end != c) {
        correct.push_back({end+1, c});
    }

    cout << "Errors: ";
    print_arr(errs);
    cout << endl;

    cout << "Correct: ";
    print_arr(correct);
    cout << endl;
}