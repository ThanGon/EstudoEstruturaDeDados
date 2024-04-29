#include <tuple>
#pragma once

namespace Heap {

	class tupla {
	public:
		int prioridade;
		int elemento;
		tupla(int prioridade, int elemento);
		tupla();
	};


	class heap
	{
	public:
		tupla* heapVetor;
		int capacidadeVetor, capacidadeAtual;
		heap(int capacidade);
		heap(tupla vetor[], int capacidade);
		~heap();
		void insere(tupla tupla);
		tupla extraiMax();
		void imprimeHeap();
		std::tuple<tupla, tupla, tupla, tupla>* busca(int chave);
		void heapify(int tamanhoVetor, int i);
		int pai(int i);
		int filhoEsquerda(int i);
		int filhoDireita(int i);
	};
}

