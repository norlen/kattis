#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    unordered_map<string, vector<int>> places;

    int a, b, year, time;
    string in;
    cin >> a;

    for (int i = 0; i < a; ++i) {
        cin >> in >> year;
        places[in].push_back(year);
    }

    for (auto& place : places) {
        sort(place.second.begin(), place.second.end());
    }

    cin >> b;
    for (int i = 0; i < b; ++i) {
        cin >> in >> time;
        cout << places[in][time - 1] << endl;
    }
}
