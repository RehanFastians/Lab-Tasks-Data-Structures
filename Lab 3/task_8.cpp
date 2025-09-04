// Not compeleted yet
#include<bits/stdc++.h>
#define nl cout<<endl;
#define f(i, s, e) for(int i=s;i<e;i++)
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d, Node* nxt, Node* pre){
        data=d;
        next=nxt;
        prev = pre;
    }
};
class DoublyLinkedList{
    Node *head=nullptr;
    Node *tail= nullptr;
    int size=0;

    public:
    DoublyLinkedList(int arr[], int n){
        size=n;
        head = new Node(arr[0], nullptr, nullptr);
        tail = head;
        tail = head;
        f(i, 1, n){
            Node *nod = new Node(arr[i], nullptr, tail);
            tail->next = nod;
            tail=tail->next;
        }
    }
    DoublyLinkedList(DoublyLinkedList l, DoublyLinkedList m){
        head = l.head;
        tail=m.tail;
        l.tail->next = m.head;
        m.head->prev = l.tail;
        size=l.size+m.size;
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
            Node *temp = new Node(val, head, nullptr);
            head = temp;
            return;
        }
        Node *temp = head;
        f(i, 0, pos-1)
            temp=temp->next;
        Node *node = new Node(val, temp->next, temp);
        temp->next = node;
    }
    void deleteNode(int val){
        if(size==0) return;
        Node *temp = head;
        Node *prev = nullptr;
        f(i, 0, size){
            if(temp->data == val){
                if(prev){
                    prev->next = temp->next;
                    temp->next->prev = prev;
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
    int l[]={1, 3, 5, 7};
    int m[]={2, 4, 6, 8};
    DoublyLinkedList L(l, 4), M(m, 4);
    L.printList();
    M.printList();
    DoublyLinkedList concatenatedList(L, M);
    concatenatedList.printList();
    return 0;
}