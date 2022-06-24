#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string in;
    getline(cin, in);

    int sum = 0;
    for (auto ch : in) {
        sum += (int)ch;
    }
    
    cout << (char)(sum / in.size()) << endl;
}
