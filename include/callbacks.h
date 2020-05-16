
#ifndef INCLUDE_CALLBACKS_H_
#define INCLUDE_CALLBACKS_H_

#include "camera.h"
#include "move.h"

#include <GL/glut.h>

int mouse_x, mouse_y;

struct Camera camera;

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

struct Action
{
	int move_forward;
	int move_backward;
	int step_left;
	int step_right;
	int move_up;
	int move_down;
	int increase_light;
	int decrease_light;
	int switch_color;
	int move_ball;

	
};
struct Action action;

//Be�ll�tja a h�v�sokat.
void set_callbacks();

//Bet�lti a grafikus k�rnyezetet.
void display();

//Ablak �tm�retez�se.
void reshape(GLsizei szelesseg, GLsizei magassag);

//Miut�n lenyomjuk a billenty�t.
void keyboard(unsigned char key, int x, int y);

//Miut�n felemelt�k a billenty�r�l az ujjunkat.
void keyboardUp(unsigned char key, int x, int y);

//Help funkci�.
void specialFunc(int key, int x, int y);

//Eg�r.
void mouse(int button, int state, int x, int y);

//Mozg�s.
void motion(int x, int y);

//Amikor nem t�rt�nik esem�ny, ez t�rt�nik.
void idle();

//Id�sz�ml�l�.
double elapsed_time_calc();

//Friss�ti a kamera poz�ci�j�t.
void update_camera_position(struct Camera* camera, double elapsed_time);


//N�veli vagy cs�kkenti 
void change_light(World* world);

//Enged�lyezi az objektumok mozg�s�t.
void move_ball_position(World* world);

//Mozgatja az objektumokat.
void move_beachball_position_go(World* world);
void move_golf_position_go(World* world);
void move_soccerball_position_go(World* world);
void move_table_position_go(World* world);



#endif /* INCLUDE_CALLBACKS_H_ */
