#include <iostream>

using namespace std;

int main() {
    string in;
    getline(cin, in);

    string out;
    for (int i = 0; i < in.length(); ++i) {
        char ch = in[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            i += 2;
        }
        out.push_back(ch);
    }
    cout << out << endl;
}