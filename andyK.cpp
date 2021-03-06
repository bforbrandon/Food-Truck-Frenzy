//Andy Koumane
//andyK.cpp

/**
 * As of 4/19/2017, I've rendered the character models and foods
 * in their appropiate places, leaving them for Jin to added
 * collision boxes for them. Now that I have the base model for the
 * rendering, I will apply them to the appropiate classes made below
 * in order for them to operate with the AI that I plan to program
 * in the near future.
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>
#include "log.h"
#include "ppm.h"
#include "andyK.h"
#include <time.h>
using namespace std;

Ppmimage *customerStanding1 = NULL;
Ppmimage *customerStanding2 = NULL;
Ppmimage *customerStanding3 = NULL;
Ppmimage *customerStanding4 = NULL;
Ppmimage *customerSitting1 = NULL;
Ppmimage *customerSitting2 = NULL;
Ppmimage *customerSitting3 = NULL;
Ppmimage *customerSitting4 = NULL;
Ppmimage *burgerOnSide = NULL;
GLuint customerStandingTexture1;
GLuint customerStandingTexture2;
GLuint customerStandingTexture3;
GLuint customerStandingTexture4;
GLuint customerSittingTexture1;
GLuint customerSittingTexture2;
GLuint customerSittingTexture3;
GLuint customerSittingTexture4;
GLuint burgerOnSideTexture;

Customer::Customer()		
{
	xPos1 = 74;
	xPos2 = 170;
	yPos1 = 498;
	yPos2 = 594;
	srand(time(NULL));
	foodChoice = rand() % 4 + 1;
	modelNum = rand() % 4 + 1;
	seatNum = rand() % 4 + 1;
	inLine = true;
	inSeat = false;
	hasFood = false;
	isEating = false;
	finishFood = false;
}

void Customer::setInLine(bool a) {
	inLine = a;
}

void Customer::setInSeat (bool a) {
	inSeat = a;
}

void Customer::setHasFood (bool a) {
	hasFood = a;
}

void Customer::setIsEating (bool a) {
	isEating = a;
}

void Customer::setFinishFood (bool a) {
	finishFood = a;
}

void Customer::renderModel()
{
	if (inLine) {
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);

		switch(modelNum) {
			case 1:
				glBindTexture(GL_TEXTURE_2D, customerStandingTexture1);
				break;
			case 2:
				glBindTexture(GL_TEXTURE_2D, customerStandingTexture2);
				break;
			case 3:
				glBindTexture(GL_TEXTURE_2D, customerStandingTexture3);
				break;
			case 4:
				glBindTexture(GL_TEXTURE_2D, customerStandingTexture4);
				break;
		}

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(xPos1, yPos1);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(xPos1, yPos2);
		glTexCoord2f(1.0f, 0.0f); glVertex2i(xPos2, yPos2);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(xPos2, yPos1);
		glEnd();
		glPopMatrix();
	}
	else {
		inSeat = true;
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		
		switch(modelNum) {
			case 1:
				glBindTexture(GL_TEXTURE_2D, customerSittingTexture1);
				break;
			case 2:
				glBindTexture(GL_TEXTURE_2D, customerSittingTexture2);
				break;
			case 3:
				glBindTexture(GL_TEXTURE_2D, customerSittingTexture3);
				break;
			case 4:
				glBindTexture(GL_TEXTURE_2D, customerSittingTexture4);
				break;
		}

		glBegin(GL_QUADS);
	
		switch(seatNum) {
			case 1:
				xPos1 = 4;
				xPos2 = 98;
				yPos1 = 253;
				yPos2 = 347;
				glTexCoord2f(0.0f, 1.0f); glVertex2i(xPos1, yPos1);
				glTexCoord2f(0.0f, 0.0f); glVertex2i(xPos1, yPos2);
				glTexCoord2f(1.0f, 0.0f); glVertex2i(xPos2, yPos2);
				glTexCoord2f(1.0f, 1.0f); glVertex2i(xPos2, yPos1);
				break;
			case 2:
				xPos1 = 526;
				xPos2 = 620;
				yPos1 = 253;
				yPos2 = 347;
				glTexCoord2f(0.0f, 1.0f); glVertex2i(xPos1, yPos1);
				glTexCoord2f(0.0f, 0.0f); glVertex2i(xPos1, yPos2);
				glTexCoord2f(1.0f, 0.0f); glVertex2i(xPos2, yPos2);
				glTexCoord2f(1.0f, 1.0f); glVertex2i(xPos2, yPos1);
				break;
			case 3:
				xPos1 = 4;
				xPos2 = 98;
				yPos1 = 48;
				yPos2 = 142;
				glTexCoord2f(0.0f, 1.0f); glVertex2i(xPos1, yPos1);
				glTexCoord2f(0.0f, 0.0f); glVertex2i(xPos1, yPos2);
				glTexCoord2f(1.0f, 0.0f); glVertex2i(xPos2, yPos2);
				glTexCoord2f(1.0f, 1.0f); glVertex2i(xPos2, yPos1);
				break;
			case 4:
				xPos1 = 526;
				xPos2 = 620;
				yPos1 = 48;
				yPos2 = 142;
				glTexCoord2f(0.0f, 1.0f); glVertex2i(xPos1, yPos1);
				glTexCoord2f(0.0f, 0.0f); glVertex2i(xPos1, yPos2);
				glTexCoord2f(1.0f, 0.0f); glVertex2i(xPos2, yPos2);
				glTexCoord2f(1.0f, 1.0f); glVertex2i(xPos2, yPos1);
				break;
		}

		glEnd();
		glPopMatrix();
	}

}

class Level
{
	private:
		int levelNum;
		int serveCount;
		bool start;
		Customer customers[];
	public:
		Level(int numLevel)
		{
			levelNum = numLevel;
			serveCount = 0;
			start = false;
		}
		
		void renderFood()
		{
			//reserved to render food images
		}
};

void makeCustomers()
{

    customerStanding1 = ppm6GetImage("customer1standing.ppm");
    customerStanding2 = ppm6GetImage("customer2standing.ppm");
    customerStanding3 = ppm6GetImage("customer3standing.ppm");
    customerStanding4 = ppm6GetImage("customer4standing.ppm");
    customerSitting1 = ppm6GetImage("customer1sitting.ppm");
    customerSitting2 = ppm6GetImage("customer2sitting.ppm");
    customerSitting3 = ppm6GetImage("customer3sitting.ppm");
    customerSitting4 = ppm6GetImage("customer4sitting.ppm");
    glGenTextures(1, &customerStandingTexture1);
    glGenTextures(1, &customerStandingTexture2);
    glGenTextures(1, &customerStandingTexture3);
    glGenTextures(1, &customerStandingTexture4);
    glGenTextures(1, &customerSittingTexture1);
    glGenTextures(1, &customerSittingTexture2);
    glGenTextures(1, &customerSittingTexture3);
    glGenTextures(1, &customerSittingTexture4);
    //customer1Standing
    glBindTexture(GL_TEXTURE_2D, customerStandingTexture1);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    customerStanding1->width, customerStanding1->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, customerStanding1->data);
    //customer2Standing
    glBindTexture(GL_TEXTURE_2D, customerStandingTexture2);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    customerStanding2->width, customerStanding2->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, customerStanding2->data);
    //customer3Standing
    glBindTexture(GL_TEXTURE_2D, customerStandingTexture3);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    customerStanding3->width, customerStanding3->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, customerStanding3->data);
    //customer4Standing
    glBindTexture(GL_TEXTURE_2D, customerStandingTexture4);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    customerStanding4->width, customerStanding4->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, customerStanding4->data);
    //customer1Sitting
    glBindTexture(GL_TEXTURE_2D, customerSittingTexture1);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    customerSitting1->width, customerSitting1->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, customerSitting1->data);
    //customer2Sitting
    glBindTexture(GL_TEXTURE_2D, customerSittingTexture2);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    customerSitting2->width, customerSitting2->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, customerSitting2->data);
    //customer3Sitting
    glBindTexture(GL_TEXTURE_2D, customerSittingTexture3);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    customerSitting3->width, customerSitting3->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, customerSitting3->data);
    //customer4Sitting
    glBindTexture(GL_TEXTURE_2D, customerSittingTexture4);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    customerSitting4->width, customerSitting4->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, customerSitting4->data);
}

void makeFoods()
{
    burgerOnSide = ppm6GetImage("burgeronplateonside.ppm");
    glGenTextures(1, &burgerOnSideTexture);
    
	//Burger on side of truck
    glBindTexture(GL_TEXTURE_2D, burgerOnSideTexture);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
	    burgerOnSide->width, burgerOnSide->height,
	    0, GL_RGB, GL_UNSIGNED_BYTE, burgerOnSide->data);
}

#ifdef RENDERTEST
void renderCustomers()
{

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, customerStandingTexture1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(74, 498);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(74, 594);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(170, 594);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(170, 498);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, customerSittingTexture1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(4, 253);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(4, 347);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(98, 347);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(98, 253);
    glEnd();
    glPopMatrix();
    
	glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, customerSittingTexture2);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(526, 253);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(526, 347);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(620, 347);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(620, 253);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, customerSittingTexture3);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(4, 48);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(4, 142);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(98, 142);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(98, 48);
    glEnd();
	glPopMatrix();
	
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, customerSittingTexture4);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(526, 48);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(526, 142);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(620, 142);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(620, 48);
    glEnd();
	glPopMatrix();
}

void renderFoods()
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, burgerOnSideTexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(482, 555);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(482, 651);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(578, 651);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(578, 555);
    glEnd();
	glPopMatrix();
    
	glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, burgerOnSideTexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(590, 555);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(590, 651);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(686, 651);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(686, 555);
    glEnd();
	glPopMatrix();
}
#endif
