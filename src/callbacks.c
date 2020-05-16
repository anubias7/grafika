
#include <math.h>

#include "callbacks.h"
#include "init.h"
#include "draw.h"
#include "model.h"
#include "move.h"

int isHelpOn = 0;

int WINDOW_WIDTH;
int WINDOW_HEIGHT;
int color = 0;
int direction = 0;
int i = 0;
int j = 0;

void display(void)
{
	double elapsed_time = elapsed_time_calc();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	update_camera_position(&camera, elapsed_time);
	draw_content(&world);
	move_ball_position(&world);
	change_light(&world);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLdouble)WINDOW_WIDTH / (GLdouble)WINDOW_HEIGHT, 0.1, 20000.0);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	set_view_point(&camera);

	
	if(isHelpOn)
	{
		GLfloat torchForHelp[] = { 0.8, 0.8, 0.8, 0.8};
		glLightfv(GL_LIGHT1, GL_AMBIENT, torchForHelp);

		glLoadIdentity();
		gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

		draw_help(world.helpTexture);

		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	}

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;


    set_clear_camera_pose(&camera);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		action.move_forward = TRUE;
		break;
	case 's':
		action.move_backward = TRUE;
		break;
	case 'a':
		action.step_left = TRUE;
		break;
	case 'd':
		action.step_right = TRUE;
		break;
	case 'q':
		action.move_down = TRUE;
		break;
	case 'e':
		action.move_up = TRUE;
		break;
	case '+':
		action.increase_light = TRUE;
		break;
	case '-':
		action.decrease_light = TRUE;
		break;
	case ' ':
		if (action.move_ball == FALSE){
		action.move_ball = TRUE;
		}
		else if (action.move_ball == TRUE){
		action.move_ball = FALSE;
		}
		break;

	
	case 27:
		exit(0);
	}

	glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		action.move_forward = FALSE;
		break;
	case 's':
		action.move_backward = FALSE;
		break;
	case 'a':
		action.step_left = FALSE;
		break;
	case 'd':
		action.step_right = FALSE;
		break;
	case 'q':
		action.move_down = FALSE;
		break;
	case 'e':
		action.move_up = FALSE;
		break;
	case '+':
		action.increase_light = FALSE;
		break;
	case '-':
		action.decrease_light = FALSE;
		break;
	}

	glutPostRedisplay();
}

void specialFunc(int key, int x, int y) {
	switch (key)
	{
		case GLUT_KEY_F1:
			if(isHelpOn == 1)
			{
				isHelpOn=0;
			}
			else isHelpOn = 1;
	}
}

void mouse(int button, int state, int x, int y)
{
	mouse_x = x;
	mouse_y = y;
}

void motion(int x, int y)
{
	double horizontal, vertical;

	horizontal = mouse_x - x;
	vertical = mouse_y - y;

	rotate_camera(&camera, horizontal, vertical);

	mouse_x = x;
	mouse_y = y;

	glutPostRedisplay();
}

void idle()
{
    glutPostRedisplay();
}

double elapsed_time_calc()
{
	static int last_frame_time = 0;
	int current_time;
	double elapsed_time;

	current_time = glutGet(GLUT_ELAPSED_TIME);
	elapsed_time = (double)(current_time - last_frame_time) / 1000.0;
	last_frame_time = current_time;


	return elapsed_time;
}

void update_camera_position(struct Camera* camera, double elapsed_time)
{
	float speed = 30;
	double distance;

	distance = elapsed_time * CAMERA_SPEED*speed;

	if (action.move_forward == TRUE) {
		move_camera_forward(camera, distance);
	}

	if (action.move_backward == TRUE) {
		move_camera_backward(camera, distance);
	}

	if (action.step_left == TRUE) {
		step_camera_left(camera, distance);
	}

	if (action.step_right == TRUE) {
		step_camera_right(camera, distance);
	}

	if (action.move_up == TRUE) {
		move_camera_up(camera, distance);
	}

	if (action.move_down == TRUE) {
		move_camera_down(camera, distance);
	}
	
	
	
	
	
}
void change_light(World* world){
	if (action.increase_light == TRUE) {
		if (light_ambient[0] < 1)
			light_ambient[0] += 0.01; 
			light_ambient[1] += 0.01; 
			light_ambient[2] += 0.01;
			glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	}

	if (action.decrease_light == TRUE) {
		if (light_ambient[0] > -0.60)
			light_ambient[0] -= 0.01; 
			light_ambient[1] -= 0.01; 
			light_ambient[2] -= 0.01;
			glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	}
}

void move_ball_position(World* world){
	if (action.move_ball == TRUE) {
		move_beachball_position_go(world);
		move_soccerball_position_go(world);
		move_golf_position_go(world);
		
		set_beachball(world);
		set_soccerball(world);
		set_golf(world);
	}
}
void move_beachball_position_go(World* world){
	
		move_beachball(world);
	
}
void move_soccerball_position_go(World* world){
		move_soccerball(world);
}
void move_golf_position_go(World* world){
		move_golf(world);

}