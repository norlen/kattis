#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    char name[40];
    for (int i = 0; i < n; ++i) {
        // EligibleContestant 2013/09/01 1995/03/12 10
        int sy, sm, sd, by, bm, bd, c;
        scanf("%s %d/%d/%d %d/%d/%d %d", name, &sy, &sm, &sd, &by, &bm, &bd, &c);
        cout << name;
        if (sy >= 2010 || by >= 1991) {
            cout << " eligible\n";
        } else if (c >= 41) {
            cout << " ineligible\n";
        } else {
            cout << " coach petitions\n";
        }
    }
}