#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "AVL.h"
using namespace std;

int main(){
    cout << "Teste" << endl;
    AVL<unsigned long long int> *CPF = new AVL<unsigned long long int>;
    AVL<string> *nome = new AVL<string>;
    AVL<struct data> *dataNascimento = new AVL<struct data>;
    vec2tree(pessoa2vec(), CPF, nome, dataNascimento);
    cout << "Testando intervalo de datas\n";
    intervaloData(dataNascimento);
}