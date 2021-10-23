#include <iostream>

using namespace std;

int main() {
    double n, k, p;
    cin >> n >> k >> p;
    double e = n*p - k;
    cout << (e < 0 ? "spela\n" : "spela inte!\n"); 
}
