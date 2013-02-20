/* 
 * File:   vertices.c
 * Author: sickboy
 *
 * Created on February 20, 2013, 3:46 PM
 */

#include "vertices.h"


int NUM;

void init_vertices(int NUM_AGENTS) {
    int i;
    vrtx_strt.seen = calloc(NUM_AGENTS, sizeof (int));
    vrtx_strt.path = calloc(NUM_AGENTS, sizeof (int));
    vrtx_strt.pebbles = calloc(NUM_AGENTS, sizeof (int));
    vrtx_strt.pebble_assign = calloc(NUM_AGENTS, sizeof (int*));

    for (i = 0; i < NUM_AGENTS; i++) {
        vrtx_strt.pebble_assign[i] = calloc(2, sizeof (int));
        vrtx_strt.pebble_assign[i][0] = -1;
        vrtx_strt.pebble_assign[i][1] = -1;
        vrtx_strt.pebbles[i] = 2;
        vrtx_strt.path[i] = -1;
        vrtx_strt.seen[i] = -1;
    }

    NUM = NUM_AGENTS;
}

void close_vertices() {
    int i;
    for (i = 0; i < NUM; i++) {
        free(vrtx_strt.pebble_assign[i]);
    }
    free(vrtx_strt.pebble_assign);
    free(vrtx_strt.seen);
    free(vrtx_strt.path);
    free(vrtx_strt.pebbles);
}