#ifndef AVL_H
#define AVL_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pessoa.h"

//testando com uma árvore só de nomes
struct Node{
    std::string dado;
    struct Node* left;
    struct Node* right;
    int height;
    Pessoa *pessoa; //ponteiro para o objeto que terá os dados da pessoa que possuir
                    //os dados que serão inseridos na árvore
    Node(){
        dado = " ";
        left = NULL;
        right = NULL;
        height = 0;
        pessoa = NULL;
    }
    Node(std::string dado, Pessoa *pessoa){
        this->dado = dado;
        this->pessoa = pessoa;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVL{
    private:
        struct Node *root;
        int height(struct Node *N);
        struct Node *add(struct Node *node, std::string dado, Pessoa *pessoa);
        struct Node *rotacaoDireita(struct Node *y);
        struct Node *rotacaoEsquerda(struct Node *x);
        int balance(struct Node *N);
        void preOrder(struct Node *node);
    public:
        void preOrder();
        void add(std::string dado, Pessoa *pessoa);
};

//função que recebe um vetor de pessoas e as insere nas árvores.
void vec2tree(std::vector<Pessoa> v, AVL *nome);

#endif