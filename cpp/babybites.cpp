#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool makes_sense = true;
    for (int i = 0; i < n; ++i) {
        string in;
        cin >> in;
        if (in != "mumble") {
            int expected = stoi(in);
            if (expected != i+1) {
                makes_sense = false;
                break;
            }
        }
    }
    cout << (makes_sense ? "makes sense\n" : "something is fishy\n");
}