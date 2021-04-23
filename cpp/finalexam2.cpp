#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int correct = 0;
    char prev = 0, curr;
    for (int i = 0; i < n; ++i) {
        cin >> curr;
        if (curr == prev) correct++;
        prev = curr;
    }
    cout << correct << endl;
}