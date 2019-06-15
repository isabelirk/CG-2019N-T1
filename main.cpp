/*+
* Autora: Isabeli Reik
* Disciplina: Computação gráfica
* Ano: 2019/1
* email: isabelireik2@gmail.com
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

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


	glutSwapBuffers(); //atualiza a display
}

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