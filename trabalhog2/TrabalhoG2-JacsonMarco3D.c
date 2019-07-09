#include "glut.h"
#include <stdlib.h>
// include de headers ou definicoes das funcoes da glut
// glut.h inclui gl.h e glu.h, que definem, respectivamente, as bibliotecas de
// fun��o OpenGL e GLU.
// glut.h inclui tambem definicoes necessarias para o uso de OpenGl nos
// diversos ambientes Windows

// constantes usadas para identificar objetos
#define MAINSCREEN 1
#define PLANET 2
#define WORLD 3
#define MONUMENT 4
#define BRASIL 5
#define PI 3.1415926535898
int proj=1;
float ang=0.0,ze=15,xis;
// constantes usadas para incrementar as verticais x e y
float cmx = 0;
float cmy = 0.5;
// guarda o tipo de objeto que deve ser  exibido
int object;
//void reshape(int w, int h);
// fun��o para escrever na tela
void drawBitmapText(char *string, float x, float y, float z){
    //pego a string passada com o ponteiro *c
    char *c;
    //especifica a posi��o na tela com as variav�is x, y, z
    glRasterPos3f(x, y, z);
    //la�o para pegar cada posi��o e renderizar na tela
    for (c = string; *c != '\0'; c++) {
        //pega o caracter e aplica a fonte
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

// inicia a renderiza��o antes do desenho
void create(void){
    //  define a cor
    glClearColor(0.0f, 0.486f, 0.604f, 1);
    //glClearColor(0.9f, 0.9f, 0.9f,1);
}
// fun��o para criar o objeto padr�o
void createObject(void)
{
    // define a cor e o objeto
    glColor3f(0.0f, 0.486f, 0.604f);
    object=MAINSCREEN;
}

// fun��o desenha
// Executada sempre que � necess�rio re-exibir a imagem
void draw(void){
    // limpa a janela com a cor especificada. (GL_COLOR_BUFFER_BIT indica
    // o buffer onde a imagem ser� armazenada
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //switch/case para cada op��o com um break logo ap�s parar(sem o break
    //o iria executar todos os cases
    switch (object) {
        case MAINSCREEN:
        // case principal, passo a cor de fundo e o texto pelo drawBitmapText
            glColor3f(0, 0, 0);
            drawBitmapText("Bem-vindos a aula de Geografia!", -0.65, 0, 0);
            break;
        case BRASIL:
        // chama a fun��o drawBrasil
            drawBrasil();
            break;
        case PLANET:
        // chama a fun��o drawPlanet
            drawPlanet();
            break;
        case WORLD:
        // chama a fun��o drawWorld
            drawWorld();
            break;
        case MONUMENT: {
        // chama a fun��o drawMonument
            drawMonument();
            break;
        }
    }
    // usado no lugar do flush, altera o buffer de gera��o de imagem
    // processa as rotinas do OpenGL
    glutSwapBuffers();
}

// fun��o para desenhar o planeta
void drawPlanet(void){
    // definidas vari�veis de inicio
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat luzAmbiente[4]={0.1,0.1,0,1,0.1}; // RGBA = cor Branca
    GLfloat luzDifusa[4]={0.8,0.8,0.8,1.0}; // "cor" R=0,8; G=0,8; B=0,8; a=1,0
    GLfloat luzEspecular[4]={1.0, 0.0, 0.0, 1.0}; // "brilho" RGBA= cor Branca
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0}; // posi��o da luz difusa
	GLfloat circle_points = 1000;

    glLoadIdentity();
	glMatrixMode(GL_PROJECTION);

	glColor3f(1, 1, 1);
    drawBitmapText("Utilize as setas direcionais", -0.65, -0.80, 0);
    drawBitmapText("Via Lactea Marco e Jacson", -0.65, 0.80, 0);

	glPushMatrix();
    gluPerspective(0.,1.0,1.0,1.0);//define a perspectiva
    gluLookAt(0.17, 0.5, 0, 1, 1, -1, .5, 0, 0);
    glTranslatef(-0.3, 0.2, 0.7);
    glRotatef(0,1.0,1,1.0);
    glColor3f(0.9569,0.6196,0.0706);
    glutSolidSphere(0.1,30,20);
    glColor3f(0,0,0);
    glutWireSphere(0.1,10,20);
    glPopMatrix();

	glPushMatrix();
    gluPerspective(0.4,1,1,1);//define a perspectiva
    gluLookAt(cmx, 0, cmy, 0, 0, 0, 0, 1, 0);
    glTranslatef(0.5, 0.08, 0.7);
    glRotatef(0.1,1.0,0.0,0);
    glColor3f(0.3059,0.2314,0.1922);
    glutSolidSphere(0.1,30,20);
    glColor3f(0,0,0);
    glutWireSphere(0.1,10,20);
    glPopMatrix();
}
// funcao para detectar tecla e movimentar o desenho
void planetOption(int key){
    // op��es de decis�o do teclado com incremento de 0.01
    if (key == GLUT_KEY_RIGHT) {
        cmx -= 0.03f;
        cmy += 0.03f;
        cmx = cmx < -0.4f ? 0.4f : cmx;
        cmy = cmy > 0.4f ? -0.4f : cmy;
    }
    if (key == GLUT_KEY_LEFT) {
        cmx += 0.03f;
        cmy -= 0.03f;
        cmx = cmx > 0.4? -0.4f : cmx;
        cmy = cmy < -0.4f ? 0.4f : cmy;
    }
    glutPostRedisplay();
}
// funcao para escrever na tela e a resposta
void drawBrasil(void){
	// definida a cor
	glColor3f(0, 0, 0);
	// chamada a fun��o para escrever com suas respectivas posi��es
    drawBitmapText("ACERTOU!", -0.9, 0.4, 0);
	drawBitmapText("180 milhoes de habitantes...", -0.9, 0.2, 0);
	drawBitmapText("Fica localizado na America do Sul...", -0.9, 0, 0);
	drawBitmapText("E sua capital e Brasilia!", -0.9, -0.2, 0);
}

// fun��o para desenhar a bandeira
void drawWorld(void){
    // defini��o de vari�veis iniciais
	GLfloat circle_points = 1000;
	int i;
	double angle;
	float x = 0;
	float y = 0.5;
    //desenha o retangulo
	glBegin(GL_POLYGON);
        //define cor e cordenadas x e y
		glColor3f(0, 1, 0);
		glVertex2f(-0.4,0.8);
		glVertex2f(0.4,0.8);
		glVertex2f(0.4,0.2);
		glVertex2f(-0.4,0.2);
	glEnd();
    //desenha o losango
	glBegin(GL_POLYGON);
        //define cor e cordenadas x e y
		glColor3f(1,1,0);
		glVertex2f(0,0.75);
		glVertex2f(-0.3,0.5);
		glVertex2f(0,0.25);
		glVertex2f(0.3,0.5);
	glEnd();
    // desenha o circulo com o uso de um la�o,com tamanho e lugar definido
    // na tela, com o auxilio da vari�vel PI para fazer o circulo
	glBegin(GL_POLYGON);
	   glColor3f(0,0,1);
	   for (i = 0; i < circle_points; i++) {
		   angle = 5*PI*i/circle_points;
		   glVertex2f(x+cos(angle)/6.5,y+sin(angle)/6.5);
	   }
	glEnd();
    //define a cor
	glColor3f(0, 0, 0);
	// chamada a fun��o para escrever com suas respectivas posi��es
	drawBitmapText("Qual pais e representado pela bandeira acima?", -0.9, -0.1, 0);
	drawBitmapText("(A) Argentina", -0.9, -0.35, 0);
	drawBitmapText("(B) Brasil", -0.9, -0.50, 0);
	drawBitmapText("(C) Chile", -0.9, -0.65, 0);
	drawBitmapText("(D) Dinamarca", -0.9, -0.80, 0);
}

//fun��o para selecionar a op��o correta passando o teclado
void worldOption(unsigned char key){
    //detecta a tecla precionada e chama o objeto da resposta
    if(key == 'b') {
        object=BRASIL;
        draw();
    }
}

// fun��o para desenhar a pir�mede
void drawMonument(void){
    glColor3f(0.6,0.3,0.1);
    GLfloat circle_points = 1000;

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

void monumentOption(int key){
    // op��es de decis�o do teclado com incremento de 0.01
    if(key == GLUT_KEY_UP) { //cmx += 0.01f;
		ang+=3;
    }
    if(key == GLUT_KEY_DOWN) { //cmy -= 0.01f;
		ang-=3;
    }
    if (key == GLUT_KEY_RIGHT) { //cmx += 0.01f;
		ang+=3;
    }
    if (key == GLUT_KEY_LEFT) { //cmx -= 0.01f;
		ang-=3;
    }
    // faz uma nova exibi��o atualizando o desenho e limpando o anterior
    glutPostRedisplay();
}

//fun��o para escolhas de objetos
void menu(int value){
    //switch/case para cada op��o com um break logo ap�s parar(sem o break
    //iria executar todos os cases abaixo
    switch(value) {
		case 0:
		    //envia o objeto a ser desenhado para o outro switch
			object=PLANET;
			//passa o teclado com teclas especiais
			glutSpecialFunc(planetOption);
			break;
		case 1:
			object=WORLD;
			//passa o teclado com teclas normais
			glutKeyboardFunc(worldOption);
			break;
		case 2:
			object=MONUMENT;
			glutSpecialFunc(monumentOption);
			break;
		case 3:
		    //sai do programa
			exit(0);
			break;
		default:
		    //objeto default
			object=MAINSCREEN;
			break;
    }
    // faz uma nova exibi��o atualizando o desenho e limpando o anterior
    glutPostRedisplay();
}

//fun��o principal
int main(int argc, char** argv){
    glutInit (&argc, argv);
    //define o tamanho da janela
    glutInitWindowSize(500, 400);
    //define a posi��o da janela
    glutInitWindowPosition(450, 150);
    // Indica que devem ser usados dois buffers para armazenamento da imagem e
    // representacao de cores RGB
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //define o titulo da janela
    glutCreateWindow("Aula de Geografia");
    //cria��o do menu para a sele��o
    glutCreateMenu(menu);
    //op��es do menu
    glutAddMenuEntry("Planeta", 0);
    glutAddMenuEntry("Mundo", 1);
    glutAddMenuEntry("Monumento", 2);
    glutAddMenuEntry("Sair", 3);
    //define o bot�o o qual chamamos o menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    //passa a funcao especifica do desenho
    glutDisplayFunc(draw);
    //executa os parametros inicias de exebi��o
    create();
    // Inicializa as informacoes geometricas do objeto
    createObject();
    // Dispara a "maquina de estados" de OpenGL
    glutMainLoop();
    return 0;
}
