// #pragma comment(lib, "glew32.lib")

// #include <GL/glew.h>
#include "Cube.hpp"
GLfloat xRotated = (GLfloat) -45, yRotated=(GLfloat) -45, zRotated= (GLfloat) 0;

const float eps = 0.0001;
Cube list[27];
float position[27][3] = {
  {-0.3,-0.3,-0.3},
  {-0.3,-0.3,0},
  {-0.3,-0.3,0.3},
  {-0.3,0,-0.3},
  {-0.3,0,0},
  {-0.3,0,0.3},
  {-0.3,0.3,-0.3},
  {-0.3,0.3,0},
  {-0.3,0.3,0.3},
  {0,-0.3,-0.3},
  {0,-0.3,0},
  {0,-0.3,0.3},
  {0,0,-0.3},
  {0,0,0},
  {0,0,0.3},
  {0,0.3,-0.3},
  {0,0.3,0},
  {0,0.3,0.3},
  {0.3,-0.3,-0.3},
  {0.3,-0.3,0},
  {0.3,-0.3,0.3},
  {0.3,0,-0.3},
  {0.3,0,0},
  {0.3,0,0.3},
  {0.3,0.3,-0.3},
  {0.3,0.3,0},
  {0.3,0.3,0.3}
};

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
    //initial position // Move right and into the screen
    for(int i=0;i<27;i++){
        glLoadIdentity();
        glRotatef(xRotated,0.3,0.0,0.0);
        // // rotation about Y axis
        glRotatef(yRotated,0.0,0.3,0.0);
        // rotation about Z axis
        glRotatef(zRotated,0.0,0.0,0.3);
        glTranslatef(list[i].getX(),list[i].getY(),list[i].getZ());

        glRotatef(list[i].getXRotated(),0.3,0.0,0.0);
        // // rotation about Y axis
        glRotatef(list[i].getYRotated(),0.0,0.3,0.0);
        // rotation about Z axis
        glRotatef(list[i].getZRotated(),0.0,0.0,0.3);

        glClearStencil(0);
        glClear(GL_STENCIL_BUFFER_BIT);

         // Render the thick wireframe version.

        glStencilFunc(GL_NOTEQUAL, 1, 0xFFFF);
        glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

        glLineWidth(3);
        glPolygonMode(GL_FRONT, GL_LINE);
        glColor3f( 1.0f, 1.0f, 1.0f );
        glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
        // Top face (y = 0.3f)
        // Define vertices in counter-clockwise (CCW) order with normal pointing out
       
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f(0.15f, 0.15f, -0.15f);
        glVertex3f(-0.15f, 0.15f, -0.15f);
        glVertex3f(-0.15f, 0.15f,  0.15f);
        glVertex3f( 0.15f, 0.15f,  0.15f);


        // Bottom face (y = -0.15f)
        glColor3f(1.0f, 1.0f, 1.0f);     // White
        glVertex3f( 0.15f, -0.15f,  0.15f);
        glVertex3f(-0.15f, -0.15f,  0.15f);
        glVertex3f(-0.15f, -0.15f, -0.15f);
        glVertex3f( 0.15f, -0.15f, -0.15f);

        // Front face  (z = 0.15f)
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f( 0.15f,  0.15f, 0.15f);
        glVertex3f(-0.15f,  0.15f, 0.15f);
        glVertex3f(-0.15f, -0.15f, 0.15f);
        glVertex3f( 0.15f, -0.15f, 0.15f);

        // Back face (z = -0.15f)
        glColor3f(1.0f, 0.5f, 0.0f);     // Orange
        glVertex3f( 0.15f, -0.15f, -0.15f);
        glVertex3f(-0.15f, -0.15f, -0.15f);
        glVertex3f(-0.15f,  0.15f, -0.15f);
        glVertex3f( 0.15f,  0.15f, -0.15f);

        // Left face (x = -0.15f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(-0.15f,  0.15f,  0.15f);
        glVertex3f(-0.15f,  0.15f, -0.15f);
        glVertex3f(-0.15f, -0.15f, -0.15f);
        glVertex3f(-0.15f, -0.15f,  0.15f);

        // Right face (x = 0.15f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f(0.15f,  0.15f, -0.15f);
        glVertex3f(0.15f,  0.15f,  0.15f);
        glVertex3f(0.15f, -0.15f,  0.15f);
        glVertex3f(0.15f, -0.15f, -0.15f);
        
        glEnd();  // End of drawing color-cube
     
    }

    glutSwapBuffers();
}

static void KeyPressFunc( unsigned char Key, int x, int y )
{
    switch ( Key ) {
        case 'q':
        case 'Q': //toggle screenmode
            if(!fullscreen){
                glutFullScreen();
                fullscreen = true;
            } else if(fullscreen){
                glutReshapeWindow(300, 300);
                glutPositionWindow(600,600);
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
        case 'z':
        case 'Z': //toggle screenmode
            zRotated +=90;
            break;
        case 'x':
        case 'X': //toggle screenmode
            xRotated +=90;
            break;
        case 'y':
        case 'Y': //toggle screenmode
            yRotated +=90;
            break;

        case 'r': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getX()-0.3)<eps){
                    list[i].rotate(0.3,0,0,90,0,0);
                    list[i].plusXRotated(90.0);
                }
            }
            break;
        case 'R': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getX()-0.3)<eps){
                    list[i].rotate(0.3,0,0,-90,0,0);
                    list[i].plusXRotated(-90.0);
                }
            }
            break;
        case 'l': //toggle screenmode
            
            for(int i=0;i<27;i++){
                if(fabs(list[i].getX()+0.3)<eps){
                    list[i].rotate(-0.3,0,0,90,0,0);
                    list[i].plusXRotated(90.0);
                }
            }
            break;
        case 'L': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getX()+0.3)<eps){
                    list[i].rotate(-0.3,0,0,-90,0,0);
                    list[i].plusXRotated(-90.0);
                }
            }
            break;
        case 'd': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getY()+0.3)<eps){
                    list[i].rotate(0,-0.3,0,0,90,0);
                    list[i].plusYRotated(90.0);
                }
            }
            break;
        case 'D': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getY()+0.3)<eps){
                    list[i].rotate(0,-0.3,0,0,-90,0);
                    list[i].plusYRotated(-90.0);
                }
            }
            break;
        case 'u': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getY()-0.3)<eps){
                    list[i].rotate(0,0.3,0,0,90,0);
                    list[i].plusYRotated(90.0);
                }
            }
            break;
        case 'U': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getY()-0.3)<eps){
                    list[i].rotate(0,0.3,0,0,-90,0);
                    list[i].plusYRotated(-90.0);
                }
            }
            break;
        case 'f': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getZ()+0.3)<eps){
                    list[i].rotate(0,0,-0.3,0,0,90);
                    list[i].plusZRotated(90.0);
                }
            }
            break;
        case 'F': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getZ()+0.3)<eps){
                    list[i].rotate(0,0,-0.3,0,0,-90);
                    list[i].plusZRotated(-90.0);
                }
            }
            break;
        case 'b': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getZ()-0.3)<eps){
                    list[i].rotate(0,0,0.3,0,0,90);
                    list[i].plusZRotated(90.0);
                }
            }
            break;
        case 'B': //toggle screenmode
            for(int i=0;i<27;i++){
                if(fabs(list[i].getZ()-0.3)<eps){
                    list[i].rotate(0,0,0.3,0,0,-90);
                    list[i].plusZRotated(-90.0);
                }
            }
            break;
        case 27:    // Escape key
            exit(1);
    }
}
void init(){
    for(int i=0;i<27;i++){
        // list[i] = new Cube(position[i][0],position[i][1],position[i][2]);
        list[i].setX(position[i][0]);list[i].setY(position[i][1]);list[i].setZ(position[i][2]);
    }
    
}
void animation(void)
{
     render();
}
int main( int argc, char** argv )
{
  init();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowPosition(300,300);
  glutInitWindowSize( 600, 600 );
  glutCreateWindow( "Cube" );
  //glutFullScreen();
  
  OpenGLInit();
  glutKeyboardFunc( KeyPressFunc );
  glutDisplayFunc(render);
  glutIdleFunc(animation);
  glutMainLoop(  );
  return(0);        
}