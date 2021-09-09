#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    // For the re-distribution to work, in a non-decreasing working it always for that the next room
    // has enough exams at least. To prevent a student from getting the same in the first room, sum(A[1..]) must be >= than A[0].
    sort(nums.rbegin(), nums.rend());
    int s = 0;
    for (int i = 1; i < nums.size(); ++i) s += nums[i].first;
    bool possible = s >= nums[0].first;

    if (!possible) {
        cout << "impossible\n";
    } else {
        for (auto n : nums) cout << n.second + 1 << " "; // 1 indexed in output.
        cout << endl;
    }
}
