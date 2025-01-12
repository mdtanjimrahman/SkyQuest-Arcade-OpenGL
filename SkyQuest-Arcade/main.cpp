#include<GL/glut.h>
#include<iostream>
#include<math.h>>
#include<cmath>
#include<stdlib.h>
#include<time.h>
# define PI 3.14159265358979323846


// Function
void keyboard(unsigned char key, int x, int y);
void circle();
void item(GLfloat x, GLfloat y);
void bg();
void aircraft();
void hills_trees();
void dayclouds(float x, float y, float radius, int segments);
void daysky();
void updateSky(int value);
void level1Display();
void darkclouds(float cx, float cy, float r, int num_segments);
void obstacles(GLfloat x, GLfloat y);
void level2Display();
void bomb(GLfloat x, GLfloat y);
void snow(GLfloat x, GLfloat y);
void snowclouds(float cx, float cy, float r, int num_segments);
void wave(float cx, float cy, float r, int num_segments);
void dayskyL3();
void itemL3(GLfloat x, GLfloat y);
void obstaclesL3(GLfloat x, GLfloat y);
void updateWave(int value);
void initializeRandomPositions();


// Variable
int currentSelection = 0; // 0 = Level 1, 1 = Level 2, 2 = Level 3
const char *levels[] = {"Level 1", "Level 2", "Level 3"};
int mainWindow; // Main menu window ID
int levelWindow; // Level window ID
float cloud1X = -0.9f, cloud2X = -0.35f, cloud3X = 0.35f, cloud4X = 0.75f, cloud5X = -0.8f, cloud6X = 1.15f;
float waveOffsetX = 0.0f, waveOffsetY = 0.0f;  // Horizontal offset for waves
GLfloat itemPosX[] = {1.2f, 0.9f, 0.7f, 0.5f, 0.3f};  // Initial X positions for items
GLfloat obstaclePosX[] = {1.2f, 1.5f, 1.8f, 0.8f, 0.6f, 1.0f};  // Initial X positions for obstacles
// Fixed Y positions as provided
GLfloat itemPosY[] = {0.75f, 0.42f, 0.16f, 0.05f, -0.3f};
GLfloat obstaclePosY[] = {-0.2f, 0.62f, 0.62f, 0.15f, -0.25f, 0.2f};
GLfloat bombPosY[] = {0.8f, 0.6f, 0.3f, 0.5f};
GLfloat speed = 0.005f; // Speed of animation


GLfloat generateRandomFloat()
{
    return (GLfloat)rand() / RAND_MAX * 2.0f - 1.0f; // Normalize rand() to range -1 to 1
}

void initializeRandomPositions()
{
    // Seed the random number generator
    srand(time(0));

    // Generate random values for item positions
    for (int i = 0; i < 5; i++)
        itemPosX[i] = generateRandomFloat();


    // Generate random values for obstacle positions
    for (int i = 0; i < 6; i++)
        obstaclePosX[i] = generateRandomFloat();


    // Generate random values for bomb positions
    for (int i = 0; i < 4; i++)
        bombPosY[i] = generateRandomFloat();

}


void circle()
{
    int i;

    GLfloat x=0.0f;
    GLfloat y= -1.4f;
    GLfloat radius =1.0f;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3ub(38, 18, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
}



void item(GLfloat x, GLfloat y)
{
    int i;

    GLfloat radius = 0.05f; // Radius of the circle
    int triangleAmount = 200; // Number of triangles used to draw the circle
    GLfloat twicePi = 2.0f * PI;

    glColor3ub(221, 136, 4); // Set color of the circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void bg()
{
    glColor3ub(50, 50, 50);
    glBegin(GL_POLYGON);
    glVertex2f (1.0f, 1.0f);
    glVertex2f (-1.0f, 1.0f);
    glVertex2f (-1.0f, -1.0f);
    glVertex2f (1.0f, -1.0f);
    glEnd();
}







void aircraft()
{
    glColor3ub(140, 140, 140);

    glBegin(GL_POLYGON);
    glVertex2f (-0.09f, 0.43f);
    glVertex2f (-0.058f, 0.445f);
    glVertex2f (0.045f, 0.445f);
    glVertex2f (0.045f, 0.415f);
    glVertex2f (-0.058f, 0.415f);
    glVertex2f (-0.09f, 0.43f);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f (-0.083f, 0.475f);
    glVertex2f (-0.055f, 0.428f);
    glVertex2f (-0.083f, 0.385f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f (-0.05f, 0.55f);
    glVertex2f (0.035f, 0.428f);
    glVertex2f (-0.02f, 0.428f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f (-0.02f, 0.428f);
    glVertex2f (0.035f, 0.428f);
    glVertex2f (-0.05f, 0.315f);
    glEnd();

    int i;

    GLfloat x=0.0465f;
    GLfloat y= 0.428f;
    GLfloat radius =0.0204f;
    int triangleAmount = 300; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3ub(10, 10, 10);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
}




void hills_trees()
{
    //Hills

    glBegin(GL_POLYGON);
    glColor3ub(38, 18, 0);
    glVertex2f (-0.96, -1.0);
    glVertex2f (-0.77, -0.64);
    glVertex2f (0.4, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 18, 0);
    glVertex2f (0.96, -1.0);
    glVertex2f (0.77, -0.64);
    glVertex2f (-0.4, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 18, 0);
    glVertex2f (-0.735, -0.68);
    glVertex2f (-0.32, -0.32);
    glVertex2f (0.2, -0.415);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 18, 0);
    glVertex2f (0.735, -0.68);
    glVertex2f (0.32, -0.32);
    glVertex2f (-0.2, -0.415);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 18, 0);
    glVertex2f (-0.3, -0.6);
    glVertex2f (0.05, -0.275);
    glVertex2f (0.45, -0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 18, 0);
    glVertex2f (-0.3, -0.6);
    glVertex2f (-0.12, -0.29);
    glVertex2f (0.45, -0.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 18, 0);
    glVertex2f (-0.75, -0.807);
    glVertex2f (-0.6, -0.5);
    glVertex2f (0.0, -0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(38, 18, 0);
    glVertex2f (0.75, -0.807);
    glVertex2f (0.6, -0.5);
    glVertex2f (0.0, -0.5);
    glEnd();

    //Trees

    //Tree 1
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59, -0.7);
    glVertex2f (-0.6, -0.7);
    glVertex2f (-0.6, -0.61);
    glVertex2f (-0.59, -0.61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56, -0.66);
    glVertex2f (-0.595, -0.61);
    glVertex2f (-0.63, -0.66);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005, -0.66+0.03);
    glVertex2f (-0.595, -0.61+0.03);
    glVertex2f (-0.63+0.005, -0.66+0.03);
    glEnd();


    //Tree 2
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59+0.2, -0.7-0.1);
    glVertex2f (-0.6+0.2, -0.7-0.1);
    glVertex2f (-0.6+0.2, -0.61-0.1);
    glVertex2f (-0.59+0.2, -0.61-0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56+0.2, -0.66-0.1);
    glVertex2f (-0.595+0.2, -0.61-0.1);
    glVertex2f (-0.63+0.2, -0.66-0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005+0.2, -0.66+0.03-0.1);
    glVertex2f (-0.595+0.2, -0.61+0.03-0.1);
    glVertex2f (-0.63+0.005+0.2, -0.66+0.03-0.1);
    glEnd();

    //Tree 3
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59+0.5, -0.7+0.25);
    glVertex2f (-0.6+0.5, -0.7+0.25);
    glVertex2f (-0.6+0.5, -0.61+0.25);
    glVertex2f (-0.59+0.5, -0.61+0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56+0.5, -0.66+0.25);
    glVertex2f (-0.595+0.5, -0.61+0.25);
    glVertex2f (-0.63+0.5, -0.66+0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005+0.5, -0.66+0.03+0.25);
    glVertex2f (-0.595+0.5, -0.61+0.03+0.25);
    glVertex2f (-0.63+0.005+0.5, -0.66+0.03+0.25);
    glEnd();

    //Tree 4
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59+0.6, -0.7+0.12);
    glVertex2f (-0.6+0.6, -0.7+0.12);
    glVertex2f (-0.6+0.6, -0.61+0.12);
    glVertex2f (-0.59+0.6, -0.61+0.12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56+0.6, -0.66+0.12);
    glVertex2f (-0.595+0.6, -0.61+0.12);
    glVertex2f (-0.63+0.6, -0.66+0.12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005+0.6, -0.66+0.03+0.12);
    glVertex2f (-0.595+0.6, -0.61+0.03+0.12);
    glVertex2f (-0.63+0.005+0.6, -0.66+0.03+0.12);
    glEnd();

    //Tree 5
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59+0.25, -0.7+0.18);
    glVertex2f (-0.6+0.25, -0.7+0.18);
    glVertex2f (-0.6+0.25, -0.61+0.18);
    glVertex2f (-0.59+0.25, -0.61+0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56+0.25, -0.66+0.18);
    glVertex2f (-0.595+0.25, -0.61+0.18);
    glVertex2f (-0.63+0.25, -0.66+0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005+0.25, -0.66+0.03+0.18);
    glVertex2f (-0.595+0.25, -0.61+0.03+0.18);
    glVertex2f (-0.63+0.005+0.25, -0.66+0.03+0.18);
    glEnd();

    //Tree 6
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59-0.15, -0.7-0.18);
    glVertex2f (-0.6-0.15, -0.7-0.18);
    glVertex2f (-0.6-0.15, -0.61-0.18);
    glVertex2f (-0.59-0.15, -0.61-0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.15, -0.66-0.18);
    glVertex2f (-0.595-0.15, -0.61-0.18);
    glVertex2f (-0.63-0.15, -0.66-0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005-0.15, -0.66+0.03-0.18);
    glVertex2f (-0.595-0.15, -0.61+0.03-0.18);
    glVertex2f (-0.63+0.005-0.15, -0.66+0.03-0.18);
    glEnd();

    //Tree 7
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59+0.35, -0.7-0.25);
    glVertex2f (-0.6+0.35, -0.7-0.25);
    glVertex2f (-0.6+0.35, -0.61-0.25);
    glVertex2f (-0.59+0.35, -0.61-0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56+0.35, -0.66-0.25);
    glVertex2f (-0.595+0.35, -0.61-0.25);
    glVertex2f (-0.63+0.35, -0.66-0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005+0.35, -0.66+0.03-0.25);
    glVertex2f (-0.595+0.35, -0.61+0.03-0.25);
    glVertex2f (-0.63+0.005+0.35, -0.66+0.03-0.25);
    glEnd();

    //Tree 8
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59+0.6, -0.7-0.25);
    glVertex2f (-0.6+0.6, -0.7-0.25);
    glVertex2f (-0.6+0.6, -0.61-0.25);
    glVertex2f (-0.59+0.6, -0.61-0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56+0.6, -0.66-0.25);
    glVertex2f (-0.595+0.6, -0.61-0.25);
    glVertex2f (-0.63+0.6, -0.66-0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005+0.6, -0.66+0.03-0.25);
    glVertex2f (-0.595+0.6, -0.61+0.03-0.25);
    glVertex2f (-0.63+0.005+0.6, -0.66+0.03-0.25);
    glEnd();

    //Tree 9
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (-0.59+0.75, -0.7+0.21);
    glVertex2f (-0.6+0.75, -0.7+0.21);
    glVertex2f (-0.6+0.75, -0.61+0.21);
    glVertex2f (-0.59+0.75, -0.61+0.21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56+0.75, -0.66+0.21);
    glVertex2f (-0.595+0.75, -0.61+0.21);
    glVertex2f (-0.63+0.75, -0.66+0.21);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (-0.56-0.005+0.75, -0.66+0.03+0.21);
    glVertex2f (-0.595+0.75, -0.61+0.03+0.21);
    glVertex2f (-0.63+0.005+0.75, -0.66+0.03+0.21);
    glEnd();

    //Tree 10
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (0.59-0.15, -0.7-0.18);
    glVertex2f (0.6-0.15, -0.7-0.18);
    glVertex2f (0.6-0.15, -0.61-0.18);
    glVertex2f (0.59-0.15, -0.61-0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (0.56-0.15, -0.66-0.18);
    glVertex2f (0.595-0.15, -0.61-0.18);
    glVertex2f (0.63-0.15, -0.66-0.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (0.56-0.005-0.15, -0.66+0.03-0.18);
    glVertex2f (0.595-0.15, -0.61+0.03-0.18);
    glVertex2f (0.63+0.005-0.15, -0.66+0.03-0.18);
    glEnd();


    //Tree 11
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (0.59, -0.7);
    glVertex2f (0.6, -0.7);
    glVertex2f (0.6, -0.61);
    glVertex2f (0.59, -0.61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (0.56, -0.66);
    glVertex2f (0.595, -0.61);
    glVertex2f (0.63, -0.66);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (0.56-0.005, -0.66+0.03);
    glVertex2f (0.595, -0.61+0.03);
    glVertex2f (0.63+0.005, -0.66+0.03);
    glEnd();

    //Tree 12
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (0.59+0.15, -0.7-0.25);
    glVertex2f (0.6+0.15, -0.7-0.25);
    glVertex2f (0.6+0.15, -0.61-0.25);
    glVertex2f (0.59+0.15, -0.61-0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (0.56+0.15, -0.66-0.25);
    glVertex2f (0.595+0.15, -0.61-0.25);
    glVertex2f (0.63+0.15, -0.66-0.25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (0.56-0.005+0.15, -0.66+0.03-0.25);
    glVertex2f (0.595+0.15, -0.61+0.03-0.25);
    glVertex2f (0.63+0.005+0.15, -0.66+0.03-0.25);
    glEnd();

    //Tree 13
    glBegin(GL_POLYGON);
    glColor3ub(14, 4, 4);
    glVertex2f (0.59-0.3, -0.7);
    glVertex2f (0.6-0.3, -0.7);
    glVertex2f (0.6-0.3, -0.61);
    glVertex2f (0.59-0.3, -0.61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (0.56-0.3, -0.66);
    glVertex2f (0.595-0.3, -0.61);
    glVertex2f (0.63-0.3, -0.66);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(14, 85, 31);
    glVertex2f (0.56-0.005-0.3, -0.66+0.03);
    glVertex2f (0.595-0.3, -0.61+0.03);
    glVertex2f (0.63+0.005-0.3, -0.66+0.03);
    glEnd();
}



// Function to draw clouds
void dayclouds(float x, float y, float radius, int segments)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void daysky()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 79, 190);
    glVertex2f (1.0, 1.0);
    glVertex2f (-1.0, 1.0);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 75, 180);
    glVertex2f (1.0, 0.9);
    glVertex2f (-1.0, 0.9);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 72, 165);
    glVertex2f (1.0, 0.8);
    glVertex2f (-1.0, 0.8);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 68, 150);
    glVertex2f (1.0, 0.7);
    glVertex2f (-1.0, 0.7);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 62, 140);
    glVertex2f (1.0, 0.6);
    glVertex2f (-1.0, 0.6);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 57, 125);
    glVertex2f (1.0, 0.5);
    glVertex2f (-1.0, 0.5);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 56, 118);
    glVertex2f (1.0, 0.4);
    glVertex2f (-1.0, 0.4);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 54, 110);
    glVertex2f (1.0, 0.3);
    glVertex2f (-1.0, 0.3);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 53, 105);
    glVertex2f (1.0, 0.2);
    glVertex2f (-1.0, 0.2);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 51, 97);
    glVertex2f (1.0, 0.1);
    glVertex2f (-1.0, 0.1);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 48, 92);
    glVertex2f (1.0, 0.1);
    glVertex2f (-1.0, 0.1);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 45, 86);
    glVertex2f (1.0, 0.0);
    glVertex2f (-1.0, 0.0);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 43, 80);
    glVertex2f (1.0, -0.1);
    glVertex2f (-1.0, -0.1);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 40, 76);
    glVertex2f (1.0, -0.2);
    glVertex2f (-1.0, -0.2);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 37, 76);
    glVertex2f (1.0, -0.3);
    glVertex2f (-1.0, -0.3);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 35, 72);
    glVertex2f (1.0, -0.4);
    glVertex2f (-1.0, -0.4);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 32, 67);
    glVertex2f (1.0, -0.5);
    glVertex2f (-1.0, -0.5);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 29, 64);
    glVertex2f (1.0, -0.6);
    glVertex2f (-1.0, -0.6);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 26, 60);
    glVertex2f (1.0, -0.7);
    glVertex2f (-1.0, -0.7);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 22, 55);
    glVertex2f (1.0, -0.8);
    glVertex2f (-1.0, -0.8);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 17, 50);
    glVertex2f (1.0, -0.9);
    glVertex2f (-1.0, -0.9);
    glVertex2f (-1.0, -1.0);
    glVertex2f (1.0, -1.0);
    glEnd();
}



void updateSky(int value)
{
    // Update cloud positions to move from right to left
    cloud1X -= 0.0004f;
    cloud2X -= 0.0004f;
    cloud3X -= 0.0004f;
    cloud4X -= 0.0004f;
    cloud5X -= 0.0004f;
    cloud6X -= 0.0004f;

    // Reset positions when clouds move off-screen (right side)
    if (cloud1X < -1.2f) cloud1X = 1.2f;
    if (cloud2X < -1.2f) cloud2X = 1.2f;
    if (cloud3X < -1.2f) cloud3X = 1.2f;
    if (cloud4X < -1.2f) cloud4X = 1.2f;
    if (cloud5X < -1.2f) cloud5X = 1.2f;
    if (cloud6X < -1.2f) cloud6X = 1.2f;

    glutPostRedisplay();              // Request a redraw
    glutTimerFunc(16, updateSky, 0);   // Call update again after 16ms (~60 FPS)
}

// Display function for Level 1
void level1Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to gray and opaque

    bg();
    daysky();


    //  clouds
    glColor3ub(235, 235, 235);
    dayclouds(cloud1X, 0.5f, 0.08f, 200);
    dayclouds(cloud1X + 0.1f, 0.55f, 0.12f, 200);
    dayclouds(cloud1X + 0.2f, 0.5f, 0.08f, 200);

    glColor3ub(235, 235, 235);
    dayclouds(cloud2X, 0.25f, 0.08f, 200);
    dayclouds(cloud2X + 0.1f, 0.3f, 0.12f, 200);
    dayclouds(cloud2X + 0.2f, 0.25f, 0.08f, 200);

    glColor3ub(235, 235, 235);
    dayclouds(cloud3X, 0.6f, 0.08f, 200);
    dayclouds(cloud3X + 0.1f, 0.65f, 0.12f, 200);
    dayclouds(cloud3X + 0.2f, 0.6f, 0.08f, 200);

    glColor3ub(235, 235, 235);
    dayclouds(cloud4X, 0.05f, 0.08f, 200);
    dayclouds(cloud4X + 0.1f, 0.1f, 0.12f, 200);
    dayclouds(cloud4X + 0.2f, 0.05f, 0.08f, 200);

    glColor3ub(235, 235, 235);
    dayclouds(cloud5X, -0.1f, 0.08f, 200);
    dayclouds(cloud5X + 0.1f, -0.05f, 0.12f, 200);
    dayclouds(cloud5X + 0.2f, -0.1f, 0.08f, 200);

    glColor3ub(235, 235, 235);
    dayclouds(cloud6X, 0.8f, 0.08f, 200);
    dayclouds(cloud6X - 0.2f, 0.85f, 0.12f, 200);
    dayclouds(cloud6X - 0.3f, 0.8f, 0.08f, 200);


    //collectibles
    item(0.75, 0.75);
    item(0.6, 0.42);
    item(0.8, 0.16);
    item(0.5, 0.05);
    item(0.9, -0.3);


    aircraft();
    circle();
    hills_trees();

    // Show message for Level 1
    glColor3ub(244, 244, 244);
    glRasterPos2f(-0.95f, 0.9f);
    const char *msg = "Score: ";
    for (const char *c = msg; *c != '\0'; ++c)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glFlush();
}






















































































































void drawCrescentMoon()
{

    int i;
    GLfloat radius = 0.1f;  // Outer moon radius
    GLfloat innerRadius = 0.08f;  // Inner cutout radius
    int triangleAmount = 360;  // Smoothness of the circle
    GLfloat twicePi = 2.0f * PI;

    // Outer white circle (main moon)
    glColor3f(1.0f, 1.0f, 1.0f);  // White color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.75f, 0.75f);  // Center of the moon
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            -0.75f + (radius * cos(i * twicePi / triangleAmount)),
            0.75f + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Inner background-colored circle to create the crescent effect
    glColor3f(0.0f, 0.0f, 0.2f);  // Same as background color for blending
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.72f, 0.78f);  // Slight offset to create the curve
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            -0.72f + (innerRadius * cos(i * twicePi / triangleAmount)),
            0.78f + (innerRadius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    }








void obstacles(GLfloat x, GLfloat y)
{

    int i;

    GLfloat radius = 0.065f; // Radius of the circle
    int triangleAmount = 200; // Number of triangles used to draw the circle
    GLfloat twicePi = 2.0f * PI;

    // Draw the hexagon
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON); // Use line loop to draw sharp sides
    for (i = 0; i < 6; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / 6)), // 6 for hexagon
            y + (radius * sin(i * twicePi / 6))
        );
    }
    glEnd();
}


void level2Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    circle();


    //Background of level 2
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.2f); // Dark blue
    glVertex2f (1.0f, 1.0f);
    glVertex2f (-1.0f, 1.0f);
    glColor3f(0.1f, 0.1f, 0.3f); // light blue
    glVertex2f (-1.0f, -1.0f);
    glVertex2f (1.0f, -1.0f);
    glEnd();


    //Mountain
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.3f, 0.5f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(0.7f, -1.0f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.7f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.4f, -0.1f);
    glVertex2f(0.3f, -1.0f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.6f, 0.8f);
    glVertex2f(-1.15f, -1.0f);
    glVertex2f(-0.7f, 0.05f);
    glVertex2f(0.0f, -1.0f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.2f, 0.4f);
    glVertex2f(-0.5f, -1.0f);
    glVertex2f(0.3f, -0.15f);
    glVertex2f(0.9f, -1.0f);
    glEnd();



    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.3f);
    glVertex2f(0.3f, -1.0f);
    glVertex2f(0.8f, -0.3f);
    glVertex2f(1.5f, -1.0f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.1f, 0.2f);
    glVertex2f(0.02f, -1.0f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(0.8f, -1.0f);
    glEnd();


    drawCrescentMoon();

    //collectibles
    item(0.75, 0.75);
    item(0.6, 0.42);
    item(0.8, 0.16);
    item(0.5, 0.05);
    item(0.9, -0.3);

    //obstacles
    obstacles(0.68, -0.2);
    obstacles(0.9, 0.62);
    obstacles(0.4, 0.62);
    obstacles(0.3, 0.15);
    obstacles(0.32, -0.25);
    obstacles(0.98, 0.2);

    aircraft();

    // Draw message for Level 2
    glColor3ub(255, 255, 255);
    glRasterPos2f(-0.95f, 0.9f);
    const char *msg = "Level 2: Avoid obstacles (Press Esc to go back";
    for (const char *c = msg; *c != '\0'; ++c)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glFlush();
}


































































































void bomb(GLfloat x, GLfloat y)
{
    int i;

    GLfloat radius = 0.04f; // Radius of the circle
    int triangleAmount = 200; // Number of triangles used to draw the circle
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0); // Set color of the circle
    glVertex2f(x, y); // Center of the circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    // Draw the sparking string
    glColor3ub(255, 165, 0); // Orange color for the string
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(x, y + radius); // Starting point at the top edge of the circle
    glVertex2f(x, y + radius + 0.04f); // End point extending upward
    glEnd();

}









void snow(GLfloat x, GLfloat y)
{

    int i;

    GLfloat radius = 0.01f; // Radius of the circle
    int triangleAmount = 200; // Number of triangles used to draw the circle
    GLfloat twicePi = 2.0f * PI;

    glColor3ub(244, 244, 244); // Set color of the circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}





void snowclouds(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++)
    {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void wave(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++)
    {
        float theta = 2.0f * PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}




//level3 sky


void dayskyL3()
{
    glBegin(GL_QUADS);

    // Top color (light blue)
    glColor3ub(135,206,235);
    glVertex2f(-1.0, 1.0); // Top-left
    glVertex2f(1.0, 1.0);  // Top-right

    // Bottom color (darker blue)
    glColor3ub(255,255,200);
    glVertex2f(1.0, -1.0); // Bottom-right
    glVertex2f(-1.0, -1.0); // Bottom-left

    glEnd();
}


void itemL3(GLfloat x, GLfloat y)
{

    int i;

    GLfloat radius = 0.05f; // Radius of the circle
    int triangleAmount = 200; // Number of triangles used to draw the circle
    GLfloat twicePi = 2.0f * PI;

    glColor3ub(255, 215, 0); // Set color of the circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void obstaclesL3(GLfloat x, GLfloat y)
{
    int i;

    GLfloat radius = 0.065f; // Radius of the circle
    int triangleAmount = 200; // Number of triangles used to draw the circle
    GLfloat twicePi = 2.0f * PI;

    // Draw the hexagon
    glColor3ub(74,71,51);
    glBegin(GL_POLYGON); // Use line loop to draw sharp sides
    for (i = 0; i < 6; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / 6)), // 6 for hexagon
            y + (radius * sin(i * twicePi / 6))
        );
    }
    glEnd();
}


void updateWave(int value)
{
    waveOffsetX -= 0.005f;  // Move the waves to the right over time
    waveOffsetY = 0.1f * sin(waveOffsetX * 3.14f);
    if (waveOffsetX < -2.0f) {
        waveOffsetX =  1.05f;  // Reset position when it moves off-screen
    }

    glutPostRedisplay();   // Request a redraw
    glutTimerFunc(16, updateWave, 0);  // Update every 16ms (~60 FPS)
}


void updateLevel3(int value)
{
   // Update item positions (move from right to left)
    for (int i = 0; i < 5; i++) {
        itemPosX[i] -= speed;  // Move items leftward
        if (itemPosX[i] < -1.2f) {
            itemPosX[i] = 1.2f; // Reset position to the right
            // initializeRandomPositions();
        }
    }

    // Update obstacle positions (move from right to left)
    for (int i = 0; i < 6; i++) {
        obstaclePosX[i] -= speed * 1.2f;  // Move obstacles faster than items
        if (obstaclePosX[i] < -1.2f) {
            obstaclePosX[i] = 1.2f;  // Reset position to the right
            // initializeRandomPositions();
        }
    }

    // Update bomb positions
    for (int i = 0; i < 4; i++) {
        bombPosY[i] -= speed * 0.6f; // Faster than obstacles
        if (bombPosY[i] < -1.2f) {
            bombPosY[i] = 1.2f;
            // initializeRandomPositions();
        }
    }

    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(16, updateLevel3, 0); // Schedule the next update (16ms for ~60 FPS)


}


// Display function for Level 3
void level3Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to gray and opaque

    bg();
    dayskyL3();


    //  clouds
    glColor3ub(235, 235, 235);
    dayclouds(cloud1X, 0.5f, 0.08f, 200);
    dayclouds(cloud1X - 0.1f, 0.55f, 0.12f, 200);
    dayclouds(cloud1X - 0.2f, 0.5f, 0.08f, 200);

    dayclouds(cloud2X, 0.25f, 0.08f, 200);
    dayclouds(cloud2X - 0.1f, 0.3f, 0.12f, 200);
    dayclouds(cloud2X - 0.2f, 0.25f, 0.08f, 200);

    dayclouds(cloud3X, 0.6f, 0.08f, 200);
    dayclouds(cloud3X - 0.1f, 0.65f, 0.12f, 200);
    dayclouds(cloud3X - 0.2f, 0.6f, 0.08f, 200);

    dayclouds(cloud4X, 0.05f, 0.08f, 200);
    dayclouds(cloud4X - 0.1f, 0.1f, 0.12f, 200);
    dayclouds(cloud4X - 0.2f, 0.05f, 0.08f, 200);

    dayclouds(cloud5X, -0.1f, 0.08f, 200);
    dayclouds(cloud5X - 0.1f, -0.05f, 0.12f, 200);
    dayclouds(cloud5X - 0.2f, -0.1f, 0.08f, 200);

    dayclouds(cloud6X, 0.8f, 0.08f, 200);
    dayclouds(cloud6X + 0.2f, 0.85f, 0.12f, 200);
    dayclouds(cloud6X + 0.3f, 0.8f, 0.08f, 200);



    //  wave4
    glColor3ub(6,66,115); // Gray color
    wave(-2.95f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-2.85f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-2.75f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-2.65f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-2.55f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-2.45f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-2.35f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-2.25f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-2.15f-.2f + waveOffsetX,-0.72f + waveOffsetY, 0.18f, 100);
    wave(-2.05f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);

    wave(-1.95f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-1.85f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-1.75f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-1.65f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-1.55f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-1.45f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-1.35f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-1.25f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-1.15f-.2f + waveOffsetX,-0.72f + waveOffsetY, 0.18f, 100);
    wave(-1.05f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);

    wave(-0.95f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-0.85f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-0.75f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-0.65f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-0.55f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-0.45f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-0.35f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(-0.25f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(-0.15f-.2f + waveOffsetX,-0.72f + waveOffsetY, 0.18f, 100);
    wave(-0.05f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(0.05f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(0.15f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(0.25f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(0.35f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(0.45f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(0.55f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(0.65f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(0.75f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(0.85f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);
    wave(0.95f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.21f, 100);
    wave(1.05f-.2f + waveOffsetX, -0.72f + waveOffsetY, 0.18f, 100);




    //wave 3
    glColor3ub(118,182,196); // light occen color
    wave(-2.95f + waveOffsetX, -0.80f + waveOffsetY, 0.18f, 100);
    wave(-2.85f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-2.75f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-2.65f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-2.55f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-2.45f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-2.35f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-2.25f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-2.15f + waveOffsetX,-0.80 + waveOffsetY, 0.18f, 100);
    wave(-2.05f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);

    wave(-1.95f + waveOffsetX, -0.80f + waveOffsetY, 0.18f, 100);
    wave(-1.85f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-1.75f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-1.65f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-1.55f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-1.45f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-1.35f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-1.25f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-1.15f + waveOffsetX,-0.80 + waveOffsetY, 0.18f, 100);
    wave(-1.05f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);


    wave(-0.95f + waveOffsetX, -0.80f + waveOffsetY, 0.18f, 100);
    wave(-0.85f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-0.75f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-0.65f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-0.55f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-0.45f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-0.35f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(-0.25f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(-0.15f + waveOffsetX,-0.80 + waveOffsetY, 0.18f, 100);
    wave(-0.05f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(0.05f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(0.15f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(0.25f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(0.35f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(0.45f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(0.55f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(0.65f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(0.75f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(0.85f + waveOffsetX, -0.80 + waveOffsetY, 0.18f, 100);
    wave(0.95f + waveOffsetX, -0.80 + waveOffsetY, 0.21f, 100);
    wave(1.05f + waveOffsetX, -0.80f + waveOffsetY, 0.18f, 100);



    //  wave2
    glColor3ub(127,205,255); // Gray color
    wave(-2.95f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-2.85f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-2.75f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-2.65f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-2.55f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-2.45f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-2.35f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-2.25f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-2.15f+.2f + waveOffsetX,-0.90f + waveOffsetY, 0.18f, 100);
    wave(-2.05f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);

    wave(-1.95f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-1.85f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-1.75f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-1.65f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-1.55f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-1.45f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-1.35f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-1.25f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-1.15f+.2f + waveOffsetX,-0.90f + waveOffsetY, 0.18f, 100);
    wave(-1.05f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);

    wave(-0.95f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-0.85f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-0.75f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-0.65f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-0.55f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-0.45f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-0.35f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(-0.25f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(-0.15f+.2f + waveOffsetX,-0.90f + waveOffsetY, 0.18f, 100);
    wave(-0.05f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(0.05f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(0.15f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(0.25f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(0.35f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(0.45f+.2f + waveOffsetX, -0.90f + waveOffsetY , 0.18f, 100);
    wave(0.45f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(0.55f+.2f + waveOffsetX, -0.90f  + waveOffsetY, 0.18f, 100);
    wave(0.65f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(0.75f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(0.85f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);
    wave(0.95f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.21f, 100);
    wave(1.05f+.2f + waveOffsetX, -0.90f + waveOffsetY, 0.18f, 100);


    //  wave
    glColor3ub(29,162,216); // occen green color
     wave(-2.95f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-2.85f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-2.75f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-2.65f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-2.55f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-2.45f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-2.35f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-2.25f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-2.15f + waveOffsetX,-0.98f + waveOffsetY, 0.18f, 100);
    wave(-2.05f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);

     wave(-1.95f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-1.85f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-1.75f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-1.65f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-1.55f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-1.45f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-1.35f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-1.25f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-1.15f + waveOffsetX,-0.98f + waveOffsetY, 0.18f, 100);
    wave(-1.05f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);

    wave(-0.95f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-0.85f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-0.75f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-0.65f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-0.55f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-0.45f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-0.35f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(-0.25f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(-0.15f + waveOffsetX,-0.98f + waveOffsetY, 0.18f, 100);
    wave(-0.05f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(0.05f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(0.15f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(0.25f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(0.35f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(0.45f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(0.55f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(0.65f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(0.75f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(0.85f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);
    wave(0.95f + waveOffsetX, -0.98f + waveOffsetY, 0.21f, 100);
    wave(1.05f + waveOffsetX, -0.98f + waveOffsetY, 0.18f, 100);


    //wave0
    glColor3ub(222,243,246); // occen green color
    wave(-2.95f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-2.85f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-2.75f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-2.65f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-2.55f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-2.45f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-2.35f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-2.25f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-2.15f-.2f + waveOffsetX,-1.06f + waveOffsetY, 0.18f, 100);
    wave(-2.05f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);

    wave(-1.95f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-1.85f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-1.75f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-1.65f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-1.55f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-1.45f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-1.35f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-1.25f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-1.15f-.2f + waveOffsetX,-1.06f + waveOffsetY, 0.18f, 100);
    wave(-1.05f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);


    wave(-0.95f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-0.85f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-0.75f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-0.65f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-0.55f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-0.45f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-0.35f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(-0.25f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(-0.15f-.2f + waveOffsetX,-1.06f + waveOffsetY, 0.18f, 100);
    wave(-0.05f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(0.05f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(0.15f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(0.25f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(0.35f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(0.45f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(0.55f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(0.65f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(0.75f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(0.85f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);
    wave(0.95f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.21f, 100);
    wave(1.05f-.2f + waveOffsetX, -1.06f + waveOffsetY, 0.18f, 100);

    // Draw collectibles (move from right to left with fixed Y positions)
    itemL3(itemPosX[0], itemPosY[0]);
    itemL3(itemPosX[1], itemPosY[1]);
    itemL3(itemPosX[2], itemPosY[2]);
    itemL3(itemPosX[3], itemPosY[3]);
    itemL3(itemPosX[4], itemPosY[4]);

    // Draw obstacles (move from right to left with fixed Y positions)
    obstaclesL3(obstaclePosX[0], obstaclePosY[0]);
    obstaclesL3(obstaclePosX[1], obstaclePosY[1]);
    obstaclesL3(obstaclePosX[2], obstaclePosY[2]);
    obstaclesL3(obstaclePosX[3], obstaclePosY[3]);
    obstaclesL3(obstaclePosX[4], obstaclePosY[4]);
    obstaclesL3(obstaclePosX[5], obstaclePosY[5]);

    // Draw bombs
    bomb(-0.3f, bombPosY[0]);
    bomb(-0.8f, bombPosY[1]);
    bomb(-0.6f, bombPosY[2]);
    bomb(0.2f, bombPosY[3]);

    aircraft();

    // Show message for Level 3
    glColor3ub(244, 244, 244);
    glRasterPos2f(-0.95f, 0.9f);
    const char *msg = "Level 3: Bombs falling from the sky (Press Esc to go back)";
    for (const char *c = msg; *c != '\0'; ++c)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);

    glFlush();
}










// Display function for the main menu (level selector)
void drawButtons()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Title
    glRasterPos2f(-0.2f, 0.4f);
    const char *title = "Select Level:";
    for (const char *c = title; *c != '\0'; ++c)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);


    // Draw buttons
    for (int i = 0; i < 3; ++i)
    {
        if (i == currentSelection)
            glColor3f(0.0, 1.0, 0.0); // Highlight selected button
        else
            glColor3f(1.0, 1.0, 1.0); // Normal color

        glRasterPos2f(-0.1f, 0.2f - i * 0.2f); // Position buttons
        for (const char *c = levels[i]; *c != '\0'; ++c)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glFlush();
}













// Switch to the main menu (level selector)
void returnToMainMenu()
{
    glutSetWindow(mainWindow); // Switch back to the main window
    glutDisplayFunc(drawButtons); // Set display function to the main menu
    glutPostRedisplay(); // Redraw the level selector screen
}

// Switch to Level 1 view
void openLevel1()
{
    glutSetWindow(mainWindow); // Keep using the same window
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Set background color for Level 1
    glutDisplayFunc(level1Display); // Register display callback for Level 1
    glutTimerFunc(16, updateSky, 0);         // Start animation for Level 1
    glutPostRedisplay(); // Redraw to display Level 1 content
}

// Switch to Level 2 view
void openLevel2()
{
    glutSetWindow(mainWindow); // Keep using the same window
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Set background color for Level 2
    glutDisplayFunc(level2Display); // Register display callback for Level 2
    glutPostRedisplay(); // Redraw to display Level 2 content
}

// Switch to Level 3 view
void openLevel3()
{
    glutSetWindow(mainWindow); // Keep using the same window
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Set background color for Level 3
    glutDisplayFunc(level3Display); // Register display callback for Level 3
    glutTimerFunc(16, updateSky, 0);
    glutTimerFunc(16, updateWave, 0);  // Start animation by calling update every 16ms
    glutTimerFunc(16, updateLevel3, 0); // Start animation by calling update every 16ms
    glutPostRedisplay(); // Redraw to display Level 3 content
}












void keyboard(unsigned char key, int x, int y)
{
    if (key == 27)    // 27 is the ASCII code for Esc key
    {
        returnToMainMenu(); // Return to the level selector
    }
    else
    {
        switch (key)
        {
        case 'w': // Move up
        case 'W':
            if (currentSelection > 0)
                currentSelection--;
            break;
        case 's': // Move down
        case 'S':
            if (currentSelection < 2)
                currentSelection++;
            break;
        case 13: // Enter key
            if (currentSelection == 0)
                openLevel1();
            else if (currentSelection == 1)
                openLevel2();
            else if (currentSelection == 2)
                openLevel3();
            break;
        }
    }
    glutPostRedisplay();
}





void display()
{
    drawButtons();
}




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutInitWindowPosition(300, 100);
    mainWindow = glutCreateWindow("SkyQuest");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color for the main menu

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register keyboard callback for main window

    glutMainLoop();
    return 0;
}
