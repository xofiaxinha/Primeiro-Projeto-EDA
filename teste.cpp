#include <iostream>
#include <vector>
#include <string>
#include "AVL.h"
using namespace std;

int main(){
    vector<Pessoa*> pessoas = pessoa2vec();
    AVL<unsigned long long int> *CPF = new AVL<unsigned long long int>;
    AVL<string> *nome = new AVL<string>;
    AVL<struct data> *dataNascimento = new AVL<struct data>;
    vec2tree(pessoas, CPF, nome, dataNascimento);
    nome->preOrder();

    cout << "\n\n";
    buscaString(nome);
    delete CPF;
    delete nome;
    delete dataNascimento;
}