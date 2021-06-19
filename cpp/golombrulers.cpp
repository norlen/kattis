#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;

        vector<int> nums;
        int num, largest = 0;
        while (ss >> num) {
            nums.push_back(num);
            largest = max(largest, num);
        }
        sort(nums.begin(), nums.end());

        vector<bool> m(largest, false);
        bool not_a_ruler = false;
        for (int i = 0; i < nums.size() && !not_a_ruler; ++i) {
            for (int j = i+1; j < nums.size() && !not_a_ruler; ++j) {
                int a = nums[i];
                int b = nums[j];
                int d = b - a - 1;
                if (d >= largest || m[d]) {
                    not_a_ruler = true;
                    break;
                }
                m[d] = true;
            }
        }

        if (not_a_ruler) {
            cout << "not a ruler\n";
        } else {
            vector<int> missing;
            for (int i = 0; i < m.size(); ++i) {
                if (m[i] == false) missing.push_back(i+1);
            }
            
            if (missing.size() == 0) {
                cout << "perfect\n";
            } else {
                cout << "missing ";
                for (int i = 0; i < missing.size(); ++i) {
                    cout << missing[i] << (i == missing.size()-1 ? "\n" : " ");
                }
            }
        }
    }
}