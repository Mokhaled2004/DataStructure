#include <iostream>
#include <string>
using namespace std;

class Student {

private:
    string Name;
    int ID;
    double GPA;

public:

    Student (){
        Name = "";
        ID = 0;
        GPA = 0;
    }

    Student (string name,int id,double gpa) {
        Name = name;
        ID = id;
        GPA = gpa;
    }

    friend class StudentList;
};

class StudentList {

private:

    struct Node {
        Student *data;
        Node *next;
    };

    Node *Head;
    Node *Tail;
    int Length;

public:

    StudentList() {
        Head = Tail = nullptr;
        Length = 0;
    }

    ~StudentList(){
        Node *temp;
        while (Head != nullptr)
        {
            temp = Head;
            Head = Head->next;
            delete temp;
        }
        Tail = nullptr;
        Length = 0;
        }


    bool isEmpty () const{
        return Length ==0;
    }

    void InsertAndSort(Student *s){
        Node *newNode = new Node;
        newNode -> data = s;

        if (Head == nullptr || s -> ID < Head -> data ->ID) {
            newNode -> next = Head;
            Head = newNode;
        }

        else {
            Node *current = Head;
            while (current -> next != nullptr && s -> ID > current -> next -> data -> ID) {
                current = current->next;
            }
            newNode -> next = current -> next;
            current -> next = newNode;

        }
        Length++;
    }

    void RemoveById(int id) {

        if (isEmpty())  {
            return;
        }

        Node *current;
        Node *previous;

        if (Head -> data -> ID == id) {
            current = Head;
            Head = Head -> next;
            delete current -> data;
            delete current;
            Length--;
        }

        else {

            current = Head -> next;
            previous = Head;

            while (current != nullptr) {

                if (current -> data -> ID == id) {
                    break;
                }
                previous = current;
                current = current -> next;
            }

            if (current == nullptr) {
                cout<<"ID not found\n";
            }
            if (Tail == current) {
                Tail = previous;
            }
            else {

                previous -> next = current -> next;
                delete current -> data;
                delete current;
                Length--;

            }

        }

    }

    void Print(){

        Node *current = Head;
        while (current != nullptr){
            cout<<current->data -> Name<<"         "<< current -> data -> ID <<"         " << current -> data -> GPA;
            cout <<endl;
            current = current -> next;
        }

    }

    void Search (int id) {

        Node *current = Head;
        while (current != nullptr) {
            if (current -> data -> ID == id) {
                cout<<current->data -> Name<<"         "<< current -> data -> ID <<"         " << current -> data -> GPA<<endl;
                return;
            }
            current = current -> next;
        }

        cout<<"Student not found!\n";

    }

    int size() const{
        return Length;
    }

    };


int main() {

    StudentList list;
    Student *s1 = new Student("mike",20,3.5);
    Student *s2 = new Student("essam",10,3.6);
    Student *s3 = new Student("mazen",40,3.7);
    Student *s4 = new Student("yasser",50,3.8);
    Student *s5 = new Student("mona",60,3.9);

    list.InsertAndSort(s1);
    list.InsertAndSort(s2);
    list.InsertAndSort(s3);
    list.InsertAndSort(s4);

    cout <<"Name          ID         GPA\n";
    list.Print();
    cout<<"-------------------------\n";
    list.RemoveById(40);
    list.RemoveById(10);
    list.InsertAndSort(s5);
    list.Print();
    cout<<"-------------------------\n";
    list.Search(20);
    cout<<"Linked List size : ";
    cout<<list.size();

    return 0;
}

