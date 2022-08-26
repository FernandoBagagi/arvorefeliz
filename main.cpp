#include <windows.h>
#include <GL/glut.h>

#include <iostream>
#include <string>

#include "Cor.h"
#include "Questao.h"
#include "Questionario.h"
#include "Arvore.h"

/*Alunos: Fernando Bagagi, Georgia Virginnya e Yan Anderson*/

GLfloat janelaEixoX = 20.0f, janelaEixoY = 30.0f;
const float tamanhoBaseEixoX = 32.0f, tamanhoBaseEixoY = 18.0f;

Questionario questionario = Questionario();

void inicializarQuestionario(){
	questionario.addQuestao(Questao("1) Como voce lava sua calcada?", "a) Com um balde de agua apenas", "b) Nao lavo, apenas uso a vassoura", "c) Com mangueira"), 0);
	questionario.addQuestao(Questao("2) Como voce separa o lixo?", "a)  Reciclaveis, nao-reciclaveis e organicos", "b) Reciclaveis e nao-reciclaveis", "c) Nao separo"), 1);
	questionario.addQuestao(Questao("3) Qual a procedencia dos alimentos que voce consome?", "a) Da minha propria horta", "b) Feiras populares, mercado as vezes", "c) Sempre em supermercados"), 2);
	questionario.addQuestao(Questao("4) Quantas vezes voce compra roupas e calcados?", "a) Ate 5 vezes por ano", "b) Uma vez por mes", "c) Mais de uma vez por mes"), 3);
	questionario.addQuestao(Questao("5) Quanto tempo voce deixa a porta da geladeira aberta?", "a) Nao demoro muito, penso sempre antes no que vou pegar", "b) Raras vezes demoro um pouco para achar o que quero", "c) Muitas vezes demoro"), 4);
	questionario.addQuestao(Questao("6) Voce costuma aproveitar a iluminacao e a ventilacao natural?", "a) Sempre", "b) Algumas vezes", "c) Nunca"), 5);
	questionario.addQuestao(Questao("7) Voce costuma tomar banho quente?", "a) Nao, prefiro tomar banho frio", "b) Sim, mas somente quando esta fazendo frio", "c) Sim, independente da condicao climatica, mas morno"), 6);
}

Arvore arvore = Arvore();

void alterarTamanhoDaJanela(GLsizei width, GLsizei height){
	if(height != 0 && width != 0) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if(width <= height) {
			gluOrtho2D (-tamanhoBaseEixoX, tamanhoBaseEixoX, -tamanhoBaseEixoY * (height / width), tamanhoBaseEixoY * (height / width));
			janelaEixoX = tamanhoBaseEixoX;
			janelaEixoY = tamanhoBaseEixoY * (height / width);
		} else {
			gluOrtho2D (-tamanhoBaseEixoX * (width / height), tamanhoBaseEixoX  * (width / height), -tamanhoBaseEixoY , tamanhoBaseEixoY);
			janelaEixoX = tamanhoBaseEixoX * (width / height);
			janelaEixoY = tamanhoBaseEixoY;	
		}	
	}
}

void MenuPrincipal(int indiceMenu){
	
	if(indiceMenu == 0){
		
		Arvore::nome = "Pau-Brasil";
		Arvore::info = "A arvore alcanca entre dez e quinze metros de altura e possui tronco reto, com casca cor cinza-escuro, coberta de aculeos, especialmente nos ramos mais jovens.";
		
		Arvore::cores[0][0] = Cor(0.0f, 0.2f, 0.1f);
		Arvore::cores[0][1] = Cor(0.8f, 0.8f, 0.0f);
		
		Arvore::cores[1][0] = Cor(0.0f, 1.0f, 0.0f);
		Arvore::cores[1][1] = Cor(1.0f, 1.0f, 0.0f);
		
		Arvore::cores[2][0] = Cor(0.0f, 0.7f, 0.0f);
		Arvore::cores[2][1] = Cor(0.9f, 0.9f, 0.0f);
		
		Arvore::cores[3][0] = Cor(0.0f, 0.4f, 0.0f);
		Arvore::cores[3][1] = Cor(0.7f, 0.7f, 0.0f);
		
		Arvore::cores[4][0] = Cor(0.0f, 0.9f, 0.3f);
		Arvore::cores[4][1] = Cor(0.6f, 0.6f, 0.0f);
		
		Arvore::cores[5][0] = Cor(0.0f, 0.5f, 0.0f);
		Arvore::cores[5][1] = Cor(0.8f, 0.5f, 0.0f);
		
		Arvore::cores[6][0] = Cor(0.0f, 0.6f, 0.0f);
		Arvore::cores[6][1] = Cor(0.7f, 0.3f, 0.0f);
		
		Arvore::cores[7][0] = Cor(0.58f, 0.3f, 0.0f);
		Arvore::cores[7][1] = Cor(0.16f, 0.16f, 0.06f);
	} else {
		
		Arvore::nome = "Ipe Amarelo";
		Arvore::info = "Pode atingir 30 metros de altura e 60 centimetros de diametro. A floracao amarela       inicia no final de agosto e a frutificacao ocorre entre setembro e fevereiro.";
		
		Arvore::cores[0][0] = Cor(0.99f, 0.99f, 0.22f);
		Arvore::cores[0][1] = Cor(0.58f, 0.58f, 0.58f);
		
		Arvore::cores[1][0] = Cor(0.99f, 0.99f, 0.32f);
		Arvore::cores[1][1] = Cor(0.82f, 0.82f, 0.82f);
		
		Arvore::cores[2][0] = Cor(0.99f, 0.99f, 0.22f);
		Arvore::cores[2][1] = Cor(0.5f, 0.5f, 0.5f);
		
		Arvore::cores[3][0] = Cor(0.99f, 0.99f, 0.32f);
		Arvore::cores[3][1] = Cor(0.67f, 0.67f, 0.67f);
		
		Arvore::cores[4][0] = Cor(0.99f, 0.99f, 0.22f);
		Arvore::cores[4][1] = Cor(0.55f, 0.55f, 0.55f);
		
		Arvore::cores[5][0] = Cor(0.99f, 0.99f, 0.32f);
		Arvore::cores[5][1] = Cor(0.73f, 0.73f, 0.73f);
		
		Arvore::cores[6][0] = Cor(0.99f, 0.99f, 0.22f);
		Arvore::cores[6][1] = Cor(0.8f, 0.8f, 0.8f);
		
		Arvore::cores[7][0] = Cor(0.29f, 0.21f, 0.13f);
		Arvore::cores[7][1] = Cor(0.2f, 0.2f, 0.2f);
	}	
	
	glutPostRedisplay();
}

void getMouse(int button, int state, int x, int y){
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		
    	int menu = glutCreateMenu(MenuPrincipal);
		glutAddMenuEntry("Pau-Brasil",0);
		glutAddMenuEntry("Ipe-Amarelo",1);
    
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	}
}

// Essa função é a que será chamada quando o usuário apertar uma tecla especial
void getTeclaEspecial(int key, int x, int y){
	if(key == GLUT_KEY_UP){
    	questionario.subirCursor();
	}else if(key == GLUT_KEY_DOWN){
		questionario.descerCursor();
	}else if(key == GLUT_KEY_INSERT){
		if(questionario.inicio == true){
			questionario.inicio = false;
		}
	}
	glutPostRedisplay();	
}

// Essa função é a que será chamada quando o usuário apertar uma tecla
void getTecla(unsigned char key, int x, int y){
	if (key == 27)
		exit(0);
	else if (key == 13){
		if(questionario.inicio == false){
			int value = questionario.proximaQuestao();
			if(value==1){
				arvore.crescer();
			}else if(value==-1){
				arvore.morrer();
			}	
		}
	} else if (key == 'a'){
		questionario.selecionarAlternativa(0);
	} else if (key == 'b'){
		questionario.selecionarAlternativa(1);
	} else if (key == 'c'){
		questionario.selecionarAlternativa(2);
	}
	glutPostRedisplay();
}

void desenhar(void){
	
	// Muda para o sistema de coordenadas do modelo
	glMatrixMode (GL_MODELVIEW);
	// Inicializa a matriz de transformação corrente
	glLoadIdentity ();
	
	Cor::setarClearCor(Cor(0.5f, 0.8f, 1.0f));
	
	// Pinta o fundo
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Desenha o chão
	glLoadIdentity();
	Cor::setarCor(Cor(0.1f, 0.5f, 0.0f));
	glBegin (GL_QUADS);
		glVertex2f(-32.0f, -16.5f);
		glVertex2f(-32.0f, -18.0f);
		glVertex2f(32.0f, -18.0f);
		glVertex2f(32.0f, -16.5f);
	glEnd ();

	arvore.desenha();

	questionario.desenha();

	// Executa os comandos OpenGL 
	glFlush();
}

int main(int argc, char** argv){
	// Inicializa a biblioteca Glut
	glutInit(&argc, argv);
	
	// Define o modo do display 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	// Define o posicionamento da tela
	glutInitWindowPosition(20, 50);
	
	// Define o tamanho da tela     
	glutInitWindowSize(1280, 720);
	
	// Cria a tela, recebe como parâmetro o título
	glutCreateWindow("Projeto - Fernando Bagagi, Georgia Virginnya e Yan Anderson"); 
 
	// Registra a função callback de desenho da janela de visualização
	// É essa função que será chamada quando precisar mostrar a tela, ou redesenhar
	glutDisplayFunc(desenhar);  
	
	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(alterarTamanhoDaJanela);
	
	// Registra a função callback para tratamento das teclas especiais
	glutSpecialFunc(getTeclaEspecial);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (getTecla);
	
	glutMouseFunc(getMouse);
	
	inicializarQuestionario();
	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();
	
	return 0;
}
