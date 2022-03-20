#include <GL/glut.h>///使用外掛,簡化程式
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///畫圖前,清畫面
    glColor3f(1,1,0); ///設定色彩
    glBegin(GL_POLYGON);///GL_POLYGON多邊形,開始化

        glColor3f(1,0,0); ///Red
        glVertex2f(-1,-1); ///頂點(X,Y)
        glColor3f(0,1,0); ///Green
        glVertex2f(1,-1); ///頂點(X,Y)
        glColor3f(0,0,1) ; ///Blue
        glVertex2f(0,1); ///頂點(X,Y)


    glEnd(); ///結束
    glutSwapBuffers();///畫好後,交換出來
}
int main(int argc,char**argv)///main()主函式進階版
{
    glutInit(&argc,argv);///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區,3D深度功能
    glutCreateWindow("第02的程式");///開啟GLUT視窗
    glutDisplayFunc(display);///用來顯示函式,display是函式
    glutMainLoop();


}
