#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string in;
    getline(cin, in);

    int words = 0;
    int wordswithae = 0;
    bool new_word = true;
    bool containsae = false;
    for (int i = 0; i < in.length(); ++i) {
        if (isspace(in[i])) {
            new_word = true;
            containsae = false;
        } else {
            if (containsae) continue;

            if (new_word) {
                words++;
                new_word = false;
            }
            if (i > 0 && in[i] == 'e' && in[i-1] == 'a') {
                containsae = true;
                wordswithae++;
            }
        }
    }
    if ((double)wordswithae / (double)words >= 0.4) {
        cout << "dae ae ju traeligt va\n";
    } else {
        cout << "haer talar vi rikssvenska\n";
    }
}