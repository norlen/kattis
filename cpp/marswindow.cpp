#include <iostream>

using namespace std;

constexpr int MONTH_DIFF = 26;
constexpr int YEAR_START = 2018;
constexpr int MONTH_START = 4;

int main() {
    int year;
    cin >> year;

    int months = (year - YEAR_START) * 12 - MONTH_START + 12;
    if (months % MONTH_DIFF < 12) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}