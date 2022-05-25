#include <GL/glut.h>
#include <stdio.h>
void timer(int t)
{
    printf("起床現在時間:%d\n",t);

    glutTimerFunc(1000,timer,t+1);
}
void display()
{


}
int main(int argc,char**argv) ///main()主函式進階版
{
    glutInit(&argc,argv); ///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///雙緩衝區,3D深度功能
    glutCreateWindow("第14的程式"); ///開啟GLUT視窗


    glutTimerFunc(5000,timer,0);

    glutDisplayFunc(display); ///用來顯示函式

    glutMainLoop();
}
