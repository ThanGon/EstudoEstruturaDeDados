#include <iostream>
#include "ListaEncadeada.h"

#pragma execution_character_set( "utf-8" )

using namespace std;
using namespace ListaEncadeada;

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
        this->valor = NULL;
        return nullptr;
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
    int posicao = 0;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return { atual, posicao };
        }
        posicao++;
        atual = atual->prox;
    }
    cout << "Valor não encontrado" << endl;
    return { nullptr, NULL };
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