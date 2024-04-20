#include <iostream>
#include <cstdlib>
using namespace std;

class LinkedList {

    struct Node {
        int item;
        Node *next;
    };
    Node *Head;
    Node *Tail;
    int length;

public:
    LinkedList () {
        Head = Tail = NULL;
        length = 0;
    }

    bool isEmpty () {
        return length ==0;
    }

    void InsertFirst(int element){

        Node *newNode = new Node;
        newNode -> item = element;

        if (length ==0 ){

            Head = Tail = newNode;
            newNode ->next = NULL;

        }

        else {

            newNode -> next = Head;
            Head = newNode;
        }
        length++;
    }

    void InsertLast(int element){
        Node *newNode = new Node;
        newNode -> item = element;
        if (length == 0) {
            Head = Tail = NULL;
            newNode -> next = NULL;
        }
        else {

            Tail -> next = newNode;
            newNode -> next = NULL;
            Tail = newNode;

        }
        length++;

    }

    void InsertAtPosition(int pos ,int element) {

        if (pos <0 || pos > length){
            cout<< "Out of range\n";
        }
        else {

            Node *newNode = new Node;
            newNode -> item = element;

            if (pos ==0) {

                InsertFirst(element);
            }

            else if (pos == length) {

                InsertLast(element);

            }

            else {

                Node *current = Head;
                for (int i =1;i<pos;i++) {
                    current = current -> next;
                }

                newNode -> next = current -> next;
                current -> next = newNode;
                length ++;

            }
        }
    }

    void RemoveFirst () {

        if (length == 0) {
            cout<<"Empty list cants be removed \n";
        }

        else if (length == 1) {
            delete Head;
            Tail = Head = NULL;
            length --;
        }

        else {

            Node *current = Head;
            Head = Head -> next;
            delete current;
            length --;

        }
    }

    void RemoveLast () {
        Node *current = Head -> next;
        Node *previous = Head;

        if (length == 0) {
            cout<<"Empty list cants be removed \n";
        }

        else if (length == 1) {
            delete Head;
            Tail = Head = NULL;
            length --;
        }

        else {

            while (current != Tail) {
                previous = current;
                current = current -> next;
            }

            delete current;
            previous -> next = NULL;
            Tail = previous;
            length --;


        }

    }

    void RemoveElement(int element) {

        if (isEmpty()) {
            cout<<"Empty list cant be removed !\n";
            return;
        }

        Node *current;
        Node *previous;

        if (Head -> item == element){
            current = Head;
            Head = Head->next;
            delete current;
            length --;
        }

        if (length == 0) {
            Tail = NULL;
        }

        else {
            current = Head -> next;
            previous = Head;

            while (current != NULL) {

                if (current -> item == element) {
                    break;
                }

                previous = current;
                current = current -> next;
            }

            if (current == NULL) {
                cout<<"Element not found \n";
            }

            else {
                previous -> next = current -> next;
                if (Tail == current) {
                    Tail = previous;
                }
                delete current;
                length --;

            }

        }

    }


    void RemoveAllOccElement(int element) {  //Remove all occurence
        while (InList(element)) {
            RemoveElement(element);
        }
    }

    bool InList(int element) {  //check if element is in the list

        Node *current = Head;
        while (current != NULL) {
            if (current -> item == element) {
                return  true;
            }

            current = current -> next;

        }
        return false;
    }



    void RemoveAtPosition(int pos){

        if (pos <0 || pos > length){
            cout<< "Out of range\n";
        }

        else {

            Node *current;
            Node *previous;

            if (pos == 0) {

                current = Head;
                Head = Head -> next;
                delete current;
                length --;

                if (length == 0) {
                    Tail = NULL;
                }

            }

            else {

                current = Head -> next;
                previous = Head;

                for(int i = 1;i< pos ; i++) {
                    previous = current;
                    current = current -> next;
                }

                previous -> next = current -> next;
                if (Tail == current) {
                    Tail = previous;
                }

                delete current;
                length --;

            }

        }

    }

    void Reverse() {

        Node *previous;
        Node *current;
        Node *next;

        previous = NULL;
        current = Head;
        next = current -> next;

        while (next != NULL) {

            next = current -> next;
            current -> next = previous;
            previous = current;
            current = next;
        }
        Head = previous;
    }

    int Search(int element) {

        Node *current = Head;
        int pos = 0;
        while (current != NULL) {

            if (current -> item == element) {
                return pos;
            }
            current = current -> next;
            pos++;
        }
        return -1;
    }


    void moveTailToFront () {
        if (length == 0 || length == 1) {
            return;
        }

        else {

            Node *current = Head;


            while (current -> next  != Tail) {
                current = current -> next;
            }

            Tail -> next = Head;
            Head = Tail;
            Tail = current;
            Tail -> next = nullptr;
        }
    }


    void deleteMin()
    {
        if (Head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* current = Head;
        Node* min = Head;
        Node* prev = nullptr;

        while (current->next != nullptr)
        {
            if (current->next-> item< min->item)
            {
                min = current->next;
                prev = current;
            }
            current = current->next;
        }

        if (min == Head) {
            Head = Head->next;
        } else {
            prev->next = min->next;
        }

        delete min;
    }



    


    void Print(){

        Node *current = Head;
        while (current != NULL){
            cout<<current->item<<" ";
            current = current -> next;
        }
    cout<<endl;
    }

};


int main() {

    LinkedList List;
    List.InsertFirst(10);
    List.InsertLast(30);
    List.InsertLast(40);
    List.InsertAtPosition(1,20);
    List.InsertFirst(0);
    List.InsertLast(50);
    List.Print(); // 0 10 20 30 40 50
    List.RemoveFirst();
    List.Print(); // 10 20 30 40 50
    List.RemoveLast();
    List.Print(); // 10 20 30 40
    List.RemoveElement(30);
    List.Print(); // 10 20 40
    List.RemoveAtPosition(1);
    List.Print(); // 10 40
    List.Reverse();
    List.Print(); // 40 10
    List.InsertFirst(60);
    List.InsertFirst(90);
    List.InsertFirst(70);
    List.Print(); // 70 90 60 40 10
    cout << List.Search(40);
    cout<<endl;
    List.InsertFirst(2);
    List.InsertFirst(2);
    List.Print();
    List.RemoveAllOccElement(2);
    List.Print();  //70 90 60 40 10


    return 0;
}
