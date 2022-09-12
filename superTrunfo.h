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