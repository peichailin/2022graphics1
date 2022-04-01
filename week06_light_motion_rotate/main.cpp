#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldx=0,oldy=0;
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
     glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
     glRotatef(angle,0,1,0);///對y軸轉動
     glScalef(scale,scale,scale);///縮放幾倍

     glColor3f(1,1,0);
     glutSolidTeapot(0.3);
        glPopMatrix();

    glutSwapBuffers();
}
void keyboard(unsigned char key,int mousex,int mousey)
{
}
void mouse(int button,int state,int mousex,int mousey)
{
}
void motion(int mousex,int mousey)
{
    angle+=(mousex-oldx);///轉動
    ///if(mousex-oldx>0) scale*=1.01;///縮放
    ///if(mousex-oldx<0) scale*=0.99;///縮放
    ///x+=(mousex-C:\Users\Administrator\Desktop\WEEK06_GLUT_LIGHT\main.cppoldx); y+=(mousey-oldy);
    oldx=mousex; oldy=mousey;
    display();

}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06 light");
    glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);///鍵盤函式
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    ///偷來的程式,要放glutCreateWindow之後才會有效
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    ///放在glutMainLoop()之前
    glutMainLoop();///glutMainLoop()之後的程式,都不會執行到
    return EXIT_SUCCESS;
}
