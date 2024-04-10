// Tree traversal in C++

#include <iostream> 
using namespace std;

// Definicion de la estructura del nodo del arbol
struct Node { 
    int data;
    struct Node *left, *right;
    Node(int data) { 
        this->data = data; 
        left = right = NULL;
    }
};

// Funcion para el recorrido en preorden del arbol
void preorderTraversal(struct Node* node) { 
    if (node == NULL)
        return;
    
    cout << node->data << "->"; // Visita el nodo
    preorderTraversal(node->left); // Recorre el subarbol izquierdo
    preorderTraversal(node->right); // Recorre el subarbol derecho
}

// Funcion para el recorrido en postorden del arbol
void postorderTraversal(struct Node* node) { 
    if (node == NULL)
        return;

    postorderTraversal(node->left); // Recorre el subarbol izquierdo
    postorderTraversal(node->right); // Recorre el subarbol derecho
    cout << node->data << "->"; // Visita el nodo
}

// Funcion para el recorrido en inorden del arbol
void inorderTraversal(struct Node* node) { 
    if (node == NULL) 
        return;

    inorderTraversal(node->left); // Recorre el subarbol izquierdo
    cout << node->data << "->"; // Visita el nodo
    inorderTraversal(node->right); // Recorre el subarbol derecho
}

int main() {
    // Construccion del arbol
    struct Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9); 
    root->left->left = new Node(5); 
    root->left->right = new Node(6);

    // Impresion de los recorridos del arbol
    cout << "Inorder traversal "; 
    inorderTraversal(root);

    cout << "\nPreorder traversal "; 
    preorderTraversal(root);
    
    cout << "\nPostorder traversal "; 
    postorderTraversal(root);

    return 0;
}