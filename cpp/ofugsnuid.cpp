#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    auto nums = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = nums.size() - 1; i >= 0; --i) {
        cout << nums[i] << endl;
    }
}