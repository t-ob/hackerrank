#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int val;
    struct node* left;
    struct node* right;
    int ht;
};

node* insert(node* root, int new_val) {
    if (!root) {
        node* new_node;
        new_node = new node();
        new_node->val = new_val;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->ht = 0;

        return new_node;
    }

    if (new_val <= root->val)
        root->left = insert(root->left, new_val);
    else
        root->right = insert(root->right, new_val);

    int ht_left = root->left ? root->left->ht : -1;
    int ht_right = root->right ? root->right->ht : -1;

    if (abs(ht_left - ht_right) > 1) {
        // Rebalance
        node* pivot;
        if (ht_left > ht_right) {
            // Go right
            pivot = root->left;
            // Simple rotation
            if ((pivot->left ? pivot->left->ht : -1) > (pivot->right ? pivot->right->ht : -1)) {
                // Left-heavy; simple rotation
                root->left = pivot->right;
                pivot->right = root;
                root = pivot;
            } else {
                // Double rotation
                node* b;
                b = pivot->right;

                pivot->right = b->left;
                b->left = pivot;
                pivot = b;
                root->left = pivot->right;
                pivot->right = root;
                root = pivot;
            }
        } else {
            // Go left
            pivot = root->right;
            // Simple rotation
            if ((pivot->right ? pivot->right->ht : -1) > (pivot->left ? pivot->left->ht : -1)) {
                // Right-heavy; simple rotation
                root->right = pivot->left;
                pivot->left = root;
                root = pivot;
            } else {
                // Double rotation
                node* b;
                b = pivot->left;

                pivot->left = b->right;
                b->right = pivot;
                pivot = b;
                root->right = pivot->left;
                pivot->left = root;
                root = pivot;
            }
        }
    }

    root->ht = 1 + max(
            ht_left,
            ht_right
    );

    return root;
}

void inOrder(node* root) {
    if (root->left)
        inOrder(root->left);
    cout << root->val << " ";
    if (root->right)
        inOrder(root->right);
}

int main() {
    node *root = new node();
    root = NULL;
    root = insert(root, 3);
    std::cout << root->val << std::endl;
    std::cout << root->ht << std::endl;

    inOrder(root);
    cout << endl << endl;

    root = insert(root, 5);
    std::cout << root->val << std::endl;
    std::cout << root->ht << std::endl;

    inOrder(root);
    cout << endl << endl;

    root = insert(root, 1);
    std::cout << root->val << std::endl;
    std::cout << root->ht << std::endl;

    inOrder(root);
    cout << endl << endl;

    node *new_root = new node();
    new_root = NULL;
//    for (int i = 1; i < 0x10; ++i) {
//        new_root = insert(root, i);
//        std::cout << new_root->val << std::endl;
//        std::cout << new_root->ht << std::endl;
//        inOrder(new_root);
//    }

    new_root = insert(new_root, 3);
    new_root = insert(new_root, 2);
    new_root = insert(new_root, 1);

    inOrder(new_root);
    std::cout << std::endl;

    node *a = new node();
    a = NULL;
    a = insert(a, 4);
    a = insert(a, 1);
    a = insert(a, 2);

    inOrder(a);
    std::cout << std::endl;

    node *b = new node();
    b = NULL;
    for (int i = 1; i < 0x10; ++i) {
        b = insert(b, i);
        inOrder(b);
        std::cout << std::endl << b->ht << std::endl;
    }

    return 0;
}