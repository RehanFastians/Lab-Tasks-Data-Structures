#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;
#define all(arr) arr.begin(), arr.end()

using namespace std;
class HashMap;
class Node
{
    string key;
    char value;
    Node *next;

public:
    Node(string key, char value, Node *next = nullptr) : key(key), value(value), next(next) {}
    friend class HashMap;
};

class HashMap
{
    Node **hashTable = nullptr;
    int hashSize = 0;

public:
    HashMap(int size = 0) : hashSize(size)
    {
        hashTable = new Node *[hashSize];
    }
    int hashFunction(string key);
    void insert(char value, string key);
    void remove(string key);
    char search(string key);
};

int HashMap ::hashFunction(string key)
{
    return accumulate(all(key), 0) % hashSize;
}

void HashMap ::insert(char value, string key)
{
    int index = hashFunction(key);
    Node *newNode = new Node(key, value);

    if (hashTable[index] == nullptr)
    {
        // No collision
        hashTable[index] = newNode;
    }
    else
    {
        // Collision occurred -> add to the end of linked list
        Node *temp = hashTable[index];
        while (temp->next != nullptr)
        {
            if (temp->key == key)
            {
                // Update existing key
                temp->value = value;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        // Check Last node
        if (temp->key == key)
        {
            temp->value = value;
            delete newNode;
            return;
        }
        temp->next = newNode;
    }
}

// Delete a key
void HashMap ::remove(string key)
{
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    Node *prev = nullptr;

    while (temp != nullptr && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Key " << key << " not found!\n";
        return;
    }

    if (prev == nullptr)
        hashTable[index] = temp->next; // Remove head node
    else
        prev->next = temp->next; // Remove middle or Last node

    delete temp;
    cout << "Key " << key << " deleted successfully.\n";
}

char HashMap ::search(string key)
{
    int index = hashFunction(key);
    Node *temp = hashTable[index];

    while (temp != nullptr)
    {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return '-';
}

int main()
{
    HashMap myHash(100);
    myHash.insert('A', "aaaaa");
    myHash.insert('B', "bbbbb");
    myHash.insert('C', "ccccc");
    myHash.insert('A', "zzzzz");
    cout << myHash.search("ccccc");
    nl

            cout
        << myHash.search("zzzzz");
    nl return 0;
}
