#include "Pousada.h"

Pousada::Pousada() {
    this->nome = nome;
    this->contato = contato;
}
/////////////////////////////////////////////////
Pousada::~Pousada() {
    cout << "Objeto destruido" << endl;
}
/////////////////////////////////////////////////
void Pousada::setNome(string nome) {
    this->nome = nome;
}
/////////////////////////////////////////////////
string Pousada::getNome() {
    return this->nome;
}
/////////////////////////////////////////////////
void Pousada::setContato(string contato) {
    this->contato = contato;
}
/////////////////////////////////////////////////
string Pousada::getContato() {
    return this->contato;
}
/////////////////////////////////////////////////
void Pousada::carregaDados() {
    string linha;
    //Carregando pousada
    fstream fsCarregaPousada("pousada.txt", iostream::in);
    if (fsCarregaPousada.is_open()) {
        getline(fsCarregaPousada, linha);
        while(!fsCarregaPousada.eof()) {
            getline(fsCarregaPousada, linha);
            this->leituraPousada(linha);
        }
        fsCarregaPousada.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo pousada.txt" << endl;
    }

    //Carregando quartos
    fstream fsCarregaQuartos("quarto.txt", iostream::in);
    if (fsCarregaQuartos.is_open()) {
        getline(fsCarregaQuartos, linha);
        while(!fsCarregaQuartos.eof()) {
            getline(fsCarregaQuartos, linha);
            quartos.push_back(new Quarto(linha));
        }
        fsCarregaQuartos.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo quartos.txt" << endl;
    }

    //Carregando reservas
    fstream fsCarregaReservas("reserva.txt", iostream::in);
    if (fsCarregaReservas.is_open()) {
        getline(fsCarregaReservas, linha);
        while(!fsCarregaReservas.eof()) {
            getline(fsCarregaReservas, linha);
            reservas.push_back(new Reserva(linha, quartos));
        }
        fsCarregaReservas.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo reservas.txt" << endl;
    }

    //Carregando produto
    fstream fsCarregaProdutos("produto.txt", iostream::in);
    if (fsCarregaProdutos.is_open()) {
        getline(fsCarregaProdutos, linha);
        while(!fsCarregaProdutos.eof()) {
            getline(fsCarregaProdutos, linha);
            produtos.push_back(new Produto(linha));
        }
        fsCarregaProdutos.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo produto.txt" << endl;
    }
}
/////////////////////////////////////////////////
void Pousada::leituraPousada(string linha) {
    stringstream ssCarregaPousada(linha);
    getline(ssCarregaPousada, this->nome, '\t');
    getline(ssCarregaPousada, this->contato);
}
/////////////////////////////////////////////////
void Pousada::consultaDisponibilidade(int data, int quarto) {
    for (auto it = reservas.begin(); it != reservas.end(); it++) {
        if ((((*it)->getQuarto()->getNumero() == quarto) && ((data >= (*it)->getDiaInicio()) && (data <= (*it)->getDiaFim()))) && ((*it)->getStatus() == 'A' || (*it)->getStatus() == 'I')) {
            cout << "Quarto ocupado nesta data!" << endl << endl;
            cout << "Dia inicial da reserva: " << (*it)->getDiaInicio() << endl;
            cout << "Dia final da reserva: " << (*it)->getDiaFim() << endl;
            cout << "Nome do cliente: " << (*it)->getCliente() << endl;
            cout << "Numero do quarto: " << (*it)->getQuarto()->getNumero() << endl;
            cout << "Status: " << (*it)->getStatus() << endl;
            cout << endl;
            break;
        } else {
            cout << "Esse quarto esta disponivel!" << endl << endl;
            cout << "Numero do quarto: " << (*it)->getQuarto()->getNumero() << endl;
            cout << "Categoria do quarto: " << (*it)->getQuarto()->getCategoria() << endl;
            cout << "Diaria: " << (*it)->getQuarto()->getDiaria() << endl;
            cout << endl;
            break;
        }
    }
}
/////////////////////////////////////////////////
void Pousada::consultaReserva(int data, string cliente, int quarto) {
    int contador = 0;
    for (auto it = reservas.begin(); it != reservas.end(); it++) { //QUANDO INFORMA TODOS
        if (((*it)->getDiaInicio() == data) && (((*it)->getQuarto()->getNumero() == quarto) && ((*it)->getCliente() == cliente))) {
            cout << "Dia inicial da reserva: " << (*it)->getDiaInicio() << endl;
            cout << "Dia final da reserva: " << (*it)->getDiaFim() << endl;
            cout << "Nome do cliente: " << (*it)->getCliente() << endl;
            cout << "Numero do quarto: " << (*it)->getQuarto()->getNumero() << endl;
            cout << "Status: " << (*it)->getStatus() << endl;
            contador++;
            cout << endl;
        } else if ((((*it)->getDiaInicio() == data) && (((*it)->getQuarto()->getNumero() == quarto) && (cliente == "0")))) { //QUANDO NAO INFORMA CLIENTE
            cout << "Dia inicial da reserva: " << (*it)->getDiaInicio() << endl;
            cout << "Dia final da reserva: " << (*it)->getDiaFim() << endl;
            cout << "Nome do cliente: " << (*it)->getCliente() << endl;
            cout << "Numero do quarto: " << (*it)->getQuarto()->getNumero() << endl;
            cout << "Status: " << (*it)->getStatus() << endl;
            contador++;
            cout << endl;
        } else if ((((*it)->getDiaInicio() == data) && (quarto == 0) && ((*it)->getCliente() == cliente))) { //QUANDO NAO INFORMA O QUARTO
            cout << "Dia inicial da reserva: " << (*it)->getDiaInicio() << endl;
            cout << "Dia final da reserva: " << (*it)->getDiaFim() << endl;
            cout << "Nome do cliente: " << (*it)->getCliente() << endl;
            cout << "Numero do quarto: " << (*it)->getQuarto()->getNumero() << endl;
            cout << "Status: " << (*it)->getStatus() << endl;
            contador++;
            cout << endl;
        } else if ((data == 0) && (quarto == (*it)->getQuarto()->getNumero()) && ((*it)->getCliente() == cliente)) { //QUANDO NAO INFORMA O QUARTO
            cout << "Dia inicial da reserva: " << (*it)->getDiaInicio() << endl;
            cout << "Dia final da reserva: " << (*it)->getDiaFim() << endl;
            cout << "Nome do cliente: " << (*it)->getCliente() << endl;
            cout << "Numero do quarto: " << (*it)->getQuarto()->getNumero() << endl;
            cout << "Status: " << (*it)->getStatus() << endl;
            contador++;
            cout << endl;
        }
    }
    if (contador == 0) {
        cout << "Nao existem reservas com os dados informados!" << endl;
    }
}
/////////////////////////////////////////////////
void Pousada::realizaReserva(int diaInicio, int diaFim, string cliente, int quartoNumero) {
    bool flag = true;
    for (auto it = reservas.begin(); it != reservas.end(); it++) {
        if ((*it)->getCliente() != cliente || (*it)->getStatus() == 'C' || (*it)->getStatus() == 'O') { //NAO DA CERTO QUE INFERNO
            if ((*it)->getQuarto()->getNumero() == quartoNumero && (!((diaInicio < (*it)->getDiaInicio() && diaFim < (*it)->getDiaInicio()) || diaInicio > (*it)->getDiaFim())) && ((*it)->getStatus() != 'C' && (*it)->getStatus() != 'O')) {
                cout << "Infelizmente ja existe uma reserva nesta data" << endl;
                flag = false;
                break;
            }
        } else {
            cout << "O cliente ja possui alguma reserva ativa em seu nome" << endl;
            flag = false;
            break;
        }
    }
    if (flag == true) {
        reservas.push_back(new Reserva (diaInicio, diaFim, cliente, quartoNumero, quartos));
    }
}
/////////////////////////////////////////////////
void Pousada::cancelaReserva (string cliente) {
    int contador = 0;
    for (auto it = reservas.begin(); it != reservas.end(); it++) {
        if ((*it)->getCliente() == cliente && (*it)->getStatus() == 'A') {
            (*it)->setStatus('C');
            contador++;
        }
    }
    if (contador == 0) {
        cout << "Nao existem reservas ativas para esse cliente!" << endl;
    }
}
/////////////////////////////////////////////////
void Pousada::realizaCheckIn (string cliente) {
    int contador = 0;
    for (auto it = reservas.begin(); it != reservas.end(); it++) {
        if ((*it)->getCliente() == cliente && (*it)->getStatus() == 'A') {
            (*it)->setStatus('I');
            cout << "Dia inicial da reserva: " << (*it)->getDiaInicio() << endl;
            cout << "Dia final da reserva: " << (*it)->getDiaFim() << endl;
            cout << "Nome do cliente: " << (*it)->getCliente() << endl;
            cout << "Numero do quarto: " << (*it)->getQuarto()->getNumero() << endl;
            cout << "Status: " << (*it)->getStatus() << endl;
            contador++;
        }
    }
    if (contador == 0) {
        cout << "Nao existem reservas ativas para check-in para esse cliente!" << endl;
    }
}
/////////////////////////////////////////////////
void Pousada::registrarConsumo(string nomeCliente) {
    cout << "Codigo" << "  " << "Nome" << "  " << "Preco" << endl;
    for (auto it = reservas.begin(); it != reservas.end(); it++) {
        if ((*it)->getCliente() == nomeCliente && (*it)->getStatus() == 'I') {
            for (auto it2 = produtos.begin(); it2 != produtos.end(); it2++) {
                (*it2)->imprimirProdutos();
            }
            (*it)->getQuarto()->adicionarConsumo();
        }
    }
}
/////////////////////////////////////////////////
void Pousada::realizaCheckOut(string cliente) {
    int contador = 0;
    float somaConsumo = 0;
    float valorDiarias = 0;
    for (auto it = reservas.begin(); it != reservas.end(); it++) {
        if ((*it)->getCliente() == cliente && (*it)->getStatus() == 'I') {
            cout << "Dia inicial da reserva: " << (*it)->getDiaInicio() << endl;
            cout << "Dia final da reserva: " << (*it)->getDiaFim() << endl;
            cout << "Quantidade de dias: " << ((*it)->getDiaFim() - (*it)->getDiaInicio()) << endl << endl;
            (*it)->getQuarto()->listarConsumo(produtos); //Para achar o numero do quarto do cliente
            somaConsumo = (*it)->getQuarto()->valorTotalConsumo(produtos); //Calcula todo o consumo do cliente
            printf ("Valor do consumo: %.2f\n", somaConsumo);
            valorDiarias += (((*it)->getQuarto()->getDiaria()) * ((*it)->getDiaFim() - (*it)->getDiaInicio()));
            printf ("Valor total da conta: %.2f\n\n", valorDiarias + somaConsumo);
            (*it)->setStatus('O');
            (*it)->getQuarto()->limpaConsumo();
            contador++;
            break;
        }
    }
    if (contador == 0) {
        cout << "Nao ha check-in ativo no nome do cliente!" << endl;
    }
}
/////////////////////////////////////////////////
void Pousada::salvarDados() {
    //Salvando pousada
    fstream fsSalvaPousada("pousada.txt", iostream::out | iostream::trunc);
    if (fsSalvaPousada.is_open()) {
        fsSalvaPousada << "nome\tcontato";
        fsSalvaPousada << endl << serializarPousada();
        fsCarregaPousada.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo pousada.txt" << endl;
    }

//Salvando quartos
    fstream fsSalvaQuartos("quarto.txt", iostream::out | iostream::trunc);
    if (fsSalvaQuartos.is_open()) {
        fsSalvaQuartos << "numero\tcategoria\tdiaria\tconsumo";
        for (auto it = quartos.begin(); it != quartos.end(); it++) {
            fsSalvaQuartos << endl << (*it)->serializarQuarto();
        }
        fsSalvaQuartos.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo quarto.txt" << endl;
    }

//Salvando reservas
    fstream fsSalvaReservas("reserva.txt", iostream::out | iostream::trunc);
    if (fsSalvaReservas.is_open()) {
        fsSalvaReservas << "diaInicio\tdiaFim\tcliente\tquarto\tstatus";
        for (auto it = reservas.begin(); it != reservas.end(); it++) {
            if ((*it)->getStatus() == 'A' || (*it)->getStatus() == 'I') {
                fsSalvaReservas << endl << (*it)->serializarReserva();
            }
        }
        fsSalvaReservas.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo reserva.txt" << endl;
    }

//Salvando produto
    fstream fsSalvaProdutos("produto.txt", iostream::out | iostream::trunc);
    if (fsSalvaProdutos.is_open()) {
        fsSalvaProdutos << "codigo\tnome\tpreco";
        for (auto it = produtos.begin(); it != produtos.end(); it++) {
            fsSalvaProdutos << endl << (*it)->serializarProduto();
        }
        fsSalvaProdutos.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo produto.txt" << endl;
    }
}
/////////////////////////////////////////////////
string Pousada::serializarPousada() {
    stringstream ssSalvarPousada;
    ssSalvarPousada << this->nome << "\t";
    ssSalvarPousada << this->contato;
    return ssSalvarPousada.str();
}

