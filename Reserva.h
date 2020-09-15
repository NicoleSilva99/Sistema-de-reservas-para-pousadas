#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
#include "Quarto.h"
#include "Produto.h"
#include <cstdio>

using namespace std;


class Reserva {
public:
    Reserva();
    Reserva(int diaInicio, int diaFim, string cliente, int quartoNumero,vector<Quarto*>quartos);
    Reserva (string linha, vector<Quarto*>quartos);
    virtual ~Reserva();
    void setDiaInicio(int diaInicio);
    int getDiaInicio();
    void setDiaFim(int diaFim);
    int getDiaFim();
    void setStatus(char status);
    char getStatus();
    void setCliente(string cliente);
    string getCliente();
    void setQuarto(Quarto *quarto);
    Quarto* getQuarto();
    string serializarReserva();

private:
    int diaInicio;
    int diaFim;
    string cliente;
    Quarto* quarto;
    char status;

};

#endif // RESERVA_H
