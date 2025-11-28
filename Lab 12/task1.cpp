#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
using namespace std;

void search(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int cnt = 0;
    f(i, 0, n - m + 1)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m)
        {
            cout << "Parent found at index: " << i << endl;
            cnt++;
        }
    }
}
int main()
{
    string text = "today is not the day i die";
    string pattern = "is";
    nl
        search(text, pattern);
    nl return 0;
}