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
class LinkedList{
    Node *head=nullptr;
    Node *tail= nullptr;
    int size=0;
    public:
    LinkedList(int arr[], int n){
        size=n;
        head = new Node(arr[0], nullptr);
        tail = head;
        tail = head;
        f(i, 1, n){
            Node *nod = new Node(arr[i], nullptr);
            tail->next = nod;
            tail=tail->next;
        }
    }
    void printList(){
        Node *temp=head;
        f(i, 0, size){
            cout<<temp->data;
            if(i!=size-1)   cout<<" -> ";
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
    void rotate(int x){
        if(size==0) return;
        x%=size;
        Node *temp = head;
        f(i, 0, x){
            tail->next=temp;
            tail = temp;
            head = temp->next;
            temp = temp->next;
        }
    }
    void sortByParity(){
        Node *oddHead =nullptr;
        Node *oddTail =nullptr;
        Node *evenHead =nullptr;
        Node *evenTail =nullptr;
        Node *temp = head;
        f(i, 0, size){
            if((temp->data&1)){
                if(oddHead){
                    oddTail->next = temp;
                    oddTail=oddTail->next;
                }else{
                    oddHead=temp;
                    oddTail=temp;
                }
            }else{
                if(evenHead){
                    evenTail->next = temp;
                    evenTail=evenTail->next;
                }else{
                    evenHead=temp;
                    evenTail=temp;
                }
            }
            temp=temp->next;
        }
        if(evenHead){
            head = evenHead;
            tail = evenTail;
        }
        if(oddHead){
            tail->next=oddHead;
            tail = oddTail;
        }
    }
};
int main(){
    int arr[]={17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    LinkedList list(arr, 10);
    list.printList();
    list.sortByParity();
    list.printList();
    return 0;
}