
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

//Beállítja a hívásokat.
void set_callbacks();

//Betölti a grafikus környezetet.
void display();

//Ablak átméretezése.
void reshape(GLsizei szelesseg, GLsizei magassag);

//Miután lenyomjuk a billentyût.
void keyboard(unsigned char key, int x, int y);

//Miután felemeltük a billentyûrõl az ujjunkat.
void keyboardUp(unsigned char key, int x, int y);

//Help funkció.
void specialFunc(int key, int x, int y);

//Egér.
void mouse(int button, int state, int x, int y);

//Mozgás.
void motion(int x, int y);

//Amikor nem történik esemény, ez történik.
void idle();

//Idõszámláló.
double elapsed_time_calc();

//Frissíti a kamera pozícióját.
void update_camera_position(struct Camera* camera, double elapsed_time);


//Növeli vagy csökkenti 
void change_light(World* world);

//Engedélyezi az objektumok mozgását.
void move_ball_position(World* world);

//Mozgatja az objektumokat.
void move_beachball_position_go(World* world);
void move_golf_position_go(World* world);
void move_soccerball_position_go(World* world);
void move_table_position_go(World* world);



#endif /* INCLUDE_CALLBACKS_H_ */
