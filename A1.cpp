#include "ListaEncadeada.hpp"
#include <iostream>
#include <Windows.h>

#pragma execution_character_set( "utf-8" )

using namespace std;
using namespace lista_encadeada;
int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Insira o primeiro valor para iniciar a lista encadeada" << endl;

    int valor;
    cin >> valor;

    no* lista = new no(valor);

    while (true) {
        if (lista->valor == NULL)
            return main();

        cout << "1 - Inserir em uma posição específica (0 para inserir no fim)" << endl;
        cout << "2 - Remover de uma posição específica (0 para remover do fim)" << endl;
        cout << "3 - Buscar elemento com valor específico" << endl;
        cout << "4 - Buscar elemento em posição específica" << endl;
        cout << "5 - Imprimir lista" << endl;
        cout << "0 - Sair" << endl;

        int opcao;
        int posicao;
        tuple<no*, int> busca;
        no* removido;
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Insira a posição e o valor para inserção (0 para inserir no fim)" << endl;
            cin >> posicao >> valor;
            posicao > 0 ? lista->insere(posicao, valor) : lista->insereNoFim(valor);
            break;
        case 2:
            cout << "Insira a posição para remoção (0 para inserir no fim)" << endl;
            cin >> posicao;
            removido = posicao > 0 ? lista->remove(posicao) : lista->removeDoFim();
            cout << "Elemento removido: " << removido->valor << endl;
            break;
        case 3:
            cout << "Insira o valor para busca" << endl;
            cin >> valor;
            busca = lista->buscaPorValor(valor);
            if (get<1>(busca) != NULL)
                cout << "Elemento na lista de valor: " << get<0>(busca)->valor << " na posição: " << get<1>(busca) << endl;
            break;
        case 4:
            cout << "Insira a posição para busca" << endl;
            cin >> valor;
            busca = lista->buscaPorPosicao(valor);
            if (get<1>(busca) != NULL)
                cout << "Elemento na lista de valor: " << get<0>(busca)->valor << " na posição: " << get<1>(busca) << endl;
            break;
        case 5:
            lista->imprimeLista();
            break;
        case 0:
            return 0;
        default:
            cout << "Opção inválida" << endl;
            break;
        }
    }
    return 0;
}