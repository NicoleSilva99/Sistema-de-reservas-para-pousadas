#ifndef POUSADA_H
#define POUSADA_H
#include <vector>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Reserva.h"
#include "Quarto.h"
#include "Produto.h"


using namespace std;


class Pousada {
public:
    Pousada();
    virtual ~Pousada();
    void carregaDados();
    void salvarDados();
    void consultaDisponibilidade(int data, int quarto);
    void consultaReserva(int data, string cliente, int quarto);
    void realizaReserva(int diaInicio, int diaFim, string cliente, int quarto);
    void cancelaReserva (string cliente);
    void realizaCheckIn (string cliente);
    void realizaCheckOut (string cliente);
    void setNome(string nome);
    string getNome();
    void setContato(string contato);
    string getContato();
    vector <Quarto*> getQuartos();
    void leituraPousada (string linha);
    void registrarConsumo(string nomeCliente);
    void listarConsumo();
    string serializarPousada();

private:
    string nome;
    string contato;
    vector<Quarto*> quartos;
    vector<Reserva*> reservas;
    vector<Produto*> produtos;
    fstream fsCarregaPousada;
    fstream fsCarregaQuartos;
    fstream fsCarregaReservas;
    fstream fsCarregaProdutos;
    fstream fsSalvaPousada;
    fstream fsSalvaQuartos;
    fstream fsSalvaReservas;
    fstream fsSalvaProdutos;
    vector<int>::iterator it;

};

#endif // POUSADA_H
