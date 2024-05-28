#include <iostream>

using namespace std;


    const int maksimalQueue = 5;
    int front = 0;
    int back = 0;
    string queueTeller[maksimalQueue]; 

    bool isFull() {
        return back == maksimalQueue;
    }

    bool isEmpty() {
        return back == 0;
    }

    void enqueueAntrian(string data) {
        if(isFull()) {
            cout << "Antrian Penuh" << endl;
        }else {
            queueTeller[back] = data;
            back++;
        }
    }

    void dequeueAntrian() {
        if(isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            for(int i = 0; i < back; i++) {
                queueTeller[i] = queueTeller[i + 1];
            }
            queueTeller[back - 1] = "";
            back--;
        }
    }

    int countQueue() {
        return back;
    }

    void clearQueue() {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        
    }

    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        for (int i=0; i < maksimalQueue; i++) {
            if(queueTeller[i] != "") {
            cout << i + 1 << ". "<< queueTeller[i] << endl;
        }else {
            cout << i+1 << ". (kosong)"<< endl;
        }
    }
    }

    int main() {
        enqueueAntrian("Andi");
        enqueueAntrian("Maya");
        viewQueue();
        cout << "Jumlah antrian = " << countQueue() << endl;

        dequeueAntrian();
        viewQueue();
        cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
    }

