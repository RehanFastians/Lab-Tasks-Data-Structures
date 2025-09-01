#include<bits/stdc++.h>
#define f(i, s, e) for(int i=s;i<e;i++)
#define nl cout<<endl;
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int d, Node* nxt){
        data=d;
        next=nxt;
    }
};
class LinkedList{
    Node *head=nullptr;
    Node *tail= nullptr;
    int size=0;
    public:
    LinkedList(int arr[], int n){
        size=n;
        head = new Node(arr[0], nullptr);
        tail = head;
        Node *temp = head;
        f(i, 1, n){
            Node *nod = new Node(arr[i], nullptr);
            temp->next = nod;
            temp=temp->next;
            tail = temp;
        }
    }
    void printList(){
        Node *temp=head;
        f(i, 0, size){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        nl
    }
    void  addNode(int pos, int val){
        if(pos>size || pos<0){
            cout<<"Not possible";
            nl
            return;
        }
        size++;
        if(pos==0){
            Node *temp = new Node(val, head);
            head = temp;
            return;
        }
        Node *temp = head;
        f(i, 0, pos-1)
            temp=temp->next;
        Node *node = new Node(val, temp->next);
        temp->next = node;
    }
    void deleteNode(int val){
        Node *temp = head;
        Node *prev = nullptr;
        f(i, 0, size){
            if(temp->data == val){
                if(prev){
                    prev->next = temp->next;
                    delete temp;
                }else{
                    Node *node = temp->next;
                    delete temp;
                    head = node;
                }
                size--;
                return;
            }
            prev = temp;
            temp=temp->next;
        }
        cout<<"Value not found!!";
        nl
    }
};
int main(){
    int arr[]={3, 1, 2, 5, 8};
    LinkedList list(arr, 5);
    list.printList();
    list.addNode(5, 9);
    list.printList();
    list.addNode(1, 11);
    list.printList();
    list.addNode(0, 4);
    list.printList();
    list.deleteNode(1);
    list.printList();
    list.deleteNode(2);
    list.printList();
    list.deleteNode(5);
    list.printList();
    return 0;
}