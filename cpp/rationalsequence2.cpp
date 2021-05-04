#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int num, d, n;
        scanf("%d %d/%d", &num, &d, &n);

        vector<int> p; // keep track of moves to reach the node.
        int depth = 0;
        while (!(d == 1 && n == 1)) {
            if (d > n) { // this is a right child.
                d -= n;
                p.push_back(1);
            } else { // left child.
                p.push_back(0);
                n -= d;
            }
            depth++;
        }

        // heap left-right child calculation.
        int N = 0;
        for (int j = p.size() - 1; j >= 0; --j) {
            if (p[j]) { // right child.
                N = 2*N + 2;
            } else { // left child.
                N = 2*N + 1;
            }
        }
        cout << i+1 << " " << N+1 << endl;
    }
}