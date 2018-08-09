#ifndef NOCANDIDATO_H
#define NOCANDIDATO_H

#include <Candidato.h>

class NoCandidato
{
public:
    Candidato* conteudo;
    NoCandidato* next;

    NoCandidato(Candidato* conteudo, NoCandidato *next);
    string toString();
};

#endif // NOCANDIDATO_H
