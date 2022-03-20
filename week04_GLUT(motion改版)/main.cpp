#include <GL/glut.h>///使用外掛,簡化程式
float angle=0,oldx=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///畫圖前,清畫面
    glPushMatrix();///備份矩陣
    glRotatef(angle,0,0,1);///旋轉矩陣
    glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣

    glutSwapBuffers();///畫好後,交換出來
}
void motion(int x,int y)
{
    angle+=(x-oldx);
    oldx=x;
    display();///重畫畫面
}
void mouse(int button,int stste,int x,int y)
{
    oldx=x;///定錨
}
int main(int argc,char**argv)///main()主函式進階版
{
    glutInit(&argc,argv);///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區,3D深度功能
    glutCreateWindow("第04的程式");///開啟GLUT視窗
    glutDisplayFunc(display);///用來顯示函glPushMatrix();
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutMainLoop(); /// 將點連接起來
}
