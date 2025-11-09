#include <bits/stdc++.h>
#define nl (cout << endl)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int val)
    {
        data = val;
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
        int l_h = get_height(node->left);
        int r_h = get_height(node->right);
        node->height = 1 + max(l_h, r_h);
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
        int balance = get_balance(node);

        if (balance > 1 && get_balance(node->left) >= 0)
            return rotate_right(node);

        if (balance > 1 && get_balance(node->left) < 0)
        {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        if (balance < -1 && get_balance(node->right) <= 0)
            return rotate_left(node);

        if (balance < -1 && get_balance(node->right) > 0)
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

        if (val < node->data)
            node->left = insert_node(node->left, val);
        else if (val > node->data)
            node->right = insert_node(node->right, val);
        else
            return node; // duplicate, ignore

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

        if (val < node->data)
            node->left = delete_node(node->left, val);
        else if (val > node->data)
            node->right = delete_node(node->right, val);
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
                    // one child: copy contents
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                // two children: use inorder successor
                Node *temp = find_min(node->right);
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        update_height(node);
        return balance_node(node);
    }

    // k-th smallest (inorder)
    void kth_smallest_util(Node *node, int &k, int &result)
    {
        if (!node)
            return;
        kth_smallest_util(node->left, k, result);
        if (k == 0)
            return;
        k--;
        if (k == 0)
        {
            result = node->data;
            return;
        }
        kth_smallest_util(node->right, k, result);
    }

    // k-th largest (reverse inorder)
    void kth_largest_util(Node *node, int &k, int &result)
    {
        if (!node)
            return;
        kth_largest_util(node->right, k, result);
        if (k == 0)
            return;
        k--;
        if (k == 0)
        {
            result = node->data;
            return;
        }
        kth_largest_util(node->left, k, result);
    }

    void preorder(Node *node)
    {
        if (!node)
            return;
        int lH = get_height(node->left);
        int rH = get_height(node->right);
        cout << node->data << " " << lH << " " << rH << endl;
        preorder(node->left);
        preorder(node->right);
    }

public:
    AVL() { root = NULL; }

    void insert(int val) { root = insert_node(root, val); }
    void remove(int val) { root = delete_node(root, val); }

    void display_preorder() { preorder(root); }

    int kthSmallest(int k)
    {
        int res = -1;
        kth_smallest_util(root, k, res);
        return res;
    }

    int kthLargest(int k)
    {
        int res = -1;
        kth_largest_util(root, k, res);
        return res;
    }
};

int main()
{
    AVL tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    int k = 2;

    nl;
    cout << k << "th smallest element: " << tree.kthSmallest(k) << endl;
    cout << k << "th largest element: " << tree.kthLargest(k) << endl;
    nl;
    tree.display_preorder();
    nl;
    return 0;
}
