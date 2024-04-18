#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

TreeNode* constructExpressionTree(const string& prefix) {
    stack<TreeNode*> st;
    
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        TreeNode* newNode = new TreeNode(c);
        
        if (isOperator(c)) {
            newNode->left = st.top(); st.pop();
            newNode->right = st.top(); st.pop();
        }
        
        st.push(newNode);
    }
    
    return st.top();
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
    
    delete root;
}

int main() {
    string prefix = "+--a*bc/def";
    
    TreeNode* root = constructExpressionTree(prefix);
    
    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    
    return 0;
}
