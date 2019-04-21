#include <GL/glut.h>

#define MAINSCREEN 1
#define PLANET 2
#define WORLD 3
#define MONUMENT 4

typedef struct XY {
	float x;
	float y;
} XYPoint;

XYPoint P0, P1, P2, P3, P4;  

int object;

void drawBitmapText(char *string, float x, float y, float z);
void reshape(int w, int h);

void drawBitmapText(char *string, float x, float y, float z)
{
    char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void reshape(int w, int h)
{
	glClearColor(1,1,1,1);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw(void) 
{
   	glClear(GL_COLOR_BUFFER_BIT);
   	
    switch (object) {
        case MAINSCREEN: {
			glBegin(GL_POLYGON);
				glVertex2f(-0.2, 0.6 - 0.3);
				glVertex2f(-0.1, 0.6 - 0.3);
				glVertex2f(-0.1, 0.5 - 0.3);
			glVertex2f(-0.2, 0.5 - 0.3);
			glEnd();

			glColor3f(0, 0, 0);
			drawBitmapText("Bem-vindos a aula de Geografia!", 80, 300, 0);

            break;
	    }
        case PLANET: {
			glBegin (GL_LINE_LOOP);
	           glVertex2f (P0.x+P1.x,P0.y+P1.y);
	           glVertex2f (P0.x+P2.x,P0.y+P2.y);
	           glVertex2f (P0.x+P3.x,P0.y+P3.y);
             glEnd();
             break;
	    }
        case WORLD: {
			glBegin (GL_LINE_LOOP);
	           glVertex2f (P0.x+P1.x,P0.y+P1.y);
	           glVertex2f (P0.x+P2.x,P0.y+P2.y);
               glVertex2f (P0.x+P4.x,P0.y+P4.y);
	           glVertex2f (P0.x+P3.x,P0.y+P3.y);               
            glEnd();
            break;   
	    }
        case MONUMENT: {
			glBegin (GL_QUADS);
			   glVertex2f (P0.x+P1.x,P0.y+P1.y);
			   glVertex2f (P0.x+P2.x,P0.y+P2.y);
			   glVertex2f (P0.x+P4.x,P0.y+P4.y);
			   glVertex2f (P0.x+P3.x,P0.y+P3.y);   
			glEnd();
		break;     
	    }
    }                           

    glutSwapBuffers();
}

void create(void) 
{
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
}

void createObject (void) 
{ 
    P0.x = 0;
    P0.y = 0;
    P1.x = 0;
    P1.y = 1;
    P2.x = -1;
    P2.y = 0;
    P3.x = 1;
    P3.y = 0;
    P4.x = 0;
    P4.y = -1;
    glColor3f(0.7f, 0.7f, 0.7f);
    object=MAINSCREEN;
}

void keyboardSpecialKeys(int key, int x, int y) 
{
    if(key == GLUT_KEY_UP)
		P0.y += 0.5;
	if(key == GLUT_KEY_DOWN)
		P0.y -= 0.5f;
	if(key == GLUT_KEY_LEFT)
		P0.x -= 0.5f;
	if(key == GLUT_KEY_RIGHT)
		P0.x += 0.5f;
	glutPostRedisplay();
}
   
void keyboard(unsigned char key, int x, int y)
{
	if(key == 'r') { 
		P0.x=0; 
		P0.y=0;
		glColor3f(1.0f,0.0f,0.0f);
	}
       
	glutPostRedisplay();
}
     
void menu(int value)
{
     switch(value) {
		case 0:
			object=PLANET;
            break;
        case 1: 
            object=WORLD;
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

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecialKeys);
    glutReshapeFunc(reshape);
    glutDisplayFunc(draw);
    
	create();
    createObject();

	glutMainLoop();
	
	return 0;
}

