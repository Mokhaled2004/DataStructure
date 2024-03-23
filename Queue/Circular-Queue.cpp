#include <iostream>
using namespace std;
template <class t>
class ArrayQueue {

private:

    int First;
    int Last;
    int length;
    int maxsize;
    t *arr;

public:

    ArrayQueue(int size) {

        maxsize = size;
        First = 0;
        Last = maxsize -1;
        length = 0;
        arr = new int [maxsize];


    }

    bool isEmpty(){
        if (length == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull (){
        return length == maxsize;
    }

    void enqueue (t element) {

        if (isFull()) {
            cout << "Queue is Full cant Enqueue\n";
        }

        else {

            Last = (Last + 1) % maxsize;
            arr[Last] = element;
            length ++;

        }

    }


    void dequeue () {

        if (isEmpty()) {
            cout << "Queue is Empty cant Dequeue\n";
        }

        else {

            First = (First + 1) % maxsize;
            --length;

        }

    }

    t getFirst() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
        }
        else {
            return arr[First];
        }
    }

    t getLast() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
        }
        else {
            return arr[Last];
        }
    }


    int QueueSearch(t element) {
        int pos = -1;
        if (!isEmpty())
        {
            for (int i = First; i != Last; i = (i + 1) % maxsize) {
                if (arr[i] == element) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1)
            {
                if (arr[Last] == element)
                    pos = Last;
            }
        }
        else
            cout << "Q is empty ! " << endl;
        return pos;
    }


    void Print()
    {
        if (!isEmpty()) {
            for (size_t i = First; i != Last; i = (i + 1) % maxsize)
            {
                cout << arr[i] << " ";
            }
            cout << arr[Last];
        }
        else
            cout << "Empty Queue";
    }

    ~ArrayQueue() {
        delete[]arr;
    }

};



int main() {

    ArrayQueue <int>queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.Print();
    queue.dequeue();
    queue.Print();
    cout << queue.getFirst();
    cout << endl;
    cout << queue.getLast();
    cout << endl;
    cout<<queue.QueueSearch(2);
    queue.enqueue(7);
    queue.enqueue(8);
    cout<<endl;
    queue.Print();
    
    return 0;
}

