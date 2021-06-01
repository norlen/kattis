#include <iostream>

using namespace std;

int main() {
    char ch;
    string in, out;
    cin >> ch >> in;

    if (ch == 'E') {
        ch = 0;
        int count = -1;
        for (int i = 0; i < in.length(); ++i) {
            if (ch != in[i]) {
                ch = in[i];
                if (count != -1) out.push_back('0' + count);
                out.push_back(in[i]);
                count = 1;
            } else {
                count++;
            }
        }
        out.push_back('0' + count);
    } else {
        for (int i = 0; i < in.length(); i += 2) {
            char ch = in[i];
            int count = in[i+1] - '0';
            for (int j = 0; j < count; ++j) out.push_back(ch);
        }
    }

    cout << out << endl;
}