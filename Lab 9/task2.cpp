#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
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
        left = right = NULL;
        height = 1;
    }
};

class AVL
{
    Node *root;

    int getHeight(Node *node)
    {
        return node == NULL ? 0 : node->height;
    }

    int getBalance(Node *node)
    {
        return node == NULL ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(Node *node)
    {
        if (!node)
            return;
        int lh = getHeight(node->left);
        int rh = getHeight(node->right);
        node->height = 1 + max(lh, rh);
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
        if (!node)
            return node;
        int bal = getBalance(node);

        // Left heavy
        if (bal > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);
        if (bal > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right heavy
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
        if (node == NULL)
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

    Node *findMin(Node *node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node *deleteNode(Node *node, int val)
    {
        if (node == NULL)
            return node;

        if (val < node->value)
            node->left = deleteNode(node->left, val);
        else if (val > node->value)
            node->right = deleteNode(node->right, val);
        else
        {
            // node to be deleted
            if (node->left == NULL || node->right == NULL)
            {
                Node *temp = node->left ? node->left : node->right;
                if (temp == NULL)
                {
                    // no child
                    temp = node;
                    node = NULL;
                }
                else
                {
                    // one child -> copy contents
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                // two children: get inorder successor
                Node *temp = findMin(node->right);
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->value);
            }
        }

        if (node == NULL)
            return node;

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
    AVL() { root = NULL; }

    void insert(int val) { root = insertNode(root, val); }
    void remove(int val) { root = deleteNode(root, val); }
    void displayInorder()
    {
        inorderPrint(root);
        cout << endl;
    }
};

int main()
{
    AVL tree;

    // initial tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder before insertion: ";
    tree.displayInorder();

    // insert new node that may trigger rotations
    tree.insert(55);

    cout << "Inorder after insertion: ";
    tree.displayInorder();

    // example deletion (keeps API available)
    // tree.remove(20);

    nl;
    return 0;
}
