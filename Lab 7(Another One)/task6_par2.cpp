#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = new int[n1], *R = new int[n2];

    f(i, 0, n1) L[i] = a[l + i];
    f(j, 0, n2) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void msort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void mergeArr(int a1[], int n1, int a2[], int n2, int res[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
        res[k++] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];

    while (i < n1) res[k++] = a1[i++];
    while (j < n2) res[k++] = a2[j++];
}

int main() {
    int a1[10], a2[10];
    cout << "Enter 10 elements for first array:"; nl
    f(i, 0, 10) cin >> a1[i];

    cout << "Enter 10 elements for second array:"; nl
    f(i, 0, 10) cin >> a2[i];

    msort(a1, 0, 9);
    msort(a2, 0, 9);

    int comb[20];
    mergeArr(a1, 10, a2, 10, comb);

    cout << "\nCombined sorted array:"; nl
    f(i, 0, 20) cout << comb[i] << " ";
    return 0;
}
