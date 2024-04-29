#include "Heap.h"
#include <iostream>
#include <iterator>

#pragma execution_character_set( "utf-8" )

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
// EQUIVALENTE A CONSTROIHEAP (CONSTRUTOR DE HEAP)
heap::heap(tupla vetor[], int capacidade) {
	this->heapVetor = vetor;
	this->capacidadeVetor = capacidade;
	this->capacidadeAtual = capacidade - 1;
	for (int i = capacidade / 2; i >= 0; i--) {
		heapify(capacidade, i);
	}
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
	if (this->capacidadeAtual + 1 > capacidadeVetor) {
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
	for (int i = 0; i < this->capacidadeAtual; i++) {
		std::cout << "Índice: " << i << "\t" << "Prioridade: " << this->heapVetor[i].prioridade << " :: " << "Elemento: " << this->heapVetor[i].elemento << std::endl;
	}
}

//tupla heap::busca(int chave, int i) {
//	if (this->heapVetor[i].prioridade < chave) {
//		return tupla();
//	}
//	if (this->heapVetor[i].prioridade == chave) {
//		return this->heapVetor[i];
//	}
//	else {
//		tupla esq = busca(chave, filhoEsquerda(i));
//		tupla dir = busca(chave, filhoDireita(i));
//		if (esq.prioridade != 0) {
//			return esq;
//		} 
//		else {
//			return dir;
//		}
//	}
//}

// NO, PAI, ESQUERDA, DIREITA
std::tuple<tupla, tupla, tupla, tupla>* heap::busca(int chave) {
	if (chave > this->capacidadeAtual || chave < 0) {
		return nullptr;
	}
	std::tuple<tupla, tupla, tupla, tupla> tuple;
	tuple = std::make_tuple(this->heapVetor[chave], this->heapVetor[pai(chave)], this->heapVetor[filhoEsquerda(chave)], this->heapVetor[filhoDireita(chave)]);
	return &tuple;
}

void heap::heapify(int tamanhoVetor, int i) {
	// HEAPIFY PARECE FALTAR DELETAR RESQUICIOS DE PONTEIROS
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
