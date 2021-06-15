#include <iostream>
#include <vector>

using namespace std;

struct B {
    int t;
    double x1, y1, x2, y2;
};

int main() {
    int n, m = -1;
    string desc;
    while (true) {
        cin >> n;
        if (n == 0) break;
        if (m != -1) cout << endl;

        vector<B> boxes(n);
        for (int i = 0; i < n; ++i) {
            cin >> boxes[i].x1 >> boxes[i].y1 >> boxes[i].x2 >> boxes[i].y2 >> desc;
            if (desc == "small") {
                boxes[i].t = 0;
            } else if (desc == "medium") {
                boxes[i].t = 1;
            } else {
                boxes[i].t = 2;
            }
        }
        
        cin >> m;
        for (int i = 0; i < m; ++i) {
            double x, y;
            cin >> x >> y >> desc;
            int corr = 0;
            if (desc == "medium") {
                corr = 1;
            } else if (desc == "large") {
                corr = 2;
            }

            int where = -1;
            for (auto& b : boxes) {
                if (x >= b.x1 && x <= b.x2 && y >= b.y1 && y <= b.y2) {
                    where = b.t;
                    break;
                }
            }
            
            cout << desc << " ";
            if (where == corr) cout << "correct\n";
            else if (where == -1) cout << "floor\n";
            else if (where == 0) cout << "small\n";
            else if (where == 1) cout << "medium\n";
            else cout << "large\n";
        }
    }
}