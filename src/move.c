
#include <math.h>
#include "model.h"
#include "callbacks.h"
#include "move.h"

int positionx = 1;
int positionz = 1;
int spositionx = 1;
int spositionz = 1;
int gpositionx = 1;
int gpositionz = 1;
int ertek = 11;


void move_beachball(World* world)
{
	
	if(world->beachball.position.x > 165){
		world->beachball.position.x = 165;
		positionx = -positionx;
	}
	else if(world->beachball.position.x < -165){
		world->beachball.position.x = -165;
		positionx = -positionx;
	}
	else if(world->beachball.position.z > 70){
		world->beachball.position.z = 70;
		positionz = -positionz;
	}
	else if(world->beachball.position.z < -70){
		world->beachball.position.z = -70;
		positionz = -positionz;
	}
	else if((abs(world->beachball.position.z - world->soccerball.position.z) < ertek ) && (abs(world->beachball.position.x - world->soccerball.position.x) < ertek)) {
		/*positionx = -positionx;
		positionz = -positionz;
		spositionx = -spositionx;
		spositionz = -spositionz;*/
		if(positionx == spositionx && positionz == -spositionz){
			positionz = -positionz;
			spositionz = -spositionz;
			set_beachball(world);
			set_soccerball(world);
		}
		else if(positionz == spositionz && positionx == -spositionx){
			positionx = -positionx;
			spositionx = -spositionx;
			set_beachball(world);
			set_soccerball(world);
		}
		else if(positionx == -spositionx && positionz == -spositionz){
			positionx = -positionx;
			positionz = -positionz;
			spositionx = -spositionx;
			spositionz = -spositionz;
			set_beachball(world);
			set_soccerball(world);
		}
		
	}
	/*else if((abs(world->golf.position.z - world->soccerball.position.z) < ertek) && (abs(world->golf.position.x - world->soccerball.position.x) < ertek )) {
		positionx = -positionx;
		positionz = -positionz;
		world->beachball.position.z += positionz;
		world->beachball.position.x += positionx;
	}*/
	else if((abs(world->golf.position.z - world->beachball.position.z) < ertek) && (abs(world->golf.position.x - world->beachball.position.x) < ertek)) {
		/*positionx = -positionx;
		positionz = -positionz;
		gpositionx = -gpositionx;
		gpositionz = -gpositionz;*/
		if(positionx == gpositionx && positionz == -gpositionz){
			positionz = -positionz;
			gpositionz = -gpositionz;
			set_golf(world);
			set_beachball(world);
		}
		else if(positionz == gpositionz && positionx == -gpositionx){
			positionx = -positionx;
			gpositionx = -gpositionx;
			set_golf(world);
			set_beachball(world);
		}
		else if(positionx == -gpositionx && positionz == -gpositionz){
			positionx = -positionx;
			positionz = -positionz;
			gpositionx = -gpositionx;
			gpositionz = -gpositionz;
			set_golf(world);
			set_beachball(world);
		}
	}
	/*world->beachball.position.z += positionz;
	world->beachball.position.x += positionx;
	glTranslatef(world->beachball.position.x, world->beachball.position.y, world->beachball.position.z);*/
}


void move_soccerball(World* world)
{
	if(world->soccerball.position.x > 165){
		world->soccerball.position.x = 165;
		spositionx = -spositionx;
	}
	else if(world->soccerball.position.x < -165){
		world->soccerball.position.x = -165;
		spositionx = -spositionx;
	}
	else if(world->soccerball.position.z > 70){
		world->soccerball.position.z = 70;
		spositionz = -spositionz;
	}
	else if(world->soccerball.position.z < -70){
		world->soccerball.position.z > -70;
		spositionz = -spositionz;
	}
	else if((abs(world->beachball.position.z - world->soccerball.position.z) < ertek ) && (abs(world->beachball.position.x - world->soccerball.position.x) < ertek)) {
		/*spositionx = -spositionx;
		spositionz = -spositionz;
		positionx = -positionx;
		positionz = -positionz;*/
		if(positionx == spositionx && positionz == -spositionz){
			spositionz = -spositionz;
			positionz = -positionz;
			set_beachball(world);
			set_soccerball(world);
		}
		else if(positionz == spositionz && positionx == -spositionx){
			spositionx = -spositionx;
			positionx = -positionx;
			set_beachball(world);
			set_soccerball(world);
		}
		else if(positionz == -spositionz && positionx == -spositionx){
			spositionx = -spositionx;
			spositionz = -spositionz;
			positionx = -positionx;
			positionz = -positionz;
			set_beachball(world);
			set_soccerball(world);
		}
		
	}
	else if((abs(world->golf.position.z - world->soccerball.position.z) < ertek) && (abs(world->golf.position.x - world->soccerball.position.x) < ertek )) {
		/*spositionx = -spositionx;
		spositionz = -spositionz;
		gpositionx = -gpositionx;
		gpositionz = -gpositionz;*/
		if(gpositionx == spositionx && gpositionz == -spositionz){
			spositionz = -spositionz;
			gpositionz = -gpositionz;
			set_golf(world);
			set_soccerball(world);
		}
		else if(gpositionz == spositionz && gpositionx == -spositionx){
			spositionx = -spositionx;
			gpositionx = -gpositionx;
			set_golf(world);
			set_soccerball(world);
		}
		else if(gpositionx == -spositionx && gpositionz == -spositionz){
			spositionx = -spositionx;
			spositionz = -spositionz;
			gpositionx = -gpositionx;
			gpositionz = -gpositionz;
			set_golf(world);
			set_soccerball(world);
		}
	}
	/*else if((abs(world->golf.position.z - world->beachball.position.z) < ertek) && (abs(world->golf.position.x - world->beachball.position.x) < ertek)) {
		spositionx = -spositionx;
		spositionz = -spositionz;
		world->beachball.position.z += spositionz;
		world->beachball.position.x += spositionx;
	}*/
	
	/*world->soccerball.position.z += spositionz;
	world->soccerball.position.x += spositionx;
	glTranslatef(world->soccerball.position.x, world->soccerball.position.y, world->beachball.position.z);*/
}




void move_golf(World* world)
{
	if(world->golf.position.x > 165){
		world->golf.position.x = 165;
		gpositionx = -gpositionx;
	}
	else if(world->golf.position.x < -165){
		world->golf.position.x > -165;
		gpositionx = -gpositionx;
	}
	else if(world->golf.position.z > 70){
		world->golf.position.z = 70;
		gpositionz = -gpositionz;
	}
	else if(world->golf.position.z < -70){
		world->golf.position.z = -70;
		gpositionz = -gpositionz;
	}
	/*else if((abs(world->beachball.position.z - world->soccerball.position.z) < ertek ) && (abs(world->beachball.position.x - world->soccerball.position.x) < ertek)) {
		gpositionx = -gpositionx;
		gpositionz = -gpositionz;
		world->beachball.position.z += gpositionz;
		world->beachball.position.x += gpositionx;
		
	}*/
	else if((abs(world->golf.position.z - world->soccerball.position.z) < ertek) && (abs(world->golf.position.x - world->soccerball.position.x) < ertek )) {
		/*gpositionx = -gpositionx;
		gpositionz = -gpositionz;
		spositionx = -spositionx;
		spositionz = -spositionz;*/
		if(gpositionx == spositionx && gpositionz == -spositionz){
			gpositionz = -gpositionz;
			spositionz = -spositionz;
			set_golf(world);
			set_soccerball(world);
		}
		else if(gpositionz == spositionz && gpositionx == -spositionx){
			gpositionx = -gpositionx;
			spositionx = -spositionx;
			set_golf(world);
			set_soccerball(world);
		}
		else if(gpositionx == -spositionx && gpositionz == -spositionz){
			gpositionx = -gpositionx;
			gpositionz = -gpositionz;
			spositionx = -spositionx;
			spositionz = -spositionz;
			set_golf(world);
			set_soccerball(world);
		}
	}
	else if((abs(world->golf.position.z - world->beachball.position.z) < ertek) && (abs(world->golf.position.x - world->beachball.position.x) < ertek)) {
		/*gpositionx = -gpositionx;
		gpositionz = -gpositionz;
		positionx = -positionx;
		positionz = -positionz;*/
		if(gpositionx == positionx && gpositionz == -positionz){
			gpositionz = -gpositionz;
			positionz = -positionz;
			set_golf(world);
			set_beachball(world);
		}
		else if(gpositionz == positionz && gpositionx == -positionx){
			gpositionx = -gpositionx;
			positionx = -positionx;
			set_golf(world);
			set_beachball(world);
		}
		else if(gpositionx == -positionx && gpositionz == -positionz){
			gpositionx = -gpositionx;
			gpositionz = -gpositionz;
			positionx = -positionx;
			positionz = -positionz;
			set_golf(world);
			set_beachball(world);
		}
	}
	
	/*world->golf.position.z += gpositionz;
	world->golf.position.x += gpositionx;
	glTranslatef(world->golf.position.x, world->golf.position.y, world->golf.position.z);*/
}

void set_beachball(World* world){
	world->beachball.position.z += positionz;
	world->beachball.position.x += positionx;
	glTranslatef(world->beachball.position.x, world->beachball.position.y, world->beachball.position.z);
}

void set_soccerball(World* world){
	world->soccerball.position.z += spositionz;
	world->soccerball.position.x += spositionx;
	glTranslatef(world->soccerball.position.x, world->soccerball.position.y, world->beachball.position.z);
}

void set_golf(World* world){
	world->golf.position.z += gpositionz;
	world->golf.position.x += gpositionx;
	glTranslatef(world->golf.position.x, world->golf.position.y, world->golf.position.z);
}