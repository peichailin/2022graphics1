#include <GL/glut.h>///�ϥΥ~��,²�Ƶ{��
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///�e�ϫe,�M�e��
    glPushMatrix();///�ƥ��x�}
    glRotatef(angle,0,0,1);///����x�}
    glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();///�e�n��,�洫�X��
}
void motion(int x,int y)
{
    angle=x;
    display();///���e�e��
}
int main(int argc,char**argv)///main()�D�禡�i����
{
    glutInit(&argc,argv);///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��04���{��");///�}��GLUT����
    glutDisplayFunc(display);///�Ψ���ܨ�glPushMatrix();
    glutMotionFunc(motion);
    glutMainLoop(); /// �N�I�s���_��
}
