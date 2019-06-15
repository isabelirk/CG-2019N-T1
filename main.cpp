/*+
* Autora: Isabeli Reik
* Disciplina: Computação gráfica
* Ano: 2019/1
* email: isabelireik2@gmail.com
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

GLfloat altura = 0.1;
GLint bx0 = 0, by0 = 0, bz0 = 0;
GLint bx1 = 0, by1 = 0, bz1 = 0;
GLint bx2 = 0, by2 = 0, bz2 = 0;
GLint angulo0 = 0, angulo1 = 0, angulo2 = 0;

void renderCoordinateAxis(){ //plano cartesiano
	//eixo x - verde
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		glVertex2f(-1.0, 0.0); //lado esquerdo - negativo
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 0.0); //lado direito - positivo
		glVertex2f(1.0, 0.0);
	glEnd();

	//eixo y - azul
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		glVertex2f(0.0, 0.0); //em cima - positivo
		glVertex2f(0.0, 1.0);
		glVertex2f(0.0, 0.0); //em baixo - negativo
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display(){
	glClearColor(1, 1, 1, 0); //fundo branco
	glClear(GL_COLOR_BUFFER_BIT); //limpa a tela
	glMatrixMode(GL_MODELVIEW); //queremos fazer alterações na matriz modelView
	renderCoordinateAxis(); //chama a função do plano cartesiano

	//bloco 1 - base
	glColor3f(0.3f, 0.5f, 0.6f);
	glTranslatef(0.4f, 0.05f, 0.0f);
	glutWireCube(altura);
	glRotated(angulo0, bx0, by0, bz0);
	glPushMatrix();
		//bloco 1
		glColor3f(0.6f, 0.5f, 0.3f);
		glTranslatef(0.0f, 0.10f, 0.0f);
		glutWireCube(altura);
		glRotated(angulo1, bx1, by1, bz1);

	glutSwapBuffers(); //atualiza a display
}

//void displayInterna() {
	//bloco 1 - base
	//glColor3f(0.3f, 0.5f, 0.6f);
	//glTranslatef(0.4f, 0.05f, 0.0f);
	//glutWireCube(0.1);
	//glRotatef(angulo0, 0.0f, 1.0f, 0.0f);
//}

void keyboard(unsigned char key, int x, int y){
	if (key == 27){ //fechar o programa
		exit(0);
	}
}

int main(int argc, char** argv){
	//chamadas para inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Braço Robótico");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop(); //loop mains
	return 0;
}