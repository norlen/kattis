#include <iostream>
#include <array>
#include <vector>
#include <set>

using namespace std;

array<string, 12> all_notes = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
array<int, 8> progression = { 0, 2, 4, 5, 7, 9, 11, 12 };

// Generate a progression from a starting index.
set<string> get_prog(int s) {
    set<string> ss;
    for (int i = 0; i < progression.size(); ++i) {
        int note_idx = (s + progression[i]) % 12;
        ss.insert(all_notes[note_idx]);
    }
    return ss;
}

int main() {
    int n;
    cin >> n;
    set<string> notes;
    string in;

    for (int i = 0; i < n; ++i) {
        cin >> in;
        notes.insert(in);
    }

    // Go through all progressions and check which ones can be used.
    vector<string> valid_progs;
    for (int i = 0; i < all_notes.size(); ++i) {
        auto ss = get_prog(i);
        int count = 0;
        for (auto& note : notes) {
            if (ss.count(note) > 0) count++;
        }
        if (count == notes.size()) {
            valid_progs.push_back(all_notes[i]);
        }
    }

    // Output result.
    if (valid_progs.size() == 0) {
        cout << "none\n";
    } else {
        for (int i = 0; i < valid_progs.size(); ++i) {
            cout << valid_progs[i] << (i == valid_progs.size()-1 ? "" : " ");
        }
        cout << endl;
    }
}