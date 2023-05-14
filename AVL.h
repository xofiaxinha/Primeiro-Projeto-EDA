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
    Node* left;
    Node* right;
    int height;
    int numPessoas;
    Pessoa *pessoa; //ponteiro para o objeto que terá os dados da pessoa que possuir
                    //os dados que serão inseridos na árvore
    Node(){
        dado = nullptr;
        left = nullptr;
        right = nullptr;
        height = 0;
        pessoa = nullptr;
        numPessoas = 0;
    }
    Node(T* dado, Pessoa *pessoa){
        this->dado = dado;
        this->pessoa = pessoa;
        left = nullptr;
        right = nullptr;
        height = 1;
        numPessoas = 1;
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
        void preOrder(struct Node<T> *node){
            if(node != nullptr){
                for(int i = 0; i < node->numPessoas; i++)
                    std::cout << *(node->dado) << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }
        void clear(Node<T> *node);
        struct Node<T> *fixup(struct Node<T> *node);
    public:
        //construtor default
        AVL(){
            root = nullptr;
        }
        //construtor a partir de vector
        void add(T* dado, Pessoa *pessoa);
        void preOrder(){
            preOrder(root);
        }
        void clear(){
            root = clear(root);
        }
};

template class AVL<unsigned long int>;
template class AVL<std::string>;
template class AVL<struct data>;
#endif