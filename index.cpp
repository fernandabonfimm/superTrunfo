// Acesse o README do projeto, para mais informações.

#include <iostream>
#include "superTrunfo.h"
#include <fstream>
#include <sstream>
#include <time.h>
#include <string>
using std::getline;
using namespace std;

superTrunfo::superTrunfo()
{
    tail = 0;
    head = 1;
    count = 0;
}

void superTrunfo::Read(carro lista[])
{
    int i;
    ifstream ler("cards.csv", ios::in);
    string convert;

    getline(ler, convert);

    for (i = 0; i < LIMIT; i++)
    {
        getline(ler, lista[i].model, ',');
        getline(ler, lista[i].curb_weight, ',');
        stringstream convertCurb;
        convertCurb << lista[i].curb_weight;
        convertCurb >> lista[i].curb_weight;
        getline(ler, lista[i].engine_size, ',');
        stringstream convertEngine;
        convertEngine << lista[i].engine_size;
        convertEngine >> lista[i].engine_size;
        getline(ler, lista[i].horsepower, ',');
        stringstream convertHorse;
        convertHorse << lista[i].horsepower;
        convertHorse >> lista[i].horsepower;
        getline(ler, lista[i].price, ',');
        stringstream convertPrice;
        convertPrice << lista[i].price;
        convertPrice >> lista[i].price;
        getline(ler, lista[i].group, '\n');
    }
}

void superTrunfo::Embaralhar(carro lista[], superTrunfo &J1, superTrunfo &J2)
{
    int value, value2;
    bool repetido;
    carro temp;

    srand(time(NULL));

    for (int i = 0; i < 128; i++)
    {
        value = rand() % LIMIT;
        value2 = rand() % LIMIT;

        temp = lista[value];
        lista[value] = lista[value2];
        lista[value2] = temp;
    }

    for (int i = 0; i <= 16; i++)
    {
        J1.Append(lista[i]);
    }

    for (int i = 16; i <= 32; i++)
    {
        J2.Append(lista[i]);
    }
}

void superTrunfo::CartasDosJogadores(carro x)
{
    cout << "|-----------------------------------------|" << endl;
    cout << "  Modelo da carta:     " << x.model << endl;
    cout << "  Grupo da carta:      " << x.group << endl;
    cout << "  Preço da carta:      " << x.price << endl;
    cout << "  Cavalos de potencia: " << x.horsepower << endl;
    cout << "  Peso do veiculo:     " << x.curb_weight << endl;
    cout << "|-----------------------------------------|" << endl;
}

bool superTrunfo::ETrunfo(carro a, carro b)
{
    switch(a.group == "1A" || b.group){
        case 
    }
    if (a.group == "1A" || b.group == "1A")
    {
        cout << "|------------------|" << endl;
        cout << "|      Trunfo!!    |" << endl;
        cout << "|------------------|" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void superTrunfo::JogadasDoJogo(superTrunfo &J1, superTrunfo &J2, carro &a, carro &b, bool &jogadas)
{
    int jogador_person;
    string convert;

    switch (jogadas)
    {
    case 0:
        cout << "|-----------------------------|" << endl;
        cout << "|  Jogador Person e sua VEZ!  |" << endl;
        cout << "|-----------------------------|" << endl;
        cin >> jogador_person;

        do
        {
            cout << "|----------------------------------------------------|" << endl;
            cout << "|  Erro! Tente novamente, insirindo uma nova carta!  |" << endl;
            cout << "|----------------------------------------------------|" << endl;
            cin >> jogador_person;
        } while (jogador_person != jogador_person || jogador_person < 0 || jogador_person > 3);
        jogadas = 1;

    case 1:
        cout << "|-------------------------------|" << endl;
        cout << "|  Jogador Machine, e sua vez!  |" << endl;
        cout << "|-------------------------------|" << endl;
        cin >> convert;

        int jogador_machine;
        jogador_machine = rand() % 3 + 1;
        jogadas = 0;
    }
}

void superTrunfo::RodadasDoJogoTrunfo(superTrunfo &J1, superTrunfo &J2, carro &a, carro &b, bool &jogadas)
{
    cout << "|----------------------------------------|" << endl;
    cout << "  Carta do Jogador Person: " << a.group << endl;
    cout << "  Carta do outro Jogador Machine: " << b.group << endl;
    cout << "|----------------------------------------|" << endl;

    if (a.group[1] == 'A')
    {
        if (b.group[1] == 'A')
        {
            cout << "|==============================|" << endl;
            cout << "|   Carta Perdedora: TRUNFO    |" << endl;
            cout << "|==============================|\n\n" << endl;
            cout << "|************************************************|" << endl;
            cout << "|     Vencedor da rodada é o Jogador Machine!    |" << endl;
            cout << "|************************************************|" << endl;

            J2.Append(a);
            J2.Append(b);
        }
        else
        {
            cout << "|*************************************************|" << endl;
            cout << "|   Carta TRUNFO do Jogador Person é a Campeao!!   | " << endl;
            cout << "|*************************************************|" << endl;
            J1.Append(b);
            J1.Append(a);
        }
    }
    else
    {
        if (a.group[1] == 'A')
        {
            cout << "|==============================|" << endl;
            cout << "|   Carta Perdedora: TRUNFO    |" << endl;
            cout << "|==============================|\n\n" << endl;
            cout << "|************************************************|" << endl;
            cout << "|     Vencedor da rodada é o Jogador Person!     |" << endl;
            cout << "|************************************************|" << endl;

            J1.Append(b);
            J1.Append(a);
        }
        else
        {
            cout << "|***************************************************|" << endl;
            cout << "|   Carta TRUNFO do Jogador Machine é a Campeao!!   | " << endl;
            cout << "|***************************************************|" << endl;
            J2.Append(a);
            J2.Append(b);
        }
    }
    if (jogadas == 0)
    {
        jogadas = 1;
    }
    else
    {
        jogadas = 0;
    }
}

void superTrunfo::Jogo(superTrunfo &J1, superTrunfo &J2)
{
    carro a, b;
    bool jogadas = rand() % 2;

    do
    {
        J1.Serve(a);
        J2.Serve(b);
        CartasDosJogadores(a);
        if (!ETrunfo(a, b))
        {
            JogadasDoJogo(J1, J2, a, b, jogadas);
        }
        else
        {
            RodadasDoJogoTrunfo(J1, J2, a, b, jogadas);
        }
        cout << "|----------------------------------------|" << endl;
        cout << "  Cartas do Jogador Person: " << J1.Size() << endl;
        cout << "|----------------------------------------|\n\n" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "  Cartas do Jogador Machine: " << J2.Size() << endl;
        cout << "|----------------------------------------|\n\n" << endl;

    } while (J1.Size() < LIMIT && J2.Size() < LIMIT);
}

bool superTrunfo::Empty()
{
    return (count == 0);
}

bool superTrunfo::Full()
{
    return (count == LIMIT);
}

void superTrunfo::Append(carro x)
{
    int i;
    if (Full())
    {
        cout << "Fila cheia!";
        abort();
    }
    count++;
    tail = (tail % LIMIT) + 1;
    carta[tail] = x;
}

void superTrunfo::Serve(carro &x)
{
    if (Empty())
    {
        cout << "Fila vazia sem cartas!";
        abort();
    }
    count = count - 1;
    x = carta[head];
    head = (head % LIMIT) + 1;
}

int superTrunfo::Size()
{
    return count;
}

void superTrunfo::Rear(carro &x)
{
    if (Empty())
    {
        cout << "Fila vazia";
        abort();
    }
    x = carta[tail];
}
