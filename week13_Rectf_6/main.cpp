///加上多個關節
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
float angle=45,oldx=0;
void mouse(int button,int state,int x,int y)
{

    oldx=x;
}
void motion(int x,int y)
{
    angle+=(x-oldx);///改變量質
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
        ///glRotatef(angle,0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///將方塊中心移到世界中心
        glColor3f(1,0,0);///紅色
        glRectf(0.3,0.5,0.7,0.3);///上手臂
            glPushMatrix();
                glTranslatef(0.7,0.4,0);///將方塊掛回原來的地方
                glRotatef(angle,0,0,1);///對z軸旋轉
                glTranslatef(-0.7,-0.4,0);///將方塊中心移到世界中心
                glColor3f(0,1,0);///綠色
                glRectf(0.7,0.5,1.0,0.3);///下手肘
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.3,0.4,0);///將方塊掛回原來的地方
        ///glRotatef(angle,0,0,1);///對z軸旋轉
        glTranslatef(0.3,-0.4,0);///將方塊中心移到世界中心
        glColor3f(1,0,0);///紅色
        glRectf(-0.3,0.5,-0.7,0.3);///上手臂
            glPushMatrix();
                glTranslatef(-0.7,0.4,0);///將方塊掛回原來的地方
                glRotatef(angle,0,0,1);///對z軸旋轉
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
    glutDisplayFunc(display); ///用來顯示函式

    glutMainLoop();
}
