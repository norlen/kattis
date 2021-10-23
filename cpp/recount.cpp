#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string in;
    unordered_map<string, int> m;
    while (getline(cin, in)) {
        if (in == "***") break;
        if (m.count(in) == 0) {
            m.insert({in, 1});
        } else {
            m[in]++;
        }
    }

    int max_votes = 0;
    string who;
    int max_vote_c = 0;
    for (auto& kv : m) {
        if (kv.second > max_votes) {
            max_votes = kv.second;
            max_vote_c = 1;
            who = kv.first;
        } else if (kv.second == max_votes) {
            max_vote_c++;
        }
    }

    if (max_vote_c > 1) {
        cout << "Runoff!\n";
    } else {
    cout << who << endl;
    }
}