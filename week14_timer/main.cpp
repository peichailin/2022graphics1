#include <GL/glut.h>
#include <stdio.h>
void timer(int t)
{
    printf("�_�ɲ{�b�ɶ�:%d\n",t);

}
void display()
{


}
int main(int argc,char**argv) ///main()�D�禡�i����
{
    glutInit(&argc,argv); ///��ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///���w�İ�,3D�`�ץ\��
    glutCreateWindow("��14���{��"); ///�}��GLUT����

    glutTimerFunc(1000,timer,1);
    glutTimerFunc(2000,timer,2);
    glutTimerFunc(3000,timer,3);
    glutTimerFunc(4000,timer,4);
    glutTimerFunc(5000,timer,5);

    glutDisplayFunc(display); ///�Ψ���ܨ禡

    glutMainLoop();
}
