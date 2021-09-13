#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> rolls(6);
    for (int i = 0; i < 6; ++i) {
        rolls[i] = {0, 0};
    }

    for (int i = 0; i < n; ++i) {
        int roll;
        cin >> roll;
        rolls[roll-1].first++;
        rolls[roll-1].second = i;
    }
    
    for (int i = 5; i >= 0; --i) {
        if (rolls[i].first == 1) {
            cout << rolls[i].second+1 << endl;
            return 0;
        }
    }
    cout << "none\n";
}