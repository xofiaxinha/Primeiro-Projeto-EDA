#include <iostream>
#include <vector>
#include <string>
#include "AVL.h"
using namespace std;

int main(){
    vector<Pessoa> pessoas = pessoa2vec();
    AVL<unsigned long int> *CPF;
    AVL<string> *nome;
    AVL<data> *dataNascimento;
    vec2tree(pessoas, CPF, nome, dataNascimento);
    CPF->preOrder();

    delete CPF;
    delete nome;
    delete dataNascimento;
}