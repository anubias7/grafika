
#include "model.h"
 
#ifndef INCLUDE_DRAW_H_
#define INCLUDE_DRAW_H_

#ifndef GL_EXT_texture_edge_clamp
#define GL_CLAMP_TO_EDGE                 0x812F
#endif

void draw_traffic_light(World* world);
/**
 * Draw the content.
 */
void draw_content(World* world);

/**
* Draws the ground.
*/
void draw_ground(Room room);

/*
* Draws the room.
*/
void draw_walls(Room room);

/**
* Draw the model.
*/
void draw_model(const struct Model* model);

/*
* Draws the help menu
*/
void draw_help(int texture);


//Draw the model.
void draw_model(const struct Model* model);


//Draw the triangles of the model.
void draw_triangles(const struct Model* model);


//Draw the quads of the model.
void draw_quads(const struct Model* model);


//Draw the normal vectors of the model.
void draw_normals(const struct Model* model, double length);

#endif /* INCLUDE_DRAW_H_ */
