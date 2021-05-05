#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, v;
    cin >> n;

    vector<pair<int,int>> p;
    for (int i = 1; i < n; ++i) {
        cin >> v;
        p.push_back({v, i+1});
    }

    cout << "1";
    sort(p.begin(), p.end());
    for (const auto& a : p) {
        cout << " " << a.second; 
    }
    cout << endl;
}