#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string in, t;
    getline(cin, in);

    vector<string> check(m);
    for (int i = 1; i <= m; ++i) {
        if (i % 15 == 0) {
            check[i-1] = "fizzbuzz";
        } else if (i % 5 == 0) {
            check[i-1] = "buzz";
        } else if (i % 3 == 0) {
            check[i-1] = "fizz";
        } else {
            check[i-1] = to_string(i);
        }
    }

    int highest = 0, idx = 1;
    for (int i = 1; i <= n; ++i) {
        int num_correct = 0;
        for (int j = 0; j < m; ++j) {
            cin >> t;
            if (check[j] == t) {
                num_correct++;
            }
        }
        if (num_correct > highest) {
            highest = num_correct;
            idx = i;
        }
    }
    cout << idx << endl;
}
