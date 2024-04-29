#include "Heap.h"
#include <iostream>
#include <tuple>
#include <Windows.h>

using namespace Heap;

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	tupla vetor[10] = { tupla(12, 5), tupla(17, 1), tupla(8, 12), tupla(2, 64), tupla(3, 33), tupla(1,55), tupla(5, 12), tupla(6, 88), tupla(4, 22), tupla(2, 38) };
	heap* filaPrioridade = new heap(vetor, 10);
	filaPrioridade->imprimeHeap();

	if (filaPrioridade->busca(9) == nullptr) {
		std::cout << "Não encontrado" << std::endl;
	}
	else {
		tupla t, p, e, d;
		auto busca = *filaPrioridade->busca(9);
		std::tie(t, p, e ,d) = busca;
		std::cout << t.prioridade << p.prioridade << e.prioridade << std::endl;
	}

}