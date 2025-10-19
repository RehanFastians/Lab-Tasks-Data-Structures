#include <bits/stdc++.h>
#define f(i, s, e) for(int i = s; i < e; i++)
#define fn(i, s, e) for(int i = s; i >= e; i--)
#define nl cout << endl
using namespace std;

const int MAX_ITEMS = 50;

class Order {
public:
    int orderID;
    pair<string, int> items[MAX_ITEMS];
    int itemCount;
    Order() {
        orderID = 0;
        itemCount = 0;
    }
    void print() {
        cout << "Order ID: " << orderID << endl;
        f(i, 0, itemCount)
            cout << "Item: " << items[i].first << ", Quantity: " << items[i].second << endl;
        nl;
    }
};

struct Node {
    Order data;
    Node *next;
    Node(Order val): data(val), next(nullptr) {}
};

class OrderQueue {
    Node *front, *rear;
    int currentID;
public:
    OrderQueue() {
        front = rear = nullptr;
        currentID = 1;
    }
    void enqueue(Order o) {
        o.orderID = currentID++;
        Node *newNode = new Node(o);
        if (!rear) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    Order dequeue() {
        if (!front) return Order();
        Node *temp = front;
        Order res = temp->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return res;
    }
    bool isEmpty() { return front == nullptr; }
    void printAllOrders() {
        Node *cur = front;
        while (cur) {
            cur->data.print();
            cur = cur->next;
        }
    }
};

int main() {
    OrderQueue q;

    Order o1;
    o1.items[0] = {"Zinger Burger", 2};
    o1.items[1] = {"Cheese Fries", 1};
    o1.itemCount = 2;
    q.enqueue(o1);

    Order o2;
    o2.items[0] = {"Pepperoni Pizza", 1};
    o2.items[1] = {"Garlic Bread", 2};
    o2.items[2] = {"Choco Lava Cake", 1};
    o2.itemCount = 3;
    q.enqueue(o2);

    Order o3;
    o3.items[0] = {"Grilled Sandwich", 2};
    o3.items[1] = {"Cold Coffee", 2};
    o3.itemCount = 2;
    q.enqueue(o3);

    Order o4;
    o4.items[0] = {"Fajita Roll", 3};
    o4.items[1] = {"Mint Margarita", 1};
    o4.itemCount = 2;
    q.enqueue(o4);

    cout << "\nAll Orders in Queue:" << endl;
    q.printAllOrders();

    cout << "Dequeued (Processed) Order:" << endl;
    Order served = q.dequeue();
    served.print();

    cout << "Remaining Orders in Queue:" << endl;
    q.printAllOrders();

    return 0;
}
