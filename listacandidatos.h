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
};

#endif // LISTACANDIDATOS_H
