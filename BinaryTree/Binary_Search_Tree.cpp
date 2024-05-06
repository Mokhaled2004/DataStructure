#include <iostream>
#include <math.h>
using namespace std;    

// insert                   47
// delete                   288
// search                   269
// getMin                   136
// getMax                   150
// getSum                   173
// getLevel                 208
// getNumberOfNodes         228
// getNumberOfLeafNodes     241
// getHeight                256
// getSumFromRootTillNode   183
// displayInorder           95
// displayPreorder          104
// displayPostorder         113

struct Node {   //Node struct 
    int item;
    Node* left;
    Node* right;
    Node(int val) {    // Node constructor
        item = val;
        left = NULL;
        right = NULL;
    }
};  


class BST{    //BSt class


    private:

        Node* root; 

    public:

        BST() {    // BST constructor

            root = nullptr;

        }

        void insert(int element) {     //insert function
            
            Node *current;
            Node *prev;
            Node *newNode;
            newNode = new Node(element); 
            newNode -> left = nullptr;
            newNode -> right = nullptr;
           

            if (root == nullptr) {     // if the tree is empty the root will be the new node
                root = newNode;
            }

            else {             // if the tree is not empty then we will traverse the tree to find the correct position for the new node
                current = root;
                while (current != nullptr) {

                    prev = current;
                    
                    if (current -> item == element) {      // if the element already exists in the tree
                        cout << "Eelement already exists in the tree" << endl; 
                        return;
                    }

                    else {     // if the element does not exist in the tree then we will traverse the tree to find the correct position for the new node

                        if (current -> item > element) {
                        current = current -> left;
                        }
                        else {
                        current = current -> right;
                        }

                    }
                }

                if (prev -> item > element) {   // if the element is less than the parent node then the new node will be the left child of the parent node
                    prev -> left = newNode;
                }
                else {
                    prev -> right = newNode;
                
                }
            }
        }    


    void inorder(Node* root) {    // inorder traversal
        if (root == nullptr) {
            return;
        }
        inorder(root -> left);
        cout << root -> item << " ";
        inorder(root -> right);
    }

    void preorder(Node* root) {     // preorder traversal
        if (root == nullptr) {
            return;
        }
        cout << root -> item << " ";
        preorder(root -> left);
        preorder(root -> right);
    }

    void postorder(Node* root) {     // postorder traversal
        if (root == nullptr) {
            return;
        }
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> item << " ";
    }


    void display_inorder() {     // display inorder traversal
        inorder(root);
    }

    void display_preorder() {      // display preorder traversal
        preorder(root);
    }

    void display_postorder() {      // display postorder traversal
        postorder(root);
    }


    int getmin(Node *root) {        // get the minimum element in the tree
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return -1;
        }
        else {
            Node *current = root;
            while (current -> left != nullptr) {
                current = current -> left;
            }
            return current -> item;
        }
    }

    int getmax(Node *root) {        // get the maximum element in the tree
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return -1;
        }
        else {
            Node *current = root;
            while (current -> right != nullptr) {
                current = current -> right;
            }
            return current -> item;
        }
    }

    int getMin() {        // get the minimum element in the tree
        return getmin(root);
    }
 
    int getMax() {          // get the maximum element in the tree
        return getmax(root);
    }


    int getsum(Node *node) {  // get the sum of a node from the node till the node

        if (node == nullptr) {
            return 0;
        }
        return node -> item + getsum(node -> left) + getsum(node -> right);

    }


    int getsumfromroottillnode(int val) {    // get the sum of all the nodes from the root to the node with the value val
        Node *current = root;
        int sum = 0;
        while (current != nullptr) {
            if (current -> item == val) {
                sum += current -> item;
                break;
            }
            else if (current -> item > val) {
                sum += current -> item;
                current = current -> left;
            }
            else {
                sum += current -> item;
                current = current -> right;
            }
        }
        return sum;
    }


    int getSum() {    // get the sum of all the nodes in the tree
        return getsum(root);
    }

    int getLevel(int element) {
        Node *current = root;
        int level = 0;
        while (current != nullptr) {
            if (current -> item == element) {
                return level;
            }
            else if (current -> item > element) {
                current = current -> left;
                level++;
            }
            else {
                current = current -> right;
                level++;
            }
        }
        return level;
    }


    int getNumberOfNodes(Node *root) {       // get the number of nodes in the tree
        if (root == nullptr) {
            return 0;
        }
        return 1 + getNumberOfNodes(root -> left) + getNumberOfNodes(root -> right);
    }

    int getNumberOfNodesintree() {        // get the number of nodes in the tree
        return getNumberOfNodes(root);
    }



    int getNumberOfLeafNodes(Node *root) {    // get the number of leaf nodes in the tree
        if (root == nullptr) {
            return 0;
        }
        if (root -> left == nullptr && root -> right == nullptr) {
            return 1;
        }
        return getNumberOfLeafNodes(root -> left) + getNumberOfLeafNodes(root -> right);
    }

    int getNumberOfLeafNodesintree() {    // get the number of leaf nodes in the tree
        return getNumberOfLeafNodes(root);
    }


    int getheight(Node *root) {    // get the height of the tree
        if (root == nullptr) {
            return 0;
        }
        int height =  max(getheight(root -> left), getheight(root -> right));
        return height + 1;
    }


    int getHeight() {    // get the height of the tree
        return getheight(root)-1;
    }

    bool search(int element) {     // search for an element in the tree

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


    void deleteNode(int element) {        // delete a node from the tree

        Node *current = root;
        Node *prev = nullptr;
        while (current != nullptr) {          // traverse the tree to find the node to be deleted
            if (current -> item == element) {
                break;
            }
            else if (current -> item > element) {
                prev = current;
                current = current -> left;
            }
            else {
                prev = current;
                current = current -> right;
            }
        }

        if (current == nullptr) {           // if the element is not found in the tree
            cout << "Element not found in the tree" << endl;
            return;
        }

        if (current -> left == nullptr && current -> right == nullptr) {         // if the node to be deleted is a leaf node

            if (prev -> left == current) {
                prev -> left = nullptr;
            }
            else {
                prev -> right = nullptr;
            }

            delete current;

        }

        else if (current -> left == nullptr || current -> right == nullptr) {            // if the node to be deleted has only one child

            if (current -> left == nullptr) {
                if (prev -> left == current) {
                    prev -> left = current -> right;
                }
                else {
                    prev -> right = current -> right;
                }
            }
            else {
                if (prev -> left == current) {
                    prev -> left = current -> left;
                }
                else {
                    prev -> right = current -> left;
                }
            }

            delete current;

        }

        else {                                             // if the node to be deleted has two children

            Node *tmp = current -> right;
            Node *tmpprev = nullptr;
            while (tmp -> left != nullptr) {
                tmpprev = tmp;
                tmp = tmp -> left;
            }

            current -> item = tmp -> item;

            if (tmpprev == nullptr) {
                current -> right = tmp -> right;
            }
            else {
                tmpprev -> left = tmp -> right;
            }

            delete tmp;

        }

    }
};


int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    tree.insert(1);
    tree.insert(4);


    //                   10
    //                  /  \
    //                 5    15
    //                / \   / \
    //               3   7 12  18
    //              / \
    //             1   4

    cout << "Inorder: " << endl;
    tree.display_inorder();                                                             // 1 3 4 5 7 10 12 15 18
    cout << endl;
     cout << "Preorder: " << endl;                                                      // 10 5 3 1 4 7 15 12 18
    tree.display_preorder();
    cout << endl;
     cout << "Postorder: " << endl;                                                     // 1 4 3 7 5 12 18 15 10
    tree.display_postorder();
    cout << endl;
    cout << "Max :" <<tree.getMax()<<endl;                                              // 18
    cout << "Min :" <<tree.getMin()<<endl;                                              // 1
    cout << "Sum :" <<tree.getSum()<<endl;                                              // 75
    cout << "Sum from root to 7 :" <<tree.getsumfromroottillnode(7)<<endl;              // 22
    cout << "Level of 7 :" <<tree.getLevel(7)<<endl;                                    // 2
    cout << "Number of nodes in the tree :" <<tree.getNumberOfNodesintree()<<endl;      // 9
    cout << "Number of leaf nodes in the tree :" <<tree.getNumberOfLeafNodesintree()<<endl;   // 5
    cout << "Height of the tree :" <<tree.getHeight()<<endl;                                  // 3
    cout << "Search for 7 :" <<tree.search(7)<<endl;                                          // 1 (True)
    cout << "Search for 8 :" <<tree.search(8)<<endl;                                          // 0 (False)
    tree.deleteNode(15);                                                             
    cout << "Inorder: " << endl;                           
    tree.display_inorder();                                                             // 1 3 4 5 7 10 12 18
    cout << endl;
    
    return 0;
}
