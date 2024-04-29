#include "Heap.h"
#include <iostream>

using namespace Heap;

int main()
{
	heap* filaPrioridade = new heap(10);
	filaPrioridade->insere(tupla(13, 1));
	filaPrioridade->insere(tupla(22, 120));
	filaPrioridade->insere(tupla(32, 125));
	filaPrioridade->insere(tupla(52, 128));
	filaPrioridade->insere(tupla(14, 122));
	filaPrioridade->insere(tupla(18, 122));
	filaPrioridade->insere(tupla(78, 122));
	std::cout << filaPrioridade->busca(13).prioridade << ":" <<filaPrioridade->busca(13).elemento << std::endl;
	std::cout << filaPrioridade->extraiMax().prioridade << std::endl;

}