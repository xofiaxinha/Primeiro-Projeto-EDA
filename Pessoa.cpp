#include "Pessoa.h"
#include <string>
#include <iostream>

Pessoa::Pessoa(unsigned long int CPF, std::string nome, std::string sobrenome, 
                std::string dataNascimento, std::string lugarNascimento){
    this->CPF = CPF;
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->dataNascimento = data(dataNascimento);
    this->lugarNascimento = lugarNascimento;
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
std::string Pessoa::getLugarNascimento(){
    return this->lugarNascimento;
}


void Pessoa::print(){
    std::cout << "CPF: " << getSobrenome() << std::endl;
    std::cout << "Nome: " << getNome() << " " << getSobrenome() << std::endl;
    std::cout << "Data de Nascimento: " << getDataNascimento() << std::endl;
}