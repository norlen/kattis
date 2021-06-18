#include <iostream>

using namespace std;

int calc(char op, int lhs, int rhs) {
    switch (op) {
        case '*': return lhs*rhs;
        case '+': return lhs+rhs;
        case '-': return lhs-rhs;
        case '/': return lhs/rhs;
    }
    return -1;
}

bool divbyzero(char op, int rhs) {
    return (op == '/' && rhs == 0);
}

constexpr char OPS[4] = {'*', '+', '-', '/'};

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    bool found_sol = false;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!divbyzero(OPS[i], b) && !divbyzero(OPS[j], d) && calc(OPS[i], a, b) == calc(OPS[j], c, d)) {
                found_sol = true;
                cout << a << " " << OPS[i] << " " << b << " = " << c << " " << OPS[j] << " " << d << endl;
            }
        }
    }
    
    if (!found_sol) {
        cout << "problems ahead\n";
    }
}