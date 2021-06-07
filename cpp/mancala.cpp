#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int t = 0; t < cases; ++t) {
        int k, n;
        cin >> k >> n;

        vector<int> bins;
        bins.push_back(n);

        for (int i = 0; i < 100; ++i) {
            int next = i+2;
            int t = bins[i];

            if (t % next == 0) {
                bins[i] = 0;
                bins.push_back(t);
            } else {
                int b = t / next;
                bins[i] = t - next * b;
                bins.push_back(next * b);
            }
            if (bins[i+1] == next) break;
        }

        cout << k << " " << bins.size() << endl;
        for (int i = 0; i < bins.size(); ++i) {
            cout << bins[i];
            if (i != bins.size()-1) {
                cout << ((i > 0 && (i+1) % 10 == 0) ? "\n" : " ");
            }
        }
        cout << endl;
    }
}