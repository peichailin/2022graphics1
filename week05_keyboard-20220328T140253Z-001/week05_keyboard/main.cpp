#include <GL/glut.h>///使用外掛,簡化程式
#include <stdio.h>
void display()
{
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///畫圖前,清畫面
    glColor3f(1,1,0); ///設定色彩(黃色)
    glutSolidTeapot(0.3); ///實心的茶壺
    glutSwapBuffers(); ///畫好後,交換出來
}
void keyboard(unsigned char key,int x,int y)
{
    printf("你按下 %c 在 %d %d 座標\n",key,x,y);///可辨別你鍵盤按了甚麼
}
int main(int argc,char**argv)///main()主函式進階版
{
    glutInit(&argc,argv);///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區,3D深度功能
    glutCreateWindow("第05的程式keyboard");///開啟GLUT視窗
    glutDisplayFunc(display);///用來顯示函式,display是函式
    glutKeyboardFunc(keyboard);///鍵盤函式
    glutMainLoop(); /// 將點連接起來
}
