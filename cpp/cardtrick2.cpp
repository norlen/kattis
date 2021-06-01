#include <iostream>
#include <vector>

using namespace std;

void test(vector<int> cards) {
    int skip = 1;
    auto it = cards.begin();
    cout << " TEST :: ";
    while (cards.size() > 0) {
        for (int i = 0; i < skip; ++i) {
            ++it;
            if (it == cards.end()) it = cards.begin();
        }
        skip++;

        cout << *it << " ";
        cards.erase(it);
        if (it == cards.end()) it = cards.begin();
    }
    cout << endl;
}

int main() {
    int cases;
    cin >> cases;

    for (int t = 0; t < cases; ++t) {
        int n;
        cin >> n;

        vector<int> out(n);
        for (int i = 0; i < n; ++i) out[i] = -1;

        int idx = 0;
        for (int i = 0; i < n; ++i) {
            int left = n - i;
            int jump_over = (1*i + 1) % left;

            while (out[idx] != -1) idx = (idx + 1) % n;
            while (jump_over > 0) {
                if (out[idx] == -1) jump_over--;
                idx = (idx + 1) % n;
            }
            while (out[idx] != -1) idx = (idx + 1) % n;
            out[idx] = i+1;
        }

        for (auto i : out) {
            cout << i << " ";
        }
        cout << endl;
    }
}