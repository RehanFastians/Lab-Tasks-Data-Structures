#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
using namespace std;

const int N = 15;

class StudentHashTable
{
private:
    int roll[N];
    string name[N];
    bool occupied[N];

    int hashFunction(int key)
    {
        return key % N;
    }

public:
    StudentHashTable()
    {
        for (int i = 0; i < N; i++)
        {
            roll[i] = 0;
            name[i] = "";
            occupied[i] = false;
        }
    }

    void InsertRecord(int rollNo, const string &studentName)
    {
        int hash = hashFunction(rollNo);
        int index;
        int attempt = 0;

        while (attempt < N)
        {
            index = (hash + attempt * attempt) % N;

            if (!occupied[index] || roll[index] == rollNo)
            {
                roll[index] = rollNo;
                name[index] = studentName;
                occupied[index] = true;
                return;
            }

            attempt++;
        }

        cout << "Hash table full, cannot insert roll number " << rollNo;
        nl
    }

    void SearchRecord(int rollNo)
    {
        int hash = hashFunction(rollNo);
        int index;
        int attempt = 0;

        while (attempt < N)
        {
            index = (hash + attempt * attempt) % N;

            if (!occupied[index])
            {
                cout << "Record not found for roll number " << rollNo;
                nl return;
            }

            if (roll[index] == rollNo)
            {
                cout << "Roll number " << rollNo << ": " << name[index];
                nl return;
            }

            attempt++;
        }

        cout << "Record not found for roll number " << rollNo;
        nl
    }
};

int main()
{
    StudentHashTable sht;

    sht.InsertRecord(1, "Ali");
    sht.InsertRecord(16, "Sara");
    sht.InsertRecord(31, "Raza");
    sht.InsertRecord(2, "Taha");

    nl
        sht.SearchRecord(16);
    sht.SearchRecord(31);
    sht.SearchRecord(5);
    nl

        return 0;
}