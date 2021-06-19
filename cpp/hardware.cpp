#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void add_to_digits(vector<int>& d, int num) {
    while (num > 0) {
        d[num % 10]++;
        num /= 10;
    }
}

int main() {
    int p;
    string in;
    cin >> p;
    getline(cin, in);
    getline(cin, in);

    for (int t = 0; t < p; ++t) {
        string addr = in;
        getline(cin, in);
        string num_addrs = in;

        vector<int> digits(10, 0);
        while (getline(cin, in)) {
            if (!(in[0] == '+' || (in[0] >= '0' && in[0] <= '9'))) {
                break;
            }

            if (in[0] == '+') {
                stringstream ss;
                ss << in;
                int s, e, step;
                char tmp;
                ss >> tmp >> s >> e >> step;
                for (int i = s; i <= e; i += step) {
                    add_to_digits(digits, i);
                }
            } else {
                add_to_digits(digits, stoi(in));
            }
        }

        int sum = 0;
        cout << addr << endl;
        cout << num_addrs << endl;
        for (int i = 0; i < 10; ++i) {
            cout << "Make " << digits[i] << " digit " << i << endl;
            sum += digits[i];
        }
        cout << "In total " << sum << " digit" << (sum > 1 ? "s" : "") << endl;
    }
}