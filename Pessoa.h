#ifndef PESSOA_H
#define PESSOA_H
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
struct data{
    int dia;
    int mes;
    int ano;

    data(){
        dia = 0;
        mes = 0;
        ano = 0;
    } //default
    data(std::string data){
        dia = std::stoi(data.substr(3,2));
        mes = std::stoi(data.substr(0,2));
        ano = std::stoi(data.substr(6,4));
    }//data no formato mm/dd/aaaa
    //sobrecarga do operador <
    bool operator<(const data& d){
        if(this->ano < d.ano){
            return true;
        }else if(this->ano == d.ano){
            if(this->mes < d.mes){
                return true;
            }else if(this->mes == d.mes){
                if(this->dia < d.dia){
                    return true;
                }
            }
        }
        return false;
    }
    bool operator>(const data& d){
        if(this->ano > d.ano){
            return true;
        }else if(this->ano == d.ano){
            if(this->mes > d.mes){
                return true;
            }else if(this->mes == d.mes){
                if(this->dia > d.dia){
                    return true;
                }
            }
        }
        return false;
    }
    friend std::ostream& operator<<(std::ostream& os, const data& d){
        os << std::setfill('0') << std::setw(2) << d.mes << "/" << std::setfill('0') << std::setw(2) << d.dia << "/" << d.ano;
        return os;
    }
};

class Pessoa{
    private:
        unsigned long int CPF;
        std::string nome;
        std::string sobrenome;
        struct data dataNascimento;
    public:
        Pessoa(unsigned long int CPF, std::string nome, std::string sobrenome, std::string dataNascimento);
        ~Pessoa();
        unsigned long int getCPF();
        std::string getNome();
        std::string getSobrenome();
        struct data getDataNascimento();
};
#endif