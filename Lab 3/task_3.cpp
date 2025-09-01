#include<bits/stdc++.h>
#define nl cout<<endl;
#define f(i, s, e) for(int i=s;i<e;i++)
using namespace std;

struct Node{
    string name;
    Node* next;
    Node(string n=""):name(n),next(NULL){}

};

class LinkedList{
    Node *head;
    Node *tail;
    public:
        LinkedList(){
            head = tail = NULL;
        }
        void push(string n){
            Node *temp= new Node(n);
            if (head==NULL)
            {
                head = tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
                
            }    
        }
        void deleteBySearch(string n){
            Node *temp= head;
            Node *t2= NULL;
            if (temp->name == n)
            {
                t2 = temp;
                head = head->next;
                delete t2;
                t2 = NULL;
                return;
            }   
            while (temp->next!=NULL)
            {
                if (temp->next==tail && tail->name==n)
                {
                    t2 = tail;
                    tail = temp;
                    delete t2; t2 =  NULL;
                    tail->next  = NULL;
                    return;
                }   
                if (temp->next->name==n)
                {
                    t2 = temp->next;
                    temp->next = temp->next->next;
                    delete t2;
                    t2 = NULL;
                    return;
                }
                
            }
        }
        void print(){
            int i=1;
            Node *temp= head;
            while (temp!=NULL)
            {
                cout<<"Passenger "<<i<<" : "<<temp->name<<endl;
                temp =  temp->next; i++;
            }
        }
        bool search(string n){
            Node *temp = head;
            while (temp!=NULL)
            {
                if (temp->name == n)
                {   
                    return true;
                }
                temp = temp->next;
                
            }
            return false;   
        }
};


int main(){
    LinkedList l;
    int n;
    while (n!=5)
    {
        cout<<"\n\tPIA TICKET RESERVATION\n";
        cout<<"1- Reserve a ticket\n2- Check Reservation\n3- Cancel Reservation\n4- Display all passengers\n5- Exit \nChose an option: ";
        cin>>n;
        string name;
        switch (n)
        {
        case 1:
            cout<<"Enter name: ";
            cin>>name;
            l.push(name);
            cout<<"Seat Reserved\n";
            break;
            case 2:
            cout<<"Enter name: ";
            cin>>name;
            cout<<(l.search(name) ? "This passenger has a Reservation \n" : "This passenger didn't reseve as seat\n");
            
            break;
            case 3:
            cout<<"Enter name: ";
            cin>>name;
                l.deleteBySearch(name);
                break;
            case 4:
                l.print();
                break;
        default:

            break;
        }
}
}