#include <iostream>
#include "ListaEncadeada.hpp"

#pragma execution_character_set( "utf-8" )

using namespace std;
using namespace lista_encadeada;

no::no(int valor) {
    this->valor = valor;
    this->prox = NULL;
}

no::no(int valor, no* prox) {
    this->valor = valor;
    this->prox = prox;
}

void no::insere(int posicao, int valor) {
    // Insere no início (substituindo o valor do no raiz)
    no* novo = new no(valor);
    no* atual = this;
    for (int i = 0; i < posicao; i++) {
        if (atual->prox == NULL) {
            cout << "Posição inválida" << endl;
            return;
        }
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
}

void no::insereNoFim(int valor) {
    no* novo = new no(valor);
    no* atual = this;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

no* no::remove(int posicao) {
    no* atual = this;
    for (int i = 0; i < posicao; i++) {
        if (atual->prox == NULL) {
            cout << "Posição inválida" << endl;
            return NULL;
        }
        atual = atual->prox;
    }
    no* removido = atual->prox;
    atual->prox = atual->prox->prox;
    return removido;
}

no* no::removeDoFim() {
    no* atual = this;
    if (atual->prox == NULL) {
        cout << "Esvaziando lista" << endl;
        no* removido = atual;
        this->valor = NULL;
        return removido;
    }
    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }
    no* removido = atual->prox;
    atual->prox = NULL;
    return removido;
}

tuple<no*, int>no::buscaPorValor(int valor) {
    no* atual = this;
    int posicao = 1;
    while (atual->prox != NULL) {
        posicao++;
        if (atual->valor == valor) {
            return { atual, posicao };
        }
        atual = atual->prox;
    }
    cout << "Valor não encontrado" << endl;
    return { NULL, NULL };
}

tuple<no*, int> no::buscaPorPosicao(int posicao) {
    no* atual = this;
    for (int i = 0; i < posicao; i++) {
        if (atual->prox == NULL) {
            cout << "Elemento não encontrado na posição informada" << endl;
            return { NULL, NULL };
        }
        atual = atual->prox;
    }
    return { atual, posicao };
}

void no::imprimeLista() {
    no* atual = this;
    while (atual != NULL) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << endl;
}