#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c, curr;
    cin >> n >> curr;

    vector<int> nums;
    nums.push_back(curr);
    for (int i = 1; i < n; ++i) {
        cin >> c;
        if (c > curr) {
            curr = c;
            nums.push_back(c);
        }
    }
    cout << nums.size() << endl;
    for (auto& n : nums) cout << n << " ";
    cout << endl;
}