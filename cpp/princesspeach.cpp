#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, y;
    cin >> n >> y;

    vector<int> o(n);
    for (int i = 0; i < n; ++i) o[i] = false;
    for (int i = 0; i < y; ++i) {
        int j;
        cin >> j;
        o[j] = true;
    }

    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (o[i] == false) {
            cout << i << endl;
        } else {
            m++;
        }
    }
    cout << "Mario got " << m << " of the dangerous obstacles.\n";
}
