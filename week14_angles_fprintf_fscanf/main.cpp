///�[�W�h�����`
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldx=0;

int angleID=0;
FILE * fout = NULL,* fin= NULL;
void myWrite()
{
    if(fout==NULL) fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++)
    {
        printf("%.1f",angle[i]);
        fprintf(fout,"%.1f",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void myRead()
{
    if(fout!=NULL) {fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {

        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();
}
void keyBoard(unsigned char key,int x,int y)
{
    if(key=='r') myRead();
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button,int state,int x,int y)
{

    oldx=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldx);///���ܶq��
    myWrite();
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
        glRotatef(angle[0],0,0,1);///��z�b����
        glTranslatef(-0.3,-0.4,0);///�N������߲���@�ɤ���
        glColor3f(1,0,0);///����
        glRectf(0.3,0.5,0.7,0.3);///�W���u
            glPushMatrix();
                glTranslatef(0.7,0.4,0);///�N������^��Ӫ��a��
                glRotatef(angle[1],0,0,1);///��z�b����
                glTranslatef(-0.7,-0.4,0);///�N������߲���@�ɤ���
                glColor3f(0,1,0);///���
                glRectf(0.7,0.5,1.0,0.3);///�U��y
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3,0.4,0);///�N������^��Ӫ��a��
        glRotatef(angle[2],0,0,1);///��z�b����
        glTranslatef(0.3,-0.4,0);///�N������߲���@�ɤ���
        glColor3f(1,0,0);///����
        glRectf(-0.3,0.5,-0.7,0.3);///�W���u
            glPushMatrix();
                glTranslatef(-0.7,0.4,0);///�N������^��Ӫ��a��
                glRotatef(angle[3],0,0,1);///��z�b����
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
    glutKeyboardFunc(keyBoard);
    glutDisplayFunc(display); ///�Ψ���ܨ禡

    glutMainLoop();
}
