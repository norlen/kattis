#include <iostream>
#include <vector>

using namespace std;

vector<int> getpoly(int n) {
    n++;
    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[n-i-1];
    }
    return std::move(m);
}

int main() {
    int p;
    cin >> p;

    for (int i = 0; i < p; ++i) {
        // Input.
        int n, m;
        cin >> n;
        auto first = getpoly(n);
        cin >> m;
        auto second = getpoly(m);
        if (second.size() > first.size()) {
            swap(first, second);
        }

        // Mul.
        int len = n + m + 1;
        vector<int> output(len, 0);
        for (int i = 0; i < second.size(); ++i) {
            for (int j = 0; j < first.size(); ++j) {
                output[i+j] += second[i] * first[j];
            }
        }

        // Output.
        cout << len-1 << endl;
        for (int i = output.size()-1; i >= 0; --i) {
            cout << output[i] << (i == 0 ? "" : " ");
        }
        cout << endl;
    }
}