#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int highest_score(unordered_map<int,int>& teams, int curr_team) {
    int highest = 0;
    for (const auto t: teams) {
        if (t.first != curr_team) {
            highest = max(t.second, highest);
        }
    }
    return highest;
}

bool bt(unordered_map<int,int>& teams, vector<pair<int,int>>& matches, int current, int team_num, vector<int> outcome) {
    if (current == matches.size()) {
        if (teams[team_num] > highest_score(teams, team_num)) {
            for (auto s: outcome) {
                std::cout << s << " ";
            }
            std::cout << std::endl;
            return true;
        }
        return false;
    }

    std::pair<int,int> alts[] = {{2, 0}, {1, 1}, {0, 2}};
    for (int i = 2; i > 0; --i) {
        auto curr_teams = matches[current];
        teams[curr_teams.first] += alts[i].first;
        teams[curr_teams.second] += alts[i].second;
        outcome.push_back(i);
        if (bt(teams, matches, current + 1, team_num, outcome) == true) return true;
        outcome.pop_back();
        teams[curr_teams.first] -= alts[i].first;
        teams[curr_teams.second] -= alts[i].second;
    }
    return false;
}

int main() {
    while (true) {
        int num_teams, m;
        std::cin >> num_teams;
        if (num_teams == -1) break;

        std::cin >> m;

        unordered_map<int,int> teams;
        vector<pair<int,int>> matches;
        vector<int> outcome;

        // Note: map teams from 1..N to 0..N-1.
        for (int i = 0; i < num_teams; ++i) {
            int points;
            std::cin >> points;
            teams.insert({i, points});
        }
        for (int i = 0; i < m; ++i) {
            int t0, t1;
            std::cin >> t0 >> t1;
            matches.push_back({t0 - 1, t1 - 1});
        }

        if (!bt(teams, matches, 0, num_teams - 1, outcome)) {
            std::cout << "NO\n";
        }
    }
    return 0;
}