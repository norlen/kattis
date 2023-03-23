#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, p, x, y;
    cin >> n >> p >> x >> y;

    // so for input (4, 10, 2, 3) the order should be something like
    // X X X Y X X X Y X X X Y X X X Y X
    //
    // we group them up so we get
    // (X X X Y) (X X X Y) (X X X Y) (X X X Y) X
    ll groups = p / (n - 1);
    ll group_time = (n - 1) * x + y;
    ll cost_groups = groups * group_time;

    // We can also get some X's after the groups.
    ll remaining = p % (n - 1);
    ll additional_cost = remaining * x;

    ll total_cost = cost_groups + additional_cost;
    cout << total_cost << endl;
}
