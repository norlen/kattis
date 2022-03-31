#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Token {
    bool is_op = false;
    char op = 0;
    int val = 0;

    Token(int val): is_op(false), val(val) {}
    Token(char ch, bool is_op): is_op(is_op), op(ch) {}
};

class BinExp {
public:
    shared_ptr<BinExp> lhs = nullptr;
    shared_ptr<BinExp> rhs = nullptr;
    char op = 0;
    int value = -1;
    char var = 0;
    bool is_value = false;

    BinExp(BinExp lhs, BinExp rhs, char op) {
        this->lhs = make_shared<BinExp>(lhs);
        this->rhs = make_shared<BinExp>(rhs);
        this->op = op;
    }
    BinExp(int value): is_value(true), value(value) {}
    BinExp(char var): var(var) {}
};

BinExp parse(const vector<Token>& tokens, int& i) {
    const Token token = tokens[i];
    i++;
    cout << "Token is_op=" << token.is_op << ", token.op=" << token.op << ", val=" << token.val << endl;

    if (token.is_op) {
        auto lhs = parse(tokens, i);
        auto rhs = parse(tokens, i);
        if (lhs.op == 0 && rhs.op == 0) {
            int v = 0;
            if (token.op == '+') {
                v = lhs.value + rhs.value;
            } else if (token.op == '-') {
                v = lhs.value - rhs.value;
            } else {
                v = lhs.value * rhs.value;
            }
            return BinExp(v);
        } else {
            return BinExp(lhs, rhs, token.op);
        }
    } else {
        if (token.op) {
            return BinExp(token.op);
        } else {
            return BinExp(token.val);
        }
    }
}

void print_binexp(BinExp* e) {
    cout << "op=" << e->op << ", e->var=" << e->var << ", e->value=" << e->value << endl;
    if (e->op) {
        cout << e->op << " ";
        print_binexp(e->lhs.get());
        print_binexp(e->rhs.get());
    } else if (e->var) {
        cout << e->var << " ";
    } else {
        cout << e->value << " ";
    }
}

int main() {
    string line;
    int c = 1;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        string t;

        vector<Token> tokens;
        while (ss >> t) {
            if (t[0] == '+' || t[0] == '-' || t[0] == '*') {
                tokens.push_back(Token(t[0], true));
            } else {
                if (t[0] >= '0' && t[0] <= '9') {
                    int v = stoi(t);
                    tokens.push_back(Token(v));
                } else {
                    tokens.push_back(Token(t[0], false));
                }
            }
        }

        int i = 0;
        BinExp root = parse(tokens, i);

        cout << "Case " << c++ << ": ";
        print_binexp(&root);
        cout << endl;



    }
}