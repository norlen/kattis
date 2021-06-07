#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    string in;
    getline(cin, in);

    int words = 0;
    for (int i = 1; i < in.length(); ++i) {
        if (in[i] == ' ' && in[i-1] != ' ') words++;
    }

    int num_names;
    cin >> num_names;

    list<string> names;
    for (int i = 0; i < num_names; ++i) {
        string name;
        cin >> name;
        names.emplace_back(name);
    }

    vector<string> teams[2];
    int team = 0;
    int start = 0;
    while (!names.empty()) {
        int next = (start + words) % names.size();
        auto it = names.begin();
        for (int i = 0; i < next; ++i) ++it;

        teams[team].push_back(*it);
        team = team == 0 ? 1 : 0;

        names.erase(it);
        start = next;
    }

    for (int i = 0; i < 2; ++i) {
        cout << teams[i].size() << endl;
        for (auto& s : teams[i]) {
            cout << s << endl;
        }
    }
}