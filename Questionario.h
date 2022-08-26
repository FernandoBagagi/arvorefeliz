#ifndef QUESTIONARIO_H
#define QUESTIONARIO_H

#include "Cor.h"
#include "Questao.h"

class Questionario
{
	public:
		Questionario();
		void desenha();
		void subirCursor();
		void descerCursor();
		int proximaQuestao();
		void selecionarAlternativa(int);
		void addQuestao(Questao,int);
		bool inicio = true;
	private:
		int numeroQuestao = 0;
		int pontuacao = 0;
		int errosConsecutivos = 0;
		bool fim = false;
		int alternativaSelecionada = 0;
		Cor corTexto = Cor(0.0f,0.0f,0.0f);
		Cor corSelecionado = Cor(1.0f,0.0f,1.0f);
		Questao questoes[7];
};

#endif
