#include "listacandidatos.h"
#include "candidato.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

ListaCandidatos::ListaCandidatos(){
    head = NULL;
}

ListaCandidatos::ListaCandidatos(string nomeDoArquivo){
    head = NULL;

    ifstream fcin(nomeDoArquivo);
    string dados;

    getline(fcin,dados);
    while(getline(fcin,dados)){
        Candidato* novoCandidato = new Candidato(dados);
        this->adicioneComoHead(novoCandidato);
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
        aux = head;
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

bool ListaCandidatos::remove(string nome, string sobrenome)
{
    NoCandidato* aux = head;
    NoCandidato* anterior = NULL;
    int cont = 0;

    if(head != NULL){

        while(aux->next != NULL && !(aux->conteudo->igual(nome,sobrenome))){
            if(cont >=1){
                anterior = aux;
            }

            aux = aux->next;
            cont++;
        }

        if(aux == head && aux->conteudo->igual(nome,sobrenome) ){ //Lista com + um elemento e o primeiro é o procurado
            head = aux->next;
            delete aux;
            delete anterior;
            return true;
        }else if(anterior==NULL && aux->conteudo->igual(nome,sobrenome)){ //só um elemento e ele é o procurado
            head = NULL;
            delete aux;
            delete anterior;
            return true;
        }
        else if(anterior==NULL && !(aux->conteudo->igual(nome,sobrenome))){ //só um elemento e ele não é o procurado
            return false;
        }
        else{
            anterior->next = aux->next;
            delete aux;
            //delete anterior;
            return true;
        }

    } else {
        delete aux;
        delete anterior;
        return false;
    }


}

void ListaCandidatos::filtrarCandidatos(int nota){//nao esta funcionando

    //Candidato *c;

    while(head!=NULL){
        if(head->conteudo->maiorigualnota(nota)){
      //      c = head->conteudo;
        //    adicioneComoHead(c);
            head = head->next;

        }else{
            remove(head->conteudo->nome,head->conteudo->sobrenome);
        }
    }


}



