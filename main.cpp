#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
//hi
float x = 0, y = 0;
bool moving = true;
void init(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

//function to move character when arrow keys are pressed
void moveChar(int key, int x, int z){
    if(key == GLUT_KEY_UP){
        if(y < 265){
           y += 5;
        }
    }
    else if(key == GLUT_KEY_DOWN){
        if(y > -120){
            y -= 5;
        }
    }
    glutPostRedisplay();
}

//arrow design
void arrow(){
    glColor3f(0.8, 0.6, 0.2);
        //back
    glBegin(GL_LINE_STRIP);
        glVertex2i(130 + x, 200 + y);
        glVertex2i(140 + x, 195 + y);
        glVertex2i(130 + x, 190 + y);
    glEnd();
        //middle
    glBegin(GL_LINES);
        glVertex2i(140 + x, 195 + y);
        glVertex2i(197 + x, 195 + y);
    glEnd();
        //arrow head
    glBegin(GL_TRIANGLES);
        glVertex2i(197 + x, 200 + y);
        glVertex2i(197 + x, 190 + y);
        glVertex2i(212 + x, 195 + y);
    glEnd();
}

//function to move the arrow when space bar is pressed
void moveArrow(){
    if(moving == true){
         x += 0.2;
        if(x >= 500){
            x = 0;
            arrow();
            moving = false;
        }
    }

    glutPostRedisplay();
}

//function to call moveArrow when space bar is pressed
void shoot(unsigned char key,int x,int y){
    switch(key){
        case ' ': moving = true;
            glutIdleFunc(moveArrow);
        break;
    }
}

//character with bow design
void character(){
    glColor3f(0, 0, 0);
    //head
    glBegin(GL_POLYGON);
        glVertex2i(145, 200 + y);
        glVertex2i(160, 215 + y);
        glVertex2i(145, 230 + y);
        glVertex2i(130, 215 + y);
    glEnd();
    //body
    //glBegin(GL_POLYGON);
        /*glVertex2i(130, 200);
        glVertex2i(160, 200);
        glVertex2i(160, 160);
        glVertex2i(130, 160);*/
    glRectf(130, 200 + y, 160, 160 + y);
    //glEnd();
    //left leg
    /*glBegin(GL_POLYGON);
        glVertex2i(130, 160);
        glVertex2i(142, 160);
        glVertex2i(142, 135);
        glVertex2i(130, 135);
    glEnd();*/
    glRectf(130, 160 + y, 142, 135 + y);
    //right leg
    /*glBegin(GL_POLYGON);
        glVertex2i(160, 160);
        glVertex2i(148, 160);
        glVertex2i(148, 135);
        glVertex2i(160, 135);
    glEnd();*/
    glRectf(160, 160 + y, 148, 135 + y);
    //platform
    /*glBegin(GL_POLYGON);
        glVertex2i(110, 135);
        glVertex2i(185, 135);
        glVertex2i(185, 130);
        glVertex2i(110, 130);
    glEnd();*/
    glRectf(110, 135 + y, 185, 130 + y);
    //hands
    /*glBegin(GL_POLYGON);
        glVertex2i(117, 200);
        glVertex2i(190, 200);
        glVertex2i(190, 190);
        glVertex2i(117, 190);
    glEnd();*/
    glRectf(117, 200 + y, 190, 190 + y);
    //bow
        //top
    glBegin(GL_POLYGON);
        glVertex2i(170, 230 + y);
        glVertex2i(170, 225 + y);
        glVertex2i(195, 205 + y);
        glVertex2i(195, 210 + y);
    glEnd();
        //middle
    glBegin(GL_POLYGON);
        glVertex2i(195, 210 + y);
        glVertex2i(190, 210 + y);
        glVertex2i(190, 180 + y);
        glVertex2i(195, 180 + y);
    glEnd();
        //bottom
    glBegin(GL_POLYGON);
        glVertex2i(195, 180 + y);
        glVertex2i(195, 185 + y);
        glVertex2i(170,160 + y);
        glVertex2i(170, 155 + y);
    glEnd();
        //string
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_STRIP);
        glVertex2i(170, 225 + y);
        glVertex2i(140, 195 + y);
        glVertex2i(170, 160 + y);
    glEnd();

    glutPostRedisplay();
    glutSwapBuffers();
}

//target design
void target(){
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        glVertex2f(307.5, 270);
        glVertex2f(270, 307.5);
        glVertex2f(307.5, 345);
        glVertex2f(345, 307.5);
    glEnd();
    glColor3f(0.2, 0.2, 1);
    glRectf(285, 285, 330, 330);
    glColor3f(1, 1, 1);
    glRectf(300, 300, 315, 315);

}

void display(){
    glClearColor(0, 0.8, 0.6, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    character();
    arrow();
    target();

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Archery Game");

    init();

    glutDisplayFunc(display);

    glutSpecialFunc(moveChar);//using special function to access up and down keys
    glutKeyboardFunc(shoot);//using keyboard function to access space bar

    glutMainLoop();
}
