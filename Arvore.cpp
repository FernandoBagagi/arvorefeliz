#include "Arvore.h"
#include "Cor.h"

std::string Arvore::nome = "Pau Brasil";
std::string Arvore::info = "A arvore alcanca entre dez e quinze metros de altura e possui tronco reto, com casca cor cinza-escuro, coberta de aculeos, especialmente nos ramos mais jovens.";

Cor Arvore::cores[8][2] = {
	{Cor(0.0f, 0.2f, 0.1f),Cor(0.8f, 0.8f, 0.0f)},
	{Cor(0.0f, 1.0f, 0.0f),Cor(1.0f, 1.0f, 0.0f)},
	{Cor(0.0f, 0.7f, 0.0f),Cor(0.9f, 0.9f, 0.0f)},
	{Cor(0.0f, 0.4f, 0.0f),Cor(0.7f, 0.7f, 0.0f)},
	{Cor(0.0f, 0.9f, 0.3f),Cor(0.6f, 0.6f, 0.0f)},
	{Cor(0.0f, 0.5f, 0.0f),Cor(0.8f, 0.5f, 0.0f)},
	{Cor(0.0f, 0.6f, 0.0f),Cor(0.7f, 0.3f, 0.0f)},
	{Cor(0.58f, 0.3f, 0.0f),Cor(0.16f, 0.16f, 0.06f)}
};

Arvore::Arvore(){
}

void Arvore::crescer(){
	errosConsecutivos=0;
	fase++;
}

void Arvore::morrer(){
	if(fase>0){
		fase--;	
	}
	errosConsecutivos++;
	if(errosConsecutivos==3){
		fase = -1;
	}
}

void Arvore::desenharQuadrado(){
	glBegin (GL_QUADS);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(-0.5f, -0.5f);
	glEnd();
	glPushMatrix();
}

void Arvore::desenharFolha(GLfloat escalaX, GLfloat escalaY, GLfloat translacaoX, GLfloat translacaoY, int cor){
	Cor::setarCor(cores[cor][errosConsecutivos == 0? 0 : 1]);
	glScalef(escalaX, escalaY, 1.0f);
	glTranslatef(translacaoX, translacaoY, 0.0f);
	desenharQuadrado();
	glLoadIdentity();
}

void Arvore::desenharCaule(GLfloat escalaX, GLfloat escalaY, GLfloat translacaoX, GLfloat translacaoY){
	Cor::setarCor(cores[7][errosConsecutivos == 0 ? 0 : 1]);
	glScalef(escalaX, escalaY, 1.0f);
	glTranslatef(translacaoX, translacaoY, 0.0f);
	desenharQuadrado();
	glLoadIdentity();
}

void Arvore::desenha(){
	glLoadIdentity();
	Cor::setarCor(Cor(0.0f,0.0f,0.0f));
	glRasterPos2f (-29, 15);
	for(int i=0; i<nome.length(); i++){
		glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, nome.at(i));
	}
	glutSwapBuffers();
	
	Cor::setarCor(Cor(0.0f,0.0f,0.0f));
	glRasterPos2f (-29, 13.5);
	for(int i=0; i<info.length()/2; i++){
		glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, info.at(i));
	}
	glutSwapBuffers();
	
	glRasterPos2f (-29, 12);
	for(int i=info.length()/2; i<info.length(); i++){
		glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, info.at(i));
	}
	glutSwapBuffers();
	
	switch(fase){
		case 0:
			desenharCaule(2.0f, 5.0f, -8.0f, -2.8f);
			desenharFolha(2.2f, 2.2f,-6.75f, -5.0f,0);
			desenharFolha(2.2f, 2.2f, -7.75f, -5.0f, 1);
			desenharFolha(2.2f, 2.2f, -6.25f, -4.0f, 2);
			desenharFolha(2.2f, 2.2f,-8.25f, -4.0f, 3);
			desenharFolha(2.2f, 2.2f, -7.25f, -4.0f,4);
			desenharFolha(2.2f, 2.2f, -6.75f, -3.0f,5);
			desenharFolha(2.2f, 2.2f, -7.75f, -3.0f,6);
			break;
		case 1:
			desenharCaule(2.2f, 5.41f, -8.0f, -2.55f);
			desenharFolha(2.3f, 2.3f,-7.18f, -4.32f,0);
			desenharFolha(2.3f, 2.3f, -8.18f, -4.32f, 1);
			desenharFolha(2.3f, 2.3f, -6.65f, -3.32f, 2);
			desenharFolha(2.3f, 2.3f,-8.65f, -3.32f, 3);
			desenharFolha(2.3f, 2.3f, -7.65f, -3.32f,4);
			desenharFolha(2.3f, 2.3f, -7.18f, -2.32f,5);
			desenharFolha(2.3f, 2.3f, -8.18f, -2.32f,6);
			break;
		case 2:
			desenharCaule(2.4f, 5.9f, -8.0f, -2.3f);
			desenharFolha(2.5f, 2.5f,-7.18f, -3.75f,0);
			desenharFolha(2.5f, 2.5f, -8.18f, -3.75f, 1);
			desenharFolha(2.5f, 2.5f, -6.65f, -2.75f, 2);
			desenharFolha(2.5f, 2.5f,-8.65f, -2.75f, 3);
			desenharFolha(2.5f, 2.5f, -7.65f, -2.75f,4);
			desenharFolha(2.5f, 2.5f, -7.18f, -1.75f,5);
			desenharFolha(2.5f, 2.5f, -8.18f, -1.75f,6);
			break;
		case 3:			
			desenharCaule(2.5f, 6.59f, -8.0f, -2.01f);
			desenharFolha(2.75f, 2.75f,-6.75f, -3.11f,0);
			desenharFolha(2.75f, 2.75f, -7.75f, -3.11f, 1);
			desenharFolha(2.75f, 2.75f, -6.24f, -2.11f, 2);
			desenharFolha(2.75f, 2.75f,-8.24f, -2.11f, 3);
			desenharFolha(2.75f, 2.75f, -7.25f, -2.11f,4);
			desenharFolha(2.75f, 2.75f, -6.75f, -1.11f,5);
			desenharFolha(2.75f, 2.75f, -7.75f, -1.11f,6);	
			break;
		case 4:
			desenharCaule(2.8f, 8.0f, -8.0f, -1.56f);
			desenharFolha(3.0f, 3.0f,-7.0f, -2.35f,0);
			desenharFolha(3.0f, 3.0f, -8.0f, -2.35f, 1);
			desenharFolha(3.0f, 3.0f, -6.5f, -1.35f, 2);
			desenharFolha(3.0f, 3.0f,-8.5f, -1.35f, 3);
			desenharFolha(3.0f, 3.0f, -7.5f, -1.35f,4);
			desenharFolha(3.0f, 3.0f, -7.0f, -0.35f,5);
			desenharFolha(3.0f, 3.0f, -8.0f, -0.35f,6);
			break;
		case 5:
			desenharCaule(3.0f, 8.5f, -8.0f, -1.45f);
			desenharFolha(3.3f, 3.3f,-6.75f, -1.95f, 0);
			desenharFolha(3.3f, 3.3f, -7.75f, -1.95f, 1);
			desenharFolha(3.3f, 3.3f, -6.25f, -0.95f, 2);
			desenharFolha(3.3f, 3.3f, -8.25f, -0.95f, 3);
			desenharFolha(3.3f, 3.3f, -7.25f, -0.95f,4);
			desenharFolha(3.3f, 3.3f, -6.75f, 0.05f,5);
			desenharFolha(3.3f, 3.3f, -7.75f,  0.05f,6);
			break;
		case 6:
			desenharCaule(3.5f, 12.5f, -6.85f, -0.83f);
			desenharFolha(3.3f, 3.3f,-6.75f, -0.75f, 0);
			desenharFolha(3.3f, 3.3f, -7.75f, -0.75f, 1);
			desenharFolha(3.3f, 3.3f, -6.25f, 0.25f, 2);
			desenharFolha(3.3f, 3.3f, -8.25f, 0.25f, 3);
			desenharFolha(3.3f, 3.3f, -7.25f, 0.25f, 4);
			desenharFolha(3.3f, 3.3f, -6.75f, 1.25f, 5);
			desenharFolha(3.3f, 3.3f, -7.75f,  1.25f, 6);
			break;
		case 7:
			desenharCaule(3.5f, 12.5f, -4.85f, -0.83f);
			desenharFolha(4.5f, 4.5f, -3.25f, -0.5f, 0);
			desenharFolha(4.5f, 4.5f, -4.25f, -0.5f, 1);
			desenharFolha(4.5f, 4.5f, -2.75f, 0.5f, 2);
			desenharFolha(4.5f, 4.5f, -4.75f, 0.5f, 3);
			desenharFolha(4.5f, 4.5f, -3.75f, 0.5f, 4);
			desenharFolha(4.5f, 4.5f, -3.25f, 1.5f, 5);
			desenharFolha(4.5f, 4.5f, -4.25f,  1.5f, 6);
			break;
		case -1:
			desenharCaule(8.0f,2.8f , -3.0f, -5.36f);
			break;				
	}	
}
