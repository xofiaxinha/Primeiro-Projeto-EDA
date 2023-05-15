#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "AVL.h"

using namespace std;

template<typename T>
struct Node<T> *repeatedNode(struct Node<T> *node, Pessoa *pessoa){
    node->pessoa = (Pessoa*)realloc(pessoa, sizeof(Pessoa) * (node->numPessoas + 1));
    node->numPessoas += 1;
    node->pessoa[node->numPessoas - 1] = *(pessoa);
    return node;
}
vector<Pessoa> pessoa2vec(int n){
    vector<Pessoa> v;
    for(int i = 0; i < n; i++){
        cout << "Digite o CPF: ";
        unsigned long int cpf;
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
        v.push_back(fulano);
    }
    return v;
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

//a função recebe as árvores a serem preenchidas
void vec2tree(vector<Pessoa> v, AVL<unsigned long int> *CPF, AVL<string> *nome, AVL<struct data> *dataNascimento){
    /*/*, AVL<string> *nome, AVL<struct data> *dataNascimento*/
    vector<Pessoa> v1(v), v2(v), v3(v);
    sort(v1.begin(), v1.end(), compareCPF);
    sort(v2.begin(), v2.end(), compareNome);
    sort(v3.begin(), v3.end(), compareDataNascimento);

    for(int i = 0; i < v.size(); i++){
        unsigned long int cpf = v1[i].getCPF();
        string nomeCompleto = v2[i].getNome() + ' ' + v2[i].getSobrenome();
        struct data dataNasc = v3[i].getDataNascimento();

        CPF->add(&cpf, &v1[i]);
        nome->add(&nomeCompleto, &v2[i]);
        dataNascimento->add(&dataNasc, &v3[i]);
        cout << "inseriu " << i << endl;
    }
}