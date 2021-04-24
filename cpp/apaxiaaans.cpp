#include <iostream>

using namespace std;

int main() {
    string in, out;
    cin >> in;

    out.push_back(in[0]);
    for (int i = 1; i < in.size(); ++i) {
        if (in[i-1] != in[i]) {
            out.push_back(in[i]);
        }
    }
    cout << out << endl;
}