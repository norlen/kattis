#include <iostream>
#include <vector>

using namespace std;

int main() {
    string in;
    vector<int> n;
    for (int i = 0; i < 5; ++i) {
        cin >> in;
        if (in.find("FBI") != string::npos) {
            n.push_back(i + 1);
        }
    }

    if (n.size() == 0) {
        cout << "HE GOT AWAY!\n";
    } else {
        cout << n[0];
        for (int i = 1; i < n.size(); ++i) {
            cout << " " << n[i];
        }
        cout << endl;
    }
}