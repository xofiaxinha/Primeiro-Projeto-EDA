#ifndef AVL_H
#define AVL_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Pessoa.h"

template<typename T>
class AVL{
    private:
        struct Node<T> *root; //📍 raíz
        int height(struct Node<T> *N); //📍 função que retorna a altura
        struct Node<T> *add(Node<T>* node, T dado, Pessoa *pessoa); //📍 função recursiva que adiciona um nó
        struct Node<T> *rotacaoDireita(struct Node<T> *y); //função que faz a rotação para a direita
        struct Node<T> *rotacaoEsquerda(struct Node<T> *x); //função que faz a rotação para a esquerda
        struct Node<T> *fixup(struct Node<T> *node);//📍 função que faz o balanceamento
        int balance(Node<T> *N);//📍 função auxiliar que retorna o fator de balanceamento
        void preOrder(struct Node<T> *node); //📍 função recursiva que faz o percurso pré-ordem
        Node<T> *clear(Node<T> *node); //📍 função recursiva que limpa a árvore
        
        //TODO: implementar as funções abaixo
        bool isThere(struct Node<T> *node, T dado); //📍 função recursiva que verifica se um dado existe na árvore
        struct Node<T> *search(struct Node<T> *node, T dado); //📍 função recursiva que retorna um nó buscado
        int min(struct Node<T> *node); //📍 função recursiva que retorna o menor valor
        int max(struct Node<T> *node);  //📍 função recursiva que retorna o maior valor
    public:
        AVL();
        ~AVL();
        //Função que adiciona um nó na árvore
        void add(T dado, Pessoa *pessoa);
        //Função que exibe os dados em pré-ordem
        void preOrder();
        //Função que limpa a árvore
        void clear();
        //Função que retorna o menor valor na árvore

        //TODO: implementar as funções abaixo
        int min();
        //Função que retorna o maior valor na árvore
        int max();
        //Função que retorna um dado existente na árvore
        int search(T dado);
};

//funções privadas:
template<typename T>
int AVL<T>::height(struct Node<T> *N){
    if (N == nullptr)
        return 0;
    return N->height;
}

template<typename T>
struct Node<T> *AVL<T>::add(Node<T>* node, T dado, Pessoa *pessoa){
    if(node == nullptr) return new Node<T>(dado, pessoa);

    if(dado == node->dado){
        repeatedNode(node, pessoa);
    };
    if(dado < node->dado) node->left = add(node->left, dado, pessoa);
    else node->right = add(node->right, dado, pessoa);

    node = fixup(node);
    return node;
}

template<typename T>
struct Node<T> *AVL<T>::rotacaoDireita(struct Node<T> *y){
    struct Node<T> *x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = std::max(height(y->left), height(y->right))+1;
    x->height = std::max(height(x->left), height(x->right))+1;
    return x;
}

template<typename T>
struct Node<T> *AVL<T>::rotacaoEsquerda(struct Node<T> *x){
    struct Node<T> *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = std::max(height(x->left), height(x->right))+1;
    y->height = std::max(height(y->left), height(y->right))+1;
    return y;
}

template<typename T>
struct Node<T> *AVL<T>::fixup(struct Node<T> *node){
    node->height = 1 + std::max(height(node->left), height(node->right));
    int bal = balance(node);
    if(bal >= -1 && bal <= 1){
        return node;
    }
    if(bal < -1){
        if(node->dado<node->left->dado) node = rotacaoDireita(node);
        else{
            node->left = rotacaoEsquerda(node->left);
            node = rotacaoDireita(node);
        }
    }
    else{
        if(node->dado>node->right->dado) node = rotacaoEsquerda(node);
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
template<typename T>
void AVL<T>::preOrder(struct Node<T> *node){
    if(node == nullptr) return;
    std::cout << node->dado << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// funções públicas:
template<typename T>
AVL<T>::AVL(){
    root = nullptr;
}
template<typename T>
AVL<T>::~AVL(){
    root = clear(root);
}
template<typename T>
void AVL<T>::preOrder(){
    preOrder(root);
}
template<typename T>
void AVL<T>::clear(){
    root = clear(root);
}
template<typename T>
void AVL<T>::add(T dado, Pessoa *pessoa){
    root = add(root, dado, pessoa);
}

template<typename T>
bool AVL<T>::isThere(struct Node<T> *node, T dado){
    if(search(node, dado) == nullptr) return false;
    return true;
}

template<typename T>
struct Node<T> *AVL<T>::search(struct Node<T> *node, T dado){
    if(node == nullptr) return nullptr;
    if(node->dado == dado) return node;
    if(dado < node->dado) return search(node->left, dado);
    return search(node->right, dado);
}

template<typename T>
int AVL<T>::min(struct Node<T> *node){
    while(node->left != nullptr) node = node->left;
    return node->dado;
}

template<typename T>
int AVL<T>::max(struct Node<T> *node){
    while(node->right != nullptr) node = node->right;
    return node->dado;
}

//funções auxiliares
std::vector<Pessoa> pessoa2vec(int n);
void vec2tree(std::vector<Pessoa> v, AVL<unsigned long int> *CPF, AVL<std::string> *nome, AVL<struct data> *dataNascimento);
template<typename T>
struct Node<T> *repeatedNode(struct Node<T> *node, Pessoa *pessoa);
void buscaCPF(AVL<unsigned long int> *CPF);
void buscaString(AVL<std::string> *nome);
void intervaloData(AVL<struct data> *dataNascimento);


template class AVL<unsigned long int>;
template class AVL<std::string>;
template class AVL<struct data>;
#endif