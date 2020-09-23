// Project submitted by
///Nushrat Jahan, 18-36586-1
///Abdullah Al Sakib, 18-36815-1
///MD. Reja-E-Rabbi Tonmoy, 17-33472-1
///Tamal Akter Piash, 17-33568-1

#include<bits/stdc++.h>
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<string.h>
using namespace std;

//l1=level1, l2=level2, l3=level3, mj=biggest monster
bool m1=true ,m2=true, m3=true, m4=true, mj=false,l1=false,l2=false,l3=false,bfire=false,pis=true;
bool mj1=false,mj2=false,mj3=false;
bool welcome = true, gr = false, win = false;
int screen_width, screen_height;
int score=0;
float theta;

GLfloat position = 0.0f;
GLfloat speed = 0.05f;
GLfloat positionroket=0.0f;
GLfloat speedroket = 0.1f;
GLfloat positionbullet=0.0f;
GLfloat speedbullet = 0.03f;
GLfloat PistolLR = 0.0f;
GLfloat PistolUD = 0.0f;
GLfloat PositionMonster=0.0f;

///level cahange, monster control
void update(int value) {

    if(position < -1.90)
    {
       position = 0.0f;
        //PositionMonster-=0.2;
       //if(PositionMonster < -.9)
        //PositionMonster =0.0;
    }
    if(mj) speed = 0.08;
    position -= speed;
	glutPostRedisplay();
     if(l1)
     {
        if(positionbullet>=position+1.0f && positionbullet-.15f<=position+1.0f )
          {
             float x1=PistolUD+.3;
             if(x1>=0.6 && x1<=0.8 )          { m1=false; positionbullet=0.0f; bfire=false; score+=10; }
             else if(x1>=0.3  && x1<=0.5 )    { m2=false; positionbullet=0.0f; bfire=false; score+=10; }
             else if(x1>=-0.05 && x1<=0.15 )  { m3=false; positionbullet=0.0f; bfire=false; score+=10; }
             else if(x1>=-.45  &&  x1<=-.25 ) { m4=false; positionbullet=0.0f; bfire=false; score+=10; }
             if(mj==true)
             {
              if(x1>=.75  &&  x1<=0.8)
                {
                     mj=false; positionbullet=0.0f; bfire=false; mj1=true; score+=50;
                }
              if(x1>=.7  &&  x1<=.75) { pis=false; gr = true; l1=false;}

             }
          }

         if(m1==false && m2==false && m3==false && m4==false && !mj1) { mj=true; }
         if(mj1 && pis)    { l1=false; l2=true; m1=true; m2=true; m3=true; m4=true; mj=false;}
    }

     else if(l2)
     {
         if(positionbullet>=position+1.0f && positionbullet-.15f<=position+1.0f )
           {
              float x1=PistolUD+.3;
              if     (x1>=0.72 && x1<=0.84)     { m1=false; positionbullet=0.0f; bfire=false; score+=10;}
              else if(x1>=0.42  && x1<=0.54)    { m2=false; positionbullet=0.0f; bfire=false; score+=10;}
              else if(x1>=0.04 && x1<=0.16)  { m3=false; positionbullet=0.0f; bfire=false; score+=10;}
              else if(x1>=-.24  &&  x1<=-.11) { m4=false; positionbullet=0.0f; bfire=false; score+=10;}
              if(mj==true)
                {
                    if(x1>=0.59  &&  x1<=0.7)
                      {
                         mj=false; positionbullet=0.0f; bfire=false; mj2=true; score+=50;
                      }
                    if(x1>=.5  &&  x1<=.58) { pis=false; gr = true; l2=false;}
                }
           }
           if(m1==false && m2==false && m3==false && m4==false && !mj2) { mj=true; }
           if(mj2 && pis )    { mj1=false; l2=false; l3=true; m1=true; m2=true; m3=true; m4=true; mj=false;}
     }

     else if(l3)
      {
          if(positionbullet>=position+1.0f && positionbullet-.15f<=position+1.0f )
           {
              float x1=PistolUD+.3;
              if(x1>=0.4 && x1<=0.5)            { m1=false; positionbullet=0.0f; bfire=false; score+=10;}
              else if(x1>=0.04  && x1<=0.26)    { m2=false; positionbullet=0.0f; bfire=false; score+=10;}
              else if(x1>=-0.26 && x1<=-0.04)   { m3=false; positionbullet=0.0f; bfire=false; score+=10;}
              else if(x1>=-.5  &&  x1<=-.4)     { m4=false; positionbullet=0.0f; bfire=false; score+=10;}
              if(mj)
                {
                    if(x1>=.58 &&  x1<=0.7 )
                    {
                         mj=false; positionbullet=0.0f; bfire=false; score+=50; mj3=true; win = true; l3=false;
                    }
                    if(x1>=.5  &&  x1<=.57) { pis=false; gr = true; l3=false;}
                }
          }
          if(m1==false && m2==false && m3==false && m4==false && !mj3) { mj=true; }
      }

	glutTimerFunc(100, update, 0);
}

///Bullet control
void updatebullet(int value) {
    if(bfire)
    {
       if(positionbullet > 1.8)
        positionbullet = 1.8f;
        positionbullet += speedbullet;
	    glutPostRedisplay();
    }
	glutTimerFunc(100, updatebullet, 0);
}

void init() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void handleMouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
		    bfire=true;
		    updatebullet(positionbullet);
		}
		if (state == GLUT_UP)
		{
		    bfire = false;
		    positionbullet=0.0f;
		}
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 27)
        exit(0);
    else if(key == ' ')
    {
        l1=true;
        welcome = false;
    }
}
void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
    if(PistolUD > .66)
        {
          PistolUD = PistolUD;
	      glutPostRedisplay();
        }
    else PistolUD+=0.05;
break;
case GLUT_KEY_DOWN:
if(PistolUD < -1.1)
        {
          PistolUD = PistolUD;
	      glutPostRedisplay();
        }
    else PistolUD-=0.05;
break;
case GLUT_KEY_LEFT:
if(PistolLR < -.2)
        {
          PistolLR = PistolLR;
	      glutPostRedisplay();
        }
    else PistolLR-=0.05;
break;
case GLUT_KEY_RIGHT:
if(PistolLR > 1.4)
        {
          PistolLR = PistolLR;
	      glutPostRedisplay();
        }
    else PistolLR+=0.05;
break;
}

glutPostRedisplay();
}

void House()
{
glColor3f (0.21, 0.5, 0.21);
glRectf(-.99,-1,-.80,-.8);
glColor3f (0.76, 0.29, 0.05);
glRectf(-0.79,-1,-.57,-.7);
glColor3f (1, 0.66, 0.66);
glRectf(-.56,-1,-.35,-.6);
glColor3f (.51, 0.6, 0.69);
glRectf(-.34,-1,-.09,-.6);
glRectf(-.31,-.6,-.12,-.5);
glColor3f (.92, 0.4, 0.78);
glRectf(-.08,-1,.16,-.55);
glColor3f (.79, 0.19, 0.63);
glRectf(.17,-1,.36,-.7);
glColor3f (0.21, 0.75, 0.51);
glRectf(.37,-1,.51,-.6);
glColor3f (.64, 0.62, 0.63);
glRectf(.52,-1,.72,-.62);
glColor3f (.94, 0.2, 0.1);
glRectf(.73,-1,.98,-.7);
glRectf(.75,-.7,.96,-.6);

// Windows
glColor3f (1.0, 1.0, 1.0);
//House 1
glRectf(-.97,-1,-.92,-.84);
glRectf(-.9,-.98,-.87,-.92);
glRectf(-.9,-.90,-.87,-.84);
glRectf(-.86,-.98,-.83,-.92);
glRectf(-.86,-.9,-.83,-.84);

//House 2
glRectf(-.77,-1,-.72,-.84);
glRectf(-.7,-.98,-.67,-.92);
glRectf(-.7,-.90,-.67,-.84);
glRectf(-.66,-.98,-.63,-.92);
glRectf(-.66,-.9,-.63,-.84);

//House 3
glRectf(-.54,-1,-.49,-.84);
glRectf(-.47,-.98,-.44,-.92);
glRectf(-.47,-.90,-.44,-.84);
glRectf(-.43,-.98,-.40,-.92);
glRectf(-.43,-.9,-.40,-.84);

glRectf(-.54,-.81,-.49,-.66);
glRectf(-.47,-.80,-.44,-.74);
glRectf(-.47,-.72,-.44,-.66);
glRectf(-.43,-.80,-.40,-.74);
glRectf(-.43,-.72,-.40,-.66);

//House 4
glRectf(-.3,-1,-.25,-.84);
glRectf(-.23,-.98,-.18,-.92);
glRectf(-.23,-.90,-.18,-.84);
glRectf(-.17,-.98,-.12,-.92);
glRectf(-.17,-.9,-.12,-.84);

glRectf(-.3,-.81,-.25,-.66);
glRectf(-.23,-.80,-.18,-.74);
glRectf(-.23,-.72,-.18,-.66);
glRectf(-.17,-.80,-.12,-.74);
glRectf(-.17,-.72,-.12,-.66);

//House 5
glRectf(-.05,-1,0.0,-.84);
glRectf(.02,-.98,0.07,-.92);
glRectf(.02,-.90,0.07,-.84);
glRectf(0.08,-.98,.13,-.92);
glRectf(0.08,-.9,.13,-.84);

glRectf(-.05,-.81,0.0,-.66);
glRectf(0.02,-.80,0.07,-.74);
glRectf(0.02,-.72,0.07,-.66);
glRectf(0.08,-.80,.13,-.74);
glRectf(0.08,-.72,.13,-.66);

//House 6
glRectf(0.19,-1,0.24,-.84);
glRectf(.26,-.98,0.29,-.92);
glRectf(.26,-.90,0.29,-.84);
glRectf(0.3,-.98,.33,-.92);
glRectf(0.3,-.9,.33,-.84);

//House 7
glRectf(0.38,-1,0.42,-.84);
glRectf(0.43,-.98,0.46,-.92);
glRectf(0.43,-.90,0.46,-.84);
glRectf(0.47,-.98,.50,-.92);
glRectf(0.47,-.9,.50,-.84);

glRectf(0.38,-.81,0.42,-.66);
glRectf(0.43,-.80,0.46,-.74);
glRectf(0.43,-.72,0.46,-.66);
glRectf(0.47,-.80,.50,-.74);
glRectf(0.47,-.72,.50,-.66);

//House 8
glRectf(0.55,-1,0.59,-.84);
glRectf(0.60,-.98,0.64,-.92);
glRectf(0.60,-.90,0.64,-.84);
glRectf(0.65,-.98,.69,-.92);
glRectf(0.65,-.9,.69,-.84);

glRectf(0.55,-.81,0.59,-.66);
glRectf(0.60,-.80,0.64,-.74);
glRectf(0.60,-.72,0.64,-.66);
glRectf(0.65,-.80,0.69,-.74);
glRectf(0.65,-.72,0.69,-.66);

//House 9
glRectf(0.78,-1,0.82,-.84);
glRectf(0.83,-.98,0.87,-.92);
glRectf(0.83,-.90,0.87,-.84);
glRectf(0.88,-.98,.92,-.92);
glRectf(0.88,-.9,.92,-.84);

glRectf(0.78,-.81,0.82,-.66);
glRectf(0.83,-.80,0.87,-.74);
glRectf(0.83,-.72,0.87,-.66);
glRectf(0.88,-.80,0.92,-.74);
glRectf(0.88,-.72,0.92,-.66);
}

void Pistol()
{
    if(pis)
    {
          if(l1)
    {
       glColor3f (0.0, 0.0, 1.0);
       glRectf(-.78,.3,-.5,.25);
       glRectf(-.78,.25,-.65,.15);
       glRectf(-.78,.15,-.7,.10);
       glColor3f (1.0, 1.0, 1.0);
       glRectf(-.74,.25,-.67,.18);
    }

    if(l2)
    {
       glColor3f (0.0, 0.0, 1.0);
       glRectf(-.6,.3,-.5,.25);

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.1416/180;
      glVertex2f(-.65+.08*cos(theta),.28+.08*sin(theta));
   }
   glEnd();
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.1416/180;
      glVertex2f(-.65+.06*cos(theta),.28+.06*sin(theta));
   }
   glEnd();
   glColor3f (0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.1416/180;
      glVertex2f(-.65+.04*cos(theta),.28+.04*sin(theta));
   }
   glEnd();
    }

    if(l3)
    {
        glBegin(GL_QUADS);
        glColor3ub(23, 100, 255);
        glVertex2f(-.7,.1);
        glVertex2f(-.7,.3);
        glVertex2f(-.8,.3);
        glVertex2f(-.8,.1);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 100, 25);
        glVertex2f(-.6,.2);
        glVertex2f(-.6,.3);
        glVertex2f(-.7,.3);
        glVertex2f(-.7,.2);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(25, 200, 25);
        glVertex2f(-.6,.2);
        glVertex2f(-.5,.25);
        glVertex2f(-.6,.3);
        glEnd();
    }
    }

}
void PistolBullet()
{
    if(pis)
    {
       if(l1 || l2)
       {
       glColor3f (1.0, 0.0, 1.0);
       glRectf(-.6,.3,-.55,.25);
       }
    if(l3)
       {
        glBegin(GL_QUADS);
        glColor3ub(255, 100, 25);
        glVertex2f(-.5,.24);
        glVertex2f(-.48,.24);
        glVertex2f(-.48,.26);
        glVertex2f(-.5,.26);
        glEnd();
       }
    }

}

void Monster()
{
    if(l1)
    {
       glColor3f (0.0, .9, 0.5);
    if(m1)
    {
       glRectf(.68,.6,.85,.75);
       glRectf(.68,.75,.73,.80);
       glRectf(.8,.75,.85,.80);

    }

    if(m2)
    {

       glRectf(.78,.3,.95,.45);
       glRectf(.78,.45,.83,.50);
       glRectf(.9,.45,.95,.50);
    }

    if(m3)
    {
       glRectf(.58,.1,.75,-.05);
       glRectf(.58,.1,.63,.15);
       glRectf(.7,.1,.75,.15);
    }

    if(m4)
    {
        glRectf(.78,-.3,.95,-.45);
        glRectf(.78,-.3,.83,-.25);
        glRectf(.9,-.3,.95,-.25);
    }
    }
    if(l2)
    {
        if(m1)
        {

            glColor3f (1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            for(int i=0; i<360; i++)
             {
               theta=i*3.1416/180;
               glVertex2f(.65+.12*cos(theta),.78+.06*sin(theta));
             }
            glEnd();
            glColor3f (0.0, 0.0, 0.0);
            glRectf(.55,.77,.62,.80);
            glRectf(.68,.77,.75,.80);
            glRectf(.64,.73,.66,.76);
           // glRectf(.64, .72, .66, .84);
        }
        if(m2)
        {
            glColor3f (1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            for(int i=0; i<360; i++)
             {
               theta=i*3.1416/180;
               glVertex2f(.68+.12*cos(theta),.48+.06*sin(theta));
             }
            glEnd();
            glColor3f (0.0, 0.0, 0.0);
            glRectf(.58,.47,.65,.50);
            glRectf(.71,.47,.78,.50);
            glRectf(.67,.43,.69,.46);
           // glRectf(.66, .42, .68, .54);
        }
        if(m3)
        {
            glColor3f (1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            for(int i=0; i<360; i++)
             {
               theta=i*3.1416/180;
               glVertex2f(.70+.12*cos(theta),.10+.06*sin(theta));
             }
            glEnd();
            glColor3f (0.0, 0.0, 0.0);
            glRectf(.60,.09,.67,.12);
            glRectf(.73,.09,.80,.12);
            glRectf(.69,.05,.71,.08);
            //glRectf(.66, .04, .68, .16);
        }
        if(m4)
        {
            glColor3f (1.0, 0.0, 0.0);
             glBegin(GL_POLYGON);
            for(int i=0; i<360; i++)
             {
               theta=i*3.1416/180;
               glVertex2f(.70+.12*cos(theta),-.18+.06*sin(theta));
             }
            glEnd();
            glColor3f (0.0, 0.0, 0.0);
            glRectf(.60,-.19,.67,-.16);
            glRectf(.73,-.19,.80,-.16);
            glRectf(.69,-.20,.71,-.23);
            //glRectf(.68, -.11, .70, -.24);
        }
    }
    if(l3)
    {
        if(m1)
        {
            glBegin(GL_QUADS);
            glColor3ub(0, 266, 25);
            glVertex2f(.8,.4);
            glVertex2f(.8,.5);
            glVertex2f(.7,.5);
            glVertex2f(.7,.4);
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.8,.43);
            glVertex2f(.86,.43);
            glVertex2f(.86,.46);
            glVertex2f(.8,.46);
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.7,.43);
            glVertex2f(.7,.46);
            glVertex2f(.64,.46);
            glVertex2f(.64,.43);
            glEnd();
        }

        if(m2)
        {
           glBegin(GL_QUADS);
           glColor3ub(0, 266, 25);
           glVertex2f(.8,.1);
           glVertex2f(.8,.2);
           glVertex2f(.7,.2);
           glVertex2f(.7,.1);
           glEnd();
           glBegin(GL_QUADS);
           glColor3ub(255, 0, 0);
           glVertex2f(.73,.04);
           glVertex2f(.76,.04);
           glVertex2f(.76,.1);
           glVertex2f(.73,.1);
           glEnd();
           glBegin(GL_QUADS);
           glColor3ub(255, 0, 0);
           glVertex2f(.73,.2);
           glVertex2f(.76,.2);
           glVertex2f(.76,.26);
           glVertex2f(.73,.26);
           glEnd();
        }

     if(m3)
     {

            glBegin(GL_QUADS);
            glColor3ub(0, 266, 25);
            glVertex2f(.8,-.1);
            glVertex2f(.8,-.2);
            glVertex2f(.7,-.2);
            glVertex2f(.7,-.1);
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.73,-.04);
            glVertex2f(.76,-.04);
            glVertex2f(.76,-.1);
            glVertex2f(.73,-.1);
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.73,-.2);
            glVertex2f(.76,-.2);
            glVertex2f(.76,-.26);
            glVertex2f(.73,-.26);
            glEnd();
     }

     if(m4)
     {
        glBegin(GL_QUADS);
            glColor3ub(0, 266, 25);
            glVertex2f(.8,-.4);
            glVertex2f(.8,-.5);
            glVertex2f(.7,-.5);
            glVertex2f(.7,-.4);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.8,-.43);
            glVertex2f(.86,-.43);
            glVertex2f(.86,-.46);
            glVertex2f(.8,-.46);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.7,-.43);
            glVertex2f(.7,-.46);
            glVertex2f(.64,-.46);
            glVertex2f(.64,-.43);
            glEnd();
     }

     }



}

 void Bigmonster()
 {
     if(l1)
     {
         if(mj)
         {
              glColor3f (0.0, .9, 0.5);
              glRectf(.68,.6,.85,.75);
              glRectf(.68,.7,.65,.65);
              glRectf(.78,.55,.83,.6);
              glRectf(.65,.35,.85,.55);
              glColor3f (0.0, 0.0, 0.0);
              glRectf(.7,.72,.75,.67);
        }
     }
     if(l2)
     {
         if(mj)
         {

             glColor3f (0.0,0.60, 0.60);
             glBegin(GL_TRIANGLES);
             glVertex2f(.95,.7);
             glVertex2f(.95,.3);
             glVertex2f(.7,.5);
             glEnd();

             glColor3f (0.60,0.0, 0.60);
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.65+.30*cos(theta),.5+.20*sin(theta));}
             glEnd();

             glColor3f (1.0,1.0, 1.0);
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.48+.05*cos(theta),.47+.05*sin(theta));}
             glEnd();
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.48+.05*cos(theta),.58+.05*sin(theta));}
             glEnd();
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.58+.05*cos(theta),.53+.05*sin(theta));}
             glEnd();

             glColor3f (0.0,0.0, 0.0);
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.48+.02*cos(theta),.47+.02*sin(theta));}
             glEnd();
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.48+.02*cos(theta),.58+.02*sin(theta));}
             glEnd();
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.58+.02*cos(theta),.53+.02*sin(theta));}
             glEnd();

             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.72+.03*cos(theta),.52+.07*sin(theta));}
             glEnd();

             glColor3f (1.0,0.0, 0.0);
             glBegin(GL_TRIANGLES);
             glVertex2f(.72,.57);
             glVertex2f(.72,.47);
             glVertex2f(.9,.5);
             glEnd();

             glColor3f (0.0, 0.40, 0.60);
             glRectf(.35,.47,.25,.54);
             //glColor3f (1.0, 1.0, 1.0);
             //glRectf(.60,.30,.65,.70);
         }
     }
     if(l3)
     {
         if(mj)
         {
             glBegin(GL_QUADS);
             glColor3ub(255, 0, 0);
             glVertex2f(.6,.3);
             glVertex2f(.9,.3);
             glVertex2f(.9,.65);
             glVertex2f(.6,.65);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(255, 255,255);
             glVertex2f(.65,.45);
             glVertex2f(.75,.45);
             glVertex2f(.75,.47);
             glVertex2f(.65,.47);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(255, 255,255);
             glVertex2f(.78,.38);
             glVertex2f(.83,.38);
             glVertex2f(.83,.40);
             glVertex2f(.78,.40);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(255, 255,255);
             glVertex2f(.78,.52);
             glVertex2f(.83,.52);
             glVertex2f(.83,.54);
             glVertex2f(.78,.54);
             glEnd();
             glBegin(GL_TRIANGLES);
             glColor3ub(0, 0, 0);
             glVertex2f(.9,.3);
             glVertex2f(1,.35);
             glVertex2f(.9,.4);
             glEnd();
             glBegin(GL_TRIANGLES);
             glColor3ub(0, 0, 0);
             glVertex2f(.9,.55);
             glVertex2f(1,.60);
             glVertex2f(.9,.65);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(0,0,0);
             glVertex2f(.6,.42);
             glVertex2f(.6,.52);
             glVertex2f(.4875,.52);
             glVertex2f(.4875,.42);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(0,0,0);
             glVertex2f(.4875,.3);
             glVertex2f(.4875,.63);
             glVertex2f(.3,.63);
             glVertex2f(.3,.3);
             glEnd();
             glBegin(GL_TRIANGLES);
             glColor3ub(0, 0, 0);
             glVertex2f(.65,.65);
             glVertex2f(.4,.75);
             glVertex2f(.6,.6);
             glEnd();
             glBegin(GL_TRIANGLES);
             glColor3ub(0, 0, 0);
             glVertex2f(.6,.35);
             glVertex2f(.43,.22);
             glVertex2f(.65,.3);
             glEnd();
        }
    }
}

  void BigAttack()
 {
     if(mj)
     {
         glColor3f (1.0, 0.0, 0.0);
         if(l1) glRectf(.68,.7,.73,.65);
         if(l2) glRectf(.45,.48,.5,.53);
         if(l3) glRectf(.45,.45,.5,.50);
     }
 }

void sun()
{
    glColor3f (1.0, .90, 0.2);
   // float theta;
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.1416/180;
      glVertex2f(.15*cos(theta),.7+.15*sin(theta));
   }
   glEnd();
}
void cloud()
{
    if(l1 || l3) glColor3f (0.6, 0.89, 1);
    else if(l2) glColor3f (1.0, 1.0, 1);

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.4+.10*cos(theta),.6+.10*sin(theta));
   }
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.25+.15*cos(theta),.6+.15*sin(theta));
   }
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.1+.10*cos(theta),.6+.10*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.9+.10*cos(theta),.8+.10*sin(theta));
   }
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.75+.15*cos(theta),.8+.15*sin(theta));
   }
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.6+.10*cos(theta),.8+.10*sin(theta));
   }
   glEnd();

}
void Trees()
{
    glColor3f (0.60, 0.0, 0.0);
  glRectf(0.73,-.86,0.77,-.66);
  glRectf(0.63,-.86,0.67,-.66);
  glRectf (0.25, -0.87, 0.29,-.66);
  glRectf (-0.43, -0.87, -0.40,-.66);
}
void Greenland()
{


   glColor3f (0.0, 0.80, 0.0);
    float theta;
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.99+0.6*cos(theta),-.99+0.3*sin(theta));
   }
   glEnd();
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.1+.4*cos(theta),-.99+.2*sin(theta));
   }
   glEnd();
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(.5+.40*cos(theta),-.99+.15*sin(theta));
   }
   glEnd();
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(0.9+.20*cos(theta),-.99+.20*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(.7+.17*cos(theta),-.7+.1*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(0.7+.1*cos(theta),-.6+.15*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.4+.17*cos(theta),-.7+.1*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-0.4+.08*cos(theta),-.65+.10*sin(theta));
   }
   glEnd();

     glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(.28+.17*cos(theta),-.7+.1*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(0.28+.08*cos(theta),-.65+.10*sin(theta));
   }
   glEnd();


}
void sky(){


 glBegin(GL_QUADS);
   glColor3ub(135, 206, 235);
   glVertex2f(1,.2);
   glVertex2f(1,1);
   glVertex2f(-1,1);
   glVertex2f(-1,.2);
   glEnd();
}
void background(){
    if(l1)
    {
        glColor3f (0.0, 0.0, 0.0);
        glRectf(-1.0,0.0,1.0,1.0);
    }
    if(l2)
    {
        glColor3f (0.60f, 0.89f, 0.89f);
        glRectf(-1.0,0.0,1.0,1.0);
    }
    if(l3) glColor3ub(225, 226, 227);
   glBegin(GL_QUADS);
   glVertex2f(1,-1);
   glVertex2f(1,.2);
   glVertex2f(-1,.2);
   glVertex2f(-1,-1);
   glEnd();
}
void hill(){

   glBegin(GL_TRIANGLES);
   glColor3ub(219, 197, 176);
   glVertex2f(-1,-1);
   glVertex2f(-.7,-.6);
   glVertex2f(-.4,-1);

   glVertex2f(-.4,-1);
   glVertex2f(-0.1,-.6);
   glVertex2f(0.2,-1);

   glVertex2f(.2,-1);
   glVertex2f(.5,-.6);
   glVertex2f(0.8,-1);

   glVertex2f(.8,-1);
   glVertex2f(1,-.7);
   glVertex2f(1,-1);
   glEnd();
}

void welcomescreen()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1,0,0);
     glRasterPos3f(-.20,.90,0.0);
     char msg1[]="WELCOME TO DEADLY MONSTERS";
     for(int i=0; i<strlen(msg1); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);

     glColor3f(0,.5,.5);
     glRasterPos3f(-0.90,0.70,0.0);
     char msg2[]="INSTRUCTIONS!!!!";
     for(int i=0; i<strlen(msg2); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg2[i]);

     glColor3f(0,.5,0);
     glRasterPos3f(-0.80,0.55,0.0);
     char msg3[]="1. Use <-(left arrow), ->(right arrow), up arrow, down arrow to control the pistol.";
     for(int i=0; i<strlen(msg3); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);

     glColor3f(0,.5,0);
     glRasterPos3f(-0.80,0.45,0.0);
     char msg4[]="2. Use left mouse to shoot.";
     for(int i=0; i<strlen(msg4); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg4[i]);

     glColor3f(0,.5,0);
     glRasterPos3f(-0.80,0.35,0.0);
     char msg5[]="3. To avoid collision with enemy , you can destroy enemy  by shooting it.";
     for(int i=0; i<strlen(msg5); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg5[i]);

     glColor3f(0,.5,0);
     glRasterPos3f(-0.80,0.25,0.0);
     char msg6[]="4. Shooting the small enemy  will give you 10 points, whereas shooting Big monster will give 50 points.";
     for(int i=0; i<strlen(msg6); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg6[i]);

     glColor3f(0,.5,0);
     glRasterPos3f(-0.80,0.15,0.0);
     char msg7[]="5. Press space to start the game.";
     for(int i=0; i<strlen(msg7); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg7[i]);

     glColor3f(0,.5,0);
     glRasterPos3f(-0.80,0.05,0.0);
     char msg8[]="6. Press Esc to quit the game.";
     for(int i=0; i<strlen(msg8); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg8[i]);

    glFlush();
}

void gameover()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1,1,0);
     glRectf(-.5,.3,.5,.8);
     glColor3f(1,0,0);
     glRasterPos3f(-.10,0.60,0.0);
     char msg1[]="GAME OVER";
     for(int i=0; i<strlen(msg1); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);

     glColor3f(0.0,0.0,0.0);
     glRasterPos3f(-.150,0.50,0.0);
     char msg2[]="PRESS Esc TO EXIT!!";
     for(int i=0; i<strlen(msg2); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg2[i]);

     glColor3f(0,0.2,0.5);
     glRectf(-.5,-.5,.5,0.0);
     glColor3f(1,1,1);
     glRasterPos3f(-.10,-0.250,0.0);
     char msg3[]="YOUR SCORE IS";
     for(int i=0; i<strlen(msg3); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);

     glRasterPos3f(0.0,-0.350,0.0);
     string s=to_string(score);
     for(int i=0; i<s.size(); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
     glFlush();
}

void winner()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1,1,0);
     glRectf(-.5,.3,.5,.8);
     glColor3f(1,0,0);
     glRasterPos3f(-.180,0.60,0.0);
     char msg1[]="CONGRATULATIONS!!!!";
     for(int i=0; i<strlen(msg1); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);

     glRasterPos3f(-.350,0.50,0.0);
     char msg2[]="YOU HAVE WON OVER THE DEADLY MONSTERS!!!";
     for(int i=0; i<strlen(msg2); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg2[i]);

     glColor3f(0.0,0.0,0.0);
     glRasterPos3f(-.20,0.40,0.0);
     char msg3[]="PLEASE PRESS Esc TO EXIT!!";
     for(int i=0; i<strlen(msg3); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg3[i]);

     glColor3f(0,0.2,0.5);
     glRectf(-.5,-.5,.5,0.0);
     glColor3f(1,1,1);
     glRasterPos3f(-.10,-0.250,0.0);
     char msg4[]=" YOUR SCORE IS ";
     for(int i=0; i<strlen(msg4); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg4[i]);

     glRasterPos3f(0.0,-0.350,0.0);
     string s=to_string(score);
     for(int i=0; i<s.size(); i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
     glFlush();
}
void display()
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
glPointSize(15.0);

if(welcome) welcomescreen();
if(gr) gameover();
if(win) winner();
if(l1)
{
glPushMatrix();
background();
House();
sun();
cloud();
glPopMatrix();

glPushMatrix();
glTranslatef(PistolLR,0.0,0.0f);
glPushMatrix();
glTranslatef(positionbullet,PistolUD,0.0f);
PistolBullet();
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,PistolUD,0.0f);
//glTranslatef(0.0f,PistolUD,0.0f);
Pistol();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(position,0.0f,0.0f);
Monster();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,PositionMonster,0.0f);
glPushMatrix();
glTranslatef(position,0.0f,0.0f);
BigAttack();
glPopMatrix();
glPushMatrix();
Bigmonster();
glPopMatrix();
glPopMatrix();
}

if(l2)
{
background();
glPushMatrix();
Trees();
Greenland();
sun();
cloud();
glPopMatrix();

glPushMatrix();
glTranslatef(PistolLR,0.0,0.0f);
glPushMatrix();
glTranslatef(positionbullet,PistolUD,0.0f);
PistolBullet();
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,PistolUD,0.0f);
Pistol();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(position,0.0f,0.0f);
Monster();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,PositionMonster,0.0f);
glPushMatrix();
glTranslatef(position,0.0f,0.0f);
BigAttack();
glPopMatrix();
glPushMatrix();
Bigmonster();
glPopMatrix();
glPopMatrix();
}

if(l3)
{
glPushMatrix();
sky();
background();
hill();
sun();
cloud();
glPopMatrix();

glPushMatrix();
glTranslatef(PistolLR,0.0,0.0f);
glPushMatrix();
glTranslatef(positionbullet,PistolUD,0.0f);
PistolBullet();
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,PistolUD,0.0f);
Pistol();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(position,0.0f,0.0f);
Monster();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,PositionMonster,0.0f);
glPushMatrix();
glTranslatef(position,0.0f,0.0f);
BigAttack();
glPopMatrix();
glPushMatrix();
Bigmonster();
glPopMatrix();
glPopMatrix();
}

glFlush ();
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   screen_width = glutGet(GLUT_SCREEN_WIDTH);
   screen_height = glutGet(GLUT_SCREEN_HEIGHT);
   glutInitWindowSize (screen_width, screen_height);
   glutInitWindowPosition (0, 0);
   glutCreateWindow("DEADLY MONSTERS");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(keyboard);
   glutMouseFunc(handleMouse);
   glutSpecialFunc(SpecialInput);
   //glutFullScreen();
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
