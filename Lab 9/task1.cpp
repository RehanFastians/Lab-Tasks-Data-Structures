#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

struct Node
{
    int value, height;
    Node *left, *right;
    Node(int val)
    {
        value = val;
        left = right = NULL;
        height = 1;
    }
};

class AVLConverter
{
    Node *root;

    int getHeight(Node *node) { return node ? node->height : 0; }

    int getBalance(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(Node *node)
    {
        if (node)
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *temp = x->right;
        x->right = y;
        y->left = temp;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *temp = y->left;
        y->left = x;
        x->right = temp;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node *balance(Node *node)
    {
        int balanceFactor = getBalance(node);
        if (balanceFactor > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);
        if (balanceFactor > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1 && getBalance(node->right) <= 0)
            return rotateLeft(node);
        if (balanceFactor < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    Node *insertBST(Node *node, int val)
    {
        if (!node)
            return new Node(val);
        if (val < node->value)
            node->left = insertBST(node->left, val);
        else if (val > node->value)
            node->right = insertBST(node->right, val);
        updateHeight(node);
        return node;
    }

    Node *convertToAVL(Node *node)
    {
        if (!node)
            return NULL;
        node->left = convertToAVL(node->left);
        node->right = convertToAVL(node->right);
        updateHeight(node);
        return balance(node);
    }

    void preorder(Node *node)
    {
        if (!node)
            return;
        int leftH = getHeight(node->left);
        int rightH = getHeight(node->right);
        cout << setw(2) << node->value << "   "
             << setw(2) << leftH << "   "
             << setw(2) << rightH << "   "
             << setw(2) << getBalance(node) << endl;
        preorder(node->left);
        preorder(node->right);
    }

public:
    AVLConverter() { root = NULL; }

    void insert(int val) { root = insertBST(root, val); }

    void convert() { root = convertToAVL(root); }

    void display()
    {
        cout << "ND   LH   RH   BF" << endl;
        preorder(root);
        nl
    }
};

int main()
{
    AVLConverter tree;
    tree.insert(10);
    tree.insert(16);
    tree.insert(12);
    tree.insert(18);

    nl
            cout
        << "Preorder of BST (Before Conversion): " << endl;
    tree.display();

    tree.convert();

    cout << "Preorder of AVL (After Conversion): " << endl;
    tree.display();

    return 0;
}
