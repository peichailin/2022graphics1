#include <GL/glut.h>///�ϥΥ~��,²�Ƶ{��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///�e�ϫe,�M�e��
    glColor3f(1,1,0); ///�]�w��m(����)
    glutSolidTeapot(0.3); ///��ߪ�����
    glutSwapBuffers(); ///�e�n��,�洫�X��
}
int main(int argc,char**argv) ///main()�D�禡�i����
{
    glutInit(&argc,argv); ///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��02���{��"); ///�}��GLUT����
    glutDisplayFunc(display); ///�Ψ���ܨ禡
    glutMainLoop();
}
