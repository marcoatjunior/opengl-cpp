#include "glut.h" 

void desenha (void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glPointSize(7); //defini o diametro dos pontos
  glBegin(GL_TRIANGLES);
     glColor3f(0.8f, 0.0f, 0.0f);
     glVertex2f(-0.9,-1.0);
     glVertex2f(0.0,-0.5);
     glVertex2f(-0.5,0.0);
  glEnd();

// A seguir, desenho do retangulo vazado
  glBegin(GL_LINE_LOOP);
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2i(0,0);
     glColor3f(0.0f, 1.0f, 0.0f);
     glVertex2f(0.0,0.8);
     glColor3f(0.0f, 0.0f, 1.0f);
     glVertex2f(0.8,0.8);
     glVertex2f(0.8,0.0);
  glEnd();
// A seguir, desenho do retangulo preenchido
  glBegin(GL_QUADS);
     glColor3f(0.0f, 0.5f, 0.0f);
     glVertex2f(0.3,0.3);
     glVertex2f(0.3,0.7);
     glVertex2f(0.7,0.7);
     glVertex2f(0.7,0.3);
  glEnd();

  glFlush(); //utilizada com GLUT_SINGLE
}

void inicializacao(void)
{
  glClearColor (0.8, 0.8, 0.8, 0.0);//cinza
}

int main (int argc, char** argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutCreateWindow ("Oi OpenGL");
    glutDisplayFunc(desenha);
    inicializacao();
    glutMainLoop();
    return 0;
}
