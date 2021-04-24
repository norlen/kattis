#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int scores[3] = {0};
    const char* names[3] = { "Adrian", "Bruno", "Goran" };
    vector<int> ans[3] = { {'A', 'B', 'C'}, {'B', 'A', 'B', 'C'}, {'C', 'C', 'A', 'A', 'B', 'B'}};
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        for (int j = 0; j < 3; ++j) {
            if (ans[j][i % ans[j].size()] == ch) {
                scores[j]++;
            }
        }
    }

    int highest = max(scores[0], max(scores[1], scores[2]));
    cout << highest << endl;
    for (int i = 0; i < 3; ++i) {
        if (scores[i] == highest) {
            cout << names[i] << endl;
        }
    }
}