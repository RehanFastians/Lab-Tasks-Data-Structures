#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;

struct Item
{
    string nm, desc;
    float pr;
    bool avail;
};

int part(Item a[], int l, int r)
{
    float piv = a[r].pr;
    int i = l - 1;
    f(j, l, r)
    {
        if (a[j].pr <= piv)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void qsort(Item a[], int l, int r)
{
    if (l < r)
    {
        int p = part(a, l, r);
        qsort(a, l, p - 1);
        qsort(a, p + 1, r);
    }
}

int main()
{
    const int n = 3;
    Item it[n];

    f(i, 0, n)
    {
        cout << "Enter name of product " << i + 1 << ": ";
        getline(cin >> ws, it[i].nm);
        cout << "Enter description: ";
        getline(cin >> ws, it[i].desc);
        cout << "Enter price: ";
        cin >> it[i].pr;
        cout << "Available (1=Yes / 0=No): ";
        cin >> it[i].avail;
        cin.ignore();
        nl
    }

    qsort(it, 0, n - 1);

    cout << "\nProducts sorted by price (ascending):\n";
    f(i, 0, n)
            cout
        << i + 1 << ". " << it[i].nm
        << " | Price: " << it[i].pr
        << " | Desc: " << it[i].desc
        << " | Avail: " << (it[i].avail ? "Yes" : "No") << "\n";

    return 0;
}
