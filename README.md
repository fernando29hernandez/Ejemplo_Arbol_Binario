# Ejemplo_Arbol_Binario
## Laboratorio de Estructuras de datos Seccion B Segundo Semestre 2019
Se utiliza para ya no llamar de la forma std::cout y otra instruccion que necesita de esta.

```using namespace std;```

Sea esta la creación de la clase nodo que usaremos para el arbol binario
```class Node {
public:
    Node *n_der,*n_izq;
    int data;
    Node (int num) {
        data = num;
        n_izq = n_der = NULL;
    }
};
```
Elementos:
1. Dato a almacenar
2. Enlace nodo izquierdo
3. Enlace a nodo izquierdo

Esta es la clase Arbol la cual tendra la logica del mismo.

```
class tree {
public:
    Node* root;
    tree () {root = NULL; }
    bool insert(int data) { 
        return insert(data,root); 
    };
    
    void inorder()  {
          inorder(root);
    };
    void postorder()  { 
          postorder(root);
    };
    void preorder()  { 
          preorder(root);
    };
    bool insert(int item, Node* raiz_actual);
    void inorder( Node* actual) ;
    void postorder( Node*actual);
    void preorder( Node* actual) ;
    
    
};
```

Metodo insertar de la clase arbol. Se tiene que implementar de la forma nombre_clase::nombre_metodo(){CUERPO}

Considerando 3 casos posibles:
1.  Cuando raiz actual es nula
2.  Cuando valor a insertar es menor al de la raiz actual(Si es nulo el hijo izquierdo se crea alli sino llamada recursiva)
3.  Cuando valor a insertar es mayor al de la raiz actual(Si es nulo el hijo derecho se crea alli sino llamada recursiva)


```
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
```

Los 3 tipos de recorridos vistos en el laboratorio

```
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
```


Y probamos nuestro arbol desde el main .

```
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
```
Pagina Utilizada para el testeo de C++:

[C++ en linea](https://www.onlinegdb.com/online_c++_compiler)
