#include <GL/glut.h>
void reshape(int w,int h)
{
    float ar =(float) w / (float) h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);///3D變2D
    glLoadIdentity();
    gluPerspective(60,ar,0.1,100);

    glMatrixMode(GL_MODELVIEW);///3D MODEL +VIEW
    glLoadIdentity();
    gluLookAt(0,0,3,
               0,0,0,
               0,1,0);
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);
    glutSwapBuffers();
}
void motion (int x,int y)
{
     glMatrixMode(GL_MODELVIEW);///3D MODEL +VIEW
    glLoadIdentity();
    gluLookAt((x-150)/150.0,(y-150)/150.0,3,
               0,0,0,
               0,1,0);
    glutPostRedisplay();///重劃畫面
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week16");
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);///保持視窗比例
    glutMainLoop();

}
