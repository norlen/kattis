#include <iostream>

using namespace std;

void print(int a, int b, int c, const char* s) {
    cout << a << (char)s[0] << b << (char)s[1] << c << endl;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c) { print(a, b, c, "+="); return 0; }
    if (a == b + c) { print(a, b, c, "=+"); return 0; }

    if (a - b == c) { print(a, b, c, "-="); return 0; }
    if (b - c == a) { print(a, b, c, "=-"); return 0; }
    
    if (a * b == c) { print(a, b, c, "*="); return 0; }
    if (b * c == a) { print(a, b, c, "=*"); return 0; }
    
    if (a / b == c) { print(a, b, c, "/="); return 0; }
    if (b / c == a) { print(a, b, c, "=/"); return 0; }
}