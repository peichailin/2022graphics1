#include <GL/glut.h>///�ϥΥ~��,²�Ƶ{��
#include <stdio.h>
void display()
{
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///�e�ϫe,�M�e��
    glColor3f(1,1,0); ///�]�w��m(����)
    glutSolidTeapot(0.3); ///��ߪ�����
    glutSwapBuffers(); ///�e�n��,�洫�X��
}
void keyboard(unsigned char key,int x,int y)
{
    printf("�A���U %c �b %d %d �y��\n",key,x,y);///�i��O�A��L���F�ƻ�
}
int main(int argc,char**argv)///main()�D�禡�i����
{
    glutInit(&argc,argv);///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��05���{��keyboard");///�}��GLUT����
    glutDisplayFunc(display);///�Ψ���ܨ禡,display�O�禡
    glutKeyboardFunc(keyboard);///��L�禡
    glutMainLoop(); /// �N�I�s���_��
}
