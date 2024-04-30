#include <tuple>
#pragma once

namespace Heap {

	class nodo {
	public:
		int prioridade;
		int elemento;
		nodo(int prioridade, int elemento);
		nodo();
	};


	class heap
	{
	public:
		nodo* heapVetor;
		int capacidadeVetor, capacidadeAtual;
		heap(int capacidade);
		heap(nodo vetor[], int capacidade);
		~heap();
		void insere(nodo tupla);
		nodo extraiMax();
		void imprimeHeap();
		void imprimeHeapArvore();
		std::tuple<nodo, nodo, nodo, nodo>* busca(int chave);
		void heapify(int tamanhoVetor, int i);
		int pai(int i);
		int filhoEsquerda(int i);
		int filhoDireita(int i);
	};
}

