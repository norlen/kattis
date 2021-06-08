#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string first, second;
    while (getline(cin, first)) {
        getline(cin, second);
        first = first.substr(first.find(' ')+1);
        second = second.substr(second.find(' ')+1);

        unordered_map<string, int> domain;
        unordered_map<string, int> codomain;
        int s = 0;
        while (true) {
            auto p = first.find(' ', s);
            string ss = first.substr(s, p-s);
            domain.insert({ss, 0});
            if (p == string::npos) break;
            s = p+1;
        }
        s = 0;
        while (true) {
            auto p = second.find(' ', s);
            string ss = second.substr(s, p-s);
            codomain.insert({ss, 0});
            if (p == string::npos) break;
            s = p+1;
        }

        bool not_func = false, not_inj = false, not_sur = false;

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string a, b, temp;
            cin >> a >> temp >> b;
            if (not_func) continue;

            // Not a function if a is not in domain, or b is not in codomain, or domain is mapped more than once.
            if (domain.count(a) == 0 || codomain.count(b) == 0 || domain[a] > 0) {
                not_func = true;
                continue;
            }
            domain[a] += 1;

            // Not injective if there isnt a one to one mapping.
            if (codomain[b] > 0) {
                not_inj = true;
            }
            codomain[b] += 1;
        }
        
        // If they all don't have mappings then it's not surjective.
        if (!not_func) {
            for (auto& kv : codomain) {
                if (kv.second == 0) {
                    not_sur = true;
                    break;
                }
            }
        }

        if (not_func) {
            cout << "not a function\n";
        } else if (not_inj && not_sur) {
            cout << "neither injective nor surjective\n";
        } else if (not_inj) {
            cout << "surjective\n";
        } else if (not_sur) {
            cout << "injective\n";
        } else {
            cout << "bijective\n";
        }

        getline(cin, first); // consume rest of row for this case.
    }
}