#include <iostream>
#include <stack>

using namespace std;

int main() {
    string in;
    getline(cin, in);
    getline(cin, in);

    stack<char> s;
    bool err = false;
    int i = 0;
    for (; i < in.length() && !err; ++i) {
        char ch = in[i];
        switch (ch) {
            case '(': s.push(')'); break;
            case '[': s.push(']'); break;
            case '{': s.push('}'); break;
        }

        if (ch == ')' || ch == ']' || ch == '}') {
            if (s.size() == 0 || s.top() != ch) {
                err = true;
                break;
            } else {
                s.pop();
            }
        }
    }

    if (err) {
        cout << in[i] << " " << i << endl;
    } else {
        cout << "ok so far\n";
    }
}