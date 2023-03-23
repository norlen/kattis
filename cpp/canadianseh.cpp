#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string line;
    getline(cin, line);

    if (line.size() >= 3 && line.substr(line.size()-3) == "eh?") {
        cout << "Canadian!";
    } else {
        cout << "Imposter!";
    }
}
