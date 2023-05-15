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
        //função que retorna a altura de um nó
        int height(struct Node<T> *N);
        //função que adiciona um nó na árvore
        struct Node<T> *add(struct Node<T> *node, T* dado, Pessoa *pessoa);
            struct Node<T> *rotacaoDireita(struct Node<T> *y);
            struct Node<T> *rotacaoEsquerda(struct Node<T> *x);
            struct Node<T> *fixup(struct Node<T> *node);
        //função que retorna o fator de balanceamento de um nó
        int balance(Node<T> *N);
        //função que faz a preordem da árvore
        void preOrder(struct Node<T> *node){
            if(node != nullptr){
                for(int i = 0; i < node->numPessoas; i++)
                    std::cout << *(node->dado) << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }
        //função que libera a memória da árvore
        Node<T> *clear(Node<T> *node);
    public:
        //construtor default
        AVL(){
            root = nullptr;
        }
        ~AVL(){
            clear();
        }
        void add(T* dado, Pessoa *pessoa);
        void preOrder(){
            preOrder(root);
        }
        void clear(){
            root = clear(root);
        }
};

//funções privadas:
template<typename T>
int AVL<T>::height(struct Node<T> *N){
    if (N == nullptr)
        return 0;
    return N->height;
}

template<typename T>
struct Node<T> *AVL<T>::add(Node<T> *node, T* dado, Pessoa *pessoa){
    //T data = *dado;
    if(node == nullptr){
        return = new Node<T>(dado, pessoa);
    }
    if(*(dado) < *(node->dado)){
        node->left = add(node->left, dado, pessoa);
    }
    else if(*(dado) > *(node->dado)){
        node->right = add(node->right, dado, pessoa);
    }
    else{
        return repeatedNode(node, pessoa);
    }
    
    return fixup(node);
}

template<typename T>
struct Node<T> *AVL<T>::rotacaoDireita(struct Node<T> *y){
    struct Node<T> *x = y->left;
    struct Node<T> *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

template<typename T>
struct Node<T> *AVL<T>::rotacaoEsquerda(struct Node<T> *x){
    struct Node<T> *y = x->right;
    struct Node<T> *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

template<typename T>
struct Node<T> *AVL<T>::fixup(struct Node<T> *node){
    node->height = 1 + max(height(node->left), height(node->right));
    int bal = balance(node);
    if(bal >= -1 && bal <= 1){
        return node;
    }
    if(bal < -1){
        if(*(node->dado)<*(node->left->dado)) node = rotacaoDireita(node);
        else{
            node->left = rotacaoEsquerda(node->left);
            node = rotacaoDireita(node);
        }
    }
    else{
        if(*(node->dado)>*(node->right->dado)) node = rotacaoEsquerda(node);
        else{
            node->right = rotacaoDireita(node->right);
            node = rotacaoEsquerda(node);
        }
    }
    return node;
}

template<typename T>
int AVL<T>::balance(struct Node<T> *N){
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

template<typename T>
Node<T> *AVL<T>::clear(Node<T> *node){
    if(node == nullptr) return nullptr;
    node->left = clear(node->left);
    node->right = clear(node->right);
    delete node;
    return nullptr;
}

// funções públicas:
template<typename T>
void AVL<T>:: add(T* dado, Pessoa *pessoa){
    root = add(root, dado, pessoa);
}

//funções auxiliares
template<typename T>
struct Node<T> *repeatedNode(struct Node<T> *node, Pessoa *pessoa);

template class AVL<unsigned long int>;
template class AVL<std::string>;
template class AVL<struct data>;
#endif