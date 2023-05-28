#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "AVL.h"
using namespace std;

int main(){
    AVL<unsigned long long int> *CPF = new AVL<unsigned long long int>;
    AVL<string> *nome = new AVL<string>;
    AVL<struct data> *dataNascimento = new AVL<struct data>;
    vec2tree(pessoa2vec(), CPF, nome, dataNascimento);
    char op = '0';
    while(op != 'q'){
        menu();
        cin >> op;
        if(op == 'q') break;
        switch (op)
        {
        case '1':
            buscaCPF(CPF);
            pause();
            break;
        case '2':
            buscaString(nome);
            pause();
            break;
        case '3':
            intervaloData(dataNascimento);
            pause();
            break;
        case '4':
            imprimirArvores(CPF, nome, dataNascimento);
            pause();
            break;
        case '5':
            adicionarPessoa(CPF, nome, dataNascimento);
            pause();
            break;
        default:
            cout << "Opção inválida!" << endl;
            pause();
            break;
        }
        //pause();
    }

    delete CPF;
    delete nome;
    delete dataNascimento;
    
}