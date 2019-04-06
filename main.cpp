/**
 Autora: Isabeli Reik
 Disciplina: Computação gráfica
 Ano: 2019/1
 */


#include <gl/glut.h>
#include <gl/gl.h>


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

	glColor3f(0.3f, 0.5f, 0.6f);
	glTranslatef(0.4f, 0.1f, 0.0f);
	glutWireCube(0.2);

	

	glutSwapBuffers(); //atualiza a display
}

void keyboard(unsigned char key, int x, int y){
	if (key == 27) {
		// ESC key
		exit(0);
	}
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