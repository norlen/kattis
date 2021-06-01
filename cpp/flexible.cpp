#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int w, p;
    cin >> w >> p;

    vector<int> ps(p+2);
    for (int i = 0; i < p; ++i) {
        cin >> ps[i+1];
    }
    ps[0] = 0;
    ps[p+1] = w;

    set<int> ds;
    for (int i = 0; i < ps.size(); ++i) {
        for (int j = i+1; j < ps.size(); ++j) {
            ds.insert(ps[j]-ps[i]);
        }
    }

    for (auto& d : ds) {
        cout << d << " ";
    }
    cout << endl;
}