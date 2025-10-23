#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

template <class T>
class myStack
{
    int top;

public:
    T a[N];
    myStack()
    {
        top = -1;
    }
    void push(T x)
    {
        if (top < N - 1)
            a[++top] = x;
    }
    void pop()
    {
        if (top >= 0)
            top--;
    }
    T peek()
    {
        if (top >= 0)
            return a[top];
        return T();
    }
    bool isEmpty()
    {
        return top < 0;
    }
};

int main()
{
    myStack<string> tasks;

    // Adding item to stack
    tasks.push("Tayyari krlo");
    cout << "List having an item.";
    nl
            cout
        << "List is " << (tasks.isEmpty() ? "empty" : "not empty.");
    nl

        // Removing item from stack
        tasks.pop();
    cout << "List having no item.";
    nl
            cout
        << "List is " << (tasks.isEmpty() ? "empty" : "not empty.");
    nl

        return 0;
}
