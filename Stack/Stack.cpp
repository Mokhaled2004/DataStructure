#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE = 100;
class Stack {

    int top;
    int item[MAX_SIZE];

public:

    Stack () {
        top = -1;
    }

    void push(int element) {

        if (top >= MAX_SIZE -1) {
            cout<<"Stack full to push\n";

        }

        else {
            top++;
            item[top] = element;
        }
    }


    bool isEmpty(){
        if (top == -1) {
            return true;
        }
        else {
            return  false;
        }
    }


    void pop() {
        if (isEmpty()){
            cout<<"Stack is empty\n";
        }
        else {
            top--;
        }
    }

    void pop(int &element) {
        if (isEmpty()){
            cout<<"Stack is empty\n";
        }
        else {
            element = item[top];
            top--;
        }
    }

    void getTop(int &StackTop) {
        if (isEmpty()){
            cout<<"Stack is empty\n";
        }
        else {
            StackTop = item[top];
            cout<<StackTop<<endl;
        }
    }

    void Print() {
        for (int i = top;i >= 0 ;i--) {
            cout<<item[i]<<" ";
        }
        cout<<endl;
    }


};





int main() {

    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);
    stack.Print();    // 20 15 10 5
    int y = 0;
    stack.getTop(y);   // 20
    stack.pop();
    stack.Print();  // 15 10 5
    stack.push(7);
    stack.Print();  // 7 15 10 5

    return 0;
}
