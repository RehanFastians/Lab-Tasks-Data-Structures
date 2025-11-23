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
    string value;
    Node *next;

public:
    Node(string key, string value, Node *next = nullptr) : key(key), value(value), next(next) {}
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
        f(i , 0, hashSize)  hashTable[i]=nullptr;
    }
    int hashFunction(string key);
    void Add_Record(string value);
    void remove(string key);
    string Word_Search(string key);
    void display_Dictionary();
};

int HashMap ::hashFunction(string key)
{
    return accumulate(all(key), 0) % 100;
}

void HashMap ::Add_Record(string value)
{
    string key = value;
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

string HashMap ::Word_Search(string key)
{
    int index = hashFunction(key);
    Node *temp = hashTable[index];

    while (temp != nullptr)
    {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return "Message not found";
}

void HashMap :: display_Dictionary(){
    f(i, 0, hashSize){
        if(!hashTable[i])   continue;
        Node *cur = hashTable[i];
    }
}

int main()
{
    HashMap myHash(100);
    // myHash.Add_Record('A', "aaaaa");
    // myHash.Add_Record('B', "bbbbb");
    // myHash.Add_Record('C', "ccccc");
    // myHash.Add_Record('A', "zzzzz");
    // cout << myHash.Word_Search("ccccc");
    // nl

    //         cout
    //     << myHash.Word_Search("zzzzz");
    nl return 0;
}
