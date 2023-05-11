#ifndef AVL_H
#define AVL_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pessoa.h"

template class AVL<long int>;
template class AVL<std::string>;
template class AVL<struct data>;

template<typename T>
struct Node{
    T* dado;
    struct Node* left;
    Node* right;
    int height;
    int numPessoas;
    Pessoa *pessoa; //ponteiro para o objeto que terá os dados da pessoa que possuir
                    //os dados que serão inseridos na árvore
    Node(){
        dado = NULL;
        left = NULL;
        right = NULL;
        height = 0;
        pessoa = NULL;
        numPessoas = 0;
    }
    Node(T* dado, Pessoa *pessoa){
        this->dado = dado;
        this->pessoa = pessoa;
        left = NULL;
        right = NULL;
        height = 1;
        numPessoas = 1;
    }
};

template<typename T>
class AVL{
    private:
        struct Node<T> *root{NULL};
        int height(struct Node<T> *N);
        struct Node<T> *add(struct Node<T> *node, T* dado, Pessoa *pessoa);
        struct Node<T> *rotacaoDireita(struct Node<T> *y);
        struct Node<T> *rotacaoEsquerda(struct Node<T> *x);
        int balance(Node<T> *N);
        void preOrder(struct Node<T> *node){
            if(node != NULL){
                for(int i = 0; i < node->numPessoas; i++)
                    std::cout << *(node->dado) << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }
        struct Node<T> *fixup(struct Node<T> *node);
    public:
        void add(T* dado, Pessoa *pessoa);
        void preOrder(){
            preOrder(root);
        }
};
//função que recebe um vetor de pessoas e as insere nas árvores.
void vec2tree(std::vector<Pessoa> v, AVL<long int> *CPF, AVL<string> *nome, AVL<struct data> *dataNascimento);

//essa função será reescrita para ler o arquivo, por enquanto é só para testes com entrada do teclado
std::vector<Pessoa> pessoa2vec(int n);

#endif