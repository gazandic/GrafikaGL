#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <GLUT/glut.h>
#elif defined(WIN32)
# include <Windows.h>
#endif

#include <GL/glut.h>

static bool fullscreen = false;
int N = 200; // default density

void OpenGLInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void render(void)
{
    GLfloat vertices[3][2] = {
        {0.0, 0.0},
        {25.0, 50.0},
        {50.0, 0.0}};
    int j, k;
    int rand();
    GLfloat p[2] = {7.5, 5.0};
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (k = 0; k < N; k++)
    {
        j = rand() % 3;
        p[0] = (p[0] + vertices[j][0]) / 2.0;
        p[1] = (p[1] + vertices[j][1]) / 2.0;
        glVertex2fv(p);
    }
    glEnd();
    glFlush();
}

static void KeyPressFunc(unsigned char Key, int x, int y)
{
    switch (Key)
    {
    case 'F':
    case 'f': //toggle screenmode
        if (!fullscreen)
        {
            glutFullScreen();
            fullscreen = true;
        }
        else if (fullscreen)
        {
            glutReshapeWindow(300, 300);
            glutPositionWindow(800, 800);
            fullscreen = false;
        }
        break;
    case 'H':
    case 'h': //toggle screenmode
        glutHideWindow();
        break;
    case 'S':
    case 's': //toggle screenmode
        glutShowWindow();
        break;
    case 27: // Escape key
        exit(1);
    }
}

int main(int argc, char **argv)
{
    printf("Density : ");
    scanf("%d", &N);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Sierpinski Point");
    glutKeyboardFunc(KeyPressFunc);
    glutDisplayFunc(render);
    OpenGLInit();
    glutMainLoop();
}
