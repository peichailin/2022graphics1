#include <GL/glut.h>///使用外掛,簡化程式
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0;
int oldx=0,oldy=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1); ///R,G,B,A(是半透明功能),
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///畫圖前,清畫面
     glPushMatrix();///備份矩陣
     glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
     glScalef(scale,scale,scale);
     glColor3f(1,1,0);
     glutSolidTeapot(0.3);
        glPopMatrix();
    glutSwapBuffers(); ///畫好後,交換出來
}
void keyboard(unsigned char key,int mousex,int mousey)
{
}
void mouse(int button,int state,int mousex,int mousey)
{
}
void motion(int mousex,int mousey)
{
    if(mousex-oldx>0) scale*=1.01;
    if(mousex-oldx<0) scale*=0.99;
    ///x+=(mousex-oldx); y+=(mousey-oldy);
    oldx=mousex; oldy=mousey;
    display();

}
int main(int argc,char**argv)///main()主函式進階版
{
    glutInit(&argc,argv);///把參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區,3D深度功能
    glutCreateWindow("第05的程式keyboard");///開啟GLUT視窗
    glutDisplayFunc(display);///用來顯示函式,display是函式
    glutKeyboardFunc(keyboard);///鍵盤函式
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop(); /// 將點連接起來
}
