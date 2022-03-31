#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, e;
    cin >> n >> e;

    int max_songs = 0;
    vector<int> num_songs(n+1, 0);
    for (int i = 0; i < e; ++i) {
        int m;
        cin >> m;

        bool has_bard = false;
        vector<int> people(m);
        for (int j = 0; j < m; ++j) {
            cin >> people[j];
            if (people[j] == 1) has_bard = true;
        }

        if (has_bard) {
            max_songs += 1;
            //cout << " -- add one to all present\n";
            for (auto p : people) {
                num_songs[p] += 1;
            }
        } else {
            int most_songs = *max_element(num_songs.begin(), num_songs.end());
            //cout << " -- set all songs to " << most_songs << endl;
            for (auto p : people) {
                num_songs[p] = most_songs;
            }
        }
    }

    for (int i = 1; i < num_songs.size(); ++i) {
        if (num_songs[i] == max_songs) {
            cout << i << endl;
        }
    }
}
