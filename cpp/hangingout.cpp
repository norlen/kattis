#include <iostream>

using namespace std;

int main() {
    int limit, n;
    cin >> limit >> n;

    int curr = 0;
    int not_allowed = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        int num;
        cin >> s >> num;
        if (s == "enter") {
            if (curr + num > limit) not_allowed++;
            else curr += num;
        } else {
            curr -= num;
        }
    }
    cout << not_allowed << endl;
}