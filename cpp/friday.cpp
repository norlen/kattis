#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int t = 0; t < cases; ++t) {
        int d, m;
        cin >> d >> m;

        vector<int> months(m);
        for (int i = 0; i < m; ++i) {
            cin >> months[i];
        }

        // First date in each year is a Sunday.
        // So first Friday is the sixth, and every consecutive one is 7 days after.
        int day = 6;
        int month = 0;
        int count = 0;
        while (true) {
            while (day > months[month]) {
                day -= months[month];
                month++;
                if (month >= months.size()) break;
            }
            if (month >= months.size()) break;
            
            if (day == 13) count++;
            day += 7;
        }
        cout << count << endl;
    }
}