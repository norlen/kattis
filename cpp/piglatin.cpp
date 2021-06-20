#include <iostream>
#include <sstream>
#include <vector>
#include <string_view>

using namespace std;

constexpr char vowels[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };

int main() {
    vector<bool> is_vowel(26, false);
    for (int i = 0; i < 6; ++i) {
        is_vowel[vowels[i] - 'a'] = true;
    }

    string line;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        string word;
        while (ss >> word) {
            if (is_vowel[word[0]-'a']) {
                cout << word << "yay ";
            } else {
                size_t first_vowel = 0;
                for (int i = 1; i < word.length(); ++i) {
                    if (is_vowel[word[i]-'a']) {
                        first_vowel = i;
                        break;
                    }
                }
                auto f = string_view(word.c_str(), first_vowel);
                auto s = string_view(&word.c_str()[first_vowel], word.length()-first_vowel);
                cout << s << f << "ay ";
            }
        }
        cout << endl;
    }
}