#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int time = 0;
    int score = 0;
    unordered_map<char, int> m;

    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;

        char letter;
        string s;
        cin >> letter >> s;
        if (s == "right") {
            score++;
            time += n;
            if (m.count(letter)) {
                time += m[letter] * 20;
            }
        } else {
            if (m.count(letter) == 0) m.insert({letter, 0});
            m[letter] += 1;
        }
    }
    cout << score << " " << time << endl;
}