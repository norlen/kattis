#include <iostream>
#include <vector>

using namespace std;

void shuffle(const vector<int>& c, vector<int>& out, bool out_shuffle) {
    if (out_shuffle) {
        int mid = c.size() / 2 + c.size() % 2;
        if (c.size() % 2 == 1) {
            out[c.size()-1] = c[mid-1];
        }
        for (int i = 0; i < c.size()/2; ++i) {
            out[i*2+1] = c[mid+i];
            out[i*2] = c[i];
        }
    } else {
        int mid = c.size() / 2;
        if (c.size() % 2 == 1) {
            out[c.size()-1] = c[c.size()-1];
        }
        for (int i = 0; i < c.size()/2; ++i) {
            out[i*2+1] = c[i];
            out[i*2] = c[mid+i];
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> c[2] = {vector<int>(n), vector<int>(n)};
    for (int i = 0; i < n; ++i) {
        c[0][i] = i;
        c[1][i] = 0;
    }

    string t;
    cin >> t;
    bool out_shuffle = t == "out";

    shuffle(c[0], c[1], out_shuffle);
    int curr = 1;
    int shuffles = 1;
    while (true) {
        bool shuffled = false;
        for (int i = 0; i < n; ++i) {
            while (c[curr][i] != i) {
                shuffles++;
                shuffle(c[curr], c[(curr+1)%2], out_shuffle);
                curr = (curr + 1) % 2;
            }
        }

        if (!shuffled) break;
    }

    cout << shuffles << endl;
}