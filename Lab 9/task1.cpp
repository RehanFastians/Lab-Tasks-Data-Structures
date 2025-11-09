#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    int height;
    Node(int v)
    {
        value = v;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree
{
    Node *root;

    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(Node *node)
    {
        if (!node)
            return;
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node *balanceNode(Node *node)
    {
        int bal = getBalance(node);
        if (bal > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);
        if (bal > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (bal < -1 && getBalance(node->right) <= 0)
            return rotateLeft(node);
        if (bal < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    Node *insertNode(Node *node, int val)
    {
        if (!node)
            return new Node(val);

        if (val < node->value)
            node->left = insertNode(node->left, val);
        else if (val > node->value)
            node->right = insertNode(node->right, val);
        else
            return node; // duplicate, ignore

        updateHeight(node);
        return balanceNode(node);
    }

    void inorderPrint(Node *node)
    {
        if (!node)
            return;
        inorderPrint(node->left);
        cout << node->value << " ";
        inorderPrint(node->right);
    }

public:
    AVLTree() { root = nullptr; }

    void insert(int val) { root = insertNode(root, val); }

    void displayInorder()
    {
        inorderPrint(root);
        cout << endl;
    }

    int height() { return getHeight(root); }
};

int main()
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    nl
            cout
        << "Inorder before inserting 15: ";
    tree.displayInorder();

    tree.insert(15);

    cout << "Inorder after inserting 15: ";
    tree.displayInorder();

    cout << "Height of AVL tree: " << tree.height() << endl;
    nl return 0;
}
