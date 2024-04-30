#include "Heap.h"
#include <iostream>
#include <tuple>
#include <Windows.h>
#include <random>


#pragma execution_character_set( "utf-8" )

// DEFINE SEED ALEATORIO PARA INSERCAO DE ELEMENTOS
#define START_SEED() std::random_device rd; std::mt19937 gen(rd()); std::uniform_int_distribution<> distrib(1, 120);
#define RANDOMIZE()	distrib(gen)

constexpr int MAX_CAPACITY = 10;

using namespace Heap;

int main()
{
	START_SEED();
	SetConsoleOutputCP(CP_UTF8);

	tupla vetor[MAX_CAPACITY] = { tupla(12, RANDOMIZE()), tupla(17, RANDOMIZE()), tupla(8, RANDOMIZE()), tupla(2, RANDOMIZE()), tupla(3, RANDOMIZE()), tupla(1, RANDOMIZE() ), tupla(5, RANDOMIZE()), tupla(6, RANDOMIZE()), tupla(4, RANDOMIZE()), tupla(2, RANDOMIZE()) };
	heap* filaPrioridade = new heap(vetor, MAX_CAPACITY);

	while (true) {
		std::cout << "1 - Inserir" << std::endl;
		std::cout << "2 - Extrair Maximo" << std::endl;
		std::cout << "3 - Buscar" << std::endl;
		std::cout << "4 - Imprimir" << std::endl;
		std::cout << "5 - Imprimir (arvore)" << std::endl;
		std::cout << "6 - Corrige Heap" << std::endl;
		std::cout << "0 - Sair" << std::endl;

		int opcao;
		int prioridade, chave;
		std::tuple<tupla, tupla, tupla, tupla>* busca;
		std::cin >> opcao;

		switch (opcao) {
		case 1:
			std::cout << "Insira a prioridade do novo elemento (gerado aleatoriamente)" << std::endl;
			std::cin >> prioridade;
			filaPrioridade->insere(tupla(prioridade, RANDOMIZE()));
			break;
		case 2: {
			tupla max = filaPrioridade->extraiMax();
			std::cout << "Elemento removido: " << max.elemento << " com prioridade máxima: " << max.prioridade << std::endl;
			break;
		}
		case 3:
			std::cout << "Insira a chave (indice) para busca" << std::endl;
			std::cin >> chave;
			busca = filaPrioridade->busca(chave);
			if (busca == nullptr) {
				std::cout << "Não encontrado" << std::endl;
			}
			else {
				tupla t, p, e, d;
				std::tie(t, p, e, d) = *busca;
				std::cout << "Elemento encontrado: " << t.elemento << " com Prioridade: " << t.prioridade << std::endl;
				std::cout << "Pai com prioridade: " << p.prioridade << std::endl;
				if (e.prioridade > 0) 
					std::cout << "Filho esquerdo com prioridade: " << e.prioridade << std::endl;
				if (d.prioridade > 0) 
					std::cout << "Filho direito com prioridade: " << d.prioridade << std::endl;
			}
			break;
		case 4:
			filaPrioridade->imprimeHeap();
			break;
		case 5:
			filaPrioridade->imprimeHeapArvore();
			break;
		case 6:
			filaPrioridade = new heap(filaPrioridade->heapVetor, filaPrioridade->capacidadeAtual);
			break;
		case 0:
			return 0;
		default:
			std::cout << "Opção inválida" << std::endl;
		}
	}

	/*filaPrioridade->imprimeHeap();

	if (filaPrioridade->busca(9) == nullptr) {
		std::cout << "Não encontrado" << std::endl;
	}
	else {
		tupla t, p, e, d;
		std::tie(t, p, e ,d) = *filaPrioridade->busca(9);
		std::cout << t.prioridade << p.prioridade << std::endl;
	}*/

}