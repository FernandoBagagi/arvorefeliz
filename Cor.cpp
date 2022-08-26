#include "Cor.h"

Cor::Cor(){
	
}

Cor::Cor(GLfloat red, GLfloat green, GLfloat blue){
	this->red = red;
	this->green = green;
	this->blue = blue;	
}

GLfloat Cor::r(void){
	return this->red;
}

GLfloat Cor::g(){
	return this->green;
}
		
GLfloat Cor::b(){
	return this->blue;
}

void Cor::setarCor(Cor cor){
	glColor3f (cor.r(), cor.g(), cor.b());
}

void Cor::setarClearCor(Cor cor){
	glClearColor(cor.r(), cor.g(), cor.b(), 1.0f);
}
