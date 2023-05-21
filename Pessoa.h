#ifndef PESSOA_H
#define PESSOA_H
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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
        int barPos = data.find("/");
        this->mes = std::stoi(data.substr(0, barPos));
        data = data.substr(barPos + 1);
        barPos = data.find("/");
        this->dia = std::stoi(data.substr(0, barPos));
        data = data.substr(barPos + 1);
        this->ano = std::stoi(data);
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
    bool operator >=(const data& d){
        if(*this > d || *this == d){
            return true;
        }
        return false;
    }
    bool operator <=(const data& d){
        if(*this < d || *this == d){
            return true;
        }
        return false;
    }
    friend std::ostream& operator<<(std::ostream& os, const data& d){
        os << std::setfill('0') << std::setw(2) << d.mes << "/" << std::setfill('0') << std::setw(2) << d.dia << "/" << d.ano;
        return os;
    }
    bool operator==(const data& d){
        if(this->ano == d.ano && this->mes == d.mes && this->dia == d.dia){
            return true;
        }
        return false;
    }
};

class Pessoa{
    private:
        unsigned long long int CPF;
        std::string nome;
        std::string sobrenome;
        struct data dataNascimento;
        std::string lugarNascimento;
    public:
        Pessoa(unsigned long long int CPF, std::string nome, std::string sobrenome, std::string dataNascimento, std::string lugarNascimento);
        ~Pessoa();
        unsigned long long int getCPF();
        std::string getNome();
        std::string getSobrenome();
        struct data getDataNascimento();
        std::string getLugarNascimento();
        void print();
};

template<typename T>
struct Node{
        T dado;
        Node* left;
        Node* right;
        std::vector<Pessoa*> pessoas; //vetor de ponteiros para pessoas com o mesmo dado
        int height;
        Node(T dado, Pessoa *pessoa){
            this->dado = dado;
            this->pessoas.push_back(pessoa);
            left = nullptr;
            right = nullptr;
            height = 1;
        }
        void print(){
            std::cout << dado << " ";
        }
};
#endif