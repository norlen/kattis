#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums(3);
    for (int i = 0; i < 3; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int d0 = nums[1] - nums[0];
    int d1 = nums[2] - nums[1];
    int ans = 0;
    if (d0 == d1) {
        ans = nums[2] + d0;
        if (ans > 100) {
            ans = nums[0] - d0;
        }
    } else if (d0 == d1/2) {
        ans = nums[1] + d0;
    } else {
        ans = nums[0] + d1;
    }
    cout << ans << endl;
}