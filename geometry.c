/*
 * geometry.c
 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * This file contains a simple geomtery functions.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

#include "geometry.h"

#define FUZZY_EQ 0.01

#define DEBUG(file, line, func, msg) fprintf(stderr, "DEBUG - %s_%d_%s: %s", file, line, func, msg);

double coord_2d_dist(const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return NAN;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return NAN;
    }

    /* Maths */
    return sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));

}

bool coord_2d_eq(const coord_2d_t* a, const coord_2d_t* b){

    /* Equal if dist <= FUZZY_EQ */
    if(coord_2d_dist(a, b) <= FUZZY_EQ){
        return true;
    }
    else{
        return false;
    }

}

void coord_2d_midpoint(coord_2d_t* mid, const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!mid){
        DEBUG(__FILE__, __LINE__, __func__, "'mid' must not be NULL");
        return;
    }
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return;
    }

    /* Maths */
    mid->x = ((a->x + b->x) / 2.0 );
    mid->y = ((a->y + b->y) / 2.0 );

}

void coord_2d_tri(float* tri, const coord_2d_t* a, const coord_2d_t* b, const coord_2d_t *c){

float lineAB = 0;
float lineBC = 0;
float temp1 = 0;
float temp2 = 0;
float temp3 = 0;

if (a->x - b->x < 0) temp1 = b->x - a->x;
else temp1 = a->x - b->x;
if (a->y - b->y < 0) temp1 = b->y - a->y;
else temp1 = a->y - b->y;
temp3 = (temp1 * temp1) + (temp2 * temp2);
lineAB = sqrt(temp3);

if (c->x - b->x < 0) temp1 = b->x - c->x;
else temp1 = c->x - b->x;
if (c->y - b->y < 0) temp1 = b->y - c->y;
else temp1 = c->y - b->y;
temp3 = (temp1 * temp1) + (temp2 * temp2);
lineBC = sqrt(temp3);
*tri = ((lineAB * lineBC) /2);

return;
	

}
