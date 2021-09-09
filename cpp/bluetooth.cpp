#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Requirements to be able to chew on a side.
    // 1. No blue tooth.
    // 2. At least one tooth upper & lower side.

    // Output:
    // 0 - left side
    // 1 - right side
    // 2 - recommend soup.
    const int UPPER = 0;
    const int LOWER = 1;
    const int RIGHT = 0;
    const int LEFT = 1;
    int teeth[2][2] = { {8, 8}, {8, 8} };
    bool blue[2] = { false, false };
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char sign, num, t;
        cin >> sign >> num >> t;
        // Rigth side has (num, sign).
        int side = num == '+' || num == '-' ? RIGHT : LEFT;
        if (side == RIGHT) swap(sign, num);

        int updown = sign == '+' ? UPPER : LOWER;
        if (t == 'b') {
            blue[side] = true;
        } else {
            teeth[side][updown]--;
        }
    }

    // There is at least one blue tooth, so these ifs are fine.
    bool ok = false;
    if (blue[LEFT] == false && teeth[LEFT][UPPER] >= 1 && teeth[LEFT][LOWER] >= 1) {
        cout << "0\n";
        ok = true;
    }
    if (blue[RIGHT] == false && teeth[RIGHT][UPPER] >= 1 && teeth[RIGHT][LOWER] >= 1) {
        cout << "1\n";
        ok = true;
    }
    if (!ok) {
        cout << "2\n";
    }
}