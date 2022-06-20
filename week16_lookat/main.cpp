
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
 void display()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidTeapot(1);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week16");
    glutReshapeFunc(reshape);



    glutMainLoop();

}
