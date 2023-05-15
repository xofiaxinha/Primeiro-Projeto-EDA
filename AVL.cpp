#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "AVL.h"

using namespace std;

template<typename T>
struct Node<T> *repeatedNode(struct Node<T> *node, Pessoa *pessoa){
    node->pessoa = (Pessoa*)realloc(pessoa, sizeof(Pessoa) * (node->numPessoas + 1));
    node->numPessoas += 1;
    node->pessoa[node->numPessoas - 1] = *(pessoa);

    return node;
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