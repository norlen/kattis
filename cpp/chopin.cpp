#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Alternative names.
    // A♯=B♭, C♯=D♭, D♯=E♭, F♯=G♭, G♯=A♭
    // A#=Bb, C#=Db, D#=Eb, F#=Gb, G#=Ab
    unordered_map<string, string> m;
    pair<string, string> n[5] = { {"A#", "Bb"}, {"C#", "Db"}, {"D#", "Eb"}, {"F#", "Gb"}, {"G#", "Ab"} };
    for (int i = 0; i < 5; ++i) {
        m.insert({n[i].first, n[i].second});
        m.insert({n[i].second, n[i].first});
    }

    string scale, tonality;
    int count = 1;
    while (cin >> scale >> tonality) {
        cout << "Case " << count << ": ";
        if (m.count(scale) > 0) {
            cout << m[scale] << " " << tonality << endl;
        } else {
            cout << "UNIQUE\n";
        }
        count++;
    }
}