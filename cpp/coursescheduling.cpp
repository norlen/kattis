#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> courses;
    set<string> applied;
    for (int i = 0; i < n; ++i) {
        string first, last, course;
        cin >> first >> last >> course;
        string s = first + " " + last + " " + course;

        if (applied.count(s) > 0) continue;
        applied.insert(s);

        if (courses.count(course) == 0) courses.insert({course, 0});
        courses[course]++;
    }
    for (auto& kv : courses) {
        cout << kv.first << " " << kv.second << endl;
    }
}