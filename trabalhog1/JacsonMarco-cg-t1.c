#include "glut.h"

#define MAINSCREEN 1
#define PLANET 2
#define WORLD 3
#define MONUMENT 4
#define BRASIL 5

#define PI 3.1415926535898

float cmx = 0;
float cmy = 0.5;

int object;

void drawBitmapText(char *string, float x, float y, float z);
void reshape(int w, int h);

void drawBitmapText(char *string, float x, float y, float z)
{
    char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void reshape(int w, int h)
{
    glClearColor(1,1,1,1);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void create(void)
{
    glClearColor(0.9f, 0.9f, 0.9f,1);
}

void createObject(void)
{
    glColor3f(0.7f, 0.7f, 0.7f);
    object=MAINSCREEN;
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    switch (object) {
        case MAINSCREEN:
            glColor3f(0, 0, 0);
            drawBitmapText("Bem-vindos a aula de Geografia!", -0.65, 0, 0);
            break;
        case BRASIL:
            drawBrasil();
            break;
        case PLANET:
            drawPlanet();
            break;
        case WORLD:
            drawWorld();
            break;
        }
        case MONUMENT: {
            drawMonument();
            break;
        }
    }

    glutSwapBuffers();
}

void drawPlanet(void)
{
	GLfloat circle_points = 1000;
	
	double angle;
	int i;
   
	glBegin(GL_POLYGON);	   
		glColor3f(0.6,0.3,0.1);
		for (i = 0; i < circle_points; i++) {
			angle = 5*PI*i/circle_points;
			glVertex2f((cmx+cos(angle)/6.5),(cmy+sin(angle)/6.5));
		}
	glEnd();
    	
	glColor3f(0, 0, 0);
	drawBitmapText("UTILIZE AS SETAS DIRECIONAIS", -0.9, -0.1, 0);
	drawBitmapText("Informacoes sobre o planeta Terra", -0.9, -0.35, 0);
	drawBitmapText("1 - Ele nao e plano", -0.9, -0.50, 0);
	drawBitmapText("2 - Faz parte da Via-Lactea", -0.9, -0.65, 0);
	drawBitmapText("3 - Sua estrela maior e o Sol", -0.9, -0.80, 0);
}

void drawBrasil(void)
{
	glColor3f(0, 0, 0);
	drawBitmapText("ACERTOU!", -0.9, 0.4, 0);
	drawBitmapText("180 milhoes de habitantes...", -0.9, 0.2, 0);
	drawBitmapText("Fica localizado na America do Sul...", -0.9, 0, 0);
	drawBitmapText("E sua capital e Brasilia!", -0.9, -0.2, 0);
}

void planetOption(int key)
{
    //if(key == GLUT_KEY_UP) { cmy += 0.5f; }
    //if(key == GLUT_KEY_DOWN) { cmy -= 0.5f; }
    
    if (key == GLUT_KEY_RIGHT) { cmx += 0.5f; }
    if (key == GLUT_KEY_LEFT) { cmx -= 0.5f; }
    
    if (cmx < -0.5f) { cmx = -0.5f; }
    if (cmx > 0.5f)  { cmx = 0.5f;  }
    //if (cmy > 0.5f)  { cmy = 0.5f;  }
    //if (cmy < -0.5f) { cmy = -0.5f; }
}

void drawWorld(void)
{
	GLfloat circle_points = 1000;
	
	int i;
	double angle;
	float x = 0;
	float y = 0.5;
	   
	glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		glVertex2f(-0.4,0.8);
		glVertex2f(0.4,0.8);
		glVertex2f(0.4,0.2);
		glVertex2f(-0.4,0.2);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1,1,0);
		glVertex2f(0,0.75);
		glVertex2f(-0.3,0.5);
		glVertex2f(0,0.25);
		glVertex2f(0.3,0.5);
	glEnd();

	glBegin(GL_POLYGON);
	   glColor3f(0,0,1);
	   for (i = 0; i < circle_points; i++) {
		   angle = 5*PI*i/circle_points;
		   glVertex2f(x+cos(angle)/6.5,y+sin(angle)/6.5);
	   }
	glEnd();

	glColor3f(0, 0, 0);
	drawBitmapText("Qual pais e representado pela bandeira acima?", -0.9, -0.1, 0);
	drawBitmapText("(A) Argentina", -0.9, -0.35, 0);
	drawBitmapText("(B) Brasil", -0.9, -0.50, 0);
	drawBitmapText("(C) Chile", -0.9, -0.65, 0);
	drawBitmapText("(D) Dinamarca", -0.9, -0.80, 0);
}

void worldOption(unsigned char key)
{
    if(key == 'b') {
        object=BRASIL;
        draw();
    }
}

void drawMonument(void)
{
	glColor3f(0.6,0.3,0.1);
	
	int i;
	double angle;
	   
	glBegin(GL_POLYGON);
	   for (i = 0; i < circle_points; i++) {
		   angle = 5*PI*i/circle_points;
		   glVertex2f(cmx+cos(angle)/6.5,cmy+sin(angle)/6.5);
	   }
	glEnd();

	drawBitmapText("UTILIZE O ESPACO", -0.9, -0.1, 0);
	drawBitmapText("Piramides do Egito", -0.9, -0.35, 0);
	drawBitmapText("1 - Localizadas em Cairo", -0.9, -0.50, 0);
	drawBitmapText("2 - Construidas em 2550 AC", -0.9, -0.65, 0);
	drawBitmapText("3 - Uma das mais antigas do mundo", -0.9, -0.80, 0);
}

void menu(int value)
{
    switch(value) {
		case 0:
			object=PLANET;
			glutSpecialFunc(planetOption);
			break;
		case 1:
			object=WORLD;
			glutKeyboardFunc(worldOption);
			break;
		case 2:
			object=MONUMENT;
			break;
		case 3:
			exit(0);
			break;
		default:
			object=MAINSCREEN;
			break;
    }

    create();
    draw();
    glColor3f (1.0f, 1.0f, 1.0f);

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(450, 150);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow("Aula de Geografia");

    glutCreateMenu(menu);
    glutAddMenuEntry("Planeta", 0);
    glutAddMenuEntry("Mundo", 1);
    glutAddMenuEntry("Monumento", 2);
    glutAddMenuEntry("Sair", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutReshapeFunc(reshape);
    glutDisplayFunc(draw);

    create();
    createObject();

    glutMainLoop();

    return 0;
}
