#include <iostream>

#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <GLUT/glut.h>
#elif defined(WIN32)
# include <Windows.h>
#endif

#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;
static bool fullscreen = false;
void OpenGLInit(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void render(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(xRotated, 0.4, 0.0, 0.0);
    // rotation about Y axis
    glRotatef(yRotated, 0.0, 0.4, 0.0);
    // rotation about Z axis
    glRotatef(zRotated, 0.0, 0.0, 0.4);
    // initial position // Move right and into the screen
    glBegin(GL_QUADS); // Begin drawing the color cube with 6 quads
    // Top face (y = 0.4f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(0.4f, 0.4f, -0.4f);
    glVertex3f(-0.4f, 0.4f, -0.4f);
    glVertex3f(-0.4f, 0.4f, 0.4f);
    glVertex3f(0.4f, 0.4f, 0.4f);

    // Bottom face (y = -0.4f)
    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    glVertex3f(0.4f, -0.4f, 0.4f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glVertex3f(-0.4f, -0.4f, -0.4f);
    glVertex3f(0.4f, -0.4f, -0.4f);

    // Front face  (z = 0.4f)
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-0.4f, 0.4f, 0.4f);
    glVertex3f(-0.4f, -0.4f, 0.4f);
    glVertex3f(0.4f, -0.4f, 0.4f);

    // Back face (z = -0.4f)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, 0.4f, -0.4f);
    glVertex3f(0.4f, 0.4f, -0.4f);

    // Left face (x = -0.4f)
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(-0.4f, 0.4f, 0.4f);
    glVertex3f(-0.4f, 0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, -0.4f);
    glVertex3f(-0.4f, -0.4f, 0.4f);

    // Right face (x = 0.4f)
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(0.4f, 0.4f, -0.4f);
    glVertex3f(0.4f, 0.4f, 0.4f);
    glVertex3f(0.4f, -0.4f, 0.4f);
    glVertex3f(0.4f, -0.4f, -0.4f);
    glEnd(); // End of drawing color-cube
    glutSwapBuffers();
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
            glutPositionWindow(600, 600);
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
void animation(void)
{
    yRotated += 0.01;
    xRotated += 0.02;
    render();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cube");
    //glutFullScreen();

    OpenGLInit();
    glutKeyboardFunc(KeyPressFunc);
    glutDisplayFunc(render);
    glutIdleFunc(animation);
    glutMainLoop();
    return (0);
}