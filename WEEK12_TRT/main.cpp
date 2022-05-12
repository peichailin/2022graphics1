#include <GL/glut.h>///使用外掛,簡化程式
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///畫圖前,清畫面
    glColor3f(1,1,1);///白色茶壺當身體
    glutSolidTeapot(0.3);
    glPushMatrix();
        glTranslatef(0.2,0,0);///整個紅茶壺往右移
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);///把紅茶壺中心放在世界中心
        glColor3f(1,0,0);///red
        glutSolidTeapot(0.2);///想像他是手臂
    glPopMatrix();
    glutSwapBuffers();///畫好後,交換出來
    angle++;
}
int main(int argc,char**argv)///main()主函式進階版
{
    glutInit(&argc,argv);///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區,3D深度功能
    glutCreateWindow("第12的程式(加分)");///開啟GLUT視窗
    glutIdleFunc(display);
    glutDisplayFunc(display);///用來顯示函式,display是函式
    glutMainLoop(); /// 將點連接起來
}
