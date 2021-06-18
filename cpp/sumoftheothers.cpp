#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        int num;
        vector<int> nums;
        while (ss >> num) {
            nums.push_back(num);
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // assume this is the sum.
        for (auto n : nums) {
            if (sum - n == n) {
                cout << n << endl;
                break;
            }
        }
    }
}
