#include <iostream>
#include <string>
#include "Pessoa.h"

template<typename T>
struct Node{
    T* dado;
    Node* left;
    Node* right;
    int height;
    Pessoa *pessoa; //ponteiro para o objeto que terá os dados da pessoa que possuir
                    //os dados que serão inseridos na árvore
};

template<typename T>
class AVL{
    private:
        Node<T> *root;
        int height(Node<T> *N);
        Node<T> *add(Node<T> *node, T* dado, Pessoa *pessoa);
        Node<T> *rotacaoDireita(Node<T> *y);
        Node<T> *rotacaoEsquerda(Node<T> *x);
        int balance(Node<T> *N);
    public:
        void add(T* dado, Pessoa *pessoa);
};