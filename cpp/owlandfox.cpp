#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int next_smaller(int n) {
    bool a = false;
    while (n > 0) {
        int nn = n % 10;
        if (!a && nn > 0) {
            // decrement first non-zero value.
            nn--;
            a = true;
        }
        s.push(nn);
        n /= 10;
    }
    // recreate number.
    int ret = 0;
    while (s.size() > 0) {
        auto v = s.top();
        s.pop();
        ret *= 10;
        ret += v;
    }
    return ret;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << next_smaller(n) << endl;
    }
}