#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for(int i=s;i<e;i++)
using namespace std;
// 24K-0707
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class LinkedList
{

private:
    Node *reverseRecursive(Node *node)
    {
        if (!node)
            return nullptr;
        swap(node->prev, node->next);
        if (node->prev == nullptr) // Base case 
        {
            return node; // yeh reversed list ka naya head jo key obv tail hoga woh return krega
        }
        return reverseRecursive(node->prev);
    }

public:
    Node *head;
    Node *tail;
    int size;
    LinkedList(Node *head) : head(head), size(1)
    {
        tail = head;
        while (tail->next)
        {
            size++;
            tail = tail->next;
        }
    }
    LinkedList(int arr[], int n) : size(n)
    {
        head = new Node(arr[0]);
        tail = head;
        f(i, 1, n)
        {
            Node *newNode = new Node(arr[i]);
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }
    ~LinkedList()
    {
        Node *cur = head;
        while (cur)
        {
            Node *temp = cur->next;
            delete cur;
            cur = temp;
        }
        head = tail = nullptr;
    }
    void print()
    {
        Node *cur = head;
        while (cur)
        {
            cout << cur->val << (cur->next ? " " : "\n");
            cur = cur->next;
        }
    }
    void deleteAtPosition(int k)
    {
        if (!head || k >= size || k<0)
            return;

        if (k == 0)
        {
            Node *temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;
            delete temp;
            size--;
            return;
        }

        Node *cur = head;
        f(i, 0, k)
            cur = cur->next;

        if (cur->next)
            cur->next->prev = cur->prev;
        else
            tail = cur->prev;

        cur->prev->next = cur->next;
        delete cur;
        size--;
    }
    void reverse()
    {
        head = reverseRecursive(head);
        tail = head;
        while (tail && tail->next)
        {
            tail = tail->next;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList list(arr, 5);
    nl
    list.print();
    int idx;
    cout << "\nEnter position of element to delete: ";
    cin >> idx;
    list.deleteAtPosition(idx);
    list.print();
    list.reverse();
    list.print();
    nl
    return 0;
}