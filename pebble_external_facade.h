/* 
 * File:   external_facade.h
 * Author: sickboy
 *
 * Created on February 20, 2013, 1:32 PM
 */

#ifndef EXTERNAL_FACADE_H
#define	EXTERNAL_FACADE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include "pebbleRigidity.h"
#include "vertices.h"
/**
 * This function is intended to init the Pebble Rigidity Test Framework
 * @param[in] n Number of Agents
 * @param[in] G Adjacency matrix representing the graph
 */    
void initPebbleRigidity(int n);
/**
 * This function is intended to reinit the Pebble Rigidity Test Framework without reallocating
 * the memory
 * @param[in] G Adjacency matrix representing the graph
 */    
void assignAdjacencyMatrix(int **Gnew) ;
/**
 * Function to test the rigidity of the current Graph
 * @return -1 if the graph is not rigid, 1 otherwise
 */
int verifyRigidity();
/**
 * Function to close the Pebble Rigidity Test Framework
 */
void closePebbleRigidity();

int** getIndependentSet();

int getIndependentSetSize();


#ifdef	__cplusplus
}
#endif

#endif	/* EXTERNAL_FACADE_H */

