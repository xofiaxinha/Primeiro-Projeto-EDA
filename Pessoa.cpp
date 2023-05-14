#include "Pessoa.h"
#include <string>
#include <iostream>

Pessoa::Pessoa(unsigned long int CPF, std::string nome, std::string sobrenome, std::string dataNascimento){
    this->CPF = CPF;
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->dataNascimento = data(dataNascimento);
}
Pessoa::~Pessoa(){}
unsigned long int Pessoa::getCPF(){
    return this->CPF;
}
std::string Pessoa::getNome(){
    return this->nome;
}
std::string Pessoa::getSobrenome(){
    return this->sobrenome;
}
struct data Pessoa::getDataNascimento(){
    return this->dataNascimento;
}