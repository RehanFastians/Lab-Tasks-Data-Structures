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
    void modifyNodes(){
        Node *temp = head;
        Node *prev = nullptr;
        Node *ntail =nullptr;
        f(i, 0, size-1){
            Node *nxt = temp->next;
            if(i&1){
                prev->next = temp->next;
                if(ntail){
                    temp->next =tail->next;
                    tail->next=temp; 
                }else{
                    tail->next = temp;
                    temp->next=nullptr;
                    ntail = temp;
                }
            }
            prev = temp;
            temp=nxt;
        }
        tail=ntail;
    }
};
int main(){
    int arr1[]={1, 2, 3, 4, 5};
    LinkedList list1(arr1, 5);
    int arr2[]={1, 2, 3, 4, 5, 6};
    LinkedList list2(arr2, 6);
    cout<<"Before modifying list 1 and list 2 (checking both even and odd length)"<<endl;
    list1.printList();
    list2.printList();
    list1.modifyNodes();
    list2.modifyNodes();
    cout<<"After modifying : "<<endl;
    list1.printList();
    list2.printList();
    return 0;
}