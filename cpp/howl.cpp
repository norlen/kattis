#include <iostream>

using namespace std;

int main() {
    string in;
    cin >> in;

    // Required: A, H, O, and W at least once.
    // Not allowed:
    // - Two consecutive W or H
    // - H followed by A or W
    // - No A after first O
    cout << "AWA" << in << endl;
}