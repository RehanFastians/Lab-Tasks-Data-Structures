#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;

struct Node
{
    int val;
    Node *nxt;
    Node(int x)
    {
        val = x;
        nxt = nullptr;
    }
};

void print(Node *cur)
{
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->nxt;
    }
    nl
}

Node *getLast(Node *ptr)
{
    while (ptr && ptr->nxt)
        ptr = ptr->nxt;
    return ptr;
}

Node *part(Node *head, Node *tail)
{
    Node *pivot = head, *prev = head, *cur = head;
    while (cur != tail->nxt)
    {
        if (cur->val < pivot->val)
        {
            swap(cur->val, prev->nxt->val);
            prev = prev->nxt;
        }
        cur = cur->nxt;
    }
    swap(pivot->val, prev->val);
    return prev;
}

void quick(Node *l, Node *r)
{
    if (!l || l == r)
        return;
    Node *p = part(l, r);
    quick(l, p);
    quick(p->nxt, r);
}

Node *sortList(Node *head)
{
    Node *tail = getLast(head);
    quick(head, tail);
    return head;
}

int main()
{
    Node *head = new Node(25);
    head->nxt = new Node(10);
    head->nxt->nxt = new Node(7);
    head->nxt->nxt->nxt = new Node(42);
    head->nxt->nxt->nxt->nxt = new Node(15);

    cout << "\nBefore sorting:\n";
    print(head);

    head = sortList(head);

    cout << "\nAfter sorting:\n";
    print(head);

    nl return 0;
}
