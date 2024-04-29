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
		~heap();
		void insere(tupla tupla);
		tupla extraiMax();
		void imprimeHeap();
		tupla busca(int chave, int i = 0);
		void heapify(int tamanhoVetor, int i);
		int pai(int i);
		int filhoEsquerda(int i);
		int filhoDireita(int i);
	};
}

