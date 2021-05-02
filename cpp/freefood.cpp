#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool free_food[366];
    for (int i = 0; i < 366; ++i) free_food[i] = false;

    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        for (int j = start; j <= end; ++j) free_food[j] = true;
    }
    int awesome_days = 0;
    for (int i = 0; i < 366; ++i) {
        if (free_food[i]) awesome_days++;
    }
    cout << awesome_days << endl;
}