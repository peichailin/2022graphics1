#include <GL/glut.h>
#include <stdio.h>
void timer(int t)
{
    printf("�_�ɲ{�b�ɶ�:%d\n",t);

    glutTimerFunc(1000,timer,t+1);
}
void display()
{


}
int main(int argc,char**argv) ///main()�D�禡�i����
{
    glutInit(&argc,argv); ///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��14���{��"); ///�}��GLUT����


    glutTimerFunc(5000,timer,0);

    glutDisplayFunc(display); ///�Ψ���ܨ禡

    glutMainLoop();
}
