#include "Heap.h"
#include <iostream>

using namespace Heap;

int main()
{
	heap* filaPrioridade = new heap(10);
	filaPrioridade->insere(tupla(3, 1));
	filaPrioridade->insere(tupla(2, 120));
	filaPrioridade->insere(tupla(2, 125));
	filaPrioridade->insere(tupla(2, 128));
	filaPrioridade->insere(tupla(4, 122));
	std::cout << filaPrioridade->extraiMax().prioridade;

}