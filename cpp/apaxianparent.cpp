#include <iostream>

using namespace std;

int main() {
    string y, p;
    cin >> y >> p;

    char last = y[y.length()-1];
    if (last == 'a' || last == 'i' || last == 'o' || last == 'u') {
        y.pop_back();
            y += "ex";
    } else if (last == 'e') {
        y.push_back('x');
    } else if (last == 'x') {
        if (y[y.length()-2] != 'e') {
            y += "ex";
        }
    } else {
        y += "ex";
    }

    cout << y + p << endl;
}