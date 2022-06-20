///week14_angle_fprintf_fscanf ��� week14_angle_fprintf
#include <GL/glut.h>
#include <stdio.h>

float angle[20] , oldx=0;
int angleID=0;///0�����` 1�����`
FILE * fout = NULL, * fin = NULL;
void myWrite(){///�C�I�s�@��myWrite()
    if( fout == NULL) fout = fopen("file.txt", "w+");

    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i] );///�p�¦L�X��
        fprintf(fout, "%.1f ", angle[i] );///�ɮצL�X��
    }///�L�X20�ӼƦr
    printf("\n");///�C�I�s�@��,�p�¸���
    fprintf(fout,"\n");///�C�I�s�@��,�ɮפ]����
    ///�o�̨S��fclose
}
float NewAngle[20], OldAngle[20];
void myRead(){
    if( fout != NULL ) { fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        OldAngle[i] = NewAngle[i];///��ӷs�����ª�
        fscanf(fin,"%f",&NewAngle[i] );///Ū��s������
    }
    glutPostRedisplay();///���e�e��
}
void myInterpolate(float alpha){
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
    }
}
int t=0;
void timer(int t)
{
    if(t%50==0) myRead();
    myInterpolate((t%50)/50.0);
    glutPostRedisplay();
    glutTimerFunc(20,timer,t+1);
}
void keyboard(unsigned char key , int x  , int y)
{
    if (key=='p'){///Play
        myRead();
        glutTimerFunc(0,timer,0);
       /// if(t%30==0) myRead();
        ///myInterpolate( (t%30)/30.0 );///���� 0.0~1.0
       /// glutPostRedisplay();
       /// t++;
    }
    if (key=='s') myWrite();///�զn�ʧ@,�Asave�s��
    if (key=='r') myRead();
    if (key=='0') angleID=0;
    if (key=='1') angleID=1;
    if (key=='2') angleID=2;
    if (key=='3') angleID=3;
}
void mouse(int button , int state , int x ,int y)
{
    oldx=x;
}
void motion (int x, int y)
{
    angle[angleID]+=(x-oldx);
    ///myWrite();
    oldx=x;
    glutPostRedisplay();///��GLUT���e�e��
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ⪺
    glRectf(0.3,0.5,-0.3,-0.5);///����,�|���

    glPushMatrix();///�k�b��
        glTranslatef(0.3,0.4,0); ///(3)����u���^����
        glRotatef(angle[0],0,0,1); ///(2)���� ��z�b���
        glTranslatef(-0.3,-0.4,0); ///(1)����u�����त�ߡA�񤤤�
        glColor3f(1,0,0);///���⪺
        glRectf(0.3,0.5,0.7,0.3);///�W���u

        glPushMatrix();
            glTranslatef(0.7,0.4,0); ///(3)����u���^����
            glRotatef(angle[1],0,0,1); ///(2)����
            glTranslatef(-0.7,-0.4,0); ///(1)����u�����त�ߡA�񤤤�
            glColor3f(0,1,0);///��⪺
            glRectf(0.7,0.5,1.0,0.3);///�U��y,�����u
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3,0.4,0); ///(3)����u���^����
        glRotatef(angle[2],0,0,1); ///(2)���� ��z�b���
        glTranslatef(0.3,-0.4,0); ///(1)����u�����त�ߡA�񤤤�
        glColor3f(1,0,0);///���⪺
        glRectf(-0.3,0.5,-0.7,0.3);///�W���u

        glPushMatrix();
            glTranslatef(-0.7,0.4,0); ///(3)����u���^����
            glRotatef(angle[3],0,0,1); ///(2)����
            glTranslatef(0.7,-0.4,0); ///(1)����u�����त�ߡA�񤤤�
            glColor3f(0,1,0);///��⪺
            glRectf(-0.7,0.5,-1.0,0.3);///�U��y,�����u
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600,600);
    glutCreateWindow("week16 rect TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}
