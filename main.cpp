/**
 Autora: Isabeli Reik
 Disciplina: Computação gráfica
 Ano: 2019/1
 */


#include <gl/glut.h>
#include <gl/gl.h>

GLfloat rdir = 0; //rotação para a direita
GLfloat resq = 0; //rotação para a esquerda

//Função que mostra o plano cartesiano
void renderCoordinateAxis(){
	//eixo X - verde
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		//lado negativo
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		//lado positivo
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	//eixo Y - azul
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		//lado positivo
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		//lado negativo
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

//Função principal - desenha na tela
void display(){
	glClearColor(1, 1, 1, 0); //fundo branco

	glClear(GL_COLOR_BUFFER_BIT); //limpa a tela

	glMatrixMode(GL_MODELVIEW); //Queremos fazer alterações na matrix modelView

	renderCoordinateAxis(); //Chama a fução para mostrar o plano cartesiano

	glLoadIdentity(); //matriz identidade para limpar qualquer transformação que tenha ocorrido
	
	//1º quadrado - base
	glColor3f(0.3f, 0.5f, 0.6f);
	glTranslatef(0.4f, 0.05f, 0.0f);
	glutWireCube(0.1);

	glRotatef(resq, 0.4f, 0.0f, 0.0f);
	glRotatef(rdir, 0.4f, 0.0f, 0.0f);

	//2º quadrado
	glPushMatrix();
		glLoadIdentity();
		glColor3f(0.6f, 0.5f, 0.3f);
		glTranslatef(0.4f, 0.15f, 0.0f);
		glutWireCube(0.1);
	glPopMatrix();

	//3º quadrado
	glPushMatrix();
		glLoadIdentity();
		glColor3f(0.3f, 0.7f, 0.2f);
		glTranslatef(0.4f, 0.25f, 0.0f);
		glutWireCube(0.1);
	glPopMatrix();

	// 4º retangulo
	glPushMatrix();
		glLoadIdentity();
		glColor3f(0.7f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
			glVertex2f(0.35f, 0.3f);
			glVertex2f(0.45f, 0.3f);
			glVertex2f(0.45f, 0.5f);
			glVertex2f(0.35f, 0.5f);
		glEnd();
	glPopMatrix();

	glFlush();
	glutSwapBuffers(); //atualiza a display
}

//função para detecção das letras do teclado
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'Q':
		case 'q':
			resq -= 5.0;
			break;
		case 'A':
		case 'a':
			rdir += 5.0;
			break;
		case 'W':
		case 'w':
			resq += 5.0;
			break;
		case 'S':
		case 's':
			rdir += 5.0;
			break;
		case 'E':
		case 'e':
			resq += 5.0;
			break;
		case 'D':
		case 'd':
			rdir += 5.0;
			break;
	}

	//display update
	glutPostRedisplay();
}

int main(int argc, char** argv){
	//inicializações obrigatorias
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Braço robótico");

	glutDisplayFunc(display); //chama a função principal
	glutKeyboardFunc(keyboard); //detecção do teclado

	glutMainLoop();
	return 0;
}