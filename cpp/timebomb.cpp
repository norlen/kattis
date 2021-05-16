#include <iostream>
#include <vector>

using namespace std;

/* Digits
***   * *** *** * * *** *** *** *** ***
* *   *   *   * * * *   *     * * * * *
* *   * *** *** *** *** ***   * *** ***
* *   * *     *   *   * * *   * * *   *
***   * *** ***   * *** ***   * *** ***
*/

const char* digits[] = {
    "******   ******", // 0
    "          *****", // 1
    "* **** * **** *", // 2
    "* * ** * ******", // 3
    "***    *  *****", // 4
    "*** ** * ** ***", // 5
    "****** * ** ***", // 6
    "*    *    *****", // 7
    "****** * ******", // 8
    "*** ** * ******", // 9
};

int parse_digit(const string& s) {
    for (int i = 0; i < 10; ++i) {
        if (s == digits[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    string in;
    vector<string> input;
    while (getline(cin, in)) input.push_back(in);

    int n = (input[0].size()+1) / 4;
    vector<string> nums(n);
    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 5; ++i) {
                nums[k].push_back(input[i][4*k + j]);
            }
        }
    }

    int num = 0;
    for (auto& s : nums) {
        int d = parse_digit(s);
        if (d == -1) {
            num = 1;
            break;
        }
        num *= 10;
        num += d;
    }
    if (num % 6 == 0) {
        cout << "BEER!!\n";
    } else {
        cout << "BOOM!!\n";
    }
}