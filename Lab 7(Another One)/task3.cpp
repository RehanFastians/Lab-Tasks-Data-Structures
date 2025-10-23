#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;

struct Runner {
    string nm;
    int t;
};

void mergeArr(Runner a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Runner *L = new Runner[n1], *R = new Runner[n2];

    f(i, 0, n1) L[i] = a[l + i];
    f(j, 0, n2) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].t < R[j].t)   // smaller time = faster
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mSort(Runner a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mSort(a, l, m);
        mSort(a, m + 1, r);
        mergeArr(a, l, m, r);
    }
}

int main() {
    const int n = 6;
    Runner r[n];

    f(i, 0, n) {
        cout << "Name of runner " << i + 1 << ": ";
        getline(cin >> ws, r[i].nm);
        cout << "Finish time (in seconds): ";
        cin >> r[i].t;
    }

    mSort(r, 0, n - 1);

    cout << "\nTop 5 fastest runners:\n";
    f(i, 0, 5)
        cout << i + 1 << ". " << r[i].nm << " - " << r[i].t << "s\n";
    return 0;
}
