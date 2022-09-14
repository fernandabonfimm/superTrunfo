// Acesse o README do projeto, para mais informações.
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <string>
#include <locale.h> 
#define LIMIT 32
using namespace std;
#ifndef SUPERTRUNFO_H
#define SUPERTRUNFO_H

/*
Organização do Código:
O trabalho foi dividido em 3 arquivos principais: superTrunfo.cpp e superTrunfo.h fazem a implementação do TAD e no arquivo main.cpp implementa o programa principal.
Para simplificar a execução do trabalho decidimos dividi-lo em mais operações além das necessárias para gerar a estrutura da fila circular. Como a operação para embaralhar, fazer as jogadas dos jogadores, rodada trunfo, comparação das cartas, mostrar a carta na tela para o usuário e a operação Jogo() que traz todas as outras funções dentro dele, facilitando sua chamada no programa principal.
*/

struct carro
{
    string model;
    string curb_weight;
    string engine_size;
    string horsepower;
    string price;
    string group;
};

typedef carro carro;

class superTrunfo
{
public:
    superTrunfo();
    void Read(carro lista[]);
    void Rear(carro &x);
    void Embaralhar(carro definicao[], superTrunfo &J1, superTrunfo &J2);
    void Serve(carro &x);
    void CartasDosJogadores(carro x);
    void Clear();
    void JogadasDoJogo(superTrunfo &J1, superTrunfo &J2, carro &a, carro &b, bool &jogadas);
    void RodadasDoJogoTrunfo(superTrunfo &J1, superTrunfo &J2, carro &a, carro &b, bool &jogadas);
    void Jogo(superTrunfo &J1, superTrunfo &J2);
    void Append(carro x);
    bool ComparacaoDeCartas(superTrunfo &J1, superTrunfo &J2, carro &a, carro &b, int escolha);
    bool Empty();
    bool Full();
    bool ETrunfo(carro a, carro b);
    int Size();

private:
    int count;
    int head, tail;
    carro carta[LIMIT + 1];
};
#endif