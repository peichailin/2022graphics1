#include <GL/glut.h>///�ϥΥ~��,²�Ƶ{��
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0;
int oldx=0,oldy=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1); ///R,G,B,A(�O�b�z���\��),
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///�e�ϫe,�M�e��
     glPushMatrix();///�ƥ��x�}
     glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
     glScalef(scale,scale,scale);
     glColor3f(1,1,0);
     glutSolidTeapot(0.3);
        glPopMatrix();
    glutSwapBuffers(); ///�e�n��,�洫�X��
}
void keyboard(unsigned char key,int mousex,int mousey)
{
}
void mouse(int button,int state,int mousex,int mousey)
{
}
void motion(int mousex,int mousey)
{
    if(mousex-oldx>0) scale*=1.01;
    if(mousex-oldx<0) scale*=0.99;
    ///x+=(mousex-oldx); y+=(mousey-oldy);
    oldx=mousex; oldy=mousey;
    display();

}
int main(int argc,char**argv)///main()�D�禡�i����
{
    glutInit(&argc,argv);///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��05���{��keyboard");///�}��GLUT����
    glutDisplayFunc(display);///�Ψ���ܨ禡,display�O�禡
    glutKeyboardFunc(keyboard);///��L�禡
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop(); /// �N�I�s���_��
}
