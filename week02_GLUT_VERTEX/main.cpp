#include <GL/glut.h>///�ϥΥ~��,²�Ƶ{��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///�e�ϫe,�M�e��
    glColor3f(1,1,0); ///�]�w��m
    glBegin(GL_POLYGON);///GL_POLYGON�h���,�}�l��

        glColor3f(1,0,0); ///Red
        glVertex2f(-1,-1); ///���I(X,Y)
        glColor3f(0,1,0); ///Green
        glVertex2f(1,-1); ///���I(X,Y)
        glColor3f(0,0,1) ; ///Blue
        glVertex2f(0,1); ///���I(X,Y)


    glEnd(); ///����
    glutSwapBuffers();///�e�n��,�洫�X��
}
int main(int argc,char**argv)///main()�D�禡�i����
{
    glutInit(&argc,argv);///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��02���{��");///�}��GLUT����
    glutDisplayFunc(display);///�Ψ���ܨ禡,display�O�禡
    glutMainLoop();


}
