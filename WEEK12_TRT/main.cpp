#include <GL/glut.h>///�ϥΥ~��,²�Ƶ{��
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///�e�ϫe,�M�e��
    glColor3f(1,1,1);///�զ��������
    glutSolidTeapot(0.3);
    glPushMatrix();
        glTranslatef(0.2,0,0);///��Ӭ��������k��
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);///����������ߩ�b�@�ɤ���
        glColor3f(1,0,0);///red
        glutSolidTeapot(0.2);///�Q���L�O���u
    glPopMatrix();
    glutSwapBuffers();///�e�n��,�洫�X��
    angle++;
}
int main(int argc,char**argv)///main()�D�禡�i����
{
    glutInit(&argc,argv);///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��12���{��(�[��)");///�}��GLUT����
    glutIdleFunc(display);
    glutDisplayFunc(display);///�Ψ���ܨ禡,display�O�禡
    glutMainLoop(); /// �N�I�s���_��
}
