#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///畫圖前,清畫面
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();

        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers(); ///畫好後,交換出來
}
int main(int argc,char**argv) ///main()主函式進階版
{
    glutInit(&argc,argv); ///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH); ///雙緩衝區,3D深度功能
    glutCreateWindow("第13的程式"); ///開啟GLUT視窗
    glutDisplayFunc(display); ///用來顯示函式

    glutMainLoop();
}
