#include <iostream>
using namespace std;

// Deklarasi struktur node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Insert di Depan
void insertFirst(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Insert di Belakang
void insertLast(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert setelah nilai tertentu
void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List kosong, silahkan insert di depan \n";
        return;
    }

    Node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ketemu\n";
    } else {
        Node *newNode = new Node;
        newNode->value = n;
        newNode->next = p->next;
        p->next = newNode;

        if (p == tail) {
            tail = newNode;
        }
    }
}

// Cetak linked list
void printList() {
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    system("cls");
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}