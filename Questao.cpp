#include "Questao.h"

Questao::Questao(){
}

Questao::Questao(std::string enunciado,std::string alternativaCorreta, std::string alternativaNeutra, std::string alternativaErrada){
	this->enunciado = enunciado;
	this->alternativaCorreta = alternativaCorreta;
	this->alternativaNeutra = alternativaNeutra;
	this->alternativaErrada = alternativaErrada;
}
