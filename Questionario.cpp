#include "Cor.h"
#include "Questionario.h"
#include <sstream>

Questionario::Questionario()
{
}

int Questionario::proximaQuestao()
{
	if (numeroQuestao < 7)
	{
		numeroQuestao++;
		if (alternativaSelecionada == 0)
		{
			pontuacao++;
			errosConsecutivos = 0;
			return 1;
		}
		else if (alternativaSelecionada == 1)
		{
			return 0;
		}
		else
		{
			errosConsecutivos++;
			if (pontuacao > 0)
			{
				pontuacao--;
			}
			return -1;
		}
	}
	return 0;
}

void Questionario::desenha()
{
	int posX = 4, posY = 4;
	if (inicio)
	{
		std::string texto = "Questionario sobre o meio ambiente";
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY);
		for (int i = 0; i < texto.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto.at(i));
		}
		glutSwapBuffers();

		texto = "Ao acertar as questoes a arvore vai crescer!";
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY - 4);
		for (int i = 0; i < texto.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto.at(i));
		}
		glutSwapBuffers();

		texto = "Porem se vc errar ela comecara a morrer :'(";
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY - 6);
		for (int i = 0; i < texto.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto.at(i));
		}
		glutSwapBuffers();

		texto = "Para comecar aperte insert";
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY - 9);
		for (int i = 0; i < texto.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto.at(i));
		}
		glutSwapBuffers();
	}
	else if (numeroQuestao < 7 && errosConsecutivos < 3)
	{
		glLoadIdentity();
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY);
		for (int i = 0; i < questoes[numeroQuestao].enunciado.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, questoes[numeroQuestao].enunciado.at(i));
		}
		glutSwapBuffers();

		Cor::setarCor(alternativaSelecionada == 0 ? corSelecionado : corTexto);
		glRasterPos2f(posX, posY - 4);
		for (int i = 0; i < questoes[numeroQuestao].alternativaCorreta.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, questoes[numeroQuestao].alternativaCorreta.at(i));
		}
		glutSwapBuffers();

		Cor::setarCor(alternativaSelecionada == 1 ? corSelecionado : corTexto);
		glRasterPos2f(posX, posY - 8);
		for (int i = 0; i < questoes[numeroQuestao].alternativaNeutra.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, questoes[numeroQuestao].alternativaNeutra.at(i));
		}
		glutSwapBuffers();

		Cor::setarCor(alternativaSelecionada == 2 ? corSelecionado : corTexto);
		glRasterPos2f(posX, posY - 12);
		for (int i = 0; i < questoes[numeroQuestao].alternativaErrada.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, questoes[numeroQuestao].alternativaErrada.at(i));
		}
		glutSwapBuffers();

		const std::string textoConfirmacao = "Confirmar (ENTER)";
		Cor::setarCor(corTexto);
		glRasterPos2f(posX + 6, posY - 16);
		for (int i = 0; i < textoConfirmacao.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, textoConfirmacao.at(i));
		}
		glutSwapBuffers();
	}
	else if (errosConsecutivos >= 3)
	{
		const std::string texto = "Voce matou a arvore.";
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY);
		for (int i = 0; i < texto.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto.at(i));
		}
		glutSwapBuffers();

		const std::string texto1 = "Reveja seus conceitos sobre meio ambiente.";
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY - 4);
		for (int i = 0; i < texto1.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto1.at(i));
		}
		glutSwapBuffers();

		const std::string texto2 = "Pontuacao: 0";
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY - 6);
		for (int i = 0; i < texto2.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto2.at(i));
		}
		glutSwapBuffers();
	}
	else
	{
		if (pontuacao > 4)
		{
			std::string texto4 = "Parabens!!";
			Cor::setarCor(corTexto);
			glRasterPos2f(posX, posY - 2);
			for (int i = 0; i < texto4.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto4.at(i));
			}
			glutSwapBuffers();
		}
		std::ostringstream aux;
		aux << pontuacao;
		std::string texto2 = "Pontuacao: " + aux.str();
		Cor::setarCor(corTexto);
		glRasterPos2f(posX, posY - 6);
		for (int i = 0; i < texto2.length(); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto2.at(i));
		}
		glutSwapBuffers();
	}
}

void Questionario::subirCursor()
{
	if (alternativaSelecionada == 0)
	{
		alternativaSelecionada = 2;
	}
	else
	{
		alternativaSelecionada = alternativaSelecionada - 1;
	}
}

void Questionario::descerCursor()
{
	if (alternativaSelecionada == 2)
	{
		alternativaSelecionada = 0;
	}
	else
	{
		alternativaSelecionada = alternativaSelecionada + 1;
	}
}

void Questionario::selecionarAlternativa(int numAlternativa)
{
	alternativaSelecionada = numAlternativa;
}

void Questionario::addQuestao(Questao questao, int posicao)
{
	this->questoes[posicao] = questao;
}
