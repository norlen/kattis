#include <iostream>

using namespace std;

int main() {
    string month, day, year;
    while (cin >> month) {
        int sh, sm, eh, em;
        char sep;
        cin >> day >> year >> sh >> sep >> sm >> eh >> sep >> em;
        int hours = eh - sh;
        int minutes = em - sm;
        if (minutes < 0) {
            minutes += 60;
            hours--;
        }
        cout << month << " " << day << " " << year << " " << hours << " hours " << minutes << " minutes\n";
    }
}