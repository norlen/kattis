#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    unordered_map<string, int> vars;

    string in;
    while (getline(cin, in)) {
        if (in.size() == 1 && in[0] == '0') break;
        vector<string> unknown_args;

        // Process input.
        stringstream s;
        s << in;
        int sum = 0;
        if (in.find('=') != string::npos) {
            string var;
            char eq;
            int n;
            s >> var >> eq >> n;
            if (vars.count(var) == 0) {
                vars.insert({var, n});
            } else {
                vars[var] = n;
            }

            continue; // Skip output.
        } else {
            string c;
            while (s >> c) {
                if (c[0] == '+') continue;

                if (c[0] >= '0' && c[0] <= '9') {
                    sum += stoi(c);
                } else if (vars.count(c) == 0) {
                    unknown_args.push_back(c);
                } else {
                    sum += vars[c];
                }
            }
        }

        // Output.
        if (sum != 0.0) {
            cout << sum << (unknown_args.size() > 0 ? " + " : "");
        }
        for (int i = 0; i < unknown_args.size(); ++i) {
            cout << unknown_args[i] << (i == unknown_args.size()-1 ? "" : " + ");
        }
        cout << endl;
    }
}