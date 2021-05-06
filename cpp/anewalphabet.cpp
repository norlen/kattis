#include <iostream>

using namespace std;

const char* trans[] = {
    "@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]",
    "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2",
};

int main() {
    string in;
    getline(cin, in);
    string out;
    for (auto ch : in) {
        if (ch >= 'a' && ch <= 'z') {
            out += trans[ch - 'a'];
        } else if (ch >= 'A' && ch <= 'Z') {
            out += trans[ch - 'A'];  
        } else {
            out.push_back(ch);
        }
    }
    cout << out << endl;
}