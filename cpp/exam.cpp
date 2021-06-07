#include <iostream>

using namespace std;

int main() {
    string a, b;
    int n;
    cin >> n >> a >> b;

    int same = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == b[i]) same++;
    }
    int different = a.length() - same;

    int same_max_correct = min(same, n);
    int diff_max_correct = min(different, static_cast<int>(a.length() - n));

    cout << same_max_correct + diff_max_correct << endl;
}