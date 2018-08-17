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
//            if(cont >=1){

//            }
            anterior = aux;
            aux = aux->next;
            cont++;
        }

        if(aux == head && aux->conteudo->igual(nome,sobrenome) ){ //Lista com + um elemento e o primeiro é o procurado

            head = aux->next;
            delete aux;
            delete anterior;
            return true;
        }
        else if(anterior==NULL && aux->conteudo->igual(nome,sobrenome)){ //só um elemento e ele é o procurado

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
            return true;
        }

    } else {
//        delete aux;
//        delete anterior;
        return false;
    }


}


void ListaCandidatos::filtrarCandidatos(int nota)
{
    if(this->estaVazia() == false){
        NoCandidato *aux;
        aux = head;

//        if (aux->next == NULL && aux->conteudo != NULL && aux->conteudo->nota < nota ){
//            this->remove(aux->conteudo->nome, aux->conteudo->sobrenome);

//        } else {
            while(aux != NULL){
                if(aux->conteudo->nota < nota){
                    NoCandidato *temp;
                    temp = aux;
                    aux = aux->next;
                    this->remove(temp->conteudo->nome, temp->conteudo->sobrenome);
                    //delete temp;
                } else {
                    aux = aux->next;
                }
            }

//        }
    }
}

void ListaCandidatos::concatena(ListaCandidatos *l)
{
    NoCandidato *aux;
    aux = head;
    if(head != NULL){
        while(aux->next!=NULL){
            aux = aux->next;
        }
        aux->next = l->head;
    }

}

