/* 
 * File:   vertices.c
 * Author: sickboy
 *
 * Created on February 20, 2013, 3:46 PM
 */

#include "vertices.h"


int NUM;

void init_vertices(int NUM_AGENTS) {
    vrtx_strt.is_rigid = 0;

    vrtx_strt.num_ind = 0;
    int i;
    vrtx_strt.indSet = calloc(2 * NUM_AGENTS - 3, sizeof (int*));

    for (i = 0; i < 2 * NUM_AGENTS - 3; i++) {
        vrtx_strt.indSet[i] = calloc(2, sizeof (int));
    }
    NUM = NUM_AGENTS;

    for (i = 0; i < 2 * NUM_AGENTS - 3; i++) {
        vrtx_strt.indSet[i][0] = 0;
        vrtx_strt.indSet[i][1] = 0;
    }
}

void close_vertices() {
    int i;
    for (i = 0; i < 2 * NUM - 3; i++) {
        free(vrtx_strt.indSet[i]);
    }
    free(vrtx_strt.indSet);
    vrtx_strt.num_ind = -1;
}