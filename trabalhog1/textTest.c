#include <GL/glut.h>

void drawBitmapText(char *string, float x, float y, float z);
void reshape(int w, int h);
void display(void);

void drawBitmapText(char *string, float x, float y, float z)
{
    char *c;
    glRasterPos3f(x, y, z);//define position on the screen where to draw text.

    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//Resets to identity Matrix.
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void display(void)
{

    glBegin(GL_POLYGON);//1
    glVertex2f(-0.2, 0.6 - 0.3);
    glVertex2f(-0.1, 0.6 - 0.3);
    glVertex2f(-0.1, 0.5 - 0.3);
    glVertex2f(-0.2, 0.5 - 0.3);
    glEnd();


    glColor3f(0, 1, 0);
    drawBitmapText("Usama Ishfaq", 200, 400, 0);//drawBitmapText("Usama Ishfaq", x(how much right), y(how much down), z);

    glutSwapBuffers();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); 
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Usama OGL Window");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
