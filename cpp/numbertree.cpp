#include <iostream>

using namespace std;

int main() {
    string in;
    getline(cin, in);
    auto space = in.find(' ');

    int h;
    if (space != string::npos) {
        h = stoi(in.substr(0, space));
        in = in.substr(space+1, in.length());
    } else {
        h = stoi(in);
        in = in.substr(0,0);
    }
    
    int ch = 0;
    int ind = 0;
    for (auto c : in) {
        ch++;
        if (c == 'L') {
            ind = ind * 2 + 1;
        } else if (c == 'R') {
            ind = ind * 2 + 2;
        }
    }

    int m = 1;
    for (int i = 0; i <= h; ++i) {
        m *= 2;
    }
    cout << m - ind - 1 << endl;
}