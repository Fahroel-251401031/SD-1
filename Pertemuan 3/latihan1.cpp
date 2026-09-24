#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value) {
    if (top == MAX - 1) {
        cout << "Stack penuh!\n";
    } else {
        top++;
        stack[top] = value;
    }
}

// TODO : Mengambil karakter paling atas
char pop() {
    if (top == -1) {
        cout << "Stack kosong!\n";
        return '\0';
    } else {
        char value = stack[top];
        top--;
        return value;
    }
}

int main() {
    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter kata ke stack
    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    cout << "Hasil kata setelah dibalik: ";

    // TODO : Mengeluarkan karakter dari stack
    while (top != -1) {
        cout << pop();
    }

    cout << endl;

    return 0;
}