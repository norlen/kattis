#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string in;
        cin >> in;

        stack<int> s;
        constexpr int MONEY = 0, INCENSE = 1, GEM = 2;

        int j = 0;
        while (j < in.length()) {
            if (in[j] == '$') {
                s.push(MONEY);
            } else if (in[j] == '|') {
                s.push(INCENSE);
            } else if (in[j] == '*') {
                s.push(GEM);
            } else if (in[j] == 't') {
                if (s.size() == 0 || s.top() != INCENSE) break;
                s.pop();
            } else if (in[j] == 'j') {
                if (s.size() == 0 || s.top() != GEM) break;
                s.pop();
            } else if (in[j] == 'b') {
                if (s.size() == 0 || s.top() != MONEY) break;
                s.pop();
            }
            j++;
        }

        cout << ((j == in.length() && s.size() == 0) ? "YES\n" : "NO\n");
    }
}