/* 
 * File:   vertices.c
 * Author: sickboy
 *
 * Created on February 20, 2013, 3:46 PM
 */

#include "vertices.h"
#include <stdio.h>

void reinit_vertices()
{
    int i;
    
    for (i = 0; i < NUM; i++) {
        vrtx_strt.pebble_assign[i][0] = -1;
        vrtx_strt.pebble_assign[i][1] = -1;
        vrtx_strt.pebbles[i] = 2;
        vrtx_strt.path[i] = -1;
        vrtx_strt.seen[i] = -1;
    }
    
}

// Initialize the pebble covering structure
void init_vertices() {
    int i;
    vrtx_strt.seen = calloc(NUM, sizeof (int));
    vrtx_strt.path = calloc(NUM, sizeof (int));
    vrtx_strt.pebbles = calloc(NUM, sizeof (int));
    vrtx_strt.pebble_assign = calloc(NUM, sizeof (int*));

    for (i = 0; i < NUM; i++) {
        vrtx_strt.pebble_assign[i] = calloc(2, sizeof (int));
        vrtx_strt.pebble_assign[i][0] = -1;
        vrtx_strt.pebble_assign[i][1] = -1;
        vrtx_strt.pebbles[i] = 2;
        vrtx_strt.path[i] = -1;
        vrtx_strt.seen[i] = -1;
    }

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