#include <stdio.h>
#include <GL/glut.h>

#include <stdlib.h>
static bool fullscreen = false;
int N = 200;        // default size

void OpenGLInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
}               

void draw_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int k)
{
    GLfloat ab[2], bc[2], ac[2];
    int j;

    if(k > 1)
    {
        for(j = 0; j < 2; j++) ab[j] = (a[j] + b[j]) / 2.0;
        for(j = 0; j < 2; j++) bc[j] = (b[j] + c[j]) / 2.0;
        for(j = 0; j < 2; j++) ac[j] = (a[j] + c[j]) / 2.0;

        GLfloat r = rand() %10 /10.0;
        GLfloat g = rand() %10/10.0;
        GLfloat _b = rand() %10/10.0;
        glColor3f(r,g,_b);
        triangle(ab, bc, ac);
        draw_triangle(a, ab, ac, k - 1);
        draw_triangle(b, bc, ab, k - 1);
        draw_triangle(c, ac, bc, k - 1);
    }
    else
    {
        glColor3f(1.0,1.0,1.0);
        triangle(a, b, c);
    }
}

void render()
{
    GLfloat a[2] = {0.2, 0.2};
    GLfloat b[2] = {9.8, 0.2};
    GLfloat c[2] = {5.0, 8.5};

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    draw_triangle(a, b, c, N);
    glEnd();
    glFlush();
}   

static void KeyPressFunc( unsigned char Key, int x, int y )
{
    switch ( Key ) {
        case 'F':
        case 'f': //toggle screenmode
            if(!fullscreen){
                glutFullScreen();
                fullscreen = true;
            } else if(fullscreen){
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
        case 27:    // Escape key
            exit(1);
    }
}

int main(int argc, char **argv)
{
    printf("Size : ");
    scanf("%d", &N);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize( 800, 800 );
    glutCreateWindow("Sierpinski Triangle");
    glutDisplayFunc(render);
    glutKeyboardFunc( KeyPressFunc );
    OpenGLInit();
    glutMainLoop();
    return 0;
}