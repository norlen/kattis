#include <iostream>

using namespace std;

int main() {
    string in;
    cin >> in;

    int score[2] = {0, 0};
    for (int i = 0; i < in.length(); i += 2) {
        if (in[i] == 'A') score[0] += in[i+1] - '0';
        else score[1] += in[i+1] - '0';
    }
    
    cout << (score[0] > score[1] ? 'A' : 'B') << endl;
}