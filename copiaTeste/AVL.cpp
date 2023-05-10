#include <iostream>
#include <vector>
#include <string>
#include "AVL.h"

using namespace std;

//funções da classe AVL
int AVL::height(struct Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}
struct Node *AVL::rotacaoDireita(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}
struct Node *AVL::rotacaoEsquerda(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
int AVL::balance(struct Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
void AVL::preOrder(){
    preOrder(root);
}
void AVL::preOrder(struct Node *node){
    if(node != NULL){
        cout << node->dado << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
struct Node *AVL::add(struct Node *node, std::string dado, Pessoa *pessoa){ //função privada que adiciona recursivamente
    if (node == NULL)
        return(new Node(dado, pessoa));
    if (dado < node->dado)
        node->left = add(node->left, dado, pessoa);
    else if (dado > node->dado)
        node->right = add(node->right, dado, pessoa);
    else //dado igual, não adiciona
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balanceamento = balance(node);
    if (balanceamento > 1 && dado < node->left->dado)
        return rotacaoDireita(node);
    if (balanceamento < -1 && dado > node->right->dado)
        return rotacaoEsquerda(node);
    if (balanceamento > 1 && dado > node->left->dado){
        node->left = rotacaoEsquerda(node->left);
        return rotacaoDireita(node);
    }
    if (balanceamento < -1 && dado < node->right->dado){
        node->right = rotacaoDireita(node->right);
        return rotacaoEsquerda(node);
    }
    return node;
}
void AVL::add(std::string dado, Pessoa *pessoa){
    root = add(root, dado, pessoa);
}
//a função recebe as árvores a serem preenchidas
void vec2tree(vector<Pessoa> v, AVL *nome){
    string nomeCompleto;

    //árvore de nomes:
    for(int i = 0; i < v.size(); i++){
        nomeCompleto = v[i].getNome() + " " + v[i].getSobrenome();
        nome->add(nomeCompleto, &v[i]);
    }
}