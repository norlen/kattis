#include <iostream>
#include <algorithm>
#include <vector>

void backwards(std::vector<int>& vec);
std::vector<int> everyOther(const std::vector<int>& vec);
int smallest(const std::vector<int>& vec);
int sum(const std::vector<int>& vec);
int veryOdd(const std::vector<int>& vec);

int main() {
    std::vector<int> test = {1, 2, 5, 3, 2, 5};
    std::vector<int> expected = {5, 2, 3, 5, 2, 1};
    backwards(test);
    if (test != expected) {
        std::cerr << "backwards() was incorrect" << std::endl;
        exit(1);
    }

    test = {1, 2, 5, 3, 2, 5};
    expected = {1, 5, 2};
    std::vector<int> got = everyOther(test);
    if (got != expected) {
        std::cerr << "everyOther() was incorrect" << std::endl;
        exit(1);
    }

    test = {1, 2, 5, 3, 2, 5};
    int ans = smallest(test);
    if (ans != 1) {
        std::cerr << "smallest() was incorrect" << std::endl;
        exit(1);
    }

    test = {1, 2, 5, 3, 2, 5};
    ans = sum(test);
    if (ans != 1+2+5+3+2+5) {
        std::cerr << "sum() was incorrect" << std::endl;
        exit(1);
    }

    test = {1, 2, 5, 3, 2, 5};
    ans = veryOdd(test);
    if (ans != 2) {
        std::cerr << "veryOdd() was incorrect" << std::endl;
        exit(1);
    }
    std::cerr << "OK!" << std::endl;
}

//#include "vectorfunctions.h"

// Reverse vector
void backwards(std::vector<int>& vec){
    for (int i = 0; i < vec.size()/2; ++i) {
        std::swap(vec[i], vec[vec.size() - 1 - i]);
    }
}

// Return every other element, starting with first.
std::vector<int> everyOther(const std::vector<int>& vec){
    std::vector<int> out(vec.size() / 2 + vec.size() % 2);
    for (int i = 0; i < vec.size(); i += 2) {
        out[i/2] = vec[i];
    }
    return out;
}

int smallest(const std::vector<int>& vec){
    int smallest = vec.size() > 0 ? vec[0] : 0;
    for (int i = 1; i < vec.size(); ++i) {
        smallest = std::min(smallest, vec[i]);
    }
    return smallest;
}

int sum(const std::vector<int>& vec){
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
        sum += vec[i];
    }
    return sum;
}

// Odd numbers with odd indexes.
int veryOdd(const std::vector<int>& suchVector){
    int c = 0;
    for (int i = 1; i < suchVector.size(); i += 2) {
        if (suchVector[i] % 2 == 1) {
            c++;
        }
    }
    return c;
}