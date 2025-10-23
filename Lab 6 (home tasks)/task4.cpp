#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i,s,e) for(int i=s;i<e;i++)
#define fr(i,s,e) for(int i=s;i>=e;i--)
using namespace std;

class ExprSolver {
    int prec(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }
    bool isOp(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
public:
    string toPostfix(const string& inf) {
        stack<char> st;
        string post;
        f(i,0,inf.size()) {
            if (inf[i] == ' ') continue;
            if (isdigit(inf[i]) || inf[i] == '.') {
                while (i < inf.size() && (isdigit(inf[i]) || inf[i] == '.'))
                    post += inf[i++];
                post += ' ';
                i--;
            } else if (inf[i] == '(') st.push('(');
            else if (inf[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    post += st.top(); post += ' '; st.pop();
                }
                if (!st.empty()) st.pop();
            } else if (isOp(inf[i])) {
                while (!st.empty() && prec(st.top()) >= prec(inf[i])) {
                    post += st.top(); post += ' '; st.pop();
                }
                st.push(inf[i]);
            }
        }
        while (!st.empty()) { post += st.top(); post += ' '; st.pop(); }
        return post;
    }

    double solvePostfix(const string& post) {
        stack<double> st;
        f(i,0,post.size()) {
            if (post[i] == ' ') continue;
            if (isdigit(post[i]) || post[i] == '.') {
                string val;
                while (i < post.size() && (isdigit(post[i]) || post[i] == '.'))
                    val += post[i++];
                st.push(stod(val)); i--;
            } else if (isOp(post[i])) {
                double y = st.top(); st.pop();
                double x = st.top(); st.pop();
                if (post[i] == '+') st.push(x + y);
                else if (post[i] == '-') st.push(x - y);
                else if (post[i] == '*') st.push(x * y);
                else st.push(x / y);
            }
        }
        return st.top();
    }
};

template <typename T>
struct Node {
    T val;
    Node* next;
    Node(T x) { val = x; next = nullptr; }
};

template <typename T>
class Stack {
    Node<T>* head;
public:
    Stack() { head = nullptr; }
    void push(T x) {
        Node<T>* n = new Node<T>(x);
        n->next = head;
        head = n;
    }
    void pop() {
        if (!head) return;
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    T top() { return head->val; }
    bool empty() { return head == nullptr; }
    void show() {
        Node<T>* cur = head;
        cout << "Top -> ";
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        nl
    }
};

int main() {
    string eq = "res = (10.5+9)*2-4/2";
    ExprSolver solver;
    Stack<string> stk;

    char lhs = eq[0];
    string rhs = eq.substr(eq.find('=') + 1);

    string post = solver.toPostfix(rhs);
    double val = solver.solvePostfix(post);

    stk.push(to_string(val));
    stk.push("=");
    stk.push(string(1, lhs));

    nl
    stk.show();
    nl

    return 0;
}
