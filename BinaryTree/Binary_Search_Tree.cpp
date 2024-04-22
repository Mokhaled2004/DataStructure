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
        assert (newNode != nullptr) ;
            newNode -> item = element;
            newNode -> left = nullptr;
            newNode -> right = nullptr;


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


    int getLevel(Node *node , int element , int level) {

        if (node == nullptr) {
            return 0;
        }

        if (node -> item == element) {
            return level;
        }

        int down = getLevel(node -> left , element,level +1);
        if (down != 0) {
            return down;
        }

        down = getLevel(node -> right , element , level + 1);
        return down;

    }


    void inOrderCall() {
        inorder(root);
        cout << endl;
    }

    void preOrderCall() {
        preorder(root);
        cout << endl;
    }

    void postOrderCall() {
        postorder(root);
        cout << endl;
    }


    void remove(int element) {

        Node *current;
        Node *prev;

        if (root == nullptr) {
            cout <<"Cannot delete from an empty tree\n";
            return;
        }

        if (root -> item == element) {
            DeleteFromTree(root);
            return;
        }

        prev = root;

        if (root -> item > element) {
            current = root -> left;
        }
        else {
            current = root -> right;
        }

        while (current != nullptr) {

            if (current -> item == element) {
                break;
            }

            else {
                prev = current;

                if (current -> item > element) {
                    current = current -> left;
                }
                else {
                    current = current -> right;
                }
            }

            if (current == nullptr) {
                cout << "item to be deleted is not in the tree\n";
            }

            else if (prev -> item > element) {
                DeleteFromTree(prev -> left);
            }
            else {
                DeleteFromTree(prev -> right);
            }
        }
    }



    void DeleteFromTree (Node* &p) {

        Node *current;
        Node *prev;
        Node *tmp;


        if (p -> left == nullptr && p -> right == nullptr) {
            delete p;
            p = nullptr;
        }

        else if (p -> left == nullptr) {
            tmp = p;
            p = p-> right;
            delete tmp;
        }

        else if (p -> right == nullptr) {
            tmp = p;
            p  = p -> left;
            delete tmp;
        }

        else {

            current = p-> left;
            prev = nullptr;

            while (current -> right != nullptr) {
                prev = current;
                current = current -> right;
            }

            p -> item = current -> item;

            if (prev == nullptr) {
                p -> left = current -> left;
            }

            else {
                prev -> right = current -> right;
            }

            delete current ;

        }
    }



   void  deleteByCopying (Node* &p) {
        Node *prev , *tmp;

        if ( p -> right == nullptr) {
            p = p -> left;
        }
        else if (p -> left == nullptr) {
            p = p -> right;
        }
        else {

            tmp = p -> left;
            prev = p;

            while (tmp -> right != 0) {
                prev = tmp;
                tmp = tmp -> right;
            }

            p -> item = tmp -> item;
            if (prev == p) {
                prev -> left = tmp -> left;
            }
            else {
                prev -> right = tmp -> left;
            }

            delete tmp;

        }
    }


};

int main() {
    BinarySearchTree b;
    b.insert(9);
    b.insert(4);
    b.insert(1);
    b.insert(5);
    b.insert(10);
    b.insert(11);


    b.inOrderCall();
    b.preOrderCall();
    b.postOrderCall();

    if(b.Search(10)) {
        cout << "Found it\n";
    }

    b.remove(4);
    b.inOrderCall();



    return 0;
}
