#include<bits/stdc++.h>
#define f(i, s, e) for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int dat, Node* val){
        data = dat;
        next=val;
    }
};
class LinkedList{
    public:
    Node *head=nullptr;
    LinkedList(int arr[], int n){
        head = new Node(arr[0], nullptr);
        Node *temp = head;
        f(i, 1, n){
            temp->next = new Node(arr[i], nullptr);
            temp= temp->next;
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
        head = nullptr;
    }
    void addElement(int val){
        Node *temp = head;
        while(temp->next)   temp=temp->next;
        temp->next = new Node(val, nullptr);
    }
    void print(){
        Node *temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void printReversed(Node *temp){
        if(temp==nullptr)   return;
        printReversed(temp->next);
        cout<<temp->data<<" ";
    }
    int size(Node *temp, int count){
        if(temp==nullptr)   return count;
        return size(temp->next, count+1);
    }
    void search(Node *temp, int val, int idx){
        if(temp==nullptr){
            cout<<"Value not found";
            return;
        }
        if(temp->data!=val)
            search(temp->next, val, idx+1);
        if(temp->data == val){
            cout<<"Value found at pos "<< idx+1;
        }
    }
};
int main(){
    int arr[]={1,2,3,4,5};
    LinkedList l1(arr, 5);
    l1.addElement(6);
    l1.print();
    nl
    l1.search(l1.head, 4, 0);
    return 0;
}