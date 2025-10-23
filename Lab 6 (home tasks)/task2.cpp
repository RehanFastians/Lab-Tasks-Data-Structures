#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Browser
{
    Node<T> *currentPage;
    stack<T> forwardStack;

public:
    Browser()
    {
        currentPage = nullptr;
    }

    void visit(T site)
    {
        if (currentPage)
            forwardStack = stack<T>(); // clear forward history
        Node<T> *newNode = new Node<T>(site);
        newNode->next = currentPage;
        currentPage = newNode;
        cout << "Visited: " << site;
        nl
    }

    void back()
    {
        if (!currentPage || !currentPage->next)
        {
            cout << "No previous page!";
            nl return;
        }
        forwardStack.push(currentPage->data);
        Node<T> *temp = currentPage;
        currentPage = currentPage->next;
        delete temp;
        cout << "Went back to: " << currentPage->data;
        nl
    }

    void forward()
    {
        if (forwardStack.empty())
        {
            cout << "No forward page!";
            nl return;
        }
        T nextSite = forwardStack.top();
        forwardStack.pop();
        visit(nextSite);
    }

    void current()
    {
        if (currentPage)
            cout << "Currently viewing: " << currentPage->data;
        else
            cout << "No pages visited yet!";
        nl
    }
};

int main()
{
    Browser<string> browser;

    browser.visit("google.com");
    browser.visit("openai.com");
    browser.visit("github.com");
    browser.visit("stackoverflow.com");

    browser.current();
    nl

        browser.back();
    browser.back();
    browser.current();
    nl

        browser.forward();
    browser.current();
    nl

        return 0;
}
