#include <iostream>
#include <string>
#include <vector>
#include "AVL.h"

void vec2tree(std::vector<Pessoa> v, AVL<unsigned long int> *CPF, AVL<std::string> *nome, AVL<struct data> *dataNascimento);
std::vector<Pessoa> pessoa2vec(int n);