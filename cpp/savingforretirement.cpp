#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int bage, bret, bsave, aage, asave;
    cin >> bage >> bret >> bsave >> aage >> asave;
    double bsavings = (bret - bage) * bsave;
    int strictlymore = (int)bsavings % asave == 0 ? 1 : 0;
    cout << (int)ceil(bsavings / asave) + aage + strictlymore << endl;
}