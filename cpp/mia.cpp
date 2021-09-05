#include <iostream>

using namespace std;

struct D {
    int a;
    int b;
};

void swapd(D& d) {
    if (d.a < d.b) swap(d.a, d.b);
}

bool mia(const D& d) {
    return d.a == 2 && d.b == 1;
}

bool doubles(const D& d) {
    return d.a == d.b;
}

int main() {
    while (true) {
        D f, s;
        cin >> f.a >> f.b >> s.a >> s.b;
        if (f.a == 0 && f.b == 0 && s.a == 0 && s.b == 0) break;

        swapd(f);
        swapd(s);

        int winner = -1; // 0=tie, 1=f, 2=s;
        if (mia(f) || mia(s)) {
            if (mia(f) && mia(s)) {
                winner = 0;
            } else {
                winner = mia(f) ? 1 : 2;
            }
        } else if (doubles(f) || doubles(s)) {
            if (doubles(f) && doubles(s)) {
                if (f.a == s.a) winner = 0;
                else winner = f.a > s.a ? 1 : 2;
            } else {
                winner = doubles(f) ? 1 : 2;
            }
        } else {
            int fv = f.a * 10 + f.b;
            int sv = s.a * 10 + s.b;
            if (fv == sv) {
                winner = 0;
            } else {
                winner = fv > sv ? 1 : 2;
            }
        }

        switch (winner) {
            case 0: cout << "Tie." << endl; break;
            case 1: cout << "Player 1 wins." << endl; break;
            case 2: cout << "Player 2 wins." << endl; break;
        }
    }
}