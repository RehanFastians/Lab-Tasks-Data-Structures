#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
#define MAXN 1000
using namespace std;

template <typename T>
class SimpleQueue {
    int frontIdx, rearIdx;
    T* buffer;
    size_t cap;

public:
    SimpleQueue(size_t n) : cap(n) {
        frontIdx = rearIdx = -1;
        buffer = new T[cap];
    }

    bool full() const { return rearIdx == (int)cap - 1; }
    bool empty() const { return (frontIdx == -1 || frontIdx > rearIdx); }

    void push(T val) {
        if (full()) return;
        if (frontIdx == -1) frontIdx = 0;
        buffer[++rearIdx] = val;
    }

    void pop() {
        if (!empty()) {
            cout << "Customer " << buffer[frontIdx] << " has been served" << endl;
            frontIdx++;
        }
    }

    T front() const {
        if (!empty()) return buffer[frontIdx];
        throw runtime_error("Queue is empty!");
    }

    void display() const {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        f(i, frontIdx, rearIdx + 1) cout << buffer[i] << " ";
        nl;
    }

    ~SimpleQueue() { delete[] buffer; }
};

int main() {
    SimpleQueue<int> q(MAXN);

    q.push(10);
    q.push(5);
    q.push(8);
    q.push(3);
    q.push(1);

    cout << "Queue after adding customers: ";
    q.display();

    q.pop();
    cout << "Queue after 1st checkout: ";
    q.display();

    q.pop();
    cout << "Queue after 2nd checkout: ";
    q.display();

    return 0;
}
