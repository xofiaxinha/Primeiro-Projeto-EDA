#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "AVL.h"
#include "func.h"

using namespace std;

template<typename T>
int AVL<T>::height(struct Node<T> *N){
    if (N == nullptr)
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
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
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

//função que recebe o nó que é igual ao valor a ser inserido e insere o valor na lista de pessoas
template<typename T>
struct Node<T> *repeatedNode(struct Node<T> *node, Pessoa *pessoa){
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

vector<Pessoa> pessoa2vec(int n){
    vector<Pessoa> v;
    for(int i = 0; i < n; i++){
        cout << "Digite o CPF: ";
        unsigned long int cpf;
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

bool compareCPF(Pessoa a, Pessoa b){
    return a.getCPF() < b.getCPF();
}
bool compareNome(Pessoa a, Pessoa b){
    return a.getNome() < b.getNome();
}
bool compareDataNascimento(Pessoa a, Pessoa b){
    return a.getDataNascimento() < b.getDataNascimento();
}

//a função recebe as árvores a serem preenchidas
void vec2tree(vector<Pessoa> v, AVL<unsigned long int> *CPF, AVL<string> *nome, AVL<struct data> *dataNascimento){
    /*/*, AVL<string> *nome, AVL<struct data> *dataNascimento*/
    vector<Pessoa> v1(v), v2(v), v3(v);
    sort(v1.begin(), v1.end(), compareCPF);
    sort(v2.begin(), v2.end(), compareNome);
    sort(v3.begin(), v3.end(), compareDataNascimento);

    for(int i = 0; i < v.size(); i++){
        unsigned long int cpf = v1[i].getCPF();
        string nomeCompleto = v2[i].getNome() + ' ' + v2[i].getSobrenome();
        struct data dataNasc = v3[i].getDataNascimento();

        CPF->add(&cpf, &v1[i]);
        nome->add(&nomeCompleto, &v2[i]);
        dataNascimento->add(&dataNasc, &v3[i]);
        cout << "inseriu " << i << endl;
    }
}