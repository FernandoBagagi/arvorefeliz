#ifndef QUESTAO_H
#define QUESTAO_H

#include<string>

class Questao
{
	public:
		Questao();
		Questao(std::string enunciado,std::string alternativaCorreta, std::string alternativaNeutra, std::string alternativaErrada);
		std::string enunciado;
		std::string alternativaCorreta;
		std::string alternativaNeutra;
		std::string alternativaErrada;		
};

#endif
