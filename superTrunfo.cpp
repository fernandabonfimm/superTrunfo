// Acesse o README do projeto, para mais informações.

#include "superTrunfo.h"
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

    for (int i = 0; i < 16; i++)
    {
        J1.Append(lista[i]);
    }

    for (int i = 16; i < 32; i++)
    {
        J2.Append(lista[i]);
    }
}

void superTrunfo::CartasDosJogadores(carro x)
{
    cout << "|-----------------------------------------|" << endl;
    cout << "  Grupo da carta:      " << x.group << endl;
    cout << "  Modelo da carta:     " << x.model << endl;
    cout << "  1 - Peso do veiculo:     " << x.curb_weight << endl;
    cout << "  2 - Preço da carta:      " << x.price << endl;
    cout << "  3 - Tamanho do Motor:    " << x.engine_size << endl;
    cout << "  4 - Cavalos de potencia: " << x.horsepower << endl;
    cout << "|-----------------------------------------|\n\n"
         << endl;
    cout << "|-----------------------------------------|" << endl;
    cout << "|       Escolha um valor de 1 a 4         |" << endl;
    cout << "|-----------------------------------------|\n\n"
         << endl;
}

bool superTrunfo::ETrunfo(carro a, carro b)
{
    if (a.group == "1A" || b.group == "1A")
    {
        cout << "|------------------|" << endl;
        cout << "|      Trunfo!!    |" << endl;
        cout << "|------------------|\n\n"
             << endl;
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
        cout << "|-----------------------------|\n\n"
             << endl;
        cin >> jogador_person;

        while (jogador_person != (int)jogador_person || jogador_person < 1 || jogador_person > 4)
        {
            cout << "|----------------------------------------------------|" << endl;
            cout << "|  Erro! Tente novamente, insirindo uma nova carta!  |" << endl;
            cout << "|----------------------------------------------------|\n\n"
                 << endl;
            cin >> jogador_person;
        }
        if (ComparacaoDeCartas(J1, J2, a, b, jogador_person))
        {
            cout << "|------------------------------------------------|" << endl;
            cout << "|      Ganhador da Rodada: Jogador Person!       |" << endl;
            cout << "|------------------------------------------------|\n\n"
                 << endl;
            J1.Append(a);
            J1.Append(b);
        }
        else
        {
            cout << "|------------------------------------------------|" << endl;
            cout << "|     Ganhador da Rodada: Jogador Machine!       |" << endl;
            cout << "|------------------------------------------------|\n\n"
                 << endl;
            J2.Append(b);
            J2.Append(a);
        }
        jogadas = 1;
        break;
    case 1:
        cout << "|-------------------------------------------------------------|" << endl;
        cout << "|  Jogador Machine jogou sua carta!                           |" << endl;
        cout << "|  Jogador Person, digite algum numero para continuar o jogo! |" << endl;
        cout << "|-------------------------------------------------------------|\n\n"
             << endl;
        cin >> jogador_person;

        int jogador_machine;
        jogador_machine = rand() % 2 + 1;
        if (ComparacaoDeCartas(J2, J1, b, a, jogador_machine))
        {
            cout << "|************************************************|" << endl;
            cout << "|     Vencedor da rodada é o Jogador Machine!    |" << endl;
            cout << "|************************************************|\n\n"
                 << endl;
            J2.Append(a);
            J2.Append(b);
        }
        else
        {
            cout << "|************************************************|" << endl;
            cout << "|     Vencedor da rodada é o Jogador Person!     |" << endl;
            cout << "|************************************************|\n\n"
                 << endl;
            J1.Append(b);
            J1.Append(a);
        }
        jogadas = 0;
        break;
    }
}

void superTrunfo::RodadasDoJogoTrunfo(superTrunfo &J1, superTrunfo &J2, carro &a, carro &b, bool &jogadas)
{
    cout << "|----------------------------------------|" << endl;
    cout << "  Carta do Jogador Person: " << a.group << endl;
    cout << "  Carta do outro Jogador Machine: " << b.group << endl;
    cout << "|----------------------------------------|\n\n"
         << endl;

    if (a.group[1] == 'A')
    {
        if (b.group[1] == 'A')
        {
            cout << "|==============================|" << endl;
            cout << "|   Carta Perdedora: TRUNFO    |" << endl;
            cout << "|==============================|\n\n"
                 << endl;
            cout << "|************************************************|" << endl;
            cout << "|     Vencedor da rodada é o Jogador Machine!    |" << endl;
            cout << "|************************************************|\n\n"
                 << endl;

            J2.Append(a);
            J2.Append(b);
        }
        else
        {
            cout << "|*************************************************|" << endl;
            cout << "|   Carta TRUNFO do Jogador Person é a Campeao!!  | " << endl;
            cout << "|*************************************************|\n\n"
                 << endl;
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
            cout << "|==============================|\n\n"
                 << endl;
            cout << "|************************************************|" << endl;
            cout << "|     Vencedor da rodada é o Jogador Person!     |" << endl;
            cout << "|************************************************|\n\n"
                 << endl;

            J1.Append(a);
            J1.Append(b);
        }
        else
        {
            cout << "|***************************************************|" << endl;
            cout << "|   Carta TRUNFO do Jogador Machine é a Campeao!!   | " << endl;
            cout << "|***************************************************|\n\n"
                 << endl;
            J2.Append(b);
            J2.Append(a);
        }
    }
    
    jogadas  == 0 ? jogadas = 1 : jogadas = 0; 
}

bool superTrunfo::ComparacaoDeCartas(superTrunfo &J1, superTrunfo &J2, carro &a, carro &b, int escolha)
{
    switch (escolha)
    {
    case 1:
        return (a.curb_weight > b.curb_weight) ? true : false;
        break;
    case 2:
        return (a.price > b.price) ? true : false;
        break;
    case 3:
        return (a.engine_size > b.engine_size) ? true : false;
        break;
    case 4:
        return (a.horsepower > b.horsepower) ? true : false;
        break;
    }

    return false;
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
        cout << "|----------------------------------------|\n\n"
             << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "  Cartas do Jogador Machine: " << J2.Size() << endl;
        cout << "|----------------------------------------|\n\n"
             << endl;

    } while (J1.Size() < LIMIT && J2.Size() < LIMIT);
    if (J1.Size() == LIMIT)
    {
        cout << "|************************************************|" << endl;
        cout << "|     Vencedor da rodada é o Jogador Person!     |" << endl;
        cout << "|************************************************|\n\n"
             << endl;
        cout << J1.Size() << endl;
        for (int i = 1; i < LIMIT; i++)
        {
            J1.Serve(a);
            cout << a.model << endl;
        }
    }
    else
    {
        cout << "|*************************************************|" << endl;
        cout << "|     Vencedor da rodada é o Jogador MAchine!     |" << endl;
        cout << "|*************************************************|\n\n"
             << endl;
        cout << J2.Size() << endl;
        for (int i = 1; i < LIMIT; i++)
        {
            J2.Serve(a);
            cout << a.model << endl;
        }
    }
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
    count--;
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
