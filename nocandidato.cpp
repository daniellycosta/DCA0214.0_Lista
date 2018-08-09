#include "nocandidato.h"

NoCandidato::NoCandidato(Candidato* _conteudo, NoCandidato* _next){
    conteudo = _conteudo;
    next = _next;
}

string NoCandidato::toString(){
    stringstream stream;
    NoCandidato* candidatoAtual;
    candidatoAtual = new NoCandidato(conteudo,next);

    while(candidatoAtual->next!= NULL){
        stream << candidatoAtual->conteudo->toString() << " -> ";

        candidatoAtual->conteudo = candidatoAtual->next->conteudo;
        candidatoAtual->next = candidatoAtual->next->next;

    }
    //Para quando a lista só tiver com 1 elemento
    if(candidatoAtual->next == NULL && candidatoAtual->conteudo != NULL){
        stream << candidatoAtual->conteudo->toString() << " -> ";
    }
    stream << "0";
    return stream.str();
}
