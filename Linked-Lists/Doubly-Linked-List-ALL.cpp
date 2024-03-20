#include <iostream>
using namespace std;

class DoublyLinkedList {
private:

    struct Node {

        int item;
        Node *next;
        Node *prev;
    };

    Node *Head;
    Node *Tail;
    int length;

public:

    DoublyLinkedList() {
        Head = Tail = NULL;
        length = 0;
    }

    bool isEmpty() {
        return (Head == NULL);
    }

    void InsertFirst(int element) {

        Node *newNode = new Node;
        newNode -> item = element;

        if(length == 0) {
            Head = Tail = newNode;
            newNode -> next = newNode -> prev = NULL;
        }

        else {

            newNode -> next = Head;
            newNode -> prev = NULL;
            Head -> prev = newNode;
            Head = newNode;

        }
        length++;
    }

    void InsertLast(int element) {

        Node *newNode = new Node;
        newNode -> item = element;

        if  (length == 0){

            Head = Tail = newNode;
            newNode -> next = newNode -> prev = NULL;

        }

        else {

            newNode -> next = NULL;
            newNode -> prev = Tail;
            Tail -> next = newNode;
            Tail = newNode;

        }
        length ++;
    }

    void InsertAtPosition(int pos, int element) {
        if (pos < 0 || pos > length) {
            cout<<"Out of range\n";
        }

        else {

            Node *newNode = new Node;
            newNode -> item = element;

            if (pos == 0) {
                InsertFirst(element);
            }

            else if(pos == length) {
                InsertLast(element);
            }

            else {
                Node *current = Head;

                for(int i =1;i<pos;i++) {
                    current = current -> next;
                }

                newNode -> next = current -> next;
                newNode -> prev = current;
                current -> next = newNode;
                current -> next -> prev = newNode;
                length ++;
            }
        }
    }

    void RemoveFirst () {
        if (length == 0) {
            cout << "Empty list\n";
            return;
        }

        else if (length == 1) {

            delete Head;
            Head = Tail = NULL;

        }

        else {

            Node *current = Head;
            Head = Head->next;
            Head->prev = NULL;
            delete current;

        }

            length--;
    }


    void RemoveLast () {

        if (length == 0) {
            cout << "Empty list\n";
            return;
        }

        else if (length == 1) {

            delete Head;
            Head = Tail = NULL;

        }


        else {

            Node *current = Tail;
            Tail = Tail -> prev;
            Tail -> next = NULL;
            delete current;

        }
    length--;
    }

    void RemoveElement(int item)
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Remove ";
            return;
        }
        Node*current = Head->next;

        if (Head->item == item)
        {
            RemoveFirst();
            return;
        }
        else
        {
            while (current != NULL)
            {
                if (current->item == item)
                    break;
                current = current->next;
            }

            if (current == NULL) {
                cout << "The item is not there\n";
                return;
            }
            else if (current->next == NULL) {
                RemoveLast();
                return;
            }

            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                length--;
            }
        }
    }

    void Print(){

        Node *current = Head;
        while (current != NULL){
            cout<<current->item<<" ";
            current = current -> next;
        }
        cout<<endl;
    }

    void PrintInReverse(){

        Node *current = Tail;
        while (current != NULL){
            cout<<current->item<<" ";
            current = current -> prev;
        }
        cout<<endl;
    }

    ~DoublyLinkedList()
    {
        Node *temp;
        while (Head != NULL)
        {
            temp = Head;
            Head = Head->next;
            delete temp;
        }
        Tail = NULL;
        length = 0;
    }

};


int main() {

    DoublyLinkedList List;
    List.InsertFirst(2);
    List.InsertFirst(4);
    List.InsertFirst(5);
    List.Print();       // 5 4 2
    List.InsertLast(10);
    List.InsertLast(20);
    List.Print();      // 5 4 2 10 20
    List.PrintInReverse();    // 20 10 2 4 5
    List.RemoveFirst();
    List.Print();    // 4 2 10 20
    List.RemoveLast();
    List.Print();    // 4 2 10
    List.InsertAtPosition(1,7);
    List.Print();    // 4 7 2 10
    List.InsertFirst(11);
    List.RemoveElement(4);
    List.Print();  // 11 7 2 10
    
    return 0;
}

