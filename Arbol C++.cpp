
#include <iostream>

using namespace std;
class Node {
public:
    Node *n_der,*n_izq;
    int data;
    Node (int num) {
        data = num;
        n_izq = n_der = NULL;
    }
};
class tree {
public:
    Node* root;
    tree () {root = NULL; }
    bool insert(int data) { 
        return insert(data,root); 
    };
    bool insert(int item, Node* raiz_actual);
    void inorder()  { inorder(root);};
    void postorder()  { postorder(root);};
    void preorder()  { preorder(root);};
    void inorder( Node* actual) ;
    void postorder( Node*actual);
    void preorder( Node* actual) ;
    
    
};

bool tree :: insert(int item, Node *raiz_actual) {
    if (root == NULL) {
        root = new Node(item);
        return true;
    }else if (item < raiz_actual->data) {
        if (raiz_actual->n_izq == NULL) {
            raiz_actual->n_izq = new Node(item);
            return true;
        }
        else {
            return insert(item, raiz_actual->n_izq);
        }
    }else if (item > raiz_actual->data) {
        if (raiz_actual->n_der == NULL) {
            raiz_actual->n_der = new Node(item);
            return true;
        }
        else {
            return insert(item, raiz_actual->n_der);
        }
    }else {
        return false;
    }
}
void tree :: inorder( Node *root) {
    if (root != NULL) {
        inorder(root -> n_izq);
        cout << " " << root->data << " ->";
        inorder(root -> n_der);
    }
    
}

void tree :: preorder( Node *root) {
    if (root != NULL) {
        cout << " " << root->data << " ->";
        preorder(root -> n_izq);
        preorder(root -> n_der);
    }
    
}


void tree :: postorder( Node *root) {
    if (root != NULL) {
        postorder(root -> n_izq);
        postorder(root -> n_der);
        cout << " " << root->data << " ->";
        
    }
    
}
int main()
{
    tree mi_arbolito;
    mi_arbolito.insert(5);
    mi_arbolito.insert(6);
    mi_arbolito.insert(10);
    mi_arbolito.insert(4);
    mi_arbolito.insert(9);
    mi_arbolito.insert(15);
    mi_arbolito.preorder();
    cout << "NULL\n";
    mi_arbolito.inorder();
    cout << "NULL\n";
    mi_arbolito.postorder();
    cout << "NULL\n";
}

