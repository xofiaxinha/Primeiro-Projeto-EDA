#include <iostream>
#include <vector>
#include <string>
#include "AVL.h"
using namespace std;

int main(){
    AVL<unsigned long int> *CPF;
    AVL<string> *nome;
    AVL<struct data> *dataNascimento;
    vec2tree(CPF, nome, dataNascimento);
    CPF->preOrder();

    delete CPF;
    delete nome;
    delete dataNascimento;
}