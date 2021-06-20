#include <iostream>
#include <sstream>
#include <array>
#include <unordered_map>

using namespace std;

array<char, 8> hard_consonants = { 'b', 'c', 'd', 'g', 'k', 'n', 'p', 't' };
array<const char*, 8> ends_in = { "ah", "ah", "ah", "ah", "oh", "oh", "oh", "uh" };

unordered_map<char, const char*> mp;
array<bool, 26> is_hard_arr;
array<char, 26> to_hard_arr;

bool is_hard(char c) {
    return is_hard_arr[c - 'a'];
}

char to_hard(char c) {
    return to_hard_arr[c - 'a'];
}

void print_nimionese(string word) {
    char cons = to_hard(tolower(word[0]));
    int s = 0;
    while (true) {
        auto e = word.find('-', s);
        string ss = word.substr(s, e-s);

        if (s == 0) {
            ss[0] = isupper(ss[0]) ? toupper(cons) : cons;
        } else {
            // Replace all hard syllables.
            for (int i = 0; i < ss.length(); ++i) {
                if (is_hard(tolower(ss[i]))) {
                    ss[i] = isupper(ss[i]) ? toupper(cons) : cons;
                }
            }
        }
        cout << ss;

        if (e == string::npos) {
            char last = tolower(ss[ss.length()-1]);
            if (is_hard(last)) {
                cout << mp[last];
            }
            break;
        }
        s = e+1;
    }
}

int main() {
    // Is hard arr.
    for (int i = 0; i < is_hard_arr.size(); ++i) {
        is_hard_arr[i] = false;
    }
    for (int i = 0; i < hard_consonants.size(); ++i) {
        is_hard_arr[hard_consonants[i] - 'a'] = true;
    }

    // Map to ending.
    for (int i = 0; i < 8; ++i) {
        mp.insert({hard_consonants[i], ends_in[i]});
    }

    // Hard consonstant lookup.
    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        char best = 0;
        int best_dist = INT32_MAX;
        for (int i = 0; i < 8; ++i) {
            int d = abs(c - hard_consonants[i]);
            if (d < best_dist) {
                best_dist = d;
                best = hard_consonants[i];
            }
        }
        to_hard_arr[i] = best;
    }

    string line, word;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        while (ss >> word) {
            print_nimionese(word);
            cout << " ";
        }
        cout << endl;
    }
}