#include<GL/gl.h>
 #include<GL/glu.h>
 #include<GL/glut.h>
 #include<stdlib.h>
 #include<windows.h>
 #include<math.h>
 #include<utility>

 //every void is identified here
void display();
void draw_circle(float x1,float y1, double radius);
void draw_cloud();
void draw_rectangular();
void draw_rectangular2();
void draw_square();
void draw_body_shape();
void draw_triangle();
void draw_body_shape2();
void draw_body_shape3();
void draw_zizag();
void draw_linestrght();
void rotation();
void reshape (int W, int h);
//end of every void

//the start of each identifier
int state= 1;
int state2=1;

float angle=45.0f;
int refreshmill =1;
float turn=0.01;
float step3=0;
float angola;
float step;
float steps;

//the end of it

//timer used for loop
void timer(int){
     glutPostRedisplay();

    glutTimerFunc(1000/60,timer,0);

   switch(state){
       case 1:
           if(step<=1){
            step+=0.05;

           }
            else
            state=-1;
           break;
       case -1:
        if(step>-10)
            step-=0.05;
        else
            state=1;
        break;
   }
}
//another timer used for loop
void timer2(int){
     glutPostRedisplay();
    glutTimerFunc(1000/60,timer2,0);
   switch(state2){
       case 1:
           if(steps<1)
            steps+=0.05;
            else
            state2=-1;
           break;
       case -1:
        if(steps>0)
            steps-=0.05;
        else
            state2=1;
        break;
   }
}
//the timer used for a loop
void timer3(int value){
    glutPostRedisplay();
    glutTimerFunc(refreshmill,timer3,0);


}
//where everything is displayed
void display(){

glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();

//the sky of the window{the blue thing at the back

    glPushMatrix();
    draw_rectangular();
    glPopMatrix();




//the house itself the other one ( the left or right cba)
    glPushMatrix();
    draw_rectangular2();
    glPopMatrix();

//the window of the house
    glPushMatrix();
    glColor3f(1,1,0);
    draw_square();
    glPopMatrix();

    //the window of the house
     glPushMatrix();
     glTranslatef(2,0,0);
     glColor3f(1,1,0);
     draw_square();
     glPopMatrix();
//the window of the house
     glPushMatrix();
     glTranslatef(4,0,0);
     glColor3f(1,1,0);
     draw_square();
     glPopMatrix();



//the  house border
     glPushMatrix();
     glTranslatef(-10,0,0);
     draw_rectangular2();
     glPopMatrix();

     //the window of the house
      glPushMatrix();
      glTranslatef(-10,0,0);
      glColor3f(1,1,0);
      draw_square();
      glPopMatrix();

      //the window of the house
      glPushMatrix();
      glTranslatef(-8,0,0);
      glColor3f(1,1,0);
      draw_square();
      glPopMatrix();
//the window ofthe house
      glPushMatrix();
      glTranslatef(-6,0,0);
      glColor3f(1,1,0);
      draw_square();
      glPopMatrix();

      //the body of a human
glPushMatrix();
 glTranslatef(-1,0,0);
draw_body_shape();
glPopMatrix();

glPushMatrix();
 glTranslatef(8,+1,0);
draw_body_shape();
glPopMatrix();

//the body of a human
glPushMatrix();
 glTranslatef(+3,+3,0);
draw_body_shape2();
glPopMatrix();

//the body of a human
glPushMatrix();
 glTranslatef(+13,+4,0);
draw_body_shape2();
glPopMatrix();

//the body of a human
glPushMatrix();
 glTranslatef(+10,+4,0);
draw_body_shape3();
glPopMatrix();

//triangle of the right house
glPushMatrix();
glColor3f(0,1,0);
glTranslatef(-10,0,0);
draw_triangle();
glPopMatrix();
//troangle of the first house at the right
glPushMatrix();
glColor3f(0,1,0);
draw_triangle();
glPopMatrix();

//the clouds
glPushMatrix();
glTranslatef(0,+2,0);
draw_cloud();
glPopMatrix();


//the tree
glPushMatrix();
glRotatef(5, 0, 1, 0);
glColor3f(1,1,0);
draw_circle(-10,8,3.2);
glPopMatrix();
//the steam of tree
glPushMatrix();
 glTranslatef(-10,+7,0);
draw_zizag();
glPopMatrix();

//the steam of the tree
glPushMatrix();
 glTranslatef(-9.5,+7.5,0);
draw_zizag();
glPopMatrix();

//the steam of the tree
glPushMatrix();
 glTranslatef(-9,+8,0);
draw_zizag();
glPopMatrix();

//the steam of the tree
glPushMatrix();
 glTranslatef(-8.5,+8.5,0);
draw_zizag();
glPopMatrix();

//the steam of the tree
glPushMatrix();
 glTranslatef(-12,6,0);
draw_zizag();
glPopMatrix();

//the steam of the tree
glPushMatrix();
 glTranslatef(-11,6.5,0);
draw_zizag();
glPopMatrix();

//the tree
glPushMatrix();
glTranslatef(+1,0,0);
glColor3f(0,1,0);
draw_circle(0,0,1.1);
draw_linestrght();
glPopMatrix();


//the tree
glPushMatrix();
glTranslatef(-9,-4,0);
glColor3f(0,1,0);
draw_circle(0,0,1.1);
draw_linestrght();
glPopMatrix();

//the tree
glPushMatrix();
glTranslatef(+9,-4,0);
glColor3f(0,1,0);
draw_circle(0,0,1.1);
draw_linestrght();
glPopMatrix();

//the tree
glPushMatrix();
glTranslatef(-6,3,0);
glColor3f(0,1,0);
draw_circle(0,0,1.1);
draw_linestrght();
glPopMatrix();

//the tree
glPushMatrix();
glTranslatef(9,3,0);
glColor3f(0,1,0);
draw_circle(0,0,1.1);
draw_linestrght();
glPopMatrix();


//the kit that has its rotation

glPushMatrix();
glTranslatef(0.5f, 0.0f, 0.0f);
glRotatef(angle,0.0,0.0,1.0f);
glColor3f(1,0,0);
draw_square();
glutSwapBuffers();
angle+=0.5;
glPopMatrix();




glFlush();

}
//the triangle drawing from here
void draw_triangle(){

    glBegin(GL_TRIANGLES);
    glVertex2f(6,8);
    glVertex2f(2,5);
    glVertex2f(9,5);
    glEnd();
}
//the sun zigzag line
void draw_zizag(){
    glBegin(GL_LINE_STRIP);
        glVertex2f(3,-2);
          glVertex2f(1,1);





    glEnd();

}


//the steam of the tree
void draw_linestrght(){
    glLineWidth(5);
glBegin(GL_LINES);
glVertex2f(0,1);
glVertex2f(0,-5);
glEnd();


}
//the body of the human
void draw_body_shape(){

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);

//this is the body of the person//
    glVertex2f(-5.5,-6);
    glVertex2f(-5.5,-7.5);

//the left hand of the body//
    glVertex2f(-5.5,-6);
    glVertex2f(-6.3,-6.8);

//the right hand of the body//
    glVertex2f(-5.5,-6);
    glVertex2f(-4.5,-6.8);

//the right leg of the body //
    glVertex2f(-5.5,-7.4);
    glVertex2f(-3.5,steps-8.3);

//the left leg of the body//
    glVertex2f(-5.5,-7.4);
    glVertex2f(-6.3,-8.3);

    glEnd();

//this is the head position of the person //
    glPushMatrix();
    glTranslatef(-6.4,-7,0);
    glScalef(0.5,0.5,0.5);
    draw_circle(2.0 , 3.0,  1.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.5,-5.4,0);
    glScalef(0.5,0.5,0.5);
    glColor3f(1,1,0);
    draw_circle(-18 , -3.5+steps,  1);
    glPopMatrix();

//this is the end of the head of the person//



}
//the body of a  human
void draw_body_shape2(){

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);

//this is the body of the person//
    glVertex2f(-5.5,-6);
    glVertex2f(-5.5,-7.5);

//the left hand of the body//
    glVertex2f(-5.5,-6);
    glVertex2f(-6.3,steps-6.8);

//the right hand of the body//
    glVertex2f(-5.5,-6);
    glVertex2f(-4.5,steps-6.8);

//the right leg of the body //
    glVertex2f(-5.5,-7.4);
    glVertex2f(-4.5,-8.3);

//the left leg of the body//
    glVertex2f(-5.5,-7.4);
    glVertex2f(-6.3,-8.3);

    glEnd();

//this is the head position of the person //
    glPushMatrix();
    glTranslatef(-6.4,-7,0);
    glScalef(0.5,0.5,0.5);
    draw_circle(2.0 , 3.0,  1.2);
    glPopMatrix();


//this is the end of the head of the person//



}
//the body of a human
void draw_body_shape3(){

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);

//this is the body of the person//
    glVertex2f(-5.5,-6);
    glVertex2f(-5.5,-7.5);

//the left hand of the body//
    glVertex2f(-5.5,-6);
    glVertex2f(-6.3,-6.8);

//the right hand of the body//
    glVertex2f(-5.5,-6);
    glVertex2f(-4.5,-6.8);

//the right leg of the body //
    glVertex2f(-5.5,-7.4);
    glVertex2f(-4.5,-8.3);

//the left leg of the body//
    glVertex2f(-5.5,-7.4);
    glVertex2f(-6.3,-8.3);

    glEnd();

//this is the head position of the person //
    glPushMatrix();
    glTranslatef(-6.4,-7,0);
    glScalef(0.5,0.5,0.5);
    draw_circle(2.0 , 3.0,  1.2);
    glPopMatrix();


//this is the end of the head of the person//



}
//the reshape where the window max is written
void reshape (int w, int h){

    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}
//the cloud drawing
void draw_cloud(){
   glColor3f(0.35,0.35,0.35);

    draw_circle(step+0.6 , 6.0,  2.5);
    draw_circle(step+1.5, 4.9,  2.5);
    draw_circle(step+1.4 , 4.8,  2.5);
    draw_circle(step+0.3 , 4.7,  2.5);
    draw_circle(step+2.2 , 4.6,  2.5);
    draw_circle(step+2.1 , 4.5,  2.5);

    draw_circle(step+8.6 , 6.0,  2.5);
    draw_circle(step+8.5, 4.9,  2.5);
    draw_circle(step+8.4 , 4.8,  2.5);
    draw_circle(step+8.3 , 4.7,  2.5);
    draw_circle(step+8.2 , 4.6,  2.5);
    draw_circle(step+8.1 , 4.5,  2.5);


}
//the background for the sky
void draw_rectangular(){
   glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
    glBegin(GL_QUADS);

    glVertex2f(-10,10);
    glVertex2f(-10,0);
    glVertex2f(10,0);
    glVertex2f(10,10);

    glEnd();

}
//the house
void draw_rectangular2(){
   glColor3i(226,135,67);
    glBegin(GL_QUADS);

    glVertex2f(2,0);
    glVertex2f(2,5);
    glVertex2f(9,5);
    glVertex2f(9,0);

    glEnd();
}
//the window
void draw_square(){

 glBegin(GL_QUADS);

   glVertex2f(3,1);
    glVertex2f(3,3);
    glVertex2f(4,3);
    glVertex2f(4,1);
    glEnd();

}
//for the circle
void draw_circle(float x1,float y1, double radius){
float x2,y2;
float angle;
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x1,y1);
for(angle = 1.0f;angle<361.0f;angle+=0.2){
    x2 = x1 + sin(angle) * radius;
    y2 = y1 +cos(angle) *radius;
    glVertex2f(x2,y2);

}
glEnd();


}
//used for initilizing
void init(){
glClearColor(0.0,0.0,0.0,1.0);

}
//the main function
int main (int argc, char**argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("yahya ibrahim 20100315");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    glutTimerFunc(0,timer2,0);
    glutTimerFunc(0,timer3,0);


    init();
    glClearColor(0.0, 0.5 ,0.0,1.0);
    glutMainLoop();
}
