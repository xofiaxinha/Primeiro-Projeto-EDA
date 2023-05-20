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
    node->pessoa = (Pessoa*)realloc(pessoa, sizeof(Pessoa) * (node->numPessoas + 1));
    node->numPessoas += 1;
    node->pessoa[node->numPessoas - 1] = *(pessoa);

    return node;
}

bool compareCPF(Pessoa a, Pessoa b){
    return a.getCPF() < b.getCPF();
}
bool compareNome(Pessoa a, Pessoa b){
    return a.getNome() < b.getNome();
}
bool compareDataNascimento(Pessoa a, Pessoa b){
    return a.getDataNascimento() < b.getDataNascimento();
}
unsigned long int stringCPF(string CPF){
    unsigned long int cpf = 0;
    for(int i=0; i<(int)CPF.size(); i++){
        if(CPF[i] == '.' || CPF[i] == '-') continue;
        cpf = cpf*10 + (CPF[i] - '0');
    }
    return cpf;
}
std::vector<Pessoa> pessoa2vec(){
    vector<Pessoa> v;
    ifstream data;

    data.open("data.csv", ios::in);
    string line;
    if(!data.is_open()) throw runtime_error("Não foi possível ler o arquivo.");
    getline(data, line); //leitura da primeira linha do arquivo, que não será inclusa.
    while(getline(data, line)){
        int commaPos = line.find(',');
        string CPF = line.substr(0, commaPos);
        unsigned long int cpf = stringCPF(CPF);
        line = line.substr(commaPos + 1);
        commaPos = line.find(',');
        string nome = line.substr(0, commaPos);
        line = line.substr(commaPos + 1);
        commaPos = line.find(',');
        string sobrenome = line.substr(0, commaPos);
        line = line.substr(commaPos + 1);
        commaPos = line.find(',');
        string dataNascimento = line.substr(0, commaPos);
        line = line.substr(commaPos + 1);
        string lugarNascimento = line;
        Pessoa p(cpf, nome, sobrenome, dataNascimento, lugarNascimento);
        v.push_back(p);
    }
    data.close();
    return v;
}
void vec2tree(std::vector<Pessoa> v, AVL<unsigned long int> *CPF, AVL<std::string> *nome, AVL<struct data> *dataNascimento){
    std::vector<Pessoa> v1(v), v2(v), v3(v);
    sort(v1.begin(), v1.end(), compareCPF); //vetor ordenado pelo CPF
    sort(v2.begin(), v2.end(), compareNome); //vetor ordenado pelo nome
    sort(v3.begin(), v3.end(), compareDataNascimento); //vetor ordenado pela data de nascimento
    for(int i=0; i<(int)v.size(); i++){
        CPF->add(v1[i].getCPF(), &v1[i]);
        nome->add((v2[i].getNome() + ' ' + v2[i].getSobrenome()), &v2[i]);
        dataNascimento->add(v3[i].getDataNascimento(), &v3[i]);
    }
}
void buscaCPF(AVL<unsigned long int> *CPF);
void buscaString(AVL<std::string> *nome);
void intervaloData(AVL<struct data> *dataNascimento);