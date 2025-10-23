#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;

int getMax(int a[], int n)
{
    int mx = a[0];
    f(i, 1, n) if (a[i] > mx)
        mx = a[i];
    return mx;
}

void cntSort(int a[], int n, int exp)
{
    int out[n], cnt[10] = {0};
    f(i, 0, n)
        cnt[(a[i] / exp) % 10]++;

    f(i, 1, 10)
        cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        out[cnt[(a[i] / exp) % 10] - 1] = a[i];
        cnt[(a[i] / exp) % 10]--;
    }

    f(i, 0, n)
        a[i] = out[i];
}

void radix(int a[], int n)
{
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        cntSort(a, n, exp);
}

int main()
{
    int a1[10], a2[10];
    cout << "Enter 10 elements for first array:";
    nl
            f(i, 0, 10) cin >>
        a1[i];

    cout << "Enter 10 elements for second array:";
    nl
            f(i, 0, 10) cin >>
        a2[i];

    int comb[20];
    f(i, 0, 10) comb[i] = a1[i];
    f(i, 0, 10) comb[10 + i] = a2[i];

    radix(comb, 20);

    cout << "\nCombined sorted array (Radix Sort):";
    nl
            f(i, 0, 20) cout
        << comb[i] << " ";
    nl
}
