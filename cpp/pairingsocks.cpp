#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(2*n);
    for (int i = 0; i < 2*n; ++i) {
        cin >> nums[i];
    }

    vector<int> s;
    for (int i = 0; i < 2*n; ++i) {
        if (s.size() > 0 && nums[i] == s.back()) {
            s.pop_back();
        } else {
            s.push_back(nums[i]);
        }
    }

    if (!s.empty()) {
        cout << "impossible\n";
    } else {
        cout << 2*n << endl;
    }
}
