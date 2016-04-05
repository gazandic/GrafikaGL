// #pragma comment(lib, "glew32.lib")
#include <iostream>
// #include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>

static bool fullscreen = false;
void OpenGLInit(void)
{
    
  	glShadeModel(GL_SMOOTH);
  	glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClearDepth( 1.0 );
    glEnable( GL_DEPTH_TEST );
}

void render(void)
{ 
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity(); 
   // initial position

  glBegin(GL_TRIANGLES);
  glColor3f(0.1, 0.2, 0.3);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0);
  glVertex3f(0, 1, 0);
  glEnd();
  glBegin(GL_TRIANGLES);
  glColor3f(0.3, 0.5, 0.4);
  glVertex3f(0, 0, 0);
  glVertex3f(-1, 0, 0);
  glVertex3f(0, -1, 0);
  glEnd();
  glBegin(GL_TRIANGLES);
  glColor3f(0.7, 0.2, 0.3);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0);
  glVertex3f(0, -1, 0);
  glEnd();
  glutSwapBuffers(); 
  glutPostRedisplay();  
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
                glutReshapeWindow(1500, 1000);
                glutPositionWindow(10,30);
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
// Main routine
// Set up OpenGL, hook up callbacks, and start the main loop
int main( int argc, char** argv )
{
  // Need to double buffer for animation
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

  // Create and position the graphics window
  
  glutInitWindowPosition(1500,1000);
  glutInitWindowSize( 0, 0 );
  glutCreateWindow( "Grafika 3segitiga" );
  glutFullScreen();

  OpenGLInit();
  glutKeyboardFunc( KeyPressFunc );
  glutDisplayFunc(render);
  glutIdleFunc(render);
  glutMainLoop(  );
  return(0);          // Compiler requires this to be here. (Never reached)
}