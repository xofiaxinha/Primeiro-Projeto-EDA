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
        struct Node<T> *root{nullptr}; //📍 raíz
        int height(struct Node<T> *N); //📍 função que retorna a altura
        struct Node<T> *add(Node<T>* node, T dado, Pessoa *pessoa); //📍 função recursiva que adiciona um nó
        struct Node<T> *rotacaoDireita(struct Node<T> *y); //função que faz a rotação para a direita
        struct Node<T> *rotacaoEsquerda(struct Node<T> *x); //função que faz a rotação para a esquerda
        struct Node<T> *fixup(struct Node<T> *node, T dado);//📍 função que faz o balanceamento
        int balance(Node<T> *N);//📍 função auxiliar que retorna o fator de balanceamento
        void preOrder(struct Node<T> *node); //📍 função recursiva que faz o percurso pré-ordem
        Node<T> *clear(Node<T> *node); //📍 função recursiva que limpa a árvore
        
        //TODO: implementar as funções abaixo
        bool isThere(struct Node<T> *node, T dado); //📍 função recursiva que verifica se um dado existe na árvore
        struct Node<T> *search(struct Node<T> *node, T dado); //📍 função recursiva que retorna um nó buscado
        T min(struct Node<T> *node); //📍 função recursiva que retorna o menor valor
        T max(struct Node<T> *node);  //📍 função recursiva que retorna o maior valor
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
        T min();
        //Função que retorna o maior valor na árvore
        T max();
        //Função que retorna um dado existente na árvore
        T search(T dado);
};

//funções privadas:
template<typename T>
int AVL<T>::height(struct Node<T> *N){
    if (N == nullptr)
        return 0;
    return N->height;
}

template<typename T>
int AVL<T>::balance(struct Node<T> *N){
    return height(N->right) - height(N->left);
}

template<typename T>
struct Node<T> *AVL<T>::add(Node<T>* node, T dado, Pessoa *pessoa){
    if(node == nullptr) return new Node<T>(dado, pessoa);

    if(dado == node->dado){
        repeatedNode(node, pessoa);
    }
    if(dado < node->dado) {
        node->left = add(node->left, dado, pessoa);}
    else {
        node->right = add(node->right, dado, pessoa);
    }
    //std::cout << "Passou pelo add\n";
    node = fixup(node, dado);
    //std::cout << "Passou pelo fixup\n";
    return node;
}

template<typename T>
struct Node<T> *AVL<T>::rotacaoDireita(struct Node<T> *p){
    Node<T> *u = p->left;
    p->left = u->right;
    u->right = p;
    p->height = std::max(height(p->left), height(p->right)) + 1;
    u->height = std::max(height(u->left), height(u->right)) + 1;
    return u;
}

template<typename T>
struct Node<T> *AVL<T>::rotacaoEsquerda(struct Node<T> *p){
    Node<T> *u = p->right;
    p->right = u->left;
    u->left = p;
    p->height = std::max(height(p->left), height(p->right)) + 1;
    u->height = std::max(height(u->left), height(u->right)) + 1;
    return u;
}

template<typename T>
struct Node<T> *AVL<T>::fixup(struct Node<T> *node, T dado){
    node->height = std::max(height(node->left), height(node->right)) + 1;
    int bal = balance(node);
    //std::cout << "Balanço: " << bal << std::endl;
    if(bal > -2 && bal < 2) return node;

    //rotações pela direita
    if(bal < -1){ //se o balanço for -2
        if(dado < node->left->dado) node = rotacaoDireita(node);
        else if(dado > node->left->dado){
            node->left = rotacaoEsquerda(node->left);
            node = rotacaoDireita(node);
        }
    }

    //rotações pela esquerda
    if(bal > 1){ //se o balanço for 2
        if(dado > node->right->dado) node = rotacaoEsquerda(node);
        else if(dado < node->right->dado){
            node->right = rotacaoDireita(node->right);
            node = rotacaoEsquerda(node);
        }
    }
    return node;
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
    for(int i=0; i<node->pessoas.size(); i++){
        node->pessoas[i]->print();
    }
    preOrder(node->left);
    preOrder(node->right);
}
template<typename T>
struct Node<T> *AVL<T>::search(struct Node<T> *node, T dado){
    if(node == nullptr) return nullptr;
    if(node->dado == dado) return node;
    if(dado < node->dado) return search(node->left, dado);
    return search(node->right, dado);
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
    root = add(this->root, dado, pessoa);
}

template<typename T>
bool AVL<T>::isThere(struct Node<T> *node, T dado){
    if(search(node, dado) == nullptr) return false;
    return true;
}

template<typename T>
T AVL<T>::search(T dado){
    struct Node<T> *node = search(root, dado);
    if(node == nullptr) throw std::runtime_error("Erro: dado não encontrado");
    return node->dado;
}

template<typename T>
T AVL<T>::min(struct Node<T> *node){
    while(node->left != nullptr) node = node->left;
    return node->dado;
}

template<typename T>
T AVL<T>::max(struct Node<T> *node){
    while(node->right != nullptr) node = node->right;
    return node->dado;
}

//funções auxiliares
//std::vector<Pessoa*> pessoa2vec();
void vec2tree(AVL<unsigned long int> *CPF, AVL<std::string> *nome, AVL<struct data> *dataNascimento);
template<typename T>
struct Node<T> *repeatedNode(struct Node<T> *node, Pessoa *pessoa);
void buscaCPF(AVL<unsigned long int> *CPF);
void buscaString(AVL<std::string> *nome);
void intervaloData(AVL<struct data> *dataNascimento);


template class AVL<unsigned long int>;
template class AVL<std::string>;
template class AVL<struct data>;
#endif