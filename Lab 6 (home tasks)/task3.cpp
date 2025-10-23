#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)
using namespace std;

class CalcHelper
{
    int priority(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    bool isOp(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

public:
    string toPostfix(string inf)
    {
        string out;
        stack<char> st;

        f(i, 0, inf.size())
        {
            if (inf[i] == ' ')
                continue;
            if (isdigit(inf[i]) || inf[i] == '.')
            {
                while (i < inf.size() && (isdigit(inf[i]) || inf[i] == '.'))
                    out += inf[i++];
                out += ' ';
                i--;
            }
            else if (inf[i] == '(')
                st.push('(');
            else if (inf[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    out += st.top();
                    out += ' ';
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else if (isOp(inf[i]))
            {
                while (!st.empty() && priority(st.top()) >= priority(inf[i]))
                {
                    out += st.top();
                    out += ' ';
                    st.pop();
                }
                st.push(inf[i]);
            }
        }

        while (!st.empty())
        {
            out += st.top();
            out += ' ';
            st.pop();
        }

        return out;
    }

    double solvePostfix(string post)
    {
        stack<double> st;
        f(i, 0, post.size())
        {
            if (post[i] == ' ')
                continue;
            if (isdigit(post[i]) || post[i] == '.')
            {
                string num;
                while (i < post.size() && (isdigit(post[i]) || post[i] == '.'))
                    num += post[i++];
                st.push(stod(num));
                i--;
            }
            else if (isOp(post[i]))
            {
                double v2 = st.top();
                st.pop();
                double v1 = st.top();
                st.pop();
                if (post[i] == '+')
                    st.push(v1 + v2);
                else if (post[i] == '-')
                    st.push(v1 - v2);
                else if (post[i] == '*')
                    st.push(v1 * v2);
                else if (post[i] == '/')
                    st.push(v1 / v2);
            }
        }
        return st.top();
    }
};

int main()
{
    CalcHelper ch;
    vector<string> expList = {
        "9 + (4 * 3) - (2 / 1)",
        "(7 + 8 / 2) * (3 + 2)",
        "(9 / 4 + 9 * 4) + (9 * 4 + 9 / 4)"};

    f(i, 0, expList.size())
    {
        string inf = expList[i];
        string post = ch.toPostfix(inf);
        double ans = ch.solvePostfix(post);

        cout << "Expression " << i + 1 << ":";
        nl
                cout
            << "  Infix  -> " << inf << endl;
        cout << "  Postfix-> " << post << endl;
        cout << "  Result -> " << fixed << setprecision(2) << ans;
        nl nl
    }

    return 0;
}
