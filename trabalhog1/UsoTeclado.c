// UsoTeclado.cpp
// UNILASALLE - Computação Gráfica - 2003/2
// Prof. Magalí T. Longhi
// Objetivo: mostra como OPENGL e GLUT podem ser utilizadas quando das
//           interveções do usuário através do teclado
// OBS.: Baseado no programa BasicoTeclado.cpp de Carla M. Freitas (UFRGS)
//   alterado por Mozart Lemos de Siqueira em agosto de 2006

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
 
    // Especifica que as primitivas graficas devem ser de cor vermelha
    glColor3f (1.0f, 0.0f, 0.0f);
    
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
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);  // cor de fundo da janela
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
    }
    
void TeclasEspeciais(int tecla, int x, int y)
 {
    if(tecla == GLUT_KEY_UP)
		P1.y += 0.5;

	if(tecla == GLUT_KEY_DOWN)
		P1.y -= 0.5f;

	if(tecla == GLUT_KEY_LEFT)
		P1.x -= 0.5f;

	if(tecla == GLUT_KEY_RIGHT)
		P1.x += 0.5f;

	if(P1.y < -1.0f)
		P1.y = -1.0f;

	if (P1.y > 1.0f)
		P1.y = 1.0f;

    if (P1.x < -1.0f)
		P1.x = -1.0f;

    if (P1.x > 1.0f)
		P1.x = 1.0f;

// Refresh da imagem: força a execuçao da rotina "desenha"
	glutPostRedisplay();
    }
    

// Especifica callback comum de teclado     
void Teclado( unsigned char tecla, int x, int y )
{
     if(tecla == 'r')
       InicializaObjeto();
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
	glutCreateWindow("Programa com uso de Teclado");

    // Especifica a funcao que vai tratar teclas comuns 
    glutKeyboardFunc(Teclado);
    
    // Especifica a funcao que vai tratar teclas especiais
 	glutSpecialFunc(TeclasEspeciais);
  
    // Especifica para a OpenGL que funcao deve ser chamada para geracao da imagem
	glutDisplayFunc(Desenha);

    // Executa a inicializacao de parametros de exibicao
	Inicializa();
 
    // Inicializa as informacoes geometricas do objeto
    InicializaObjeto();

    // Dispara a "maquina de estados" de OpenGL 
	glutMainLoop();
    }

