#include <iostream>
#include <vector>

using namespace std;

int main() {
    string in;
    vector<int> lens;
    int longest = 0;

    while (getline(cin, in)) {
        int l = in.length();
        lens.push_back(l);
        longest = max(longest, l);
    }
    if (lens.size() > 0) lens.pop_back();

    int ans = 0;
    for (auto n : lens) {
        ans += (n - longest) * (n - longest);
    }

    cout << ans << endl;
}