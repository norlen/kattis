#include <iostream>

using namespace std;

int main() {
    int num_articles, impact;
    cin >> num_articles >> impact;

    cout << (num_articles * (impact - 1)) + 1 << endl;
}