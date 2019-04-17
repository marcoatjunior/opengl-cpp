// UsoMouse.cpp
// UNILASALLE - Computação Gráfica - 2003/2
// Autor: Prof. Magalí T. Longhi
// Objetivo: implementa o uso do mouse através dos conceitos de programamção
//           2D com GLUT
//   alterado por Mozart Lemos de Siqueira em agosto de 2006
/* include de definicoes das funcoes da glut 
   glut.h inclui gl.h, que contem os headers de funcoes da OpenGL propriamente dita
   glut.h inclui tambem definicoes necessarias para o uso de OpenGl nos diversos ambientes Windows
*/
#include <GL/glut.h>

// estrutura que descreve um ponto (x,y)
typedef struct XY {
        float x;
        float y;
} PontoXY;

PontoXY P1, P2, P3;


// Função de callback de desenho
// Executada sempre que é necessario re-exibir a imagem
void Desenha(void)
	{
	// Limpa a janela com a cor especificada como cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);
 
    // Chamadas de funções OpenGL para desenho
    glBegin (GL_TRIANGLES);
	  glVertex2f (P1.x,P1.y);
	  glVertex2f (P2.x,P2.y);
	  glVertex2f (P3.x,P3.y);
    glEnd();

	// Flush dos comandos de desenho que estejam no "pipeline" da OpenGL
    // para conclusao da geracao da imagem
    glFlush();
	}


// Inicializa aspectos do rendering
void Inicializa(void)
    {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // cor de fundo da janela
    }

// Inicializa os tres pontos com valores default
void InicializaObjeto (void)
    { 
    P1.x = 0;
    P1.y = 1;
    P2.x = -1;
    P2.y = 0;
    P3.x = 1;
    P3.y = 0;

//  Especifica a cor inicial da primitivas grafica
    glColor3f (1.0f, 0.0f, 0.0f);
    }
    
// Especifica callback comum de teclado
void Teclado( unsigned char tecla, int x, int y )
{
     if(tecla == 'r')
       InicializaObjeto();
       glutPostRedisplay();
     
}

/*
*---------------------------------------------------------- 
* Rotina para tratamento de eventos relacionados ao mouse 
* 
* botao: Botao que foi pressionado.
* GLUT_LEFT_BUTTON, GLUT_RIGHT_BUTTON, GLUT_MIDDLE_BUTTON 
* 
* estado: botão clicado ou solto
* GLUT_UP ou GLUT_DOWN 
* 
* x,y: posicao do mouse dentro da janela 
*---------------------------------------------------------- 
*/ 
void Mouse ( int botao, int estado, int x, int y )
{
     if ( botao == GLUT_LEFT_BUTTON )
        glColor3f(1.0, 1.0, 0.0);

     if ( botao == GLUT_RIGHT_BUTTON )
        glColor3f(0.0, 1.0, 1.0);

     glutPostRedisplay();
}       
    
// Parte principal - ponto de início de execução
// Cria janela 
// Inicializa aspectos relacionados a janela e a geracao da imagem
// Especifica a função de callback de desenho
// Especifica funções de callback de teclado para teclas normais e especiais
int main(int argc, char** argv)
    {
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Indica que deve ser usado um unico buffer para armazenamento da imagem e 
    //representacao de cores RGB
    
    // Cria uma janela com o titulo especificado
	glutCreateWindow("OpenGl com uso do Mouse");

    // Especifica a funcao que vai tratar teclas comuns 
    glutKeyboardFunc(Teclado);
    
    // Especifica a funcao que vai tratar teclas especiais
 	//glutSpecialFunc(TeclasEspeciais);

    // Especifica call back de mouse
    glutMouseFunc(Mouse);
  
    // Especifica para a OpenGL que funcao deve ser chamada para geracao da imagem
	glutDisplayFunc(Desenha);

    // Executa a inicializacao de parametros de exibicao
	Inicializa();
 
    // Inicializa as informacoes geometricas do objeto
    InicializaObjeto();

    // Dispara a "maquina de estados" de OpenGL 
	glutMainLoop();
    }

