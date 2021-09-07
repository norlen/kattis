#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int mul[] = { 9, 4, 4, 4, 7 };
pair<double, double> parse(const string& line) {
    double fat = 0.0, fat_percent = 0.0;
    double total = 0.0;
    double percent = 0;

    stringstream ss;
    ss << line;
    int amount;
    char unit;
    int add;
    for (int i = 0; i < 5; ++i) {
        ss >> amount;
        ss >> unit;
        if (unit == 'g') {
            amount *= mul[i];
        } else if (unit == '%') {
            percent += static_cast<double>(amount) / 100.0;
            amount = 0;
        }
        total += amount;

        if (i == 0) {
            if (unit == '%') {
                fat_percent = percent;
            } else {
                fat = amount;
            }
        }
    }

    total /= (1.0 - percent);
    if (fat_percent > 0.0) {
        fat = total * fat_percent;
    }
    return {fat, total};
}

int main() {
    // Example:
    // 3g 10g 10% 0g 0g
    // fat, protein, sugar, starch, alcohol.
    // units: g (grams), C (calories), % (percent calories).

    // fat contains 9 Calories/g of food energy.
    // Protein, sugar, and starch contain about 4 Calories/g
    // alcohol contains about 7 Calories/g

    string curr, prev;
    double total_calories = 0.0;
    double fat_calories = 0.0;
    while (true) {
        getline(cin, curr);
        if (curr[0] == '-') {
            if (prev[0] == '-') {
                break;
            }
            double f = fat_calories / total_calories * 100.0;
            cout << round(f) << "%\n";
            total_calories = 0.0;
            fat_calories = 0.0;
        }
        auto p = parse(curr);
        fat_calories += p.first;
        total_calories += p.second;
        prev = curr;
    }
}