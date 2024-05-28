#include <iostream>

using namespace std;

// Struktur Node untuk linked list dengan atribut Nama dan NIM
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Struktur Queue menggunakan linked list
struct Queue {
    Node* depan;
    Node* belakang;
};

// Fungsi untuk membuat node baru
Node* buatNode(string nama, string nim) {
    Node* nodeBaru = new Node();
    nodeBaru->nama = nama;
    nodeBaru->nim = nim;
    nodeBaru->next = nullptr;
    return nodeBaru;
}

// Fungsi untuk menginisialisasi queue kosong
void inisialisasiQueue(Queue &q) {
    q.depan = nullptr;
    q.belakang = nullptr;
}

// Fungsi untuk memeriksa apakah queue kosong
bool isEmpty(Queue q) {
    return q.depan == nullptr;
}

// Fungsi untuk menambahkan elemen ke queue
void enqueueAntrian(Queue &q, string nama, string nim) {
    Node* nodeBaru = buatNode(nama, nim);
    if (isEmpty(q)) {
        q.depan = nodeBaru;
        q.belakang = nodeBaru;
    } else {
        q.belakang->next = nodeBaru;
        q.belakang = nodeBaru;
    }
}

// Fungsi untuk menghapus elemen dari queue
void dequeueAntrian(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = q.depan;
        q.depan = q.depan->next;
        delete temp;
        if (q.depan == nullptr) {
            q.belakang = nullptr;
        }
    }
}

// Fungsi untuk menghitung elemen dalam queue
int countQueue(Queue q) {
    int count = 0;
    Node* current = q.depan;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi untuk mengosongkan queue
void clearQueue(Queue &q) {
    while (!isEmpty(q)) {
        dequeueAntrian(q);
    }
}

// Fungsi untuk menampilkan elemen-elemen dalam queue
void viewQueue(Queue q) {
    cout << "Data antrian mahasiswa: " << endl;
    Node* current = q.depan;
    int index = 1;
    while (current != nullptr) {
        cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
        index++;
    }
    if (index == 1) {
        cout << "Antrian kosong" << endl;
    }
}

int main() {
    Queue q;
    inisialisasiQueue(q);

    enqueueAntrian(q, "Andi", "123456");
    enqueueAntrian(q, "Maya", "789101");
    viewQueue(q);
    cout << "Jumlah antrian = " << countQueue(q) << endl;

    dequeueAntrian(q);
    viewQueue(q);
    cout << "Jumlah antrian = " << countQueue(q) << endl;

    return 0;
}
