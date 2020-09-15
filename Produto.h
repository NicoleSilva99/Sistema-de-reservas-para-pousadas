#ifndef PRODUTO_H
#define PRODUTO_H
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>

using namespace std;


class Produto {
public:
    Produto();
    Produto(string linha);
    virtual ~Produto();
    void setCodigo(int codigo);
    int getCodigo();
    void setNome(string nome);
    string getNome();
    void setPreco(float preco);
    float getPreco();
    void imprimirProdutos();
    string serializarProduto();

private:
    int codigo;
    string nome;
    float preco;
};

#endif // PRODUTO_H
