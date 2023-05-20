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
    return CPF;
}
std::string Pessoa::getNome(){
    return nome;
}
std::string Pessoa::getSobrenome(){
    return sobrenome;
}
struct data Pessoa::getDataNascimento(){
    return dataNascimento;
}
std::string Pessoa::getLugarNascimento(){
    return lugarNascimento;
}


void Pessoa::print(){
    std::cout << "CPF: " << getCPF() << std::endl;
    std::cout << "Nome: " << getNome() << " " << getSobrenome() << std::endl;
    std::cout << "Data de Nascimento: " << getDataNascimento() << std::endl;
    std::cout << "Lugar de Nascimento: " << getLugarNascimento() << std::endl;
}