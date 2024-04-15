#include "Pilha.hpp"
#include <iostream>

using namespace Pilha;
//using namespace std;

int main() {
	pilha *p = new pilha(5);

	p->empilha(1);
	p->empilha(2);
	p->imprimePilha();
}