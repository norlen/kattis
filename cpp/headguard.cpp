#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in;
    while (getline(cin, in)) {
        char prev = in[0];
        int run_length = 1;
        string out = "";
        for (int i = 1; i < in.size(); ++i) {
            if (in[i-1] == in[i]) {
                run_length += 1;
            } else {
                out.append(to_string(run_length));
                out.push_back(in[i-1]);
                run_length = 1;
            }
        }
        out.append(to_string(run_length));
        out.push_back(in[in.size()-1]);
        cout << out << endl;
    }
}

