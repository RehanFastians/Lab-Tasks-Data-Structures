#include <bits/stdc++.h>
#define nl cout << endl;
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define N 1000
#define d 256

using namespace std;

void rabinKarpSearch(string text, string pattern, int q)
{
    int n = text.length();
    int m = pattern.length();
    if (m == 0 || m > n)
    {
        cout << "No valid pattern to search.\n";
        return;
    }
    int p = 0;
    int t = 0;
    int h = 1;

    f(i, 0, m - 1)
    {
        h = (h * d) % q;
    }

    f(i, 0, m)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    f(i, 0, n - m + 1)
    {
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = t + q;
        }
    }
}

int main()
{
    string text = "Today we are final lab.";
    string pattern = "final";

    int q = 101;

    nl
        rabinKarpSearch(text, pattern, q);
    nl

        return 0;
}