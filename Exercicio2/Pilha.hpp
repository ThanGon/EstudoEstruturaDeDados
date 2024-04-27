namespace Pilha {
	class pilha {
	public:
		int topo;
		int capa;
		float *pElementos;

		pilha(int capa);

		void empilha(float elemento);

		float verTopo();

		float desempilha();

		void imprimePilha();
	};
}