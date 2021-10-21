#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    int switches = 0;
    int i = 0;
    while (i < p.size()) {
        if (p[i] != i+1) {
            swap(p[i], p[p[i]-1]);
            switches++;
        } else {
            i++;
        }
    }
    cout << switches << endl;
}
