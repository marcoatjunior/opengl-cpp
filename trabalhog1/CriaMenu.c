// Pratica #2 - Prog. CriaMenu.cpp
// Objetivo: Implementa interação por menu pop-up e por teclado
// UNILASALLE - Computação Gráfica - 2003/2
// prof. Magalí T. Longhi
// Baseado no programa BasicoMenu.cpp - autor prof. Carla M. Freitas
// UFRGS - fevereiro,2002
// alterado por Mozart Lemos de Siqueira em agosto de 2006

#include <GL/glut.h>
// include de headers ou definicoes das funcoes da glut
//   glut.h inclui gl.h e glu.h, que definem, respectivamente, as bibliotecas de
//   função OpenGL e GLU.
//   glut.h inclui tambem definicoes necessarias para o uso de OpenGl nos
//   diversos ambientes Windows


// constantes usadas para identificar objetos
#define TRIANGULOCHEIO 1
#define TRIANGULOARAME 2
#define QUADRILATEROARAME 3
#define QUADRILATEROCHEIO 4

// estrutura que descreve um ponto (x,y)
typedef struct XY {
        float x;
        float y;
} PontoXY;

PontoXY P0, P1, P2, P3, P4;  

// guarda o tipo de objeto que deve ser  exibido
int objeto;

// Função de callback (recursiva) de desenho
// Executada sempre que é necessario re-exibir a imagem
void Desenha(void)
	{
   	glClear(GL_COLOR_BUFFER_BIT);
    // Limpa a janela com a cor especificada como cor de fundo.
    // O parâmetro GL_COLOR_BUFFER_BIT indica o buffer onde a imagem será
    // armazenada internamente. Limpar o buffer com glClear remove o desenho da
    // janela.
     
    // Chamadas de funções OpenGL para desenho
    // Observe que P0 corresponde a posição do objeto no SRU
    // Os demais pontos correspondem a geometria do objeto relativa a (0,0)
    switch (objeto)
    {
        case TRIANGULOCHEIO: 
           {glBegin (GL_TRIANGLES);
	           glVertex2f (P0.x+P1.x,P0.y+P1.y);
	           glVertex2f (P0.x+P2.x,P0.y+P2.y);
	           glVertex2f (P0.x+P3.x,P0.y+P3.y);
             glEnd();
             break;
           }
        case TRIANGULOARAME: 
           {glBegin (GL_LINE_LOOP);
	           glVertex2f (P0.x+P1.x,P0.y+P1.y);
	           glVertex2f (P0.x+P2.x,P0.y+P2.y);
	           glVertex2f (P0.x+P3.x,P0.y+P3.y);
             glEnd();
             break;
           }
        case QUADRILATEROARAME:
           {glBegin (GL_LINE_LOOP);
	           glVertex2f (P0.x+P1.x,P0.y+P1.y);
	           glVertex2f (P0.x+P2.x,P0.y+P2.y);
               glVertex2f (P0.x+P4.x,P0.y+P4.y);
	           glVertex2f (P0.x+P3.x,P0.y+P3.y);               
            glEnd();
            break;   
           }
        case QUADRILATEROCHEIO:
           {
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
	// Alterna o buffer de geracao da imagem; contem um "flush" implicito.
    // Ou seja, glutSwapBuffers é usada no lugar da glFlush. Quando ocorre
    // a troca (ou swap) de buffers é feita, implicitamente, uma operação de
    // flush. Esta função continua fazendo o flush mesmo que o programa esteja
    // sendo executado no modo single-buffer, porém com uma qualidade bastante
    // inferior.
    // O Flush dispara os comandos de desenho que estejam no "pipeline" da
    // OpenGL para conclusao da geracao da imagem, isto é, começa a processar as
    // rotinas OpenGL.
    }


// Inicializa aspectos do rendering
void Inicializa(void)
    {
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);  // cor azul de fundo da janela
    }

// Inicializa os pontos com valores default, cor vermelha e objeto aramado
void InicializaObjeto (void)
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
    glColor3f(1.0f, 0.0f, 0.0f);
    objeto=TRIANGULOARAME;
    }

// Callback de teclas especiais
// Desloca a origem do objeto conforme as teclas
// Não evita que saia da área vísivel    
void TeclasEspeciais(int tecla, int x, int y)
	{
    if(tecla == GLUT_KEY_UP)
		P0.y += 0.5;
	if(tecla == GLUT_KEY_DOWN)
		P0.y -= 0.5f;
	if(tecla == GLUT_KEY_LEFT)
		P0.x -= 0.5f;
	if(tecla == GLUT_KEY_RIGHT)
		P0.x += 0.5f;
	glutPostRedisplay();
    }
   
// Callback comum de teclado     
void Teclado ( unsigned char tecla, int x, int y )
{
     if(tecla == 'r') // reset do objeto para a origem (0,0) e vermelho
       { P0.x=0; 
         P0.y=0;
         glColor3f(1.0f,0.0f,0.0f);
       }
     glutPostRedisplay();
     // Esta rotina deve ser chamada toda vez que um evento ocasionar uma
     // mudança no que está sendo exibido na tela e esta mudança precisa ser
     // re-exibida.
}
// Callback de menu     
void TrataMenu ( int valor )
{
     switch(valor)
        {
        case 1: // cor vermelha
            glColor3f (1.0f, 0.0f, 0.0f);
            break;

        case 2: // cor azul
            glColor3f (0.0f, 0.0f, 1.0f);
            break;

        case 3: // cor verde
            glColor3f (0.0f, 1.0f, 0.0f);
            break;

        case 4:  // cor branca
            glColor3f (1.0f, 1.0f, 1.0f);
            break;

        case 5:  // cor preta
            glColor3f (0.0f, 0.0f, 0.0f);
            break;

        case 6:   // cor amarela
            glColor3f (1.0f, 1.0f, 0.0f);
            break;

        case 7:   // triangulo preenchido
            objeto=TRIANGULOCHEIO;
            break;

        case 8:    // triangulo aramado
            objeto=TRIANGULOARAME;
            break;

        case 9:    // quadrilatero aramado
            objeto=QUADRILATEROARAME;
            break;
        case 10:   // um quadrilatero preenchido
            objeto=QUADRILATEROCHEIO;
            break;
        case 11:   // cor de fundo branca
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
            break;
        case 12:   // cor de fundo azul
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
            break;
        
        default: // default para objeto
            objeto=TRIANGULOARAME;
            break;
        }
     
     glutPostRedisplay();   
}


// Parte principal - ponto de início de execução
// Cria janela 
// Inicializa aspectos relacionados a janela e a geracao da imagem
// Cria menus e associa função de tratamento
// Especifica a função callback de desenho
// Especifica funções de callback de teclado para teclas normais e especiais

int main(int argc, char** argv)
    {
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     // Indica que devem ser usados dois buffers para armazenamento da imagem e
     // representacao de cores RGB

	glutCreateWindow("OpenGL com Uso de Menus");
    // Cria uma janela com o titulo especificado


	int menuCor;       // sub-menu para cor do objeto
    int menuObjeto;    // sub-menu para tipo de objeto
    int mainMenu;      // Cria menu para escolher a cor corrente e o objeto a
                       // ser exibido
          
    menuCor = glutCreateMenu(TrataMenu);
	glutAddMenuEntry("Vermelho",1);
	glutAddMenuEntry("Azul",2);
	glutAddMenuEntry("Verde",3);
	glutAddMenuEntry("Branco",4);
	glutAddMenuEntry("Preto",5);
	glutAddMenuEntry("Amarelo",6);
		
	menuObjeto = glutCreateMenu(TrataMenu);
	glutAddMenuEntry("Triangulo preenchido",7);
	glutAddMenuEntry("Triangulo aramado",8);
	glutAddMenuEntry("Quadrilatero aramado",9);
	glutAddMenuEntry("Quadrilater preenchido",10);
	    
	mainMenu = glutCreateMenu(TrataMenu);
	glutAddSubMenu("Cor", menuCor);
   	glutAddSubMenu("Objeto", menuObjeto);
    glutAddMenuEntry("Fundo Branco",11);
    glutAddMenuEntry("Fundo Azul",12);
        
	glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutKeyboardFunc(Teclado);
    // Especifica a funcao que vai tratar teclas comuns 

    glutSpecialFunc(TeclasEspeciais);
    // Especifica a funcao que vai tratar teclas especiais

	glutDisplayFunc(Desenha);
    // Especifica para a OpenGL a funcao responsável pelo desenho

	Inicializa();
    // Executa a inicializacao de parametros de exibicao

    InicializaObjeto();
    // Inicializa as informacoes geometricas do objeto

	glutMainLoop();
    // Dispara a "maquina de estados" de OpenGL 
    }

