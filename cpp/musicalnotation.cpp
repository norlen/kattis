#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    char outnotes[14] = { 'G', 'F', 'E', 'D', 'C', 'B', 'A', 'g', 'f', 'e', 'd', 'c', 'b', 'a' };

    // {note, {starts_at, duration}}
    unordered_map<char, vector<pair<int,int>>> notes;
    for (char note : outnotes) {
        notes.insert({note, vector<pair<int,int>>()});
    }

    int len = 0;
    string in;
    for (int i = 0; i < n; ++i) {
        cin >> in;

        int duration = 1;
        if (in.length() == 2) {
            duration = in[1] - '0';
        }

        notes[in[0]].push_back({len, duration});
        len += duration + 1;
    }
    len--; // remove final padding.

    for (int i = 0; i < 14; ++i) {
        cout << outnotes[i] << ": ";
        const char fill = (i % 2 == 0 || outnotes[i] == 'c') ? ' ' : '-';

        vector<pair<int,int>>& curr_notes = notes[outnotes[i]];
        sort(curr_notes.begin(), curr_notes.end());

        int k = 0;
        for (pair<int,int> note : curr_notes) {
            // Fill until we hit the starting position.
            while (k < note.first) {
                cout << fill;
                k++;
            }
            // Put the actual note stuff.
            for (int l = 0; l < note.second; ++l) {
                cout << '*';
                k++;
            }
        }
        // Fill the rest of the line.
        while (k < len) {
            cout << fill;
            k++;
        }
        cout << endl;
    }
}