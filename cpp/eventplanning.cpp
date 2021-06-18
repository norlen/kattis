#include <iostream>

using namespace std;

int main() {
    int n, b, h, w;
    cin >> n >> b >> h >> w;

    int lowest = -1;
    for (int i = 0; i < h; ++i) {
        int price, rooms;
        cin >> price;
        for (int j = 0; j < w; ++j) {
            cin >> rooms;
            if (rooms < n) continue;
            int cost = n * price;
            if (cost <= b && (lowest == -1 || cost < lowest)) {
                lowest = cost;
            }
        }
    }

    if (lowest == -1) {
        cout << "stay home\n";
    } else {
        cout << lowest << endl;
    }
}