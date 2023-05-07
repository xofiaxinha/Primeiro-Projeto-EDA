#include <iostream>
#include <vector>
#include <string>
#include "AVL.h"
using namespace std;

int main(){
    long int cpf;
    string nome, sobrenome, dataNascimento;
    vector<Pessoa> v;
    
    AVL<long int> CPF;
    AVL<string> nomeCompleto;
    AVL<struct data> dataNasc;

    for(int i=0; i<10; i++){
        cout << "CPF: ";
        cin >> cpf;
        cout << "Nome: ";
        cin >> nome;
        cout << "Sobrenome: ";
        cin >> sobrenome;
        cout << "Data de nascimento (mm/dd/aaaa): ";
        cin >> dataNascimento;
        cout << endl;
        Pessoa p(cpf, nome, sobrenome, dataNascimento);
        v.push_back(p);
    }
    vec2tree(v, &CPF, &nomeCompleto, &dataNasc);
    cout << "Arvore organizada pelo CPF:\n";
    CPF.preOrder();
}