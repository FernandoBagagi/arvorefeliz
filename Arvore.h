#ifndef ARVORE_H
#define ARVORE_H

#include "Cor.h"
#include <string>
class Arvore
{
	public:
		Arvore();
		void crescer();
		void morrer();
		void desenha();
		static Cor cores[8][2];
		static std::string nome;
		static std::string info;
	private:
		int fase = 0;
		int errosConsecutivos = 0;
		void desenharQuadrado();
		void desenharFolha(GLfloat, GLfloat, GLfloat, GLfloat, int);
		void desenharCaule(GLfloat, GLfloat, GLfloat, GLfloat);
};

#endif
