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

    typedef struct {
        //(2*N-3 X 2 structure containing the independent set)
        int **indSet;
        int num_ind;
    } Vertices;

/**
 * Function to initialize the vertex structure
 * @param NUM_AGENTS Number of agents involved
 */
void init_vertices(int NUM_AGENTS);
    
#ifdef	__cplusplus
}
#endif

#endif	/* VERTICES_H */

