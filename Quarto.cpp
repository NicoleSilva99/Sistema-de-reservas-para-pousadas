#include "Quarto.h"

Quarto::Quarto() {}
/////////////////////////////////////////////////
Quarto::Quarto(string linha) {
    int item;
    stringstream ssCarrega(linha);
    ssCarrega >> this->numero;
    ssCarrega >> this->categoria;
    ssCarrega >> this->diaria;
    while(ssCarrega >> item) {
        consumo.push_back(item);
    }
}
/////////////////////////////////////////////////
Quarto::~Quarto() {
    cout << "Objeto destruido" << endl;
}
/////////////////////////////////////////////////
void Quarto::setNumero(int numero) {
    this->numero = numero;
}
/////////////////////////////////////////////////
int Quarto::getNumero() {
    return this->numero;
}
/////////////////////////////////////////////////
void Quarto::setCategoria(char categoria) {
    this->categoria = categoria;
}
/////////////////////////////////////////////////
char Quarto::getCategoria () {
    return this->categoria;
}
/////////////////////////////////////////////////
void Quarto::setDiaria(float diaria) {
    this->diaria = diaria;
}
/////////////////////////////////////////////////
float Quarto::getDiaria() {
    return this->diaria;
}
/////////////////////////////////////////////////
void Quarto::adicionarConsumo() {
    int codigo;
    cout << "Informe o codigo do produto escolhido pelo cliente: ";
    cin >> codigo;
    consumo.push_back(codigo);
}
/////////////////////////////////////////////////
void Quarto::listarConsumo(vector<Produto*> produtos) {
    cout << "Lista de consumo do cliente: " << endl;
    printf ("Codigo  Preco\n");
    for (auto it2 = consumo.begin(); it2 != consumo.end(); it2++) { //Percorre o vector de consumo do quarto do cliente
        for (auto it3 = produtos.begin(); it3 != produtos.end(); it3++) { //Percorre todo o vector de produtos para achar os codigos dos produtos consumos pelo cliente
            if ((*it3)->getCodigo() == (*it2)) { //Se achar algum codigo em comum, ele printa
                printf ("%d  %.2f\n", (*it2),(*it3)->getPreco());
            }
        }
    }
    cout << endl;
}
/////////////////////////////////////////////////
void Quarto::limpaConsumo() {
    consumo.clear();
}
/////////////////////////////////////////////////
float Quarto::valorTotalConsumo(vector<Produto*> produtos) {
    float valorConsumo = 0;
    for (auto it = consumo.begin(); it != consumo.end(); it++) {
        for (auto it2 = produtos.begin(); it2 != produtos.end(); it2++) {
            if ((*it2)->getCodigo() == (*it))
                valorConsumo += (*it2)->getPreco();
        }
    }
    return valorConsumo;
}
/////////////////////////////////////////////////
string Quarto::serializarQuarto() {
    stringstream ssSalvarQuartos;
    ssSalvarQuartos << this->numero << "\t";
    ssSalvarQuartos << this->categoria << "\t";
    ssSalvarQuartos << this->diaria << "\t";
    for (auto it = consumo.begin(); it != consumo.end(); it++) {
        ssSalvarQuartos << (*it) << "\t";
    }
    return ssSalvarQuartos.str();
}
