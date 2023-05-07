#include <iostream>
#include <string>
#include <vector>
#include "Pessoa.h"

template<typename T>
struct Node{
    T* dado;
    Node* left;
    Node* right;
    int height;
    Pessoa *pessoa; //ponteiro para o objeto que terá os dados da pessoa que possuir
                    //os dados que serão inseridos na árvore
    Node(){
        dado = NULL;
        left = NULL;
        right = NULL;
        height = 0;
        pessoa = NULL;
    }
    Node(T* dado, Pessoa *pessoa){
        this->dado = dado;
        this->pessoa = pessoa;
        left = NULL;
        right = NULL;
        height = 1;
    }
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
        void preOrder(Node<T> *node);
    public:
        void add(T* dado, Pessoa *pessoa);
        void preOrder();
};

//função que recebe um vetor de pessoas e as insere nas árvores.
void vec2tree(std::vector<Pessoa> v, AVL<long int> *CPF, AVL<std::string> *nome, AVL<struct data> *dataNascimento);