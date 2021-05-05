#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll l, n;
    cin >> l >> n;
    ll count = 0;
    ll left_on_next = n;
    while (l % left_on_next != 0) {
        count++;
        left_on_next -= l % left_on_next;
    }
    cout << count+1 << endl;
}