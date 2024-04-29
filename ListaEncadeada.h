#include <tuple>

namespace ListaEncadeada {
    class no {
    public:
        no(int valor);

        no(int valor, no* prox);

        int valor;
        no* prox;

        void insere(int posicao, int valor);

        void insereNoFim(int valor);

        no* remove(int posicao);

        no* removeDoFim();

        std::tuple<no*, int>buscaPorValor(int valor);

        std::tuple<no*, int> buscaPorPosicao(int posicao);

        void imprimeLista();
    };
}