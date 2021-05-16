#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int dw = 0;
    unordered_map<int,int> w;

    for (int i = 0; i < q; ++i) {
        string in;
        cin >> in;
        int a, b;
        if (in[0] == 'S') {
            cin >> a >> b;
            w[a] = b;
        } else if (in[0] == 'P') {
            cin >> a;
            if (w.count(a) > 0) {
                cout << w[a] << endl;
            } else {
                cout << dw << endl;
            }
        } else if (in[0] == 'R') {
            cin >> a;
            w.clear();
            dw = a;
        }
    }
}