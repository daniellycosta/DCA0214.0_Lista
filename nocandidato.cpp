#include "nocandidato.h"

NoCandidato::NoCandidato(Candidato* _conteudo, NoCandidato* _next){
    conteudo = _conteudo;
    next = _next;
}

string NoCandidato::toString(){
    stringstream stream;
    stream << conteudo->toString() << " -> " << next->conteudo->toString();
    if(next->conteudo== NULL){
        stream << "0";
    }
    return stream.str();


}
