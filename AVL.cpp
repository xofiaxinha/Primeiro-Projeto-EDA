#include <iostream>
#include <vector>
#include <string>
#include "AVL.h"

using namespace std;

//a função recebe as árvores a serem preenchidas
void vec2tree(vector<Pessoa> v, AVL<long int> *CPF, AVL<string> *nome, AVL<struct data> *dataNascimento){
    string nomeCompleto;
    long int cpf;
    struct data dataNasc;

    //árvore de nomes:
    for(int i = 0; i < v.size(); i++){
        nomeCompleto = v[i].getNome() + " " + v[i].getSobrenome();
        nome->add(&nomeCompleto, &v[i]);
    }
    //árvore de cpfs:
    for(int i = 0; i < v.size(); i++){
        cpf = v[i].getCPF();
        CPF->add(&cpf, &v[i]);
    }
    //árvore de datas de nascimento:
    for(int i = 0; i < v.size(); i++){
        dataNasc = v[i].getDataNascimento();
        dataNascimento->add(&dataNasc, &v[i]);
    }
}
template<typename T>
void AVL<T>:: add(T* dado, Pessoa *pessoa){
    root = add(root, dado, pessoa);
}
template<typename T>
Node<T>* AVL<T>:: add(Node<T> *node, T* dado, Pessoa *pessoa){
    if(node == NULL){
        Node<T> *newNode = new Node<T>;
        newNode->dado = dado;
        newNode->pessoa = pessoa;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }
    if(*dado < *(node->dado)){
        node->left = add(node->left, dado, pessoa);
    }
    else if(*dado > *(node->dado)){
        node->right = add(node->right, dado, pessoa);
    }
    else{
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int balanceamento = balance(node);
    if(balanceamento > 1 && *dado < *(node->left->dado)){
        return rotacaoDireita(node);
    }
    if(balanceamento < -1 && *dado > *(node->right->dado)){
        return rotacaoEsquerda(node);
    }
    if(balanceamento > 1 && *dado > *(node->left->dado)){
        node->left = rotacaoEsquerda(node->left);
        return rotacaoDireita(node);
    }
    if(balanceamento < -1 && *dado < *(node->right->dado)){
        node->right = rotacaoDireita(node->right);
        return rotacaoEsquerda(node);
    }
    return node;
}
