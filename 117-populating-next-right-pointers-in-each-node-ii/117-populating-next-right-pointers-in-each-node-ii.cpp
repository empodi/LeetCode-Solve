/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if (!root) return root;
        
        Node *P, *parent;
        
        root->next = nullptr;
        parent = root;
        P = nullptr;
        Node* prev = nullptr;
        
        while (parent) {
            
            if (parent->left && parent->right) {
                if (prev) prev->next = parent->left;
                else P = parent->left;
                
                parent->left->next = parent->right;
                prev = parent->right;
            }
            else if (parent->left) {
                if (prev) prev->next = parent->left;
                else P = parent->left;
                prev = parent->left;
            }
            else if (parent->right) {
                if (prev) prev->next = parent->right;
                else P = parent->right;
                prev = parent->right;
            }
            parent = parent->next;

            if (!parent) {
                if (!P) return root;
                
                parent = P;
                prev = P = nullptr;
            }
        }
        
        return root;
    }
};