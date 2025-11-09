#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val, Node *lft, Node *rght) : data(val), left(lft), right(rght) {}
};
class BST
{
    Node *root = nullptr;
    void preorder(Node *curr)
    {
        if (curr == nullptr)
            return;
        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }
    Node *insert(Node *curr, int val)
    {
        if (curr == nullptr)
        {
            return new Node(val, nullptr, nullptr);
        }
        else if (curr->data > val)
        {
            curr->left = insert(curr->left, val);
        }
        else if (curr->data < val)
        {
            curr->right = insert(curr->right, val);
        }
        return curr;
    }
    Node *findMin(Node *curr)
    {
        curr = curr->right;
        while (curr && curr->left)
            curr = curr->left;
        return curr;
    }
    Node *delNode(Node *curr, int val)
    {
        if (curr == nullptr)
            return curr;
        if (val < curr->data)
        {
            curr->left = delNode(curr->left, val);
        }
        else if (val > curr->data)
        {
            curr->right = delNode(curr->right, val);
        }
        else
        {
            if (curr->left == nullptr)
            {
                Node *temp = curr->right;
                delete curr;
                return temp;
            }
            if (curr->right == nullptr)
            {
                Node *temp = curr->left;
                delete curr;
                return temp;
            }
            Node *temp = findMin(curr);
            curr->data = temp->data;
            curr->right = delNode(curr->right, temp->data);
        }
        return curr;
    }
    bool search(Node *curr, int val)
    {
        if (curr == nullptr)
            return false;
        if (curr->data == val)
            return true;
        if (val < curr->data)
            return search(curr->left, val);
        if (val > curr->data)
            return search(curr->right, val);
    }

public:
    void insert(int val)
    {
        root = insert(root, val);
    }
    void preorder()
    {
        preorder(root);
    }
    void delNode(int val)
    {
        delNode(root, val);
    }
    bool search(int val)
    {
        return search(root, val);
    }
};
int main()
{
    BST meraBST;
    meraBST.insert(6);
    meraBST.insert(1);
    meraBST.insert(2);
    meraBST.insert(3);
    meraBST.insert(4);
    meraBST.insert(5);
    nl
        meraBST.preorder();
    nl
        meraBST.delNode(2);
    meraBST.preorder();
    nl if (meraBST.search(2)) cout << 2 << " Found!";
    else cout << 2 << " Not Found!";
    nl if (meraBST.search(4)) cout << 4 << " Found!";
    else cout << 4 << " Not Found!";
    return 0;
}