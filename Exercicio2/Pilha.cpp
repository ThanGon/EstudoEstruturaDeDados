#include "Pilha.hpp"
#include <iostream>

#define underline "\033[4m"
#define no_underline "\033[24m"

using namespace Pilha;
using namespace std;

pilha::pilha(int capa) {
	this->capa = capa;
	this->topo = -1;
	this->pElementos = new float[capa];
	cout << "Pilha criada com capacidade para " << capa << " elementos" << endl;
}

void pilha::empilha(float elemento) {
	if (this->topo == this->capa - 1) {
		cout << "Pilha cheia" << endl;
		return;
	}
	this->topo++;
	this->pElementos[this->topo] = elemento;
}

float pilha::verTopo() {
	if (this->topo == -1) {
		cout << "Pilha vazia" << endl;
		return 0;
	}
	return this->pElementos[this->topo];
}

float pilha::desempilha() {
	if (this->topo == -1) {
		cout << "Pilha vazia" << endl;
		return 0;
	}
	float elemento = this->pElementos[this->topo];
	this->topo--;
	return elemento;
}

void pilha::imprimePilha() {
	if (this->topo == -1) {
		cout << "Pilha vazia" << endl;
		return;
	}
	cout << underline << endl;
	for(int i = this->topo; i >= 0; i--) {
		cout << "  " << this->pElementos[i] << "  \r\n";
	}
	cout << no_underline <<  endl;
}