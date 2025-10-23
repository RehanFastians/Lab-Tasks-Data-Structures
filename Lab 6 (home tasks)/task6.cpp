#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 1000
using namespace std;

template <typename T>
class NodeItem {
public:
    T info;
    NodeItem* next;
    NodeItem(T val) {
        info = val;
        next = nullptr;
    }
};

template <typename T>
class MessageQueue {
    NodeItem<T>* head;
    NodeItem<T>* tail;

public:
    MessageQueue() {
        head = tail = nullptr;
    }

    void push(T val) {
        NodeItem<T>* node = new NodeItem<T>(val);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        cout << "Message \"" << val << "\" added to queue" << endl;
    }

    void pop() {
        if (!head) {
            cout << "No pending messages (Queue Empty)" << endl;
            return;
        }
        cout << "Delivering message: " << head->info << endl;
        NodeItem<T>* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    void frontView() {
        if (!head)
            cout << "Message box is empty." << endl;
        else
            cout << "Next message awaiting delivery: " << head->info << endl;
    }

    bool empty() {
        return head == nullptr;
    }
};

int main() {
    MessageQueue<string> msgBox;
    nl;
    msgBox.push("Hi there!");
    msgBox.push("Meeting at 3 PM");
    msgBox.push("See you tomorrow");
    msgBox.frontView();
    msgBox.pop();
    msgBox.pop();
    msgBox.pop();
    msgBox.pop();
    nl;
    return 0;
}
