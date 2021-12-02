#include<string.h>
#include<stdarg.h>
#include<stdbool.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

static double x=0.0;
static int m_id;
static float help1=1;
static bool day= false;
static int grow=0;
static double angle=0;
static float lightIntensity=0;
const double PI = 3.141592654;
static int value=0;
static int window;
int frameNumber = 0;


void stroke_output(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

void stroke_output1(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScaled(0.0005, 0.00088, 0.00088);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
	glPopMatrix();
}
void stroke_output2(GLfloat x, GLfloat y, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScaled(0.0012, 0.002, 0.0028);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
	glPopMatrix();
}

void drawtext(float x,float y,char *s)
{
	glColor3f(1,0,0);
	int i;
	glRasterPos2f(x,y);
	for(i=0;s[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
}

void doInit() 
{
    
	/* Background and foreground color */
   
 if(day){
	glClearColor(0.9,0.9,0.9,0.0);
	}else{
	glClearColor(0.3,0.3,0.3,0.0);
	}
	glColor3f(0.0,1.0,0.0);
    glViewport(0,0,640,480);
 
	/* Select the projection matrix and reset it then
     setup our view perspective */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);    
    /* Select the modelview matrix, which we alter with rotatef() */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
    glDepthFunc(GL_LEQUAL);
}




void help(){


glPushMatrix();
glScaled(0.7,0.7,0.7);

stroke_output(-3.2,3,"SOLAR POWER MANAGEMENT");
//stroke_output(-5,2,"A project by Student name");
stroke_output(-3,-1," PRESS D TO Toggle Day / Night");
stroke_output(-3,0," PRESS R TO Toggle RUN / HALT");
stroke_output(-3,-2," PRESS Q TO QUIT");
glPopMatrix();




}

void drawHouse(int x,int y,int z){

glPushMatrix();
glTranslatef(x,y,z);
glScaled(0.5,0.5,0.5);
glColor3f(1,1,1);

	//House
glPushMatrix();
glTranslatef(0,0,-15);
glScaled(1,1,1);
glColor3f(0.1,0.2,0.0);
glutSolidCube(8);
glPopMatrix();

//House Door
glPushMatrix();
glTranslatef(2.4,-1.8,-8);
glScaled(.7,1.8,-0.5);

if(day){
glColor3f(0,0,0);
}else{
	glColor3f(1,1,0);
}
glutSolidCube(2);
glPopMatrix();

//House window1
glPushMatrix();
glTranslatef(-.1,0.6,-8);
glScaled(.9,0.9,0.1);
if(day){
glColor3f(0,0,0);
}else{
 glColor3f(1,1,0);
}
glutSolidCube(2);
glPopMatrix();


//House window2
glPushMatrix();
glTranslatef(-2,0.6,-8);
glScaled(.9,0.9,0.1);
if(day){
glColor3f(0,0,0);
}else{
	glColor3f(1,1,0);
}
glutSolidCube(2);
glPopMatrix();

//House roof
glPushMatrix();
glTranslatef(0,4,-15);
glScaled(1,.2,1);
glDisable(GL_LIGHTING);
glColor3f(0.5,0.5,0.5);
glutSolidCube(8);
glEnable(GL_LIGHTING);
glPopMatrix();
//roof elongated
glPushMatrix();
glTranslatef(4.56,0.376,-14.6);
glScaled(0.13,1.09,1);
glColor3f(0,0.8,0.8);
glutSolidCube(8);
glPopMatrix();


glPopMatrix();

}

void drawHouse1(int x,int y,int z)
{
 glPushMatrix();
glTranslatef(x,y,z);
glScaled(0.5,0.5,0.5);
glColor3f(1,1,1);

	//House
glPushMatrix();
glTranslatef(0,0,-15);
glScaled(1,1,1);
glColor3f(0.1,0.2,0.0);
glutSolidCube(8);
glPopMatrix();


glPushMatrix();
glTranslatef(2,-0.5,-8);
glScaled(1.8,1.5,0.1);
if(day){
glColor3f(0,0,0);
}else{
 glColor3f(1,1,0);
}
glutSolidCube(2);
glPopMatrix();


//House window2
glPushMatrix();
glTranslatef(-2,-0.5,-8);
glScaled(-1.9,1.5,0.1);
if(day){
glColor3f(0,0,0);
}else{
	glColor3f(1,1,0);
}
glutSolidCube(2);
glPopMatrix();

//House roof
glPushMatrix();
glTranslatef(-2.0,5.0,-15);
//glRotated(-25,0,0,.5);
glScaled(1.82,.24,1);
glDisable(GL_LIGHTING);
glColor3f(0.5,0.5,0.5);
glutSolidCube(8);
glEnable(GL_LIGHTING);
glPopMatrix();
//roof elongated
glPushMatrix();
glTranslatef(4.7,-2.81,-15);
glScaled(0.19,2.22,1);
glColor3f(0.5,0.5,0.5);
glutSolidCube(8);
glPopMatrix();

glPopMatrix();

} 

void drawSolarPanel(float x,float y,float z){

glPushMatrix();
glTranslatef(x,y,z);

//Top panel
glPushMatrix();
glTranslatef(5,0,-15);
glRotatef(135,1,0,0);
glScaled(1,2,0.2);
if(day){
glColor3f(0.3,0.3,0.6);
}
else
{
 glColor3f(0.2,0.2,0.4);
}
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslatef(5,0.053,-14.5);
glRotatef(135,1,0,0);
glScaled(.3,1.9,0);
glColor3f(1,1,0);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslatef(4.7,0.053,-14.5);
glRotatef(135,1,0,0);
glScaled(.3,1.9,0);
glColor3f(1,1,0);
glutWireCube(1);
glPopMatrix();

//horizontal wire frame on solar
glPushMatrix();
glTranslatef(4.9,0,-14.5);
glRotatef(135,1,0,0);
glScaled(1,1,0);
glColor3f(1,1,0);
glutWireCube(1);
glPopMatrix();

//Stand

glPushMatrix();
glTranslatef(5.5,-1,-16);
glScaled(0.1,2,0.2);
glColor3f(0.9,0.9,0.9);
glutSolidCube(1);
glPopMatrix();

glPopMatrix();
}

/*void  drawroad(int x1,int y1,int z1){
 glPushMatrix();
 glTranslatef(0,-6,-15);
 glScaled(.5,.7,.1);
 glColor3f(1.0,1.0,1.0);
 glutSolidCube(8);
 glPopMatrix();
}*/

void drawroad1()
{
 glColor3f(0.9f,0.9f,0.9f);
 glBegin(GL_POLYGON);
 glVertex3f(-6.4,-3.0,0.0);
 glVertex3f(6.4,-3.0,0.0);
 glVertex3f(6.4,-1.0,0.0);
 glVertex3f(-6.4,-1.0,0.0);
 glEnd();
}

void drawline()
{
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex3f(-6.4,-2.0,0.0);
glVertex3f(6.4,-2.0,0.0);
glVertex3f(6.4,-1.9,0.0);
 glVertex3f(-6.4,-1.9,0.0);
glEnd();
}

void drawpole(float a,float b,float c)
{
 glPushMatrix();
 glTranslatef(a,b,c);
 glScaled(0.2,0.21,0.2);
 //bulb
 glPushMatrix();
 glTranslatef(-2.8,9.18,-15);
 glRotatef(60,2,0,0);
 glScaled(1.2,2.2,0.2);
 if(day){
 glColor3f(0.5,0.5,0.5);
 }
 else
 {
  glColor3f(1,1,0);
 }
 glutSolidCube(1);
 glPopMatrix();


 glPushMatrix();
 glTranslatef(0,-1,-4);
 glScaled(0.12,5.95,0.2);
 glColor3f(0.9,0.9,0.9);
 glutSolidCube(3);
 glPopMatrix();
 
 
 glPopMatrix();
}

void drawpole1(float a,float b,float c)
{
 glPushMatrix();
 glTranslatef(a,b,c);
 glScaled(0.2,0.2,0.2);
 //bulb
 glPushMatrix();
 glTranslatef(-0.3,9.18,-15);
 glRotatef(60,2,0,0);
 glScaled(1.2,2.2,0.2);
 if(day){
 glColor3f(0.5,0.5,0.5);
 }
 else
 {
  glColor3f(1,1,0);
 }
 glutSolidCube(1);
 glPopMatrix();


 glPushMatrix();
 glTranslatef(0.0,-1,-4);
 glScaled(0.12,5.95,0.2);
 glColor3f(0.9,0.9,0.9);
 glutSolidCube(3);
 glPopMatrix();
 
 
 glPopMatrix();
}

void drawpole2(float a,float b,float c)
{
 glPushMatrix();
 glTranslatef(a,b,c);
 glScaled(0.2,0.2,0.2);
 //bulb
 glPushMatrix();
 glTranslatef(2.2,9.18,-15);
 glRotatef(60,2,0,0);
 glScaled(1.2,2.2,0.2);
 if(day){
 glColor3f(0.5,0.5,0.5);
 }
 else
 {
  glColor3f(1,1,0);
 }
 glutSolidCube(1);
 glPopMatrix();


 glPushMatrix();
 glTranslatef(0,-1,-4);
 glScaled(0.12,5.95,0.2);
 glColor3f(0.9,0.9,0.9);
 glutSolidCube(3);
 glPopMatrix();
 
 
 glPopMatrix();
}


void drawDisk(double radius)
{
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++)
	{
		double angle = 2 * PI / 32 * d;
		glVertex2d(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}

void drawWheel()
{
	int i;
	glColor3f(0, 0, 0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0, 0, 0);
	drawDisk(0.7);
	glRotatef(frameNumber * 20, 0, 0, 1);
	glBegin(GL_LINES);
	for (i = 0; i < 15; i++)
	{
		glVertex2f(0, 0);
		glVertex2d(cos(i * 2 * PI / 15), sin(i * 2 * PI / 15));
	}
	glEnd();
}
void doFrame(int v)
{
	frameNumber++;
	glutPostRedisplay();
	glutTimerFunc(30, doFrame, 0);
}

void drawcar()
{
  glPushMatrix();
  glTranslatef(-4.3f, -1.7f, 0);
  glScalef(0.15f, 0.15f, 1);
  drawWheel();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-3.55f, -1.7f, 0);
  glScalef(0.15, 0.15f, 1);
  drawWheel();
  glPopMatrix(); 
 glColor3f(0.2,.6,.9);
 glBegin(GL_POLYGON);
 glVertex3f(-4.6,-1.7,0.0);
 glVertex3f(-3.3,-1.7,0.0);
 glVertex3f(-3.3,-1.5,0.0);
 glVertex3f(-3.6,-1.5,0.0);
 glVertex3f(-3.8,-1.3,0.0);
 glVertex3f(-4.13,-1.3,0.0);
 glVertex3f(-4.3,-1.5,0.0);
 glVertex3f(-4.6,-1.5,0.0);
 glEnd();
 glColor3f(0.8f,0.8f,0.8f);
 glBegin(GL_POLYGON);
 glVertex3f(-4.05,-1.5,0.0);
 glVertex3f(-3.86,-1.5,0.0);
 glVertex3f(-3.86,-1.35,0.0);
 glVertex3f(-4.05,-1.35,0.0);
 glEnd();
 glColor3f(0.99,0.0,0.99);
 glBegin(GL_LINES);
 glVertex3f(-3.95,-1.5,0.0);
 glVertex3f(-3.95,-1.35,0.0);
 glScaled(1,1, 1);
 glEnd();
}
void draw(){


 if(day){
	glClearColor(0.9,0.9,0.7,0.0);
	}else{
	glClearColor(0.3,0.3,0.3,0.0);
	}


 glPushMatrix();
 glRotatef(angle,1,0,0);
 glTranslatef(-10,20,-155);
 //glTranslatef(42,20,-155);
 glScaled(1,1,0.6);
 if(day){
 glColor3f(1,1,0);
 }else{
 glColor3f(1,1,1);
 }
 glutSolidSphere(5,100,100);
 glPopMatrix();

 
 glPushMatrix();
 glTranslatef(0,-10,5);
 glScaled(500,10,1000);
 if(day) 
  glColor3f(0.0f,0.9f,0.0f);
  else
  glColor3f(0.0,0.4,0.0);
 glutSolidCube(1);
 glPopMatrix();


drawHouse(-5,5,-55);
drawHouse(-4,0,-35); 
drawHouse(-5,0,-15);

drawHouse(-10,0,-15);
drawHouse1(-10,4,-15); //2storey
drawroad1();
glDisable(GL_LIGHTING);
drawline();
drawpole(-3.1,-0.9,0);
drawpole1(-0.28,-0.9,0);
drawpole2(2.47,-0.9,0);
glPushMatrix();
glTranslated(-3 + 13 * (frameNumber % 300) / 300.0, 0, 0);
glScaled(1,1, 1);
drawcar();
glEnable(GL_LIGHTING);
glPopMatrix();
glutSwapBuffers();
//drawheel(-4.45,-1.7,0.0);


//Solar Panels
for(int i=-1;i<3;i++)
{
	for(int j=5;j>-2;j--)

drawSolarPanel(i*2,1,j);

}


//draw power station.
//stroke_output2(0.3,1.59,"POWER STATION");
//stroke_output1(0.07,1.38,"ENERGY LEVEL");


// transformer

glPushMatrix();
glTranslatef(14.5,8.5,-185);
glScaled(1.8,2,2.2);
glColor3f(0.1,0.1,0.1);
glutSolidCube(17);
glPopMatrix();

glPushMatrix();
glTranslatef(6.4,-0.15,-166);
glScaled(2.0,1.8,-0.052);
glDisable(GL_LIGHTING);
glColor3f(0.8,0.8,0.8);
glutSolidCube(6);
glDisable(GL_LIGHTING);
glPopMatrix();

void trans_level(float x,float y,float z)
{
 glPushMatrix();
 glTranslatef(x,y,z);
 glScaled(.3,0.4,-0.052);
 glColor3f(1,1,0);
 glutSolidCube(2);
 glPopMatrix();
}

//Transformer Power levels




	
			// y axis from 5 to 18 and show growth in one second delay

if(day){
		if(grow<=10000){
	       grow++;
		   angle+=0.002;
		}
	}
	else{
		if(grow>=0){
	       grow--;
		   angle-=0.002;
		}
	}
			

	if(grow>1800){

  				trans_level(0.4,2.5,-12);
				stroke_output2(0.06,1.59,"20%");		 		
				
			}

	 if(grow>3600){

							 		
				trans_level(1.2,2.5,-12);
				stroke_output2(0.5,1.59,"40%");
				
			
			}

if(grow>5400){

				trans_level(2.0,2.5,-12);		 		
				stroke_output2(0.92,1.59,"60%");
			
			}

if(grow>7200){

		 		trans_level(2.8,2.5,-12);
				stroke_output2(1.325,1.59,"80%");
			
			}

if(grow>9000){

				trans_level(3.6,2.5,-12);		 		
				stroke_output2(1.65,1.59,"100%");
			}

	/*if(grow>6000){

		 		glPushMatrix();
				glTranslatef(3.9,3,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}

	if(grow>7000){

		 		glPushMatrix();
				glTranslatef(3.9,4,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}


	if(grow>8000){

		 		glPushMatrix();
				glTranslatef(3.9,5,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}

	if(grow>9000){

		 		glPushMatrix();
				glTranslatef(3.9,6,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}

	if(grow>10000){

		 		glPushMatrix();
				glTranslatef(3.9,7,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}


if(grow>11000){

		 		glPushMatrix();
				glTranslatef(3.9,8,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}


if(grow>12000){

		 		glPushMatrix();
				glTranslatef(3.9,9,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}

if(grow>13000){

		 		glPushMatrix();
				glTranslatef(3.9,10,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}

if(grow>14000){

		 		glPushMatrix();
				glTranslatef(3.9,11,-99.8);
				glScaled(1,0.05,0.2);
				glColor3f(1,1,0);
				glutSolidCube(9);
				glPopMatrix();
			
			}*/

if(grow>15000){

		 		
			
			}

                        
	}

void interior()
{
 if(!day)
 {
  glEnable(GL_LIGHTING);
 }
 else
 {
  glDisable(GL_LIGHTING);
 } 
 glClearColor(0.2,0.2,0.2,0);
 glColor3f(0.8,0.2,0);
 glBegin(GL_POLYGON);
 glVertex3f(6.4,-4.8,0);
 glVertex3f(6.4,4.8,0);
 glVertex3f(2.8,4.8,0);
 glVertex3f(2.8,-2.0,0);
 glEnd();
 
 glColor3f(0.9,0.4,0);
 glBegin(GL_POLYGON);
 glVertex3f(-6.4,-4.8,0);
 glVertex3f(-6.4,4.8,0);
 glVertex3f(-3.5,4.8,0);
 glVertex3f(-3.5,-4.8,0);
 glEnd();

 //GLfloat mat_ambient[]={1.0,1.0,0.4,0.0};
 //glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
 glColor3f(0.35,0.35,0.67);
 glBegin(GL_POLYGON);
 //glColor3f(0.1,0.1,0.1);
 glVertex3f(2.8,-2.0,0);
 glVertex3f(2.8,4.8,0);
 glVertex3f(-2.5,4.8,0);
 glVertex3f(-2.5,-2.0,0);
 glEnd();
 
 glColor3f(0.8,0.2,0);
 glBegin(GL_POLYGON);
 glVertex3f(-2.5,-2.0,0);
 glVertex3f(-2.5,4.8,0);
 glVertex3f(-3.5,4.8,0);
 glVertex3f(-3.5,-4.8,0);
 glEnd();
 
 //tv
 glColor3f(0.9f,0.9f,0.9f);
 glBegin(GL_POLYGON);
 glVertex3f(-1.2,0.2,0);
 glVertex3f(1.5,0.2,0);
 glVertex3f(1.5,2.2,0);
 glVertex3f(-1.2,2.2,0);
 glEnd();
 
 glColor3f(0.1f,0.1f,0.1f);
 glBegin(GL_POLYGON);
 glVertex3f(-1.15,0.35,0);
 glVertex3f(1.45,0.35,0);
 glVertex3f(1.45,2.15,0);
 glVertex3f(-1.15,2.15,0);
 glEnd();
 
 //LAMP1
 
 glColor3f(0.2f,0.2f,0.2f);
 glBegin(GL_POLYGON);
 glVertex3f(-2.0,4.8,0);
 glVertex3f(-2.0,1.8,0);
 glVertex3f(-1.95,1.8,0);
 glVertex3f(-1.95,4.8,0);
 glEnd();
 glPushMatrix();
 glRotatef(angle,1,0,0);
 glTranslatef(-1.97,1.75,0);
 //glTranslatef(42,20,-155);
 glScaled(1,1,0.6);
 if(day){
 glColor3f(1,1,0);
 }else{
 glColor3f(1,1,1);
 }
 glutSolidSphere(0.25,25,25);
 glPopMatrix();

 //LAMP2
 
 glColor3f(0.2f,0.2f,0.2f);
 glBegin(GL_POLYGON);
 glVertex3f(2.3,4.8,0);
 glVertex3f(2.3,1.8,0);
 glVertex3f(2.35,1.8,0);
 glVertex3f(2.35,4.8,0);
 glEnd();
 glPushMatrix();
 glRotatef(angle,1,0,0);
 glTranslatef(2.33,1.75,0);
 //glTranslatef(42,20,-155);
 glScaled(1,1,0.6);
 if(day){
 glColor3f(1,1,0);
 }else{
 glColor3f(1,1,1);
 }
 glutSolidSphere(0.25,25,25);
 glPopMatrix();
 
  //window
 glColor3f(0.8,0.6,0.7);
 glBegin(GL_POLYGON);
 glVertex3f(3.2,0.8,0);
 glVertex3f(4.2,0.6,0);
 glVertex3f(4.2,2.0,0);
 glVertex3f(3.2,2.0,0);
 glEnd();

 glutSwapBuffers();
 
}

void solar_cell()
{
glColor3f(0.5,0.5,0.5);
 glBegin(GL_LINE_LOOP);
 glVertex3f(1.35,0.7,0);
 glVertex3f(1.35,1.0,0);
 glVertex3f(3.0,1.0,0);
 glVertex3f(3.0,-0.70,0);
 glVertex3f(3.2,-0.70,0);
 glVertex3f(3.2,-0.90,0);
 glVertex3f(3.0,-0.90,0);
 glVertex3f(3.0,-2.5,0);
 glVertex3f(1.35,-2.5,0);
 glVertex3f(1.35,-2.0,0);
 glEnd(); 
 glPushMatrix();
 glRotatef(angle,1,0,0);
 glTranslatef(3.4,-0.74,0);
 //glTranslatef(42,20,-155);
 glScaled(1,1,0.6);
 if(day){
 glColor3f(1,1,0);
 }else{
 glColor3f(1,1,1);
 }
 glutSolidSphere(0.25,25,25);
 glPopMatrix();

 glClearColor(0.8,0.8,0.8,0);
 glColor3f(0,0.8,0.1);
 glBegin(GL_POLYGON);
 glVertex3f(-2.0,-2.2,0);
 glVertex3f(2.0,-2.2,0);
 glVertex3f(2.0,-1.8,0);
 glVertex3f(-2.0,-1.8,0);
 glEnd();
 
 glColor3f(0.34,0.4,0.9);
 glBegin(GL_POLYGON);
 glVertex3f(-2.0,-1.8,0);
 glVertex3f(2.0,-1.8,0);
 glVertex3f(2.0,-0.8,0);
 glVertex3f(-2.0,-0.8,0);
 glEnd(); 

 glColor3f(0.8,0.6,0.7);
 glBegin(GL_POLYGON);
 glVertex3f(-2.0,-0.8,0);
 glVertex3f(2.0,-0.8,0);
 glVertex3f(2.0,0.2,0);
 glVertex3f(-2.0,0.2,0);
 glEnd(); 

 glColor3f(0.9,0.47,0.1);
 glBegin(GL_POLYGON);
 glVertex3f(-2.0,0.2,0);
 glVertex3f(2.0,0.2,0);
 glVertex3f(2.0,0.6,0);
 glVertex3f(-2.0,0.6,0);
 glEnd(); 
 
 glColor3f(0.9,0.47,0.1);
 glBegin(GL_POLYGON);
 glVertex3f(-2.0,0.2,0);
 glVertex3f(2.0,0.2,0);
 glVertex3f(2.0,0.6,0);
 glVertex3f(-2.0,0.6,0);
 glEnd(); 

glColor3f(0.1372,0.1372,0.5568);
 glBegin(GL_POLYGON);
 glVertex3f(-1.6,0.2,0);
 glVertex3f(-1.1,0.2,0);
 glVertex3f(-1.1,0.7,0);
 glVertex3f(-1.6,0.7,0);
 glEnd(); 

glColor3f(0.1372,0.1372,0.5568);
 glBegin(GL_POLYGON);
 glVertex3f(-0.7,0.2,0);
 glVertex3f(-0.2,0.2,0);
 glVertex3f(-0.2,0.7,0);
 glVertex3f(-0.7,0.7,0);
 glEnd(); 

glColor3f(0.1372,0.1372,0.5568);
 glBegin(GL_POLYGON);
 glVertex3f(0.2,0.2,0);
 glVertex3f(0.7,0.2,0);
 glVertex3f(0.7,0.7,0);
 glVertex3f(0.2,0.7,0);
 glEnd(); 

glColor3f(0.1372,0.1372,0.5568);
 glBegin(GL_POLYGON);
 glVertex3f(1.1,0.2,0);
 glVertex3f(1.6,0.2,0);
 glVertex3f(1.6,0.7,0);
 glVertex3f(1.1,0.7,0);
 glEnd(); 

 
 drawtext(-4.2,-0.3,"N-TYPE SILICON(B+) ------------>");
 drawtext(-4.2,-1.3,"P-TYPE SILICON(P-) ------------>");
 drawtext(-4.1,-2.1,"BACK ELECTRODE ------------>");
 drawtext(2.1,-2.3,"CURRENT -->");
 stroke_output(-1.0,2.4,"SUNLIGHT");
 stroke_output(-0.4,1.6,"|");
 stroke_output(-0.5,0.95,"V");
 stroke_output(0.4,-0.3,"+ -");
 stroke_output(-0.9,-1.3,"- +");
}
void menu(int num)
{
	if (num == 0)
	{
		glutDestroyWindow(window);
		exit(0);
	}
	else
	{
		value = num;
	}
}	
	
	
void createmenu(void)
{
 m_id=glutCreateMenu(menu);
 glutAddMenuEntry("Solar Energy", 1);
 glutAddMenuEntry("HOME INTERIOR", 2);
 glutAddMenuEntry("SOLAR CELL", 3);
 glutAddMenuEntry("FORFEIT", 0);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void frame1()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 if(help1){
		help();
	}
	else
	{
	    glEnable(GL_LIGHTING);
            draw();
	}
 glFlush();
}

void frame2()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 glDisable(GL_LIGHTING);
 interior();
 glFlush();
}

void frame3()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 glDisable(GL_LIGHTING);
 solar_cell();
 glFlush();
}
void doDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-13.0f);
	
	
        stroke_output2(-3.0,3.0,"PROJECT THEME: ");
	stroke_output2(-1.0,3.0,"HUMAN AND NATURE INTERACTION");
	stroke_output2(-3.0,2.2,"PROJECT TITLE: ");
	stroke_output2(-1.0,2.2,"SOLAR POWER MANAGEMENT");
	stroke_output2(-2.4,0.8,"PRADYUMNA KUMAR");
	stroke_output2(-0.4,0.8,"(1BI16CS096)");
	stroke_output2(-2.4,-0.2,"PAVAN S");
	stroke_output2(-0.4,-0.2,"(1BI16CS094)");
	stroke_output2(-3.0,-1.4,"UNDER THE GUIDENCE OF:");
        stroke_output2(-3.0,-1.8,"BHANUSHREE K J");
	stroke_output2(-3.0,-2.9,"BANGALORE INSTITUTE OF TECHNOLOGY,BANGALORE-004");
        // Write your Own Code Here
	
        switch(value)
        {
	  case 1: frame1();
                  break;
          case 2: frame2();
                  break;
          case 3: frame3();
                  break;
        }
	/*if(help1){
		help();
	}
	else
	{
	    draw();
	}*/


          //comntd
	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={100.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	/*GLfloat lightIntensity[]={3.7f,0.7f,0.7f,1.0f};     Orange
	GLfloat light_position[]={2.0f,5.0f,3.0f,1.0f};*/

	/*light source properties*/
	//if(day){
			
         //comntd
	GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
	GLfloat light_position[]={2.0f,0.0f,0.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);

	GLfloat light_position2[]={0.0f,0.0f,8.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position2);

	
	GLfloat light_position3[]={0.0f,5.0f,15.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

	/*}else{
	
	

	GLfloat lightIntensity[]={0.7f,0.7f,0.7f,0.5f};
	GLfloat light_position[]={2.0f,0.0f,0.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);

	GLfloat light_position2[]={0.0f,0.0f,8.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position2);

	
	GLfloat light_position3[]={0.0f,2.0f,2.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
	
	}*/




	glFlush();
	glutSwapBuffers();
	
    
}

void mykey(unsigned char key,int x,int y)
{
	if(key=='q'||key=='Q')
	{
		exit(0);
	}

	
	if(key=='r'||key=='R')
	{
		help1=!help1;
		glutPostRedisplay();

	}


	if(key=='d' || key=='D'){
	
		if(day){
		day=false;
		}else{
		day=true;
		}
	glutPostRedisplay();
	glutIdleFunc(doDisplay);
	
	
	}





}


int main(int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Solar power");
    glutDisplayFunc(doDisplay);
        createmenu();	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	glutKeyboardFunc(mykey);
	doInit();
   glutTimerFunc(200, doFrame, 0); 
   glutMainLoop();
   return 0; 
}



