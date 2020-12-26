#include <iostream>

using namespace std;

template <typename T>
struct node {
    T data;
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
            parent->left = parent->right = NULL;
            return parent;
        } else if (value < parent->data) {
            parent->left = insert(value, parent->left);
        } else if (value > parent->data) {
            parent->right = insert(value, parent->right);
        } 
        // parent = balance(parent);
        return parent;        
    }

    void inorder(node<T>* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node<T>* getSuccessor(node<T>* parent) {
        if (parent->right == NULL) {
            return parent;
        } else {
            return getSuccessor(parent->right);
        }
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
            return 0;
        } else {
            int leftHeight = nodeHeight(parent->left);
            int rightHeight = nodeHeight(parent->right);
            if (leftHeight > rightHeight) {
                return leftHeight + 1;
            } else {
                return rightHeight + 1;
            }
        }
    }

    int balanceFactor(node<T>* parent) {
        int leftHeight = nodeHeight(parent->left);
        int rightHeight = nodeHeight(parent->right);
        return rightHeight - leftHeight;
    }

    node<T>* rightRotate(node<T>* parent) {
        node<T>* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        return temp;
    }

    node<T>* leftRotate(node<T>* parent) {
        node<T>* temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
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

    node<T>* balance(node<T>* parent) {
        int balancefactor = balanceFactor(parent);
        if (balancefactor < -1) {
            if(balanceFactor(parent->left) < 0) {
                parent = rightRotate(parent);
            } else {
                parent = leftRightRotate(parent);
            }
        } else if (balancefactor > 1) {
            if (balanceFactor(parent->right) < 0) {
                parent = rightLeftRotate(parent);
            } else {
                parent = leftRotate(parent);
            }
        }
        return parent;
    }

    void display(node<T>* parent, int lvl) {
        if (parent == NULL) {
            return;
        } 
        if (parent == root) {
            cout << "Root: " << parent->data << endl;
        } else {
            cout << parent->data << endl;
        }
        cout << lvl << "L: ";
        display(parent->left, lvl + 1);
        cout << "\n" << lvl << "R: ";
        display(parent->right, lvl + 1);

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
            printBT( prefix + (isLeft ? "│   " : "    "), parent->right, false);
        }
    }

    void display() {
        printBT("", root, false);    
    }

    // pass the root node of your binary tree

    // void display() {
    //     display(root, 1);
    // }

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




    // void remove(int val) {
    //     remove(val, root);
    // }

    //this function is totally fucked
    // node<T>* remove(int value, node<T>* parent) {
    //     node<T>* temp;

        // if (parent == NULL) {
        //     return parent;
        // } 
        // else if (value < parent->data) {
        //     parent->left = remove(value, parent->left);
        // } else {
        //     if (value > parent->data) {
        //         parent->right = remove(value, parent->right);
        //     } else {
        //         //no children
        //         if(parent->left == NULL && parent->right == NULL) {
        //             delete parent;
        //             parent = NULL;
        //         //two children
        //         }  
                
        //         else if (parent->left != NULL && parent->right != NULL) {
        //             temp = FindMin(parent->right);
        //             parent->data = temp->data;
        //             parent->right = remove(parent->data, parent->right);
        //         //one child
        //         } else if (parent->left != NULL || parent->right != NULL) {
        //             temp = parent;
        //             if (parent->left == NULL) {
        //                 parent = parent->right;
        //             } else if (parent->right == NULL) {
        //                 parent = parent->left;
        //             }
        //             delete temp;
        //         } 
        //     }
        // }
        // return parent;



        // if(parent == NULL) {
        //     return parent;
        // } else if (value < parent->data) {
        //     parent->left = remove(value, parent->left);
        // } else if (value > parent->data) {
        //     parent->right = remove(value, parent->right);
        // } else if(parent->left != NULL && parent->right != NULL) {
        //     temp = getSuccessor(parent->right);
        //     parent->data = temp->data;
        //     parent->right = remove(parent->data, parent->right);
        // } else {
        //     temp = parent;
        //     if (parent->left == NULL) {
        //         parent = parent->right;
        //     } else if (parent->right == NULL) {
        //         parent = parent->left;
        //     }
        //     delete temp;
        // }
        // return parent;

        // else {
        //     //no child node
        //     if (parent->left == NULL && parent->right == NULL) {
        //         parent = NULL;
        //     //one child node
        //     } else if (parent->left == NULL || parent->right == NULL) {
        //         if (parent->right != NULL) {
        //             temp = parent->right;
        //         } else {
        //             temp = parent->left;
        //         }
        //     //two child nodes
        //     } else {
        //         temp = getSuccessor(parent->left);
        //         parent->data = temp->data;
        //         parent->left = remove(temp->data, parent->left);
        //     }
        // }
    // }
