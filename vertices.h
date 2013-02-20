/* 
 * File:   vertices.h
 * Author: sickboy
 *
 * Created on February 20, 2013, 3:41 PM
 */

#ifndef VERTICES_H
#define	VERTICES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h>
    
    typedef struct {
        int *seen;
        int *path;
        int *pebbles;
        //I decided to use only the endpoint of the edge because the starting point is obvious
        int **pebble_assign;
    } Vertices;

    Vertices vrtx_strt;
    /**
     * Function to initialize the vertex structure
     * @param NUM_AGENTS Number of agents involved
     */
    void init_vertices(int NUM_AGENTS);
    
    /**
     * Function to close the data structure and to clean the memory
     */
    void close_vertices();

#ifdef	__cplusplus
}
#endif

#endif	/* VERTICES_H */

