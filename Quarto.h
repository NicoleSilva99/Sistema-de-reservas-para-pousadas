#ifndef QUARTO_H
#define QUARTO_H
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Produto.h"
#include <cstdio>

using namespace std;


class Quarto {
public:
    Quarto();
    Quarto(string linha);
    virtual ~Quarto();
    void adicionarConsumo();
    void listarConsumo(vector<Produto*> produtos);
    float valorTotalConsumo(vector<Produto*> produtos);
    void limpaConsumo();
    void setNumero(int numero);
    int getNumero();
    void setCategoria(char categoria);
    char getCategoria();
    void setDiaria(float diaria);
    float getDiaria();
    string serializarQuarto();


private:
    int numero;
    char categoria;
    float diaria;
    vector <int> consumo;

};

#endif // QUARTO_H
