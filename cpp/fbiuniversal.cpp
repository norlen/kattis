#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    string vals = "0123456789ACDEFHJKLMNPRTVWX";
    unordered_map<char, int> map;
    for (int i = 0; i < vals.size(); ++i) {
        map.insert({vals[i], i});
    }

    for (int i = 0; i < n; ++i) {
        string in;
        cin >> m >> in;

        bool valid = in.size() == 9;
        if (valid) {
            for (int j = 0; j < in.size(); ++j) {
                bool valid_char = in[j] >= 'A' && in[j] <= 'Z' || in[j] >= '0' && in[j] <= '9';
                if (!valid_char) {
                    valid = false;
                    break;
                }
                switch (in[j]) {
                    case 'B': in[j] = '8'; break;
                    case 'G': in[j] = 'C'; break;
                    case 'I': in[j] = '1'; break;
                    case 'O': in[j] = '0'; break;
                    case 'Q': in[j] = '0'; break;
                    case 'S': in[j] = '5'; break;
                    case 'U': in[j] = 'V'; break;
                    case 'Y': in[j] = 'V'; break;
                    case 'Z': in[j] = '2'; break;
                }
            }

            int check_dig = (2*map[in[0]] + 4*map[in[1]] + 5*map[in[2]] + 7*map[in[3]] + 8*map[in[4]] + 10*map[in[5]] + 11*map[in[6]] + 13*map[in[7]]) % 27;
            valid = in[8] == vals[check_dig];
        }

        if (valid) {
            long long base10value = 0;
            long long mul = 1;
            for (int i = 7; i >= 0; --i) {
                base10value += map[in[i]] * mul;
                mul *= 27;
            }

            cout << m << " " << base10value << endl;
        } else {
            cout << m << " Invalid\n";
        }
    }
}