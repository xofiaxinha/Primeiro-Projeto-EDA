#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "AVL.h"

using namespace std;

template<typename T>
struct Node<T> *repeatedNode(struct Node<T> *node, Pessoa *pessoa){
    node->pessoas.push_back(pessoa);
    return node;
}

bool compareCPF(Pessoa *a, Pessoa *b){
    return a->getCPF() < b->getCPF();
}
bool compareNome(Pessoa *a, Pessoa *b){
    return a->getNome() < b->getNome();
}
bool compareDataNascimento(Pessoa *a, Pessoa *b){
    return a->getDataNascimento() < b->getDataNascimento();
}
unsigned long long int stringCPF(string CPF){
    unsigned long long int cpf = 0;
    for(int i=0; i<(int)CPF.size(); i++){
        if(CPF[i] == '.' || CPF[i] == '-') continue;
        cpf = cpf*10 + (CPF[i] - '0');
    }
    return cpf;
}
std::vector<Pessoa*> pessoa2vec(){
    vector<Pessoa*> v;
    ifstream data;

    data.open("data.csv", ios::in);
    string line;
    if(!data.is_open()) throw runtime_error("Não foi possível ler o arquivo.");
    getline(data, line); //leitura da primeira linha do arquivo, que não será inclusa.
    for(int i=0; i<10; i++){
        getline(data, line);
        stringstream ss(line);
        string CPF, nome, sobrenome, dataNascimento, lugarNascimento;
        getline(ss, CPF, ',');
        getline(ss, nome, ',');
        getline(ss, sobrenome, ',');
        getline(ss, dataNascimento, ',');
        getline(ss, lugarNascimento, ',');
        cout << "CPF: " << CPF << '\n';
        unsigned long long int cpf = stringCPF(CPF);
        cout << "CPF2: " << cpf << '\n';
        Pessoa *pessoa = new Pessoa(cpf, nome, sobrenome, dataNascimento, lugarNascimento);
        v.push_back(pessoa);
    }
    data.close();
    return v;
}
void vec2tree(std::vector<Pessoa*> v, AVL<unsigned long long int> *CPF, AVL<std::string> *nome, 
            AVL<struct data> *dataNascimento){
    std::vector<Pessoa*> v1(v), v2(v), v3(v);
    //cout << "Criou os vetores\n";
    sort(v1.begin(), v1.end(), compareCPF); //vetor ordenado pelo CPF
    //cout << "Ordenou o vetor 1\n";
    sort(v2.begin(), v2.end(), compareNome); //vetor ordenado pelo nome
    //cout << "Ordenou o vetor 2\n";
    sort(v3.begin(), v3.end(), compareDataNascimento); //vetor ordenado pela data de nascimento
    //cout << "Ordenou o vetor 3\n";

    for(unsigned int i=0; i<(int)v.size(); i++){
        CPF->add(v1.at(i)->getCPF(), v1.at(i));
        nome->add(v2.at(i)->getNome() + ' ' + v2.at(i)->getSobrenome(), v2.at(i));
        dataNascimento->add(v3.at(i)->getDataNascimento(), v3.at(i));
    }
}
void buscaCPF(AVL<unsigned long long int> *CPF){
    unsigned long long int cpf;
    cout << "Digite o CPF que deseja buscar: ";
    cin >> cpf;
    if(CPF->isThere(cpf)){
        cout << "CPF encontrado!\n";
        CPF->printNode(cpf);
    }
    else cout << "CPF não encontrado.\n";
}
void buscaString(AVL<string> *nome){
    string nomePessoa;
    cout << "Digite o nome que deseja buscar: ";
    getline(cin, nomePessoa);
    if(nome->isThere(nomePessoa)){
        cout << "Nome encontrado!\n";
        nome->printNode(nomePessoa);
    }
    else cout << "Nome não encontrado.\n";
}
void intervaloData(AVL<struct data> *dataNascimento){
    string data1, data2;
    cout << "Digite o intervalo de datas que deseja buscar: ";
    cin >> data1 >> data2;
    
}