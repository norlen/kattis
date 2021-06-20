#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int p, n;
    cin >> p;

    for (int t = 0; t < p; ++t) {
        cin >> n;

        vector<int> nums(n);
        bool permuted = false, non_arith = false;

        bool pos_dir = true;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            if (i == 1) {
                pos_dir = nums[i-1] > nums[i];
            } else if (!permuted && i > 1 && pos_dir != (nums[i-1] > nums[i])) {
                permuted = true;
            }
        }

        if (permuted) {
            sort(nums.begin(), nums.end());
        }

        int d = nums[1] - nums[0];
        for (int i = 2; i < n; ++i) {
            if ((nums[i]-nums[i-1]) != d) {
                non_arith = true;
                break;
            }
        }

        if (non_arith) {
            cout << "non-arithmetic\n";
        } else if (permuted) {
            cout << "permuted arithmetic\n";
        } else {
            cout << "arithmetic\n";
        }
    }
}