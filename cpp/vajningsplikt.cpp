#include <iostream>

using namespace std;

int rel(const string& me, const string& other) {
    switch (me[0]) {
        case 'N': {
            switch (other[0]) {
                case 'E': return -1;
                case 'S': return 0;
                case 'W': return 1;
            }
        }
        case 'E': {
            switch (other[0]) {
                case 'N': return 1;
                case 'S': return -1;
                case 'W': return 0;
            }
        }
        case 'S': {
            switch (other[0]) {
                case 'N': return 0;
                case 'E': return 1;
                case 'W': return -1;
            }
        }
        case 'W': {
            switch (other[0]) {
                case 'N': return -1;
                case 'E': return 0;
                case 'S': return 1;
            }
        }
    }
    return -10;
}

int main() {
    string my, des, other;
    cin >> my >> des >> other;

    int d = rel(my, des);
    int o = rel(my, other);

    cout << (o <= d ? "No\n" : "Yes\n");
}