#include <iostream>

using namespace std;

const char* p0 = "pea soup";
const char* p1 = "pancakes";

int main() {
    int n, c;
    string target = "", name, item;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        bool a = false, b = false;

        cin >> c;
        getline(cin, name); // consume end of line whitespace for c.
        getline(cin, name); // get the actual name.
        for (int j = 0; j < c; ++j) {
            getline(cin, item);
            if (item == p0) a = true;
            if (item == p1) b = true;
        }

        if (a && b) {
            target = name;
            break;
        }
    }

    if (target.length() > 0) {
        cout << target << endl;
    } else {
        cout << "Anywhere is fine I guess\n";
    }
}