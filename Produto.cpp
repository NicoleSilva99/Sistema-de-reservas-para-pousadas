#include "Produto.h"

Produto::Produto() {}
/////////////////////////////////////////////////
Produto::Produto(string linha) {
    //char separador;
    stringstream ssCarrega(linha);
    ssCarrega >> this->codigo;
    ssCarrega.get();
    getline(ssCarrega, this->nome, '\t');
    ssCarrega >> this->preco;
}
/////////////////////////////////////////////////
Produto::~Produto() {
    cout << "Objeto destruido" << endl;
}
/////////////////////////////////////////////////
void Produto::setCodigo(int codigo) {
    this->codigo = codigo;
}
/////////////////////////////////////////////////
int Produto::getCodigo() {
    return this->codigo;
}
/////////////////////////////////////////////////
void Produto::setNome(string nome) {
    this->nome = nome;
}
/////////////////////////////////////////////////
string Produto::getNome() {
    return this->nome;
}
/////////////////////////////////////////////////
void Produto::setPreco(float preco) {
    this->preco = preco;
}
/////////////////////////////////////////////////
float Produto::getPreco() {
    return this->preco;
}
/////////////////////////////////////////////////
void Produto::imprimirProdutos() {
    cout << this->codigo << "  ";
    cout << this->nome << "  ";
    printf ("%.2f  ", this->preco);
    cout << endl;
}
/////////////////////////////////////////////////
string Produto::serializarProduto() {
    stringstream ssSalvarProduto;
    ssSalvarProduto << this->codigo << "\t";
    ssSalvarProduto << this->nome << "\t";
    ssSalvarProduto << this->preco << "\t";
    return ssSalvarProduto.str();
}
