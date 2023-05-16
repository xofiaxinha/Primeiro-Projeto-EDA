#include <iostream>
#include <vector>
#include <string>
#include "AVL.h"
using namespace std;

int main(){
    cout << "Testes \n";
    AVL<unsigned long int> *CPF = new AVL<unsigned long int>;
    AVL<string> *Nome = new AVL<string>;
    AVL<struct data> *DataNascimento = new AVL<struct data>;
    cout << "Digite o CPF: ";
    unsigned long int cpf;
    cin >> cpf;
    cout << "Digite o nome: ";
    string nome;
    getline(cin, nome);
    cout << "Digite o sobrenome: ";
    string sobrenome;
    getline(cin, sobrenome);
    cout << "Digite a data de nascimento: ";
    string dataNascimento;
    getline(cin, dataNascimento);
    cout << "Digite a cidade: ";
    string cidade;
    getline(cin, cidade);
    Pessoa p1(cpf, nome, sobrenome, dataNascimento, cidade);
    cout << "Adicionando nas árvores...\n";
    CPF->add(cpf, &p1);
    Nome->add(nome, &p1);
    DataNascimento->add(p1.getDataNascimento(), &p1);
    cout << "Exibindo as árvores:\n"
        << "CPF: ";
    CPF->preOrder();
    cout << "\nNome: ";
    Nome->preOrder();
    cout << "\nData de nascimento: ";
    DataNascimento->preOrder();
    cout << "\n";
}