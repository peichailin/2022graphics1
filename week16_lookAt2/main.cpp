#include <GL/glut.h>
void reshape(int w,int h)
{
    float ar=(float) w/(float) h;
     glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///3D≈‹2D
    glLoadIdentity();
    gluPerspective(60,ar,0.1,100);
     glMatrixMode(GL_MODELVIEW);///3DModel+view
     glLoadIdentity();
     gluLookAt(0,0,3,
               0,0,0,
               0,1,0);
}
void motion(int x,int y)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt((x-150)/150.0,(y-150)/150.0,3,
               0,0,0,
               0,1,0);
    glutPostRedisplay();
}
 void display()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16");
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);



    glutMainLoop();

}
