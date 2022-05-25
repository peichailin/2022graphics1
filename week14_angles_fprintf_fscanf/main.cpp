///加上多個關節
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
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
    angle[angleID]+=(x-oldx);///改變量質
    myWrite();
    oldx=x;
    glutPostRedisplay();///重畫畫面
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///畫圖前,清畫面
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();///右半邊
        glTranslatef(0.3,0.4,0);///將方塊掛回原來的地方
        glRotatef(angle[0],0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///將方塊中心移到世界中心
        glColor3f(1,0,0);///紅色
        glRectf(0.3,0.5,0.7,0.3);///上手臂
            glPushMatrix();
                glTranslatef(0.7,0.4,0);///將方塊掛回原來的地方
                glRotatef(angle[1],0,0,1);///對z軸旋轉
                glTranslatef(-0.7,-0.4,0);///將方塊中心移到世界中心
                glColor3f(0,1,0);///綠色
                glRectf(0.7,0.5,1.0,0.3);///下手肘
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.3,0.4,0);///將方塊掛回原來的地方
        glRotatef(angle[2],0,0,1);///對z軸旋轉
        glTranslatef(0.3,-0.4,0);///將方塊中心移到世界中心
        glColor3f(1,0,0);///紅色
        glRectf(-0.3,0.5,-0.7,0.3);///上手臂
            glPushMatrix();
                glTranslatef(-0.7,0.4,0);///將方塊掛回原來的地方
                glRotatef(angle[3],0,0,1);///對z軸旋轉
                glTranslatef(0.7,-0.4,0);///將方塊中心移到世界中心
                glColor3f(0,1,0);///綠色
                glRectf(-0.7,0.5,-1.0,0.3);///下手肘
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers(); ///畫好後,交換出來
}
int main(int argc,char**argv) ///main()主函式進階版
{
    glutInit(&argc,argv); ///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///雙緩衝區,3D深度功能
    glutCreateWindow("第13的程式"); ///開啟GLUT視窗
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyBoard);
    glutDisplayFunc(display); ///用來顯示函式

    glutMainLoop();
}
