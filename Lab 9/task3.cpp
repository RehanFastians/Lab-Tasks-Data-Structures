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

    int get_height(Node *node)
    {
        return node == NULL ? 0 : node->height;
    }

    int get_balance(Node *node)
    {
        return node == NULL ? 0 : get_height(node->left) - get_height(node->right);
    }

    void update_height(Node *node)
    {
        if (!node)
            return;
        int lh = get_height(node->left);
        int rh = get_height(node->right);
        node->height = 1 + max(lh, rh);
    }

    Node *rotate_right(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        update_height(y);
        update_height(x);

        return x;
    }

    Node *rotate_left(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        update_height(x);
        update_height(y);

        return y;
    }

    Node *balance_node(Node *node)
    {
        if (!node)
            return node;
        int bal = get_balance(node);

        // Left heavy
        if (bal > 1 && get_balance(node->left) >= 0)
            return rotate_right(node);

        if (bal > 1 && get_balance(node->left) < 0)
        {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        // Right heavy
        if (bal < -1 && get_balance(node->right) <= 0)
            return rotate_left(node);

        if (bal < -1 && get_balance(node->right) > 0)
        {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }

        return node;
    }

    Node *insert_node(Node *node, int val)
    {
        if (node == NULL)
            return new Node(val);

        if (val < node->value)
            node->left = insert_node(node->left, val);
        else if (val > node->value)
            node->right = insert_node(node->right, val);
        else
            return node; // duplicate

        update_height(node);
        return balance_node(node);
    }

    Node *find_min(Node *node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node *delete_node(Node *node, int val)
    {
        if (node == NULL)
            return node;

        if (val < node->value)
            node->left = delete_node(node->left, val);
        else if (val > node->value)
            node->right = delete_node(node->right, val);
        else
        {
            // node found
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
                    // one child: copy content
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                // two children: replace with inorder successor
                Node *temp = find_min(node->right);
                node->value = temp->value;
                node->right = delete_node(node->right, temp->value);
            }
        }

        if (node == NULL)
            return node;

        update_height(node);
        return balance_node(node);
    }

    void inorder_traverse(Node *node)
    {
        if (!node)
            return;
        inorder_traverse(node->left);
        cout << node->value << " ";
        inorder_traverse(node->right);
    }

public:
    AVL() { root = NULL; }

    void insert(int val) { root = insert_node(root, val); }
    void remove(int val) { root = delete_node(root, val); }

    void display_inorder()
    {
        inorder_traverse(root);
        cout << endl;
    }
};

int main()
{
    AVL tree;

    // build initial tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "Inorder before insertion: ";
    tree.display_inorder();

    // insert that may trigger rotations
    tree.insert(12);

    cout << "Inorder after insertion: ";
    tree.display_inorder();

    nl;
    return 0;
}
