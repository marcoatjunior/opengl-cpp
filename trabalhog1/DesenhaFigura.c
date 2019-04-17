// DesenhaFigura.c
// prof. Magal� T. Longhi

//   include de headers ou definicoes das funcoes da glut
//   glut.h inclui gl.h e glu.h, que definem, respectivamente, as bibliotecas de
//   fun��o OpenGL e GLU.
//   glut.h inclui tambem definicoes necessarias para o uso de OpenGl nos diversos
//   ambientes Windows
//   alterado por Mozart Lemos de Siqueira em agosto de 2006
#include <GL/glut.h>

// defini��o de um ponto (x,y)

typedef struct XY {
        float x;
        float y;
} PontoXY;

PontoXY P1, P2, P3, P4;


void Desenha(void)
// Fun��o de callback (recursiva) de desenho
// Executada sempre que � necessario re-exibir a imagem

	{
	glClear(GL_COLOR_BUFFER_BIT);
// Limpa a janela com a cor especificada como cor de fundo.
// O par�metro GL_COLOR_BUFFER_BIT indica o buffer onde a imagem ser�
// armazenada internamente. Limpar o buffer com glClear remove o desenho da
// janela.

    // Aqui devem ser inseridas chamadas de fun��es OpenGL para desenho
    glClearColor(1,0,0,0);

    glColor3f (1.0f, 1.0f, 0.0f);
// Especifica (R,G,B) = (1,1,0) como cor amarela da figura. Todos os objetos
// desenhados a partir deste ponto ter�o cor amarela.

    glBegin (GL_LINES);
	  glVertex2f (P1.x,P1.y);
      glColor3f (1.0f, 1.0f, 0.0f);
	  glVertex2f (P2.x,P2.y);
      glColor3f (1.0f, 1.0f, 0.0f);
      glVertex2f (P3.x,P3.y);
      glColor3f (1.0f, 1.0f, 0.0f);
      glVertex2f (P4.x,P4.y);
      glColor3f (1.0f, 1.0f, 0.0f);
   	  //glVertex2f (P1.x,P1.y);
    glEnd();
   // glutSolidTeapot(0.4);
// Chamadas de fun��es OpenGL para desenho
// As fun��es glBegin ( ) e glEnd ( ) delimitam os v�rtices da figura ou de um
// grupo de figuras. O par�mtro GL_TRIANGLES indica que os v�rtices especificados
// a seguir devem ser tratados como um trio de prontos para compor um tri�ngulo.
// a fun��o glVertex define as coordenadas de um v�rtice.


    glFlush();
// Flush dos comandos de desenho que estejam no "pipeline" da OpenGL
// para conclusao da geracao da imagem, isto �, come�a a processar as rotinas
// OpenGL. Neste exemplo de programa tem apenas a fun��o glClear.

}


// Inicializa aspectos do renderin
void Inicializa(void)
    {
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
// determina a cor de fundo da janela
}

// Inicializa os tres pontos com valores default
void InicializaObjeto(void)
    {
    P1.x = 0;
    P1.y = 1;
    P2.x = -1;
    P2.y = 0;
    P3.x = 0;
    P3.y = -1;
    P4.x = 1;
    P4.y = 0;
    }

// programa principal - ponto de in�cio de execu��o
// Cria janela
// Inicializa aspectos relacionados a janela e a geracao da imagem
// Especifica a fun��o de callback de desenho
int main(int argc, char** argv)
    {
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Indica que deve ser usado um unico buffer para armazenamento da imagem e representacao de cores RGB
	glutCreateWindow("Primeira Aplica��o OpenGL"); // Cria uma janela com o titulo especificado
 	glutDisplayFunc(Desenha); // Especifica para a OpenGL que funcao deve ser chamada para geracao da imagem
	Inicializa();       // Executa a inicializacao de parametros de exibicao
    InicializaObjeto(); // Inicializa as informacoes geometricas do objeto
	glutMainLoop();     // Dispara a "maquina de estados" de OpenGL
    }

