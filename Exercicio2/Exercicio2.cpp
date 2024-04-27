#include "Pilha.hpp"
#include <iostream>
#include <Windows.h>

#pragma execution_character_set( "utf-8" )

using namespace Pilha;
using namespace std;


int main() {
	SetConsoleOutputCP(CP_UTF8);
	cout << "Insira a capacidade máxima da pilha" << endl;
	int capa;
	cin >> capa;
	pilha* p = new pilha(capa);

	while (true) {
		cout << "1 - Empilhar" << endl;
		cout << "2 - Desempilhar" << endl;
		cout << "3 - Ver topo" << endl;
		cout << "4 - Imprimir pilha" << endl;
		cout << "0 - Sair" << endl;

		int opcao;
		float elemento;
		cin >> opcao;

		switch (opcao) {
		case 1:
			cout << "Insira o elemento para empilhar" << endl;
			cin >> elemento;
			p->empilha(elemento);
			break;
		case 2:
			cout << "Elemento desempilhado: " << p->desempilha() << endl;
			break;
		case 3:
			cout << "Topo: " << p->verTopo() << endl;
			break;
		case 4:
			p->imprimePilha();
			break;
		case 0:
			return 0;
		default:
			cout << "Opção inválida" << endl;
		}

	}

	return 0;
}