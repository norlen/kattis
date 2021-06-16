#include <iostream>
#include <vector>

using namespace std;

void move(int move, pair<int,int>& pos, int& angle) {
    switch (move) {
        case 0: {
            switch (angle) {
                case 0: pos.second++; break;
                case 1: pos.first--; break;
                case 2: pos.second--; break;
                case 3: pos.first++; break;
            }
            break;
        }
        case 1: angle = (angle - 1 + 4) % 4; break;
        case 2: angle = (angle + 1) % 4; break;
    }
}

pair<int,int> run(const vector<int>& moves) {
    pair<int,int> pos = {0, 0};
    int angle = 0;
    for (auto m : moves) {
        move(m, pos, angle);
    }
    return pos;
}

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> instr(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int m;
        if (s == "Forward") {
            m = 0;
        } else if (s == "Right") {
            m = 1;
        } else if (s == "Left") {
            m = 2;
        }
        instr[i] = m;
    }

    int changed = -1, to;
    pair<int,int> pos = {0, 0};
    int angle = 0;
    for (int i = 0; i < n && changed == -1; ++i) {
        int old = instr[i];
        for (int j = 0; j < 3; ++j) {
            instr[i] = j;
            if (j == old) continue;
            pair<int,int> end = run(instr);
            if (end.first == x && end.second == y) {
                changed = i+1;
                to = j;
                break;
            }
        }
        instr[i] = old;
    }

    string txt;
    switch (to) {
        case 0: txt = "Forward"; break;
        case 1: txt = "Right"; break;
        case 2: txt = "Left"; break;
    }
    cout << changed << " " << txt << endl;
}
