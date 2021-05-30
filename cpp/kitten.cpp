#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int target;
    cin >> target;
    string in;
    getline(cin, in);

    unordered_map<int, int> e;
    bool done = false;
    while (!done) {
        getline(cin, in);

        int s = 0;
        int a = -1;
        while (true) {
            auto n = in.find(' ', s);
            auto num = stoi(in.substr(s, n-s));
            if (num == -1) {
                done = true;
                break;
            }
            if (a == -1) {
                a = num;
            } else {
                // Insert edges reversed.
                // It's a tree so there should only be one edge.
                e.insert({num, a});
            }
            if (n == string::npos) break;
            s = n+1;
        }
    }

    int u = target;
    while (e.count(u) > 0) {
        cout << u << " ";
        u = e[u];
    }
    cout << u << endl;
}