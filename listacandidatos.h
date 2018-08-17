#ifndef LISTACANDIDATOS_H
#define LISTACANDIDATOS_H
#include "NoCandidato.h"

class ListaCandidatos
{
public:
    NoCandidato* head;

    ListaCandidatos();
    ListaCandidatos(string nomeDoArquivo);
    void adicioneComoHead(Candidato* c);
    bool estaVazia();
    int tamanho();
    string toString();
    bool remove(string nome, string sobrenome);
    void filtrarCandidatos(int nota);
    void concatena(ListaCandidatos* l);
};

#endif // LISTACANDIDATOS_H
