#include <iostream>
#include <cassert>
using namespace std;
template <class t>
class linkedQueue {

private:
     struct Node {
         t item;
         Node *next;
     };

     Node *front;
     Node *rear;
     int length;

public:

    linkedQueue() {
        front = rear = nullptr;
        length = 0;
    }


    bool isEmpty () {
        if (rear == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }


    void Enqueue(t element) {

        if (isEmpty()) {
            front = new Node;
            front -> item = element;
            front -> next = nullptr;
            rear = front ;
            length++;
        }

        else {

            Node *newNode = new Node;
            newNode -> item = element;
            newNode -> next = nullptr;
            rear -> next = newNode;
            rear = newNode;
            length++;

        }
    }

    void Dequeue () {

        if (isEmpty()) {
            return;
        }

        else {

            Node *tmp;
            tmp = front;

            if (length == 1) {
                front = nullptr;
                rear = nullptr;
                length = 0;
            }
            else {
                front = front->next;
                tmp->next = nullptr;
                delete tmp;
                length--;
            }
        }
    }


    int getFront () {
        assert(!isEmpty());
        return front -> item;

    }

    int getRear () {
        assert(!isEmpty());
        return rear-> item;
    }

    void getFront2 (t &element) {
        element = front -> item;
    }

    int getSize () {
        return length;
    }

    void print() {

        if (isEmpty()) {
            cout<<"queue is empty cant print\n";
        }
        else {

            Node *current = front;
            while (current != nullptr) {
                cout << current -> item << " ";
                current = current -> next;
            }
            cout<<endl;

        }
    }

    void clearQueue () {

        if (isEmpty()) {
            cout<<"Queue is already empty\n";
        }

        else {

            Node *current;

            while (front != nullptr) {
                current = front;
                front = front -> next;
                delete current;
            }
            rear = nullptr;
            length =0;

        }





    }


    void search (t element) {

        Node *current = front;
        bool flag = false;
        while (current != nullptr) {
            if (current -> item == element ) {
                flag = true;
                break;
            }
            current = current -> next;
        }

        if (flag == false) {
            cout << "item is not found in this queue :(\n";
        }
        else {
            cout << "item found :)\n";
        }
    }

    void searchreturnPos (t element) {

        Node *current = front;
        bool flag = false;
        int count = 0;
        while (current != nullptr) {
            if (current -> item == element ) {
                flag = true;
                break;
            }
            current = current -> next;
            count++;
        }

        if (flag == false) {
            cout << "item is not found in this queue :(\n";
        }
        else {
            cout << "item found :) at position: " << count<<endl;
        }
    }


};



int main() {

    linkedQueue <int>q1;

    q1.Enqueue(100);
    q1.Enqueue(200);
    q1.Enqueue(300);
    q1.print();    // 100 200 300
    q1.Dequeue();
    q1.print();    // 200 300
    q1.Enqueue(400);
    q1.print();    // 200 300 400
    cout << q1.getFront();   // 200
    cout << endl;
    cout << q1.getRear();    // 400
    cout << endl;
    cout << q1.getSize();   // 3
    cout << endl;
    q1.clearQueue();
    q1.print();    // queue is empty cant print
    cout << q1.getSize(); // 0
    cout << endl;
    q1.Enqueue(100);
    q1.Enqueue(200);
    q1.Enqueue(300);
    q1.print();   // 100 200 300
    q1.search(200);  // item found :)
    q1.search(600);   // item is not found in this queue :(
    q1.searchreturnPos(300);  // item found :) at position: 2

    return 0;
}

