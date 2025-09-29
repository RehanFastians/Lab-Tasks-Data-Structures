#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for(int i=s;i<e;i++)
// 24K-0707
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value) : value(value), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList(Node *head) : head(head), size(0)
    {
        tail = head;
        while (tail && tail->next)
        {
            size++;
            tail = tail->next;
        }
        if (tail) size++;
    }

    LinkedList(int arr[], int n) : size(n)
    {
        head = new Node(arr[0]);
        tail = head;
        f(i, 1, n)
        {
            tail->next = new Node(arr[i]);
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
        size = 0;
    }

    void print()
    {
        Node *cur = head;
        while (cur)
        {
            cout << cur->value << (cur->next? " " : "\n");
            cur = cur->next;
        }
    }

    void sort(){
        Node *cur1 = head, *temp1 = nullptr;
        f(i, 0, size-1){
            Node *cur2 = cur1->next, *temp2 = cur2;
            f(j, i+1, size){
                if(cur1->value>cur2->value){
                    swap(cur1->next, cur2->next);
                    temp2->next = cur1;
                    if(i){ 
                        temp1->next = cur2;
                    }else{
                        head = cur2;
                    }
                    swap(cur1, cur2);
                }
                temp2 = temp2->next;
                cur2=cur2->next;
            }
            cur1 = cur1->next;
            temp1=temp1->next;
        }
    }
};

int main()
{
    int arr2[] = {4, 1, 6, 11, 3, 8, 2};
    LinkedList list1(arr2, 7);
    nl
    cout << "List 1: ";
    list1.print();
    list1.sort();
    nl
    cout << "List 1: ";
    list1.print();
    return 0;
}