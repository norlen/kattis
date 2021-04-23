#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "P=NP") {
            cout << "skipped\n";
            continue;
        }

        size_t plus = s.find('+');
        int a = stoi(s.substr(0, plus));
        int b = stoi(s.substr(plus+1, s.length()));
        cout << a + b << endl;
    }
}