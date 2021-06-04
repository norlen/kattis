#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int p = m / n;
    int q = m % n;

    string s;
    for (int i = 0; i < p+1; ++i) s.push_back('*');

    for (int i = 0; i < n; ++i) {
        if (i == q) s.pop_back();
        cout << s << endl;
    }
}
