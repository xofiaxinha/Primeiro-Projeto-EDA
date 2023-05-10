#ifndef AVL_H
#define AVL_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pessoa.h"

template<typename T>
struct Node{
    T* dado;
    struct Node* left;
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
        struct Node<T> *root;
        int height(struct Node<T> *N);
        struct Node<T> *add(struct Node<T> *node, T* dado, Pessoa *pessoa);
        struct Node<T> *rotacaoDireita(struct Node<T> *y);
        struct Node<T> *rotacaoEsquerda(struct Node<T> *x);
        int balance(Node<T> *N);
        void preOrder(Node<T> *node);
        struct Node<T> *fixup(struct Node<T> *node);
    public:
        void add(T* dado, Pessoa *pessoa);
        void preOrder();
};

//função que recebe um vetor de pessoas e as insere nas árvores.
void vec2tree(std::vector<Pessoa> v, AVL<long int> *CPF, AVL<std::string> *nome, AVL<struct data> *dataNascimento);

#endif