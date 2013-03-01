/* 
 %PEBBLERIGIDITY Pebble game for finding independent edge set (rigidity)
%
% Written by:  Ryan K. Williams, University of Southern California, 2013
%
% This algorithm is based on the paper:
% D. J. Jacobs and B. Hendrickson, 'An algorithm for two-dimensional 
% rigidity percolation: the pebble game,' J. Comput. Phys., vol. 137, 
% no. 2, pp. 346?365, 1997.
%
% We assume the input graph is undirected, and that the algorithm returns
% the set of independent edges in the graph, where checking terminates when
% 2*N-3 independent edges are found (Laman condition).

% To generate a set of independent edges, we begin with an empty pebble
% covering and enlarge the covering for each edge incrementally.  If a
% covering exists for a considered edge, it is added to the independent
% set.
 */

#ifndef PEBBLERIGIDITY_H
#define	PEBBLERIGIDITY_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdlib.h>
#include "vertices.h"
#include "globals.h"
#include <stdio.h>

    
int isRigid;
int num_ind;
int **ind_set;

extern Vertices vrtx_strt;

void reinit_rigidity_check();

void init_rigidity_check();

void close_rigidity_check();

int pebbleRigidity();



#ifdef	__cplusplus
}
#endif

#endif	/* PEBBLERIGIDITY_H */

