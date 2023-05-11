#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "AVL.h"

using namespace std;

template<typename T>
int AVL<T>::height(struct Node<T> *N){
    if (N == NULL)
        return 0;
    return N->height;
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
int AVL<T>::balance(struct Node<T> *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
template<typename T>
struct Node<T> *AVL<T>::add(struct Node<T> *node, T* dado, Pessoa *pessoa){
    //T data = *dado;
    if(node == NULL){
        struct Node<T> *newNode = new Node<T>(dado, pessoa);
        return newNode;
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

//função que recebe o nó que é igual ao valor a ser inserido e insere o valor na lista de pessoas
template<typename T>
struct Node<T> repeatedNode(struct Node<T> *node, Pessoa *pessoa){
    node->pessoa = (Pessoa*)realloc(pessoa, sizeof(Pessoa) * (node->numPessoas + 1));
    node->numPessoas += 1;
    node->pessoa[node->numPessoas - 1] = *(pessoa);
    return node;
}
template<typename T>
void AVL<T>:: add(T* dado, Pessoa *pessoa){
    root = add(root, dado, pessoa);
}
template<typename T>
struct Node<T> *AVL<T>::fixup(struct Node<T> *node){
    node->height = 1 + max(height(node->left), height(node->right));
    int balanceamento = balance(node);
    if((balanceamento > -2 && balanceamento < 2) || node == NULL){
        return node;
    }
    if(balanceamento > 1 && *(node->dado) < *(node->left->dado)){
        return rotacaoDireita(node);
    }
    if(balanceamento < -1 && *(node->dado) > *(node->right->dado)){
        return rotacaoEsquerda(node);
    }
    if(balanceamento > 1 && *(node->dado) > *(node->left->dado)){
        node->left = rotacaoEsquerda(node->left);
        return rotacaoDireita(node);
    }
    if(balanceamento < -1 && *(node->dado) < *(node->right->dado)){
        node->right = rotacaoDireita(node->right);
        return rotacaoEsquerda(node);
    }
    return node;
}

vector<Pessoa> pessoa2vec(int n){
    vector<Pessoa> v;
    for(int i = 0; i < n; i++){
        cout << "Digite o CPF: ";
        long int cpf;
        cin >> cpf;
        cin.ignore();
        cout << "Digite o nome e o sobrenome separados por enter: ";
        string nome;
        getline(cin, nome);
        string sobrenome;
        getline(cin, sobrenome);
        cout << "Digite a data de nascimento (mm/dd/aaaa): ";
        string dataNascimento;
        getline(cin, dataNascimento);
        Pessoa fulano(cpf, nome, sobrenome, dataNascimento);
        v.push_back(fulano);
    }
    return v;
}
//a função recebe as árvores a serem preenchidas
void vec2tree(vector<Pessoa> v, AVL<long int> *CPF, AVL<string> *nome, AVL<struct data> *dataNascimento){
    /*/*, AVL<string> *nome, AVL<struct data> *dataNascimento*/
    long int cpf;

    for(int i=0; i<(int)v.size(); i++){
        cpf = v[i].getCPF();
        CPF->add(&cpf, &v[i]);
    }
}