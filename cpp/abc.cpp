#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    array<int, 3> nums;
    for (int i = 0; i < nums.size(); ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    string s;
    cin >> s;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[s[i] - 'A'] << (i == 2 ? "\n" : " ");
    }
}