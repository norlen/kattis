#include <iostream>
#include <cmath>

using namespace std;

struct C {
    double re, im;
    C(): re(0), im(0) {};
    C(double r, double i): re(r), im(i) {};
};

int main() {
    C c;
    int r, t = 1;
    while (cin >> c.re >> c.im >> r) {
        C z;
        bool converges = true;
        for (int i = 0; i < r; ++i) {
            C next;
            next.re = z.re*z.re - z.im*z.im + c.re;
            next.im = 2.0*z.re*z.im + c.im;
            z = next;

            if (sqrt(z.re*z.re + z.im*z.im) > 2.0) {
                converges = false;
                break;
            }
        }

        cout << "Case " << t++ << ": " << (converges ? "IN\n" : "OUT\n");
    }
}
