#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

struct r {
    ll a, b;
    r(ll c, ll d): a(c), b(d) {}
};

void rgcd(r& o) {
    auto g = gcd(o.a, o.b);
    o.a /= g;
    o.b /= g;
}

r sub(r lhs, r rhs) {
    r o(lhs.a*rhs.b - rhs.a*lhs.b, lhs.b*rhs.b);
    rgcd(o);
    return o;
}

r div(r lhs, r rhs) {
    r o(lhs.a * rhs.b, lhs.b * rhs.a);
    rgcd(o);
    return o;
}

int main() {
    ll d, n;
    char tmp;
    cin >> d >> tmp >> n;
    if (d < 0 && n < 0) {
        d = -d;
        n = -n;
    }
    if (n < 0) swap(d, n);

    // F = 9/5C + 32
    auto ans = r(d, n);
    rgcd(ans);
    ans = sub(ans, r(32, 1));
    ans = div(ans, r(9, 5));

    cout << ans.a << "/" << ans.b << endl;
}