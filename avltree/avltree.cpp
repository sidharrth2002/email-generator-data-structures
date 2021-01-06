#include <iostream>

using namespace std;

template <typename T>
struct node {
    T data;
    int height;
    node<T>* left;
    node<T>* right;
};

template <typename T>
class BST {
    public:
    node<T>* root;

    BST() {
        root = NULL;
    }

    node<T>* insert(T value, node<T>* parent) {
        if (parent == NULL) {
            parent = new node<T>;
            parent->data = value;
            parent->height = 0;
            parent->left = parent->right = NULL;
        } else if (value < parent->data) {
            parent->left = insert(value, parent->left);
            if (balanceFactor(parent) == 2) {
                if (value < parent->left->data) {
                    parent = rightRotate(parent);
                } else {
                    parent = leftRightRotate(parent);
                }
            }
        } else if (value > parent->data) {
            parent->right = insert(value, parent->right);
            if (balanceFactor(parent) == 2) {
                if (value > parent->right->data) {
                    parent = leftRotate(parent);
                } else {
                    parent = rightLeftRotate(parent);
                }
            }
        }
        //manually store the height of the node
        parent->height = max(nodeHeight(parent->left), nodeHeight(parent->right)) + 1; 
        return parent;        
    }

    void inorder(node<T>* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node<T>* findElement(node<T>* parent, T value) {
        if (parent == NULL) {
            return NULL; 
        } 
        if (parent->data == value) {
            return parent;
        } else if (value < parent->data) {
            return findElement(parent->left, value);
        } else {
            return findElement(parent->right, value);
        }
    }

    int nodeHeight(node<T>* parent) {
        if (parent == NULL) {
            return -1;
        } else {
            return parent->height;
        }
    }

    int balanceFactor(node<T>* parent) {
        if (parent == NULL) {
            return 0;
        } else {
            return abs(nodeHeight(parent->left) - nodeHeight(parent->right));    
        }
    }

    node<T>* rightRotate(node<T>* parent) {
        node<T>* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;

        parent->height = max(nodeHeight(parent->left), nodeHeight(parent->right)) + 1;
        temp->height = max(nodeHeight(temp->left), parent->height)+1;
        return temp;
    }

    node<T>* leftRotate(node<T>* parent) {
        node<T>* temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;

        parent->height = max(nodeHeight(parent->left), nodeHeight(parent->right)) + 1;
        temp->height = max(nodeHeight(temp->right), parent->height)+1;
        return temp;
    }

    node<T>* leftRightRotate(node<T>* parent) {
        node<T>* temp = parent->left;
        parent->left = leftRotate(temp);
        return rightRotate(parent);
    }

    node<T>* rightLeftRotate(node<T>* parent) {
        node<T>* temp = parent->right;
        parent->right = rightRotate(temp);
        return leftRotate(parent);
    }

    //from stack overflow- not mine
    void printBT(const std::string& prefix, node<T>* parent, bool isLeft) {
        if (parent != NULL) {
            cout << prefix;

            cout << (isLeft ? "├──" : "└──" );

            // print the value of the node
            cout << parent->data << std::endl;

            // enter the next tree level - left and right branch
            printBT( prefix + (isLeft ? "│   " : "    "), parent->left, true);
            // cout << parent->height << endl;
            printBT( prefix + (isLeft ? "│   " : "    "), parent->right, false);
        }
    }

    void display() {
        printBT("", root, false);    
    }

    void insert(T x) {
        root = insert(x, root);
    }

    bool find(T val) {
        if (findElement(root, val) == NULL) {
            return false;
        } else {
            return true;
        }
    }
};