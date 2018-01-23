#include "Cube.hpp"

GLfloat xRotated = (GLfloat)-45, yRotated = (GLfloat)-45, zRotated = (GLfloat)0;

int iterasi = 1;
float fsize = 0.15f;
const float eps = 0.0001;
Cube list[27];
GLuint textures;
GLuint texture1;
GLuint texture2;
GLuint texture3;
GLuint texture4;
GLuint texture5;
GLuint texture6;
float xtranslate = 0, ytranslate = 0, ztranslate = 0;
float position[27][3] = {
    {-0.3, -0.3, -0.3},
    {-0.3, -0.3, 0},
    {-0.3, -0.3, 0.3},
    {-0.3, 0, -0.3},
    {-0.3, 0, 0},
    {-0.3, 0, 0.3},
    {-0.3, 0.3, -0.3},
    {-0.3, 0.3, 0},
    {-0.3, 0.3, 0.3},
    {0, -0.3, -0.3},
    {0, -0.3, 0},
    {0, -0.3, 0.3},
    {0, 0, -0.3},
    {0, 0, 0},
    {0, 0, 0.3},
    {0, 0.3, -0.3},
    {0, 0.3, 0},
    {0, 0.3, 0.3},
    {0.3, -0.3, -0.3},
    {0.3, -0.3, 0},
    {0.3, -0.3, 0.3},
    {0.3, 0, -0.3},
    {0.3, 0, 0},
    {0.3, 0, 0.3},
    {0.3, 0.3, -0.3},
    {0.3, 0.3, 0},
    {0.3, 0.3, 0.3}};
// load a 256x256 RGB .RAW file as a texture
GLuint LoadTexture(const char *filename)
{
    int width, height;
    unsigned char *data;
    FILE *file;
    GLuint texture;
    // open texture data
    file = fopen(filename, "rb");
    if (file == NULL)
        return 0;

    // allocate buffer
    width = 256;
    height = 256;
    data = (unsigned char *)malloc(width * height * 3);

    // read texture data
    fread(data, width * height * 3, 1, file);
    fclose(file);

    // allocate a texture name
    glGenTextures(1, &texture);
    // select our current texture
    glBindTexture(GL_TEXTURE_2D, texture);

    // build our texture mipmaps
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height,
                      GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // free buffer
    free(data);

    return texture;
}
static bool fullscreen = false;
void OpenGLInit(void)
{
    /*tambahan*/
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    //glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    //glEnable(GL_TEXTURE_GEN_T);
    // load our texture
    glEnable(GL_TEXTURE_2D);
    texture1 = LoadTexture("bricks.bmp");
    //glDisable(GL_TEXTURE_2D) ;
}

void render(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //initial position // Move right and into the screen
    for (int i = 0; i < 27; i++)
    {
        glLoadIdentity();
        glRotatef(xRotated, 0.3, 0.0, 0.0);
        // // rotation about Y axis
        glRotatef(yRotated, 0.0, 0.3, 0.0);
        // rotation about Z axis
        glRotatef(zRotated, 0.0, 0.0, 0.3);
        glTranslatef(list[i].getX(), list[i].getY(), list[i].getZ());
        glRotatef(list[i].getXRotated(), 0.3, 0.0, 0.0);
        // // rotation about Y axis
        glRotatef(list[i].getYRotated(), 0.0, 0.3, 0.0);
        // rotation about Z axis
        glRotatef(list[i].getZRotated(), 0.0, 0.0, 0.3);

        glClearStencil(0);
        glClear(GL_STENCIL_BUFFER_BIT);

        // Render the thick wireframe version.

        glStencilFunc(GL_NOTEQUAL, 1, 0xFFFF);
        glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

        glLineWidth(3);
        glPolygonMode(GL_FRONT, GL_LINE);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS); // Begin drawing the color cube with 6 quads
        // Top face (y = 0.3f)
        // Define vertices in counter-clockwise (CCW) order with normal pointing out
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow

        //glGenTextures( 1, &texture1 );
        glBindTexture(GL_TEXTURE_2D, texture1);
        glTexCoord2d(0.0, 0.0);
        glVertex3f(fsize, fsize, -fsize);
        glTexCoord2d(1.0, 0.0);
        glVertex3f(-fsize, fsize, -fsize);
        glTexCoord2d(0.0, 1.0);
        glVertex3f(-fsize, fsize, fsize);
        glTexCoord2d(1.0, 1.0);
        glVertex3f(fsize, fsize, fsize);
        // Bottom face (y = -fsize)
        glColor3f(1.0f, 1.0f, 1.0f); // White
        //glGenTextures( 1, &texture2 );

        glTexCoord2d(0.0, 0.0);
        glVertex3f(fsize, -fsize, fsize);
        glTexCoord2d(0.0, 1.0);
        glVertex3f(-fsize, -fsize, fsize);
        glTexCoord2d(1.0, 0.0);
        glVertex3f(-fsize, -fsize, -fsize);
        glTexCoord2d(1.0, 1.0);
        glVertex3f(fsize, -fsize, -fsize);
        // Front face  (z = fsize)
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glTexCoord2d(0.0, 0.0);
        glVertex3f(fsize, fsize, fsize);
        glTexCoord2d(0.0, 1.0);
        glVertex3f(-fsize, fsize, fsize);
        glTexCoord2d(1.0, 0.0);
        glVertex3f(-fsize, -fsize, fsize);
        glTexCoord2d(1.0, 1.0);
        glVertex3f(fsize, -fsize, fsize);

        // Back face (z = -fsize)
        glColor3f(1.0f, 0.5f, 0.0f); // Orange
        glTexCoord2d(0.0, 0.0);
        glVertex3f(fsize, -fsize, -fsize);
        glTexCoord2d(0.0, 1.0);
        glVertex3f(-fsize, -fsize, -fsize);
        glTexCoord2d(1.0, 0.0);
        glVertex3f(-fsize, fsize, -fsize);
        glTexCoord2d(1.0, 1.0);
        glVertex3f(fsize, fsize, -fsize);

        // Left face (x = -fsize)
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glTexCoord2d(0.0, 0.0);
        glVertex3f(-fsize, fsize, fsize);
        glTexCoord2d(0.0, 1.0);
        glVertex3f(-fsize, fsize, -fsize);
        glTexCoord2d(1.0, 0.0);
        glVertex3f(-fsize, -fsize, -fsize);
        glTexCoord2d(1.0, 1.0);
        glVertex3f(-fsize, -fsize, fsize);

        // Right face (x = fsize)
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glTexCoord2d(0.0, 0.0);
        glVertex3f(fsize, fsize, -fsize);
        glTexCoord2d(0.0, 1.0);
        glVertex3f(fsize, fsize, fsize);
        glTexCoord2d(1.0, 0.0);
        glVertex3f(fsize, -fsize, fsize);
        glTexCoord2d(1.0, 1.0);
        glVertex3f(fsize, -fsize, -fsize);

        glEnd(); // End of drawing color-cube
    }

    glutSwapBuffers();
}
static void MouseFunc(int button, int state, int x, int y)
{
    if (button == 0)
    {
        if (state == GLUT_DOWN)
        {
            xtranslate = (float)0.4f * (x - 300) / 600;
            ytranslate = (float)0.4f * (y - 300) / 600;
            if (xtranslate > 1.0f)
                xtranslate = 1.0f;
            else if (xtranslate < -1.0f)
                xtranslate = -1.0f;
            if (ytranslate > 1.0f)
                ytranslate = 1.0f;
            else if (ytranslate < -1.0f)
                ytranslate = -1.0f;
        }
        else if (state == GLUT_UP)
        {
            xtranslate -= (float)0.4f * (x - 300) / 600;
            ytranslate -= (float)0.4f * (y - 300) / 600;

            if (xtranslate > 1.0f)
                xtranslate = 1.0f;
            else if (xtranslate < -1.0f)
                xtranslate = -1.0f;

            if (ytranslate > 1.0f)
                ytranslate = 1.0f;
            else if (ytranslate < -1.0f)
                ytranslate = -1.0f;

            if (ytranslate > 0.0f)
                xRotated += 90 * ytranslate * 3;
            else
                xRotated += 90 * ytranslate * 3;

            if (xtranslate > 0.0f)
                yRotated += 90 * xtranslate * 3;
            else
                yRotated += 90 * xtranslate * 3;
        }
    }
}

static void KeyPressFunc(unsigned char Key, int x, int y)
{
    switch (Key)
    {
    case 'q':
    case 'Q': //toggle screenmode
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

    case 'r': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getX() - 0.3) < eps)
            {
                list[i].rotate(0.3, 0, 0, 90, 0, 0);
                list[i].plusXRotated(90.0);
            }
        }
        break;
    case 'R': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getX() - 0.3) < eps)
            {
                list[i].rotate(0.3, 0, 0, -90, 0, 0);
                list[i].plusXRotated(-90.0);
            }
        }
        break;
    case 'l': //toggle screenmode

        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getX() + 0.3) < eps)
            {
                list[i].rotate(-0.3, 0, 0, 90, 0, 0);
                list[i].plusXRotated(90.0);
            }
        }
        break;
    case 'L': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getX() + 0.3) < eps)
            {
                list[i].rotate(-0.3, 0, 0, -90, 0, 0);
                list[i].plusXRotated(-90.0);
            }
        }
        break;
    case 'd': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getY() + 0.3) < eps)
            {
                list[i].rotate(0, -0.3, 0, 0, 90, 0);
                list[i].plusYRotated(90.0);
            }
        }
        break;
    case 'D': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getY() + 0.3) < eps)
            {
                list[i].rotate(0, -0.3, 0, 0, -90, 0);
                list[i].plusYRotated(-90.0);
            }
        }
        break;
    case 'u': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getY() - 0.3) < eps)
            {
                list[i].rotate(0, 0.3, 0, 0, 90, 0);
                list[i].plusYRotated(90.0);
            }
        }
        break;
    case 'U': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getY() - 0.3) < eps)
            {
                list[i].rotate(0, 0.3, 0, 0, -90, 0);
                list[i].plusYRotated(-90.0);
            }
        }
        break;
    case 'f': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getZ() + 0.3) < eps)
            {
                list[i].rotate(0, 0, -0.3, 0, 0, 90);
                list[i].plusZRotated(90.0);
            }
        }
        break;
    case 'F': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getZ() + 0.3) < eps)
            {
                list[i].rotate(0, 0, -0.3, 0, 0, -90);
                list[i].plusZRotated(-90.0);
            }
        }
        break;
    case 'b': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getZ() - 0.3) < eps)
            {
                list[i].rotate(0, 0, 0.3, 0, 0, 90);
                list[i].plusZRotated(90.0);
            }
        }
        break;
    case 'B': //toggle screenmode
        for (int i = 0; i < 27; i++)
        {
            if (fabs(list[i].getZ() - 0.3) < eps)
            {
                list[i].rotate(0, 0, 0.3, 0, 0, -90);
                list[i].plusZRotated(-90.0);
            }
        }
        break;
    case 27: // Escape key
        exit(1);
    }
}
void init()
{
    for (int i = 0; i < 27; i++)
    {
        // list[i] = new Cube(position[i][0],position[i][1],position[i][2]);
        list[i].setX(position[i][0]);
        list[i].setY(position[i][1]);
        list[i].setZ(position[i][2]);
    }
}
void animation(void)
{
    render();
}
int main(int argc, char **argv)
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cube");
    //glutFullScreen();

    OpenGLInit();
    glutMouseFunc(MouseFunc);
    glutKeyboardFunc(KeyPressFunc);
    glutDisplayFunc(render);
    glutIdleFunc(animation);
    glutMainLoop();
    return (0);
}