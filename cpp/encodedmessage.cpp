#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int w = ceil(sqrt(static_cast<double>(s.length())));
        string out;
        
        int row = 0;
        int col = w-1;
        for (int j = 0; j < s.length(); ++j) {
            int ind = row * w + col;
            out.push_back(s[ind]);
            row++;
            if (row >= w) {
                row = 0;
                col--;
            }
        }
        cout << out << endl;
    }
}