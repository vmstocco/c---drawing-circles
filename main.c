#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <gl/glut.h>
#include <time.h>

#define PI 3.1415926535898

// Função callback chamada para fazer o desenho
void Desenha()
{
     int i,j;
     int aux = 0;

     clock_t inicio, fim;

     //número de pontos do círculo;
     GLfloat circle_points = 200.0f;
     GLfloat angle, raioX = 1.0f, raioY = 1.0f;

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é verde
     //         R     G     B
     glColor3f(0.0f, 1.0f, 0.0f);

     glBegin(GL_LINE_LOOP);

        inicio = clock();
        //repete o algoritmo 100 vezes
        for(j = 0; j < 100; j++)
        {
            //calcula a posição e desenha os pontos do círculo
            for (i = 0; i < circle_points; i++)
            {
                angle = 2*PI*i/circle_points;
                glVertex2f(cos(angle)*raioX*aux+100, 100+sin(angle)*raioY*aux);
            }
            aux += 5;
        }
        fim = clock();

        printf("Tempo pra executar o algoritmo = %lf",((double)(fim - inicio)/CLOCKS_PER_SEC));

     glEnd();

     // Executa os comandos OpenGL
     glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;

                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h)
                           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                   else
                           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

// Programa Principal
int main(void)
{
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(700,700);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Quadrado");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     Inicializa();
     glutMainLoop();

     return 0;
}
