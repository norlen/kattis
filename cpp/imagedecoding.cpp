#include <iostream>

using namespace std;

int main() {
    bool first = true;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        string in;
        getline(cin, in);

        if (first) first = false;
        else cout << endl;

        int len = -1;
        bool err = false;
        for (int i = 0; i < n; ++i) {
            getline(cin, in);
            char ch = in[0];
            int s = 2;
            string out;

            for (int j = 2; j < in.length(); ++j) {
                if ((s != j && in[j] == ' ') || (j == in.length()-1)) {
                    int amount = stoi(in.substr(s, j-s+1));
                    for (int k = 0; k < amount; ++k) {
                        out.push_back(ch);
                    }
                    ch = ch == '.' ? '#' : '.';
                    s = j+1;
                }
            }

            if (len == -1) len = out.length();
            if (len != out.length()) err = true;
            cout << out << endl;
        }
        if (err) {
            cout << "Error decoding image\n";
        }
    }
}