#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string in;
    int previous_length = -1;

    vector<int> positions;
    vector<int> counts;

    while (true) {
        auto& res = getline(cin, in);
        if (previous_length != -1 && in.length() != previous_length) {
            // output.
            sort(positions.begin(), positions.end());
            for (auto c : counts) {
                string out;
                out.reserve(previous_length);
                for (int k = 0; k < previous_length; k++) out.push_back('.');
                for (int k = 0; k < c; ++k) {
                    int l = positions[positions.size()-1];
                    positions.pop_back();
                    out[l] = '*';
                }
                cout << out << endl;
            }

            positions.clear();
            counts.clear();
        }
        if (!res) break;

        int count = 0;
        for (int i = 0; i < in.length(); ++i) {
            if (in[i] == '*') {
                count++;
                positions.push_back(i);
            }
        }
        counts.push_back(count);

        previous_length = in.length();
    }
}