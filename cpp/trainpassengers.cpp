#include <iostream>

using namespace std;

int main() {
    int c, n;
    cin >> c >> n;

    int on_train = 0;
    bool not_ok = false;
    for (int i = 0; i < n; ++i) {
        int left, entered, stayed;
        cin >> left >> entered >> stayed;
        int new_val = on_train - left + entered;
        if (on_train < left || new_val < 0 || new_val > c || (new_val < c && stayed > 0)) {
            not_ok = true;
            break;
        }
        on_train = new_val;
    }

    cout << ((not_ok == true || on_train != 0) ? "impossible" : "possible") << endl;
}
