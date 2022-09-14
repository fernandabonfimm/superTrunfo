// Responsáveis: Fernanda Bonfim Santos - Cod: 2069922, Barbara Diogo - Cod: 2063853
// Acesse o README do projeto, para mais informações.

#include "superTrunfo.h"
using namespace std;

//O programa principal traz o vetor com o tamanho limite de cartas, lê e embaralha todo o baralho e por fim chama o método Jogo(J1, J2), pois nele todas as outras funções estão contidas e serão chamadas dentro dele.
int main()
{
     setlocale(LC_ALL, "Portuguese");
     superTrunfo p, J1, J2;
     carro lista[LIMIT];
     p.Read(lista);
     p.Embaralhar(lista, J1, J2);

     cout << "\n\n|****************************************************|" << endl;
     cout << "| Bem-Vindo ao SuperTrunfo da Fernanda e da Barbara! |" << endl;
     cout << "|****************************************************|\n\n"
          << endl;

     cout << "|----------------------------------------------------------------|" << endl;
     cout << "| Chamaremos aqui, o usuario atras da maquina de: Jogador Person |" << endl;
     cout << "| Chamaremos aqui, a maquina de: Jogador Machine                 |" << endl;
     cout << "|----------------------------------------------------------------|\n\n"
          << endl;
     p.Jogo(J1, J2);

     return 0;
}
