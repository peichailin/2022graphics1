///�[�W�h�����`
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
float angle=45,oldx=0;
void mouse(int button,int state,int x,int y)
{

    oldx=x;
}
void motion(int x,int y)
{
    angle+=(x-oldx);///���ܶq��
    oldx=x;
    glutPostRedisplay();///���e�e��
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///�e�ϫe,�M�e��
    glColor3f(1,1,1);///�զ⪺
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();///�k�b��
        glTranslatef(0.3,0.4,0);///�N������^��Ӫ��a��
        ///glRotatef(angle,0,0,1);///��z�b����
        glTranslatef(-0.3,-0.4,0);///�N������߲���@�ɤ���
        glColor3f(1,0,0);///����
        glRectf(0.3,0.5,0.7,0.3);///�W���u
            glPushMatrix();
                glTranslatef(0.7,0.4,0);///�N������^��Ӫ��a��
                glRotatef(angle,0,0,1);///��z�b����
                glTranslatef(-0.7,-0.4,0);///�N������߲���@�ɤ���
                glColor3f(0,1,0);///���
                glRectf(0.7,0.5,1.0,0.3);///�U��y
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3,0.4,0);///�N������^��Ӫ��a��
        ///glRotatef(angle,0,0,1);///��z�b����
        glTranslatef(0.3,-0.4,0);///�N������߲���@�ɤ���
        glColor3f(1,0,0);///����
        glRectf(-0.3,0.5,-0.7,0.3);///�W���u
            glPushMatrix();
                glTranslatef(-0.7,0.4,0);///�N������^��Ӫ��a��
                glRotatef(angle,0,0,1);///��z�b����
                glTranslatef(0.7,-0.4,0);///�N������߲���@�ɤ���
                glColor3f(0,1,0);///���
                glRectf(-0.7,0.5,-1.0,0.3);///�U��y
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers(); ///�e�n��,�洫�X��
}
int main(int argc,char**argv) ///main()�D�禡�i����
{
    glutInit(&argc,argv); ///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��13���{��"); ///�}��GLUT����
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display); ///�Ψ���ܨ禡

    glutMainLoop();
}
