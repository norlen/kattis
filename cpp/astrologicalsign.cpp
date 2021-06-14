#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

pair<string,int> months[12] = {
    {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
    {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
    {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12},
};

int days_per_month[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

unordered_map<string, int> mp;
int daystothismonth[12];

int dd(const string& month, int day) {
    return daystothismonth[mp[month]-1] + day - 1;
}

int main() {
    int n;
    cin >> n;

    daystothismonth[0] = 0;
    for (int i = 0; i < 11; ++i) {
        daystothismonth[i+1] = daystothismonth[i] + days_per_month[i];
    }

    for (int i = 0; i < 12; ++i) {
        mp.insert(months[i]);
    }

    vector<pair<string, pair<int,int>>> signs;
    signs.push_back({"Aries", {dd("Mar", 21), dd("Apr", 20)}});
    signs.push_back({"Taurus", {dd("Apr", 21), dd("May", 20)}});
    signs.push_back({"Gemini", {dd("May", 21), dd("Jun", 21)}});
    signs.push_back({"Cancer", {dd("Jun", 22), dd("Jul", 22)}});
    signs.push_back({"Leo", {dd("Jul", 23), dd("Aug", 22)}});
    signs.push_back({"Virgo", {dd("Aug", 23), dd("Sep", 21)}});
    signs.push_back({"Libra", {dd("Sep", 22), dd("Oct", 22)}});
    signs.push_back({"Scorpio", {dd("Oct", 23), dd("Nov", 22)}});
    signs.push_back({"Sagittarius", {dd("Nov", 23), dd("Dec", 21)}});
    signs.push_back({"Capricorn", {dd("Dec", 22), dd("Dec", 40)}});
    signs.push_back({"Capricorn", {0, dd("Jan", 20)}});
    signs.push_back({"Aquarius", {dd("Jan", 21), dd("Feb", 19)}});
    signs.push_back({"Pisces", {dd("Feb", 20), dd("Mar", 20)}});

    int d;
    string m;
    for (int i = 0; i < n; ++i) {
        cin >> d >> m;
        d = dd(m, d);
        for (auto& s : signs) {
            if (s.second.first <= d && d <= s.second.second) {
                cout << s.first << endl;
                break;
            }
        }
    }
}