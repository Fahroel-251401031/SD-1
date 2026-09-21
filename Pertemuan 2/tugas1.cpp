#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    if (temp == NULL) {
        cout << "NULL\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->nilai << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertFirst(int val) {
    Node *newNode = new Node;
    newNode->nilai = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printList();
}

void insertLast(int val) {
    Node *newNode = new Node;
    newNode->nilai = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    printList();
}

void insertAfter(int val, int target) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node *p = head;
    while (p != NULL && p->nilai != target) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Nilai " << target << " tidak ditemukan!\n";
    } else {
        Node *newNode = new Node;
        newNode->nilai = val;
        newNode->next = p->next;
        p->next = newNode;

        if (p == tail) {
            tail = newNode;
        }
        printList();
    }
}

void deleteByValue(int target) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head->nilai == target) {
        Node *temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
        printList();
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->nilai != target) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Nilai " << target << " tidak ditemukan!\n";
    } else {
        Node *temp = p->next;
        p->next = temp->next;

        if (temp == tail) {
            tail = p;
        }
        delete temp;
        printList();
    }
}

int main() {
    int pilihan, nilai, target;

    do {
        cout << "\n MENU SINGLE LINKED LIST\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertFirst(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(nilai);
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> target;
                insertAfter(nilai, target);
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> target;
                deleteByValue(target);
                break;
            case 5:
                printList();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}