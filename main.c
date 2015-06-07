//TRABALHO FINAL DE COMPUTAÇÃO GRÁFICA 2015

//ABOMINATION HUNTER GAME
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hunter.h"
#include "weapon.h"
#include "world.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define SCREEN_WIDTH 800
#define SCREEN_HIGHT 600

#define TIMER_DURATION 1000

//CONTROLE DE VERSÃO
static float version = 0.01f;
//CONTROLE DE JANELA
static int win;

//CAMERA
GLfloat cam_distance;
GLfloat cam_pos[3];

//MOUSE
//Posição do cursor
GLdouble mouseX, mouseY, mouseZ;

//PERSONAGEM

Hunter h;

//MUNDO

Map m;

//INCIALIZAÇÃO DE ESTADO DO JOGO

void initGame()
{

    h = initHunter();
    m = initWorld();
}

//GAME OVER

void endGame()
{
	printf("You died!!!\n");
	exit(1);
}

//funções CALLBACK
//Aqui entratiam as funções que são executadas independemente das interações, tipo animação do ambiente

int checkHunterPosition()
{
	if (h.pos[0] > m.size) return 1;
	else if (h.pos[2] > m.size) return 1;
	else return 0;
}

void gameRun(int tick)
{
	printf("x %.2f y %.2f\n", h.pos[0], h.pos[2]);
	if (checkHunterPosition()) {
		h.hp = 0;
	}
	//...
	if (isHunterDead(h)) endGame();
	//...

	glutPostRedisplay();
	glutTimerFunc(TIMER_DURATION, gameRun, 1);
}

/*
Função de inicialização, aqui serão determinados as propriedades do nosso programa,
o tipo de iluminação, a perspectiva e etc
*/

void initGL(int Width, int Height)
{
	//FOG NÃO FUNCIONA BEM, PRECISO AJUSTAR O CÁLCULO DA AREA DE RENDERIZAÇÃO
	/*GLfloat fogColor[4] = {0.0f, 0.0f, 0.0f, 1.0f};
 
	glFogi(GL_FOG_MODE, GL_LINEAR);        // Fog Mode
	glFogi(GL_FOG_COORD_SRC, GL_FRAGMENT_DEPTH);
	glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
	glFogf(GL_FOG_DENSITY, 0.1f);              // How Dense Will The Fog Be
	glHint(GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
	glFogf(GL_FOG_START, 30.0f);             // Fog Start Depth
	glFogf(GL_FOG_END, 35.0f);               // Fog End Depth
	glEnable(GL_FOG);                   // Enables GL_FOG*/

	GLfloat light0_ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light0_position[] = {1.0, 1.0, 1.0, 0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

   	glShadeModel (GL_SMOOTH);
  	glClearDepth(1.0);

	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();

  	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);  

  	glMatrixMode(GL_MODELVIEW);

	//CAMERA
	cam_distance = 15.0f;
	cam_pos[0] = cam_distance;
	cam_pos[1] = cam_distance;
	cam_pos[2] = cam_distance;

}

/*
Função de que faz a recalculo da cena caso a janela mude de tamanho
*/

void changeSize(int Width, int Height)
{
    if (Height==0)
        Height=1;

    glViewport(0, 0, Width, Height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
}

/////////////////////////////////////////
//      FUNÇÕES DE RENDERIZAÇÃO        //
/////////////////////////////////////////

//CAÇADOR
void renderBodyHunter(Hunter h)
{
    glColor3f(0.5, 0.5, 0.3);
    glTranslatef(0.0, h.hight, 0.0);

    //CORPO
    glPushMatrix();
    glScalef(0.6, 1.5, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    //CABEÇA
    glTranslatef(0.0, 1.5, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glutSolidSphere(0.5, 5, 5);
    glPopMatrix();
}

void renderHunter(Hunter h)
{

    glPushMatrix();
    glTranslatef(h.pos[0], h.pos[1], h.pos[2]);
    glRotatef(h.angle, 0.0, 1.0, 0.0);
    renderBodyHunter(h);
    //renderArms
    //renderLegs
    // ...
    glPopMatrix();
}


//MAPA

//Desenha uma arvore
void renderTree(Tree t)
{

    //TRONCO
    glPushMatrix();
    glColor3f(8.0f, 5.0f, 2.0f);
    glRotatef(270, 1.0f, 0.0f, 0.0f);
    glutSolidCone(0.25f, 3.0f, 6, 6);
    glPopMatrix();

    //FOLHAS
    glPushMatrix();
    glColor3f(0.05f, 0.5f, 0.05f);
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(270, 1.0f, 0.0f, 0.0f);
    glutSolidCone(2.0f, 2.0f, 10, 6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1f, 0.6f, 0.1f);
    glTranslatef(0.0f, 2.0f, 0.0f);
    glRotatef(270, 1.0f, 0.0f, 0.0f);
    glutSolidCone(1.5f, 2.0f, 10, 6);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2f, 0.9f, 0.1f);
    glTranslatef(0.0f, 3.0f, 0.0f);
    glRotatef(270, 1.0f, 0.0f, 0.0f);
    glutSolidCone(1.0f, 2.0f, 10, 6);
    glPopMatrix();
}

//SOLO

void renderMap()
{

    int i;

    glPushMatrix();
	//CHÃO
    glColor3f(0.2f, 0.5f, 0.1f);
    glBegin(GL_QUADS);
    	glVertex3f(-m.size, 0.0f , -m.size);
    	glVertex3f(m.size, 0.0f, -m.size);
    	glVertex3f(m.size, 0.0f, m.size);
    	glVertex3f(-m.size, 0.0f, m.size);
    glEnd();
	//ÁGUA
	glColor3f(0.2f, 0.3f, 0.9f);
    glBegin(GL_QUADS);
    	glVertex3f(-m.size*10, -0.1f , -m.size*10);
    	glVertex3f(m.size*10, -0.1f, -m.size*10);
    	glVertex3f(m.size*10, -0.1f, m.size*10);
    	glVertex3f(-m.size*10, -0.1f, m.size*10);
    glEnd();
    glPopMatrix();

    for (i = 0; i < m.tree_count; i++)
    {
        glPushMatrix();
        glTranslatef(m.trees[i].loc[0], 0.0f, m.trees[i].loc[2]);
        renderTree(m.trees[i]);
        glPopMatrix();
    }
}

//Função principal de renderização

void renderScene(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(m.size+h.pos[0]+cam_pos[0],cam_pos[1],m.size+h.pos[2]+cam_pos[2],
              m.size+h.pos[0], h.pos[1], m.size+h.pos[2],
              0,1,0);

    glTranslatef(m.size, 0.0f, m.size);
    //DESENHA O MAPA
    renderMap(m);
    //DESENHA O CAÇADOR
    renderHunter(h);
    //DESENHA OS MONSTROS
    //renderMonsters()
    // ...

    glutSwapBuffers();
}

// Função de interação com o teclado

/*
Foi pensando em comandos de movimentação do legado FPS (W, A, S, D);
a tecla ESC sairia do loop principal da glut, retornando pro terminal do console
caso queiramos criar um menu protótipo
*/

void keyboard (unsigned char key, int x, int y)
{

    switch(key)
    {
    case 'w':
        h = forward(h, mouseZ);
        break;
    case 's':
        h = back(h, mouseZ);
        break;
    case 'a':
        h = left(h, mouseZ);
        break;
    case 'd':
        h = right(h, mouseZ);
        break;
    case 27 :
        glutDestroyWindow(win);
        exit(1);
        break;
    default :
        break;
    }
    glutPostRedisplay();
}

//Função de interação com o mouse

//Função que faz o personagem sempre olhar na direção em que o cursor estiver apontado
void cursor (int x, int y)
{

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;

    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winX = (float) x;
    winY = (float) viewport[3] - (float) y;
    glReadPixels( x, (int) winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &mouseX, &mouseY, &mouseZ);

    mouseX -= h.pos[0];
    mouseZ -= h.pos[2];

    h.angle = atan(mouseX/mouseZ)*180/M_PI;
    glutPostRedisplay();
}

/*
Foi pensado que o botão esquerdo ele executaria um ataque normal (tiro, espadada, machadada, etc)
e o botão direito ele executaria um movimento especial (chute, poder especial ou qualquer coisa do tipo)
*/

void mouse (int b, int e, int x, int y)
{
    switch (b)
    {
    case GLUT_LEFT_BUTTON :
        if (e == GLUT_DOWN)
            //attack();
            break ;
    case GLUT_RIGHT_BUTTON :
        if (e == GLUT_DOWN)
            //specialAttack();
            break ;
    default :
        break ;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{

    printf("ABOMINATION HUNTER v %.2f\n\n", version);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HIGHT);
    win = glutCreateWindow("Abomination Hunter Alpha .01");

    glutDisplayFunc(renderScene);
	glutTimerFunc(TIMER_DURATION, gameRun, 1);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(cursor);


    initGame();
    initGL(SCREEN_WIDTH, SCREEN_HIGHT);

    glutMainLoop();

    return 0;
}
