#include "Heap.h"
#include <iostream>

using namespace Heap;

tupla::tupla(int prioridade, int elemento) {
	this->prioridade = prioridade;
	this->elemento = elemento;
}

tupla::tupla() {
	this->prioridade = 0;
	this->elemento = 0;
}

heap::heap(int capacidade) {
	this->heapVetor = new tupla[capacidade];
	this->capacidadeVetor = capacidade;
	this->capacidadeAtual = 0;
}

int heap::pai(int i) {
	return (i - 1) / 2;
}

int heap::filhoEsquerda(int i) {
	return (2 * i) + 1;
}

int heap::filhoDireita(int i) {
	return (2 * i) + 2;
}

void heap::insere(tupla tupla) {
	if (this->capacidadeAtual + 1 > capacidadeVetor ) {
		std::cout << "Heap cheio" << std::endl;
		return;
	}
	this->heapVetor[capacidadeAtual] = tupla;
	this->capacidadeAtual++;
	int i = this->capacidadeAtual - 1;
	while (i > 0 && this->heapVetor[pai(i)].prioridade < this->heapVetor[i].prioridade) {
		Heap::tupla temp = this->heapVetor[pai(i)];
		this->heapVetor[pai(i)] = this->heapVetor[i];
		this->heapVetor[i] = temp;
		i = pai(i);
	}
}

tupla heap::extraiMax() {
	if (this->capacidadeAtual < 1) {
		return tupla();
	}
	else {
		// PENSAR NOS PONTEIROS
		tupla max = this->heapVetor[0];
		this->heapVetor[0] = this->heapVetor[this->capacidadeAtual - 1];
		this->capacidadeAtual--;
		heapify(this->capacidadeAtual, 0);
		return max;
	}
}

void heap::imprimeHeap() {

}

tupla heap::busca(int chave) {
	
	// preguica 
	// importante dar uma olhada depois
	return tupla();
}

void heap::heapify(int tamanhoVetor, int i) {
	int esq = filhoEsquerda(i);
	int dir = filhoDireita(i);
	int maior = i;

	if (esq < tamanhoVetor && this->heapVetor[esq].prioridade > this->heapVetor[i].prioridade) {
		maior = esq;
	}
	if (dir < tamanhoVetor && this->heapVetor[dir].prioridade > this->heapVetor[maior].prioridade) {
		maior = dir;
	}
	if (maior != i) {
		tupla temp = this->heapVetor[i];
		this->heapVetor[i] = this->heapVetor[maior];
		this->heapVetor[maior] = temp;
		heapify(tamanhoVetor, maior);
	}
}

heap::~heap() {
	delete[] this->heapVetor;
}
