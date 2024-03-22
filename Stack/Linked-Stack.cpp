#include <iostream>
using namespace std;

template <class t>
class Stack {

    struct Node {
        t item;
        Node *next;
    };

    Node *top , *current;
public:

    Stack() {
        top = nullptr;
    }

    void push(t element) {
        Node *newNode = new Node;

        newNode -> item = element;
        newNode -> next = top;
        top  = newNode;
    }

    bool IsEmpty () {
        return top == nullptr;
    }

    void pop() {

        if (IsEmpty()) {
            cout << "Stack is empty on pop\n";
        }

        else {

            Node *tmp = top;
            top = top -> next;
            tmp -> next = nullptr;
            delete tmp;
        }

    }

    void pop(t &element) {

        if (IsEmpty()) {
            cout << "Stack is empty on pop\n";
        }

        else {
            element = top -> item;
            Node *tmp = top;
            top = top -> next;
            delete tmp;
        }

    }

    void getTop(t &element) {

        if (IsEmpty()) {
            cout << "Stack is empty on pop\n";
        }

        else {
            element = top -> item;
            
            cout<<element;
        }

    }

    void Print () {



            current = top;

            while (current != nullptr) {
                cout << current -> item << " ";
                current = current -> next;
            }

        cout<<endl;
    }


};


int main() {

    Stack <int > stack;
    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.Print();     // 300 200 100
    stack.pop();
    stack.Print();     // 200 100
    int x = 0;
    stack.pop(x);
    cout<<x<<endl;     // 200
    stack.push(400);
    stack.Print();     // 400 100
    int y = 0;
    stack.getTop(y);    // 400





    return 0;
}

