#define GLUT_DISABLE_ATEXIT_HACK
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<string.h>
#include<stdlib.h>

float y = 0, xa = 0, ya = 0;
float ys1 = 0.1, ys2 = 0.1, ys3 = 0.1, ys4 = 0.1, ys5 = 0.1, ys6 = 0.1, ys7 = 0.1;
bool moving = false;
int view = 0, score = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0;
char scoreText[10];

//function to print the string in the screen
void display_string(int x, int y, char *string)
{
    int len,i;
	glColor3f(0, 0, 0);
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	}

}

void init(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1000, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
}

//function to move character when arrow keys are pressed
void moveChar(int key, int x, int z){
    if(key == GLUT_KEY_UP){
        if(y < 750){
           y += 7;
        }
    }
    else if(key == GLUT_KEY_DOWN){
        if(y > -120){
            y -= 7;
        }
    }
    if(!moving){
        ya = y;
    }
    glutPostRedisplay();
}

//arrow design
void arrow(){
    glColor3f(0.8, 0.6, 0.2);
        //back
    glBegin(GL_LINE_STRIP);
        glVertex2i(60 + xa, 200 + ya);
        glVertex2i(70 + xa, 195 + ya);
        glVertex2i(60 + xa, 190 + ya);
    glEnd();
        //middle
    glBegin(GL_LINES);
        glVertex2i(70 + xa, 195 + ya);
        glVertex2i(127 + xa, 195 + ya);
    glEnd();
        //arrow head
    glBegin(GL_TRIANGLES);
        glVertex2i(127 + xa, 200 + ya);
        glVertex2i(127 + xa, 190 + ya);
        glVertex2i(142 + xa, 195 + ya);
    glEnd();
}

//checking if the arrow head hits the target or not
bool hit(float xt1, float xt2, float yt1, float yt2, float xa, float ya){
    if(xa >= xt1 && xa <= xt2 && ya <= yt1 && ya >= yt2){
        score += 10;
        return true;
    }
    return false;

}

//function to move the arrow when space bar is pressed
void moveArrow(){
    if(moving == true){
         xa += 0.4;
        if(xa >= 900){
            xa = 0;
            arrow();
            moving = false;
        }
    }
    glutPostRedisplay();
}

//function to check the key pressed
void keys(unsigned char key,int x,int y){
    switch(key){
        case ' ': moving = true;
            glutIdleFunc(moveArrow);
            break;
        case 'p': view = 1;
                  ys1 = 0.1; ys2 = 0.1; ys3 = 0.1; ys4 = 0.1; ys5 = 0.1; ys6 = 0.1; ys7 = 0.1;
                  count1 = 0; count2 = 0; count3 = 0; count4 = 0; count5 = 0; count6 = 0; count7 = 0;
                  ::y = 0;
                  xa = 0; ya = 0;
                  moving = false;
                  score = 0;
                  break;
        case 'r': view = 0;
                    ::y=0;
                  break;
        case 'q' :exit(0);

    }
}

//character with bow design
void character(){
    glColor3f(0, 0, 0);
    //head
    glBegin(GL_POLYGON);
        glVertex2i(75, 200 + y);
        glVertex2i(90, 215 + y);
        glVertex2i(75, 230 + y);
        glVertex2i(60, 215 + y);
    glEnd();
    //body
    //glBegin(GL_POLYGON);
        /*glVertex2i(130, 200);
        glVertex2i(160, 200);
        glVertex2i(160, 160);
        glVertex2i(130, 160);*/
    glRectf(60, 200 + y, 90, 160 + y);
    //glEnd();
    //left leg
    /*glBegin(GL_POLYGON);
        glVertex2i(130, 160);
        glVertex2i(142, 160);
        glVertex2i(142, 135);
        glVertex2i(130, 135);
    glEnd();*/
    glRectf(60, 160 + y, 72, 135 + y);
    //right leg
    /*glBegin(GL_POLYGON);
        glVertex2i(160, 160);
        glVertex2i(148, 160);
        glVertex2i(148, 135);
        glVertex2i(160, 135);
    glEnd();*/
    glRectf(90, 160 + y, 78, 135 + y);
    //platform
    /*glBegin(GL_POLYGON);
        glVertex2i(110, 135);
        glVertex2i(185, 135);
        glVertex2i(185, 130);
        glVertex2i(110, 130);
    glEnd();*/
    glRectf(40, 135 + y, 115, 130 + y);
    //hands
    /*glBegin(GL_POLYGON);
        glVertex2i(117, 200);
        glVertex2i(190, 200);
        glVertex2i(190, 190);
        glVertex2i(117, 190);
    glEnd();*/
    glRectf(47, 200 + y, 120, 190 + y);

    //bow
        //top
    glBegin(GL_POLYGON);
        glVertex2i(100, 230 + y);
        glVertex2i(100, 225 + y);
        glVertex2i(125, 205 + y);
        glVertex2i(125, 210 + y);
    glEnd();
        //middle
    glBegin(GL_POLYGON);
        glVertex2i(125, 210 + y);
        glVertex2i(120, 210 + y);
        glVertex2i(120, 180 + y);
        glVertex2i(125, 180 + y);
    glEnd();
        //bottom
    glBegin(GL_POLYGON);
        glVertex2i(125, 180 + y);
        glVertex2i(125, 185 + y);
        glVertex2i(100, 160 + y);
        glVertex2i(100, 155 + y);
    glEnd();
        //string
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_STRIP);
        glVertex2i(100, 225 + y);
        glVertex2i(70, 195 + y);
        glVertex2i(100, 160 + y);
    glEnd();

    glutPostRedisplay();
    glutSwapBuffers();
}

//target design
void target(){
    glColor3f(1, 1, 1);
    //outer square(rhombus)
    glBegin(GL_POLYGON);
        glVertex2f(307.5, 1000);
        glVertex2f(270, 962.5);
        glVertex2f(307.5, 925);
        glVertex2f(345, 962.5);
    glEnd();
    //middle square
    glColor3f(0.2, 0.2, 1);
    glRectf(285, 985, 330, 940);
    //inner square
    glColor3f(1, 1, 1);
    glRectf(300, 970, 315, 955);

}

//display when you won the game
void gameWonDisplay(){
    glClearColor(0.1, 0.7, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    display_string(365, 700, "GAME COMPLETED");
    display_string(420, 650, "SCORE : ");
    display_string(520, 650, scoreText);
    display_string(350, 550, "PRESS 'R' TO RETURN");
    glFlush();
}

//display when the game is over
void gameOverDisplay(){
    glClearColor(0.8, 0.3, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    display_string(400, 700, "GAME OVER");
    display_string(420, 650, "SCORE : ");
    display_string(520, 650, scoreText);
    display_string(350, 550, "PRESS 'R' TO RETURN");
}

//display the start screen of the game
void gameStartDisplay(){
    glClearColor(0, 0.8, 0.4, 1);
    glClear(GL_COLOR_BUFFER_BIT);
	display_string(400, 800, "ARCHERY GAME");
	display_string(300, 700, "CMR INSTITUE OF TECHNOLOGY");
	display_string(200, 650, "DONE BY : ");
	display_string(250, 600, "DUSI UJWAL - 1CR19CS051");
	display_string(250, 550, "C K AMRUTHA - 1CR19CS032");
	display_string(200, 500, "KEYBOARD");
	display_string(250, 460, "PRESS 'SPACE BAR' TO RELEASE ARROWS");
	display_string(250, 420, "PRESS 'UP ARROW KEY' TO MOVE UP");
	display_string(250, 380, "PRESS 'DOWN ARROW KEY' TO MOVE DOWN");
	display_string(200, 300, "INSTRUCTIONS");
	display_string(250, 260, "DESTROY TARGETS TO WIN");
	display_string(250, 220, "WHEN TARGET HITS GROUND YOU LOOSE");
	display_string(200, 140, "PRESS 'P' TO PLAY GAME");
	display_string(200, 100, "PRESS 'Q' TO QUIT THE GAME");
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void display(){
    if(view == 0){
        gameStartDisplay();
    }
    else{
        glClearColor(0, 0.8, 0.6, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        itoa(score, scoreText, 10);
        display_string(10, 950, "SCORE : ");
        display_string(110, 950, scoreText);

        character();
        arrow();

        glPushMatrix();
            if(count1 < 1){
                glTranslatef(0, 100 + ys1, 0);
                if(hit(270, 345, 1000 + 100 + ys1, 925 + 100 + ys1, 142 + xa, 195 + y)){
                    count1++;
                }
                ys1 -= 0.03;
                target();
            }
        glPopMatrix();

        glPushMatrix();
            if(count2 < 1){
                glTranslatef(100, 100 + ys2, 0);
                if(hit(270 + 100, 345 + 100, 1000 + 100 + ys2, 925 + 100 + ys2, 142 + xa, 195 + y)){
                    count2++;
                }
                ys2 -= 0.05;
                target();
            }
        glPopMatrix();

        glPushMatrix();
            if(count3 < 1){
                glTranslatef(200, 100 + ys3, 0);
                if(hit(270 + 200, 345 + 200, 1000 + 100 + ys3, 925 + 100 + ys3, 142 + xa, 195 + y)){
                    count3++;
                }
                ys3 -= 0.06;
                target();
            }
        glPopMatrix();

        glPushMatrix();
            if(count4 < 1){
                glTranslatef(300, 100 + ys4, 0);
                if(hit(270 + 300, 345 + 300, 1000 + 100 + ys4, 925 + 100 + ys4, 142 + xa, 195 + y)){
                    count4++;
                }
                ys4 -= 0.08;
                target();
            }
        glPopMatrix();

        glPushMatrix();
            if(count5 < 1){
                glTranslatef(400, 100 + ys5, 0);
                if(hit(270 + 400, 345 + 400, 1000 + 100 + ys5, 925 + 100 + ys5, 142 + xa, 195 + y)){
                    count5++;
                }
                ys5 -= 0.1;
                target();
            }
        glPopMatrix();

        glPushMatrix();
            if(count6 < 1){
                glTranslatef(500, 100 + ys6, 0);
                if(hit(270 + 500, 345 + 500, 1000 + 100 + ys6, 925 + 100 + ys6, 142 + xa, 195 + y)){
                    count6++;
                }
                ys6 -= 0.07;
                target();
            }
        glPopMatrix();

        glPushMatrix();
            if(count7 < 1){
                glTranslatef(600, 100 + ys7, 0);
                if(hit(270 + 600, 345 + 600, 1000 + 100 + ys7, 925 + 100 + ys7, 142 + xa, 195 + y)){
                    count7++;
                }
                ys7 -= 0.05;
                target();
            }
        glPopMatrix();

        //checking if target went below the screen. If yes then game over
        if(ys1 < -1100 || ys2 < -1100 || ys3 < -1100 || ys4 < -1100 || ys5 < -1100 || ys6 < -1100 || ys7 < -1100){
            gameOverDisplay();
        }

        //checking if we hit all the targets. If yes game completed
        if(count1 == 1 && count2 == 1 && count3 == 1 && count4 == 1 && count5 == 1 && count6 == 1 && count7 == 1){
            gameWonDisplay();
        }

        glutPostRedisplay();
        glutSwapBuffers();
        glFlush();
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Archery Game");

    init();

    glutDisplayFunc(display);

    glutSpecialFunc(moveChar);//using special function to access up and down keys
    glutKeyboardFunc(keys);//using keyboard function to access space bar

    glutMainLoop();
}
