#include <iostream>
#include <vector>
#include <string>
#include "AVL.h"
using namespace std;

int main(){
    cout << "Testes \n";

    cout << "Node de exemplo:\n";
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
    Node<long int> *node = new Node<long int>(&cpf, &fulano);

    cout << "CPF: " << *(node->dado) << endl;
    cout << "Nome: " << node->pessoa->getNome() << endl;
    cout << "Data de nascimento: " << node->pessoa->getDataNascimento() << endl;

    cout << "AVL de exemplo:\n";
    AVL<long int> *CPF = new AVL<long int>();
    AVL<string> *Nome = new AVL<string>();
    AVL<struct data> *DataNascimento = new AVL<struct data>();
    
}