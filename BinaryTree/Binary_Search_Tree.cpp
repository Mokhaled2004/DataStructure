#include <iostream>
#include <cassert>
using namespace std;

struct Node{

    int item;
    Node *left;
    Node *right;

};

class BinarySearchTree{


private:

    Node *root;

public:



    BinarySearchTree() {
        root = nullptr;
    }



    void inorder(Node *p){

        if (p != nullptr) {

            inorder(p -> left);
            cout << p->item << " ";
            inorder(p -> right);

        }
    }


    void preorder(Node *p) {

        if (p != nullptr) {

            cout << p ->item << " ";
            preorder(p -> left);
            preorder(p -> right);

        }
    }


    void postorder(Node *p) {

        if (p != nullptr) {

            postorder(p -> left);
            postorder(p -> right);
            cout << p -> item << " ";

        }
    }


    int nodeCount(Node *p) {

        if (p == nullptr) {
            return 0;
        }
        else {
            return 1 + nodeCount(p -> left) + nodeCount(p -> right);
        }
    }


    int leavesCount(Node *p) {

        if ( p == nullptr) {
            return 0;
        }

        else if (( p -> left == nullptr) && ( p -> right == nullptr)) {
            return 1;
        }

        else {
            return leavesCount(p -> left) + leavesCount( p -> right);
        }
    }


    bool Search(int element) {

        Node *current = root;

        while (current != nullptr) {

            if (current -> item == element) {
                return true;
            }

            else if (current -> item > element) {
                current = current -> left;
            }

            else {
                current = current -> right;
            }
        }
        return false;
    }

    int max(int x, int y){

        if (x >= y) {
            return x;
        }
        else {
            return y;
        }

    }




    int height(Node *p) {

        if ( p == nullptr) {
            return 0;
        }

        else {
            return 1 + max(height(p -> left), height(p -> right));
        }
    }

    void insert (int element) {

        Node *current;
        Node *prev;
        Node *newNode;
        newNode = new Node;
        assert (newNode != nullptr) {
            newNode -> item = element;
            newNode -> left = nullptr;
            newNode -> right = nullptr;
        }

        if (root == nullptr) {
            root = newNode;
        }
        else {

            current = root;

            while (current != nullptr) {

                prev = current;

                if (current -> item == element) {
                    cout << "duplicates not allowed\n";
                    return;
                }

                else {

                    if (current -> item > element) {
                        current = current -> left;
                    }
                    else {
                        current = current -> right;
                    }

                }
            }

            if (prev -> item > element) {
                prev -> left = newNode;
            }
            else {
                prev -> right = newNode;
            }
        }
    }
};

int main() {

    return 0;
}

