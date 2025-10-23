#include <bits/stdc++.h>
#include <unistd.h>
#define nl cout << endl;
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define N 1000
using namespace std;

template <typename T>
class NodeBox {
public:
    T info;
    NodeBox* next;
    NodeBox(T val) {
        info = val;
        next = nullptr;
    }
};

template <typename T>
class SimpleQueue {
    NodeBox<T>* head;
    NodeBox<T>* tail;
public:
    SimpleQueue() {
        head = tail = nullptr;
    }

    void push(T val) {
        NodeBox<T>* node = new NodeBox<T>(val);
        if (!tail) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    void pop() {
        if (!head) return;
        NodeBox<T>* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    T front() {
        if (!head) throw runtime_error("Queue is empty!");
        return head->info;
    }

    bool empty() {
        return head == nullptr;
    }
};

class Customer {
public:
    string id;
    int serviceDur;
    Customer(string n = "", int t = 0) {
        id = n;
        serviceDur = t;
    }
};

class Clerk {
public:
    bool isBusy;
    int remainingTime;
    Customer currentTask;

    Clerk() {
        isBusy = false;
        remainingTime = 0;
    }

    void start(Customer c) {
        currentTask = c;
        isBusy = true;
        remainingTime = c.serviceDur;
    }

    void tick() {
        if (isBusy) {
            remainingTime--;
            if (remainingTime <= 0) isBusy = false;
        }
    }
};

void runSimulation(SimpleQueue<Customer>& line, Clerk clerks[], int totalClerks) {
    int timeStep = 0;
    bool anyoneBusy = true;

    while (!line.empty() || anyoneBusy) {
        anyoneBusy = false;

        // Assign free clerks new customers
        if (!line.empty()) {
            f(i,0,totalClerks) {
                if (!clerks[i].isBusy && !line.empty()) {
                    Customer c = line.front();
                    line.pop();
                    clerks[i].start(c);
                    cout << "[t=" << timeStep << "] Clerk #" << i+1 
                         << " starts helping " << c.id 
                         << " (Duration: " << c.serviceDur << " min)" << endl;
                }
            }
        }

        usleep(1000000);
        nl
        timeStep++;

        // Progress work
        f(i,0,totalClerks) {
            if (clerks[i].isBusy) {
                clerks[i].tick();
                anyoneBusy = true;
                if (!clerks[i].isBusy)
                    cout << "[t=" << timeStep << "] Clerk #" << i+1 
                         << " finished with " << clerks[i].currentTask.id << endl;
            }
        }
    }
}

int main() {
    SimpleQueue<Customer> line;
    line.push(Customer("Ahmed", 3));
    line.push(Customer("Zara", 2));
    line.push(Customer("Bilal", 1));
    line.push(Customer("Kiran", 2));
    line.push(Customer("Danish", 3));

    const int totalClerks = 4;
    Clerk clerks[totalClerks];
    nl;
    runSimulation(line, clerks, totalClerks);
    nl;
    return 0;
}
