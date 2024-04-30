#include "Heap.h"
#include <iostream>
#include <iterator>
#include <iomanip>

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
	this->capacidadeAtual = capacidade;
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
		std::cout << "Heap vazio" << std::endl;
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


void printSpaces(int count) {
	for (int i = 0; i < count; ++i) {
		std::cout << " ";
	}
}

void heap::imprimeHeapArvore() {
	int n = this->capacidadeAtual;

	if (n == 0) {
		std::cout << "Heap is empty" << std::endl;
		return;
	}

	int levels = log2(n) + 1; // Calculate total levels in the tree
	int maxDigits = this->capacidadeVetor; // Maximum digits for proper spacing

	int levelNodes = 1;
	int printedNodes = 0;
	int level = 0;

	while (printedNodes < n) {
		int startIdx = printedNodes;
		int endIdx = std::min(printedNodes + levelNodes, n);
		printSpaces((1 << (levels - level)) - 1); // Calculate indentation

		for (int i = startIdx; i < endIdx; ++i) {
			// Print node value
			std::cout << std::setw(maxDigits) << this->heapVetor[i].prioridade;
			printSpaces((1 << (levels - level + 1)) - 1); // Space between nodes
		}

		std::cout << std::endl;
		levelNodes *= 2;
		printedNodes = endIdx;
		++level;
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
	if (filhoEsquerda(chave) > this->capacidadeAtual) {
		//tuple = std::make_tuple(this->heapVetor[chave], this->heapVetor[pai(chave)], tupla(), tupla());
		std::get<2>(tuple) = tupla();
	}
	if (filhoDireita(chave) > this->capacidadeAtual) {
		//tuple = std::make_tuple(this->heapVetor[chave], this->heapVetor[pai(chave)], this->heapVetor[filhoEsquerda(chave)], tupla());
		std::get<3>(tuple) = tupla();
	}
	return &tuple;
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
