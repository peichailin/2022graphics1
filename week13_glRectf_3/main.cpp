#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
float angle=45;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///�e�ϫe,�M�e��
    glColor3f(1,1,1);///�զ⪺
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///�N������^��Ӫ��a��
        glRotatef(angle,0,0,1);///��z�b����
        glTranslatef(-0.3,-0.4,0);///�N������߲���@�ɤ���
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers(); ///�e�n��,�洫�X��
}
int main(int argc,char**argv) ///main()�D�禡�i����
{
    glutInit(&argc,argv); ///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��13���{��"); ///�}��GLUT����
    glutDisplayFunc(display); ///�Ψ���ܨ禡

    glutMainLoop();
}
