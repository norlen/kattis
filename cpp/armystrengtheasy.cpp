#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int g, m, p;
        cin >> g >> m;

        // - The larger the value, the stronger the monster.
        // - The war will consist of a series of battles.
        // - In each battle, the weakest of all the monsters that are still alive is killed.
        //     If there are several weakest monsters, but all of them in the same army, one of them is killed at random.
        // - If both armies have at least one of the weakest monsters, a random weakest monster of MechaGodzilla’s army is killed.
        // - The war is over if in one of the armies all monsters are dead. The dead army lost, the other one won. You are given the strengths of all the monsters. Find out who wins the war.
        priority_queue<int, vector<int>, greater<int>> G;
        priority_queue<int, vector<int>, greater<int>> M;

        for (int i = 0; i < g; ++i) {
            cin >> p;
            G.push(p);
        }
        for (int i = 0; i < m; ++i) {
            cin >> p;
            M.push(p);
        }

        while (!G.empty() && !M.empty()) {
            if (G.top() < M.top()) {
                G.pop();
            } else {
                M.pop();
            }
        }

        if (G.empty()) {
            cout << "MechaGodzilla\n";
        } else {
            cout << "Godzilla\n";
        }
    }
}