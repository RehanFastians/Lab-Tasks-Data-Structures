#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;
template <typename T>
class MyStack
{
    T *arr = nullptr;
    int size = 0;
    int used = 0;

public:
    MyStack(int size) : size(size)
    {
        arr = new T[size];
    }
    void push(T x)
    {
        if (used == size)
            return;
        arr[used++] = x;
    }
    void pop()
    {
        if (used != 0)
            used--;
    }
    int top()
    {
        if (used != 0)
            return arr[used - 1];
        else
            return -1;
    }
    bool isEmpty() const { return used == 0; }
};

int main()
{
    // string word = "BOROOROB";   //A valid palindorome for checking
    string word = "BORROWROB";
    MyStack<char> left(9), right(9);
    f(i, 0, word.length()) left.push(word[i]);
    fn(i, word.length() - 1, 0) right.push(word[i]);
    bool check = true;
    while (!left.isEmpty())
    {
        if (left.top() != right.top())
            check = false;
        left.pop();
        right.pop();
    }
    if (check)
        cout << "Yes it is a palindrome!!";
    else
        cout << "Unfortunately it is not a palindrome!!!!";
    nl return 0;
}