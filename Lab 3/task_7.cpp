// Not compeleted yet
#include<bits/stdc++.h>
#define nl cout<<endl;
#define f(i, s, e) for(int i=s;i<e;i++)
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int d, Node* nxt){
        data=d;
        next=nxt;
    }
};
class CircularLinkedList{
    Node *head=nullptr;
    Node *tail= nullptr;
    int size=0;

    public:
    CircularLinkedList(int arr[], int n){
        size=n;
        head = new Node(arr[0], nullptr);
        tail = head;
        tail = head;
        f(i, 1, n){
            Node *nod = new Node(arr[i], nullptr);
            tail->next = nod;
            tail=tail->next;
        }
        tail->next=head;
    }
    void printList(){
        Node *temp=head;
        f(i, 0, size){
            cout<<temp->data;
            if(i!=size-1)
               cout<<" -> ";
            temp=temp->next;
        }
        nl
    }
    void addNode(int pos, int val){
        if(pos>size || pos<0){
            cout<<"Not possible";
            nl
            return; 
        }
        size++;
        if(pos==0){
            Node *temp = new Node(val, head);
            head = temp;
            tail->next=head;
            return;
        }
        Node *temp = head;
        f(i, 0, pos-1)
            temp=temp->next;
        Node *node = new Node(val, temp->next);
        temp->next = node;
    }
    void deleteNode(int val){
        if(size==0) return;
        Node *temp = head;
        Node *prev = tail;
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
    int arr1[]={17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    CircularLinkedList list1(arr1, 10);
    list1.printList();
    list1.addNode(0, 20);
    list1.printList();
    list1.addNode(11, 21);
    list1.printList();
    list1.deleteNode(10);
    list1.printList();
    return 0;
}