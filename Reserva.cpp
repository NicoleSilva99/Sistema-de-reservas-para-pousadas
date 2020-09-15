#include "Reserva.h"

Reserva::Reserva() {}
/////////////////////////////////////////////////
Reserva::Reserva(int diaInicio, int diaFim, string cliente, int quartoNumero, vector<Quarto*>quartos) {
    this->diaInicio = diaInicio;
    this->diaFim = diaFim;
    this->cliente = cliente;
    for (auto it = quartos.begin(); it != quartos.end(); it++) {
        if ((*it)->getNumero() == quartoNumero) {
            quarto = (*it);
            break;
        }
    }
    this->status = 'A';
}
/////////////////////////////////////////////////
Reserva::Reserva(string linha, vector<Quarto*>quartos) {
    int quartoNumero;
    stringstream ssCarrega(linha);
    ssCarrega >> this->diaInicio;
    ssCarrega >> this->diaFim;
    ssCarrega >> this->cliente;
    ssCarrega >> quartoNumero;
    quarto = NULL;
    for (auto it = quartos.begin(); it != quartos.end(); it++) { //Não tá dando certo
        if ((*it)->getNumero() == quartoNumero) {
            quarto = (*it);
            break;
        }
    }
    ssCarrega >> this->status;
}
/////////////////////////////////////////////////
Reserva::~Reserva() {
    cout << "Objeto destruido" << endl;
}
/////////////////////////////////////////////////
void Reserva::setDiaInicio(int diaInicio) {
    this->diaInicio = diaInicio;
}
/////////////////////////////////////////////////
int Reserva::getDiaInicio () {
    return this->diaInicio;
}
/////////////////////////////////////////////////
void Reserva::setDiaFim(int diaFim) {
    this->diaFim = diaFim;
}
/////////////////////////////////////////////////
int Reserva::getDiaFim() {
    return this->diaFim;
}
/////////////////////////////////////////////////
void Reserva::setStatus(char status) {
    this->status = status;
}
/////////////////////////////////////////////////
char Reserva::getStatus() {
    return this->status;
}
/////////////////////////////////////////////////
void Reserva::setQuarto(Quarto *quarto) {
    this->quarto = quarto;
}
/////////////////////////////////////////////////
Quarto* Reserva::getQuarto() { //NAO SEI SE TÁ CERTO ISSO
    return this->quarto;
}
/////////////////////////////////////////////////
void Reserva::setCliente(string cliente) {
    this->cliente = cliente;
}
/////////////////////////////////////////////////
string Reserva::getCliente() {
    return this->cliente;
}
/////////////////////////////////////////////////
string Reserva::serializarReserva() {
    stringstream ssSalvarReserva;
    ssSalvarReserva << this->diaInicio << "\t";
    ssSalvarReserva << this->diaFim << "\t";
    ssSalvarReserva << this->cliente << "\t";
    ssSalvarReserva << this->quarto->getNumero() << "\t";
    ssSalvarReserva << this->status << "\t";
    return ssSalvarReserva.str();
}
