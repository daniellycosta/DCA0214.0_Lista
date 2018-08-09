#include "listacandidatos.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

ListaCandidatos::ListaCandidatos(){
    head = NULL;
}

ListaCandidatos::ListaCandidatos(string nomeDoArquivo){ //Não está funcionando
    ifstream fcin(nomeDoArquivo);
    string dados;
    ListaCandidatos* novaLista = new ListaCandidatos();

    getline(fcin,dados);
    while(getline(fcin,dados)){
      Candidato* novoCandidato = new Candidato(dados);
      novaLista->adicioneComoHead(novoCandidato);

    }

}

void ListaCandidatos::adicioneComoHead(Candidato* c){
    NoCandidato* novoNo = new NoCandidato(c,head);
    head = novoNo;
}

bool ListaCandidatos::estaVazia(){
    return head == NULL;
}

int ListaCandidatos::tamanho(){
    NoCandidato* aux;
    int cont = 0;

    if(head != NULL){
        aux = new NoCandidato(head->conteudo,head->next);
        while(aux->next != NULL){
            cont++;
            aux = aux->next;
        }
        if(aux->next == NULL && aux->conteudo != NULL){
            cont++;
        }
    }

    return cont;
}

string ListaCandidatos::toString(){
    NoCandidato* aux;
    string lista;

    if(head != NULL){
        aux = new NoCandidato(head->conteudo,head->next);
        lista = aux->toString();
    }else{
        lista = "0";
    }

    return lista;
}
