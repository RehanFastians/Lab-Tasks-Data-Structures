#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;

int getMax(int a[], int n)
{
    int mx = a[0];
    f(i, 1, n)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void countingSort(int a[], int n, int place, bool isAscending)
{
    int output[n + 1];
    int count[10] = {0};

    f(i, 0, n)
        count[(a[i] / place) % 10]++;

    if (isAscending)
    {
        f(i, 1, 10)
            count[i] += count[i - 1];
    }
    else
    {
        fn(i, 8, 0)
            count[i] += count[i + 1];
    }

    fn(i, n - 1, 0)
    {
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }

    f(i, 0, n)
        a[i] = output[i];
}

void radixsort(int a[], int n, bool isAscending = true)
{
    int mx = getMax(a, n);
    for (int place = 1; mx / place > 0; place *= 10)
        countingSort(a, n, place, isAscending);
}

void printArray(int a[], int n)
{
    f(i, 0, n)
        cout << a[i] << " ";
    nl
}

int main()
{
    int a[] = {181, 289, 390, 121, 145, 736, 514, 888, 122};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "\nBefore sorting array elements are - \n";
    printArray(a, n);

    radixsort(a, n, true);
    cout << "\nAfter applying Radix sort in ascending order, the array elements are - \n";
    printArray(a, n);

    radixsort(a, n, false);
    cout << "\nAfter applying Radix sort in descending order, the array elements are - \n";
    printArray(a, n);
    return 0;
}
