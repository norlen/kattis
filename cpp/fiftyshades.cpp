#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 0;
    for (int i = 0; i < n; ++i) {
        string in;
        cin >> in;

        string lower;
        for (auto ch : in) lower.push_back(tolower(ch));

        if (lower.find("rose") != string::npos) total++;
        else if (lower.find("pink") != string::npos) total++;
    }
    
    if (total == 0) {
        cout << "I must watch Star Wars with my daughter\n";
    } else {
        cout << total << endl;
    }
}