#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr char START = 'S';
constexpr char TREASURE = 'G';
constexpr char RIVER = '#';
constexpr char PLAIN = '.';
constexpr char FOREST = 'F';
constexpr char MOUNTAIN = 'M';
const pair<int,int> offsets[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int n, m, k;

int get_stamina_cost(vector<string>& grid, int r, int c) {
    if (grid[r][c] == PLAIN) {
        return 1;
    } else if (grid[r][c] == FOREST) {
        return 2;
    } else if (grid[r][c] == MOUNTAIN) {
        return 3;
    }
    return 0;
}

using KEY = pair<pair<int,int>, pair<int,int>>;
map<KEY, int> memo;

int search(vector<string>& grid, pair<int,int> s, int stamina, int days) {
    if (grid[s.first][s.second] == TREASURE) {
        return days;
    }
    KEY key = {s, {stamina, days}};
    if (memo.count(key) > 0) {
        return memo[key];
    }

    char value = grid[s.first][s.second];
    grid[s.first][s.second] = RIVER;

    int min_days = -1;
    for (auto o : offsets) {
        int vr = s.first + o.first;
        int vc = s.second + o.second;
        if (vr < 0 || vr >= n || vc < 0 || vc >= m ||
            grid[vr][vc] == RIVER || grid[vr][vc] == START) continue;

        int stamina_cost = get_stamina_cost(grid, vr, vc);
        if (stamina_cost > k) continue;

        int curr_stamina = stamina;
        int curr_days = days;

        // Check if we have to rest to move.
        if (stamina_cost > stamina) {
            curr_stamina = k - stamina_cost;
            curr_days += 1;
        } else {
            curr_stamina -= stamina_cost;
        }

        int rec_days = search(grid, {vr,vc}, curr_stamina, curr_days);

        if (rec_days == -1) continue;
        if (min_days == -1 || rec_days < min_days) {
            min_days = rec_days;
        }
    }

    grid[s.first][s.second] = value;
    
    memo[key] = min_days;
    return min_days;
}

int main() {
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    pair<int,int> s = {-1, -1};
    for (int i = 0; i < n && s.first == -1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == START) {
                s = {i, j};
                break;
            }
        }
    }

    int days = search(grid, s, k, 1);
    cout << days << endl;
}
