#ifndef COR_H
#define COR_H

#include <GL/glut.h>

class Cor
{
	public:
		Cor();
		Cor(GLfloat red, GLfloat green, GLfloat blue);
		GLfloat r(void);
		GLfloat g(void);
		GLfloat b(void);
		static void setarCor(Cor cor);
		static void setarClearCor(Cor cor);
	private:
		GLfloat red;
		GLfloat green;
		GLfloat blue;
};

#endif
