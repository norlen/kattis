#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class TreeNode {
public:
    TreeNode(int v): v(v), left(nullptr), right(nullptr) {};

    int v;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;
};

void insert(TreeNode* root, int n) {
    if (root->v < n) {
        if (root->left) {
            insert(root->left.get(), n);
        } else {
            root->left = make_unique<TreeNode>(n);
        }
    } else {
        if (root->right) {
            insert(root->right.get(), n);
        } else {
            root->right = make_unique<TreeNode>(n);
        }
    }
}

void to_str(TreeNode* root, string& s) {
    if (root == nullptr) return;

    s.push_back('.');

    if (root->left == nullptr && root->right == nullptr) return;
    s.push_back('[');
    to_str(root->left.get(), s);
    s.push_back(']');

    s.push_back('[');
    to_str(root->right.get(), s);
    s.push_back(']');
}

int main() {
    int n, k;
    cin >> n >> k;

    unordered_set<string> vars;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        auto root = make_unique<TreeNode>(v);

        for (int j = 1; j < k; ++j) {
            cin >> v;
            insert(root.get(), v);
        }

        string rep;
        to_str(root.get(), rep);
        vars.insert(rep);
    }

    cout << vars.size() << endl;
}
