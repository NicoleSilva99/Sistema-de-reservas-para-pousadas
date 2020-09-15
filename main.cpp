#include <iostream>
#include "Pousada.h"
#include "Produto.h"

using namespace std;


int main() {
    //Declaração de variáveis
    int numero;
    int dia, diaInicio, diaFim;
    int numeroQuarto;
    string nomeCliente;

    //Criando a pousada
    Pousada *pousada = new Pousada;
    pousada->carregaDados();

    //Criando menu
    while(1) {
        cout << "Menu:" << endl;
        cout << "Opcao 1 - Consultar disponibilidade" << endl;
        cout << "Opcao 2 - Consultar reserva" << endl;
        cout << "Opcao 3 - Realizar reserva" << endl;
        cout << "Opcao 4 - Cancelar reserva" << endl;
        cout << "Opcao 5 - Check-In" << endl;
        cout << "Opcao 6 - Check-Out" << endl;
        cout << "Opcao 7 - Registrar consumo" << endl;
        cout << "Opcao 8 - Salvar" << endl;
        cout << "Opcao 0 - Sair" << endl;
        cout << "-----------------------" << endl;
        cout << "Escolha uma opcao: ";
        cin >> numero;
        system("clear || cls");

        switch (numero) {
        case 1:
            cout << "Consultar disponibilidade: " << endl << endl;
            cout << "Informe a data: ";
            cin >> dia;
            cout << "Informe o numero do quarto: ";
            cin >> numeroQuarto;
            system("clear || cls");
            pousada->consultaDisponibilidade(dia, numeroQuarto);
            break;
        case 2:
            cout << "Consultar reserva: " << endl << endl;
            cout << "Informe a data: ";
            cin >> dia;
            cout << "Informe o numero do quarto: ";
            cin >> numeroQuarto;
            cout << "Informe o nome do cliente: ";
            cin >> nomeCliente;
            system("clear || cls");
            pousada->consultaReserva(dia, nomeCliente, numeroQuarto);
            break;
        case 3:
            cout << "Realizar reserva: " << endl << endl;
            cout << "Informe a data de check-in: ";
            cin >> diaInicio;
            cout << "Informe a data de check-out: ";
            cin >> diaFim;
            cout << "Informe o numero do quarto: ";
            cin >> numeroQuarto;
            cout << "Informe o nome do cliente: ";
            cin >> nomeCliente;
            system("clear || cls");
            pousada->realizaReserva(diaInicio, diaFim, nomeCliente, numeroQuarto);
            break;
        case 4:
            cout << "Cancelar reserva: " << endl << endl;
            cout << "Informe o nome do cliente: ";
            cin >> nomeCliente;
            system("clear || cls");
            pousada->cancelaReserva(nomeCliente);
            break;
        case 5:
            cout << "Realizar check-in: " << endl << endl;
            cout << "Informe o nome do cliente: ";
            cin >> nomeCliente;
            system("clear || cls");
            pousada->realizaCheckIn(nomeCliente);
            break;
        case 6:
            cout << "Realizar check-out: " << endl << endl;
            cout << "Informe o nome do cliente: ";
            cin >> nomeCliente;
            system("clear || cls");
            pousada->realizaCheckOut(nomeCliente);
            break;
        case 7:
            cout << "Registrar consumo: " << endl << endl;
            cout << "Informe o nome do cliente: ";
            cin >> nomeCliente;
            system("clear || cls");
            pousada->registrarConsumo(nomeCliente);
            break;
        case 8:
            cout << "Salvar dados: " << endl << endl;
            pousada->salvarDados();
            break;
        case 0:
            return 0;
            break;
        }
    }
    delete pousada;
    return 0;
}
