#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i < e; i++)
#define fn(i, s, e) for (int i = s; i >= e; i--)
#define nl cout << endl;

using namespace std;

class Node{
    int key;
    string value;
    public:
    Node(int key, string value) : key(key), value(value){}
};

void insert(int key, string value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    if (table[index] == nullptr) {
        // No collision
        table[index] = newNode;
    } else {
        // Collision occurred -> add to the end of linked list
        Node* temp = table[index];
        while (temp->next != nullptr) {
            if (temp->key == key) {
                // Update existing key
                temp->value = value;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        // Check Last node
        if (temp->key == key) {
            temp->value = value;
            delete newNode;
            return;
        }
        temp->next = newNode;
    }
}

// Delete a key
void remove(int key) {
    int index = hashFunction(key);
    Node* temp = table[index];
    Node* prev = nullptr;

    while (temp != nullptr && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Key " << key << " not found!\n";
        return;
    }

    if (prev == nullptr)
        table[index] = temp->next; // Remove head node
    else
        prev->next = temp->next;   // Remove middle or Last node

    delete temp;
    cout << "Key " << key << " deleted successfully.\n";
}

string search(int key) {
    int index = hashFunction(key);
    Node* temp = table[index];

    while (temp != nullptr) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return "Key not found";
}



int main()
{

    return 0;
}
