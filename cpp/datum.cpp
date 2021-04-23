#include <iostream>

using namespace std;

int main() {
    int day, month;
    cin >> day >> month;
    const char* days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int days_in_months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int d = 0;
    for (int i = 0; i < month-1; ++i) {
        d += days_in_months[i];
    }
    d += day - 1;
    cout << days[(d + 3) % 7] << endl;
}