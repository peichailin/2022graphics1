#include <GL/glut.h>///使用外掛,簡化程式
void hand()
{
    glColor3f(0,1,0); ///設定色彩
    glutSolidTeapot(0.2); ///實心的茶壺

}
void body()
{
    glColor3f(1,1,0); ///設定色彩
    glutSolidTeapot(0.3); ///實心的茶壺
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///畫圖前,清畫面
    body();
    glPushMatrix();
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
    glPopMatrix();
    glutSwapBuffers(); ///畫好後,交換出來
    angle++;
}
int main(int argc,char**argv) ///main()主函式進階版
{
    glutInit(&argc,argv); ///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///雙緩衝區,3D深度功能
    glutCreateWindow("第02的程式"); ///開啟GLUT視窗
    glutIdleFunc(display);
    glutDisplayFunc(display); ///用來顯示函式

    glutMainLoop();
}
