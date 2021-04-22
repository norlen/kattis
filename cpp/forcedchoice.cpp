#include <iostream>

using namespace std;

int main() {
    int n, pred, steps;
    cin >> n >> pred >> steps;

    for (int i = 0; i < steps; ++i) {
        int num;
        cin >> num;
        bool keep = false;
        for (int i = 0; i < num; ++i) {
            int c;
            cin >> c;
            if (c == pred) keep = true;
        }

        if (keep) {
            cout << "KEEP\n";
        } else {
            cout << "REMOVE\n";
        }
    }
}