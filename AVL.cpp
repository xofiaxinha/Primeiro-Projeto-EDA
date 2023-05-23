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
vector<Pessoa*> pessoa2vec(){
    vector<Pessoa*> v;
    ifstream data;

    data.open("data.csv", ios::in);
    string line;
    if(!data.is_open()) throw runtime_error("Não foi possível ler o arquivo.");
    getline(data, line); //leitura da primeira linha do arquivo, que não será inclusa.
    while(getline(data, line)){
        stringstream ss(line);
        string CPF, nome, sobrenome, dataNascimento, lugarNascimento;
        getline(ss, CPF, ',');
        getline(ss, nome, ',');
        getline(ss, sobrenome, ',');
        getline(ss, dataNascimento, ',');
        getline(ss, lugarNascimento, ',');
        unsigned long long int cpf = stringCPF(CPF);
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
    //lê substring a ser buscada
    string nomePessoa;
    cout << "Digite o nome que deseja buscar: ";
    getline(cin, nomePessoa);
    vector<Pessoa*> v;

    //busca a substring
    Node<string> *aux = nome->getRoot();
    while(aux != NULL){
        if(aux->dado.substr(0, (int)nomePessoa.size()) == nomePessoa){
            for(int i=0; i<(int)aux->pessoas.size(); i++){
                v.push_back(aux->pessoas[i]);
            }
        }
        if(aux->dado.substr(0, (int)nomePessoa.size()) < nomePessoa) aux = aux->right;
        else aux = aux->left;
    }
    cout << "Pessoas encontradas:\n";
    for(int i=0; i<(int)v.size(); i++){
        v[i]->print();
    }
}
void intervaloData(AVL<struct data> *dataNascimento){
    string data1, data2;
    cout << "Digite o intervalo de datas que deseja buscar\n";
    cout << "Data inicial: ";
    getline(cin, data1);
    cout << "Data final: ";
    getline(cin, data2);
    struct data d1(data1), d2(data2);
    cout << "Pessoas presentes no intervalo:\n";
    dataNascimento->intervalo(d1, d2);
}