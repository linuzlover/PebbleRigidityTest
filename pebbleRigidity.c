#include "pebbleRigidity.h"
#include "globals.h"
#include <stdio.h>

void rearrangePebbles(Vertices *vertices, int i, int j) {
    int index, k;

    // Free pebble taken directly from vertex i, given to edge

    if (vertices->path[i] == -1) {
        index=2-vertices->pebbles[i];
        vertices->pebbles[i]--;
        vertices->pebble_assign[i][index] = j;
        return;

    } 
    // We know we found a pebble in the graph to shift, make local shift
    // first

    else {

        if (vertices->pebble_assign[i][0] == vertices->path[i])
            vertices->pebble_assign[i][0] = j;
        if (vertices->pebble_assign[i][1] == vertices->path[i])
            vertices->pebble_assign[i][1] = j;
    }

    while (vertices->path[i] != -1) {
        k = vertices->path[i];

        // Cover edge (i,j) with free pebble from j
        if (vertices->path[k] == -1) {
            index=2-vertices->pebbles[k];
            vertices->pebble_assign[k][index] = i;
            vertices->pebbles[k]--;

        }
        // Cover edge (i,j) with pebble from edge (j,path(j)) by shifting
        else {
            if (vertices->pebble_assign[k][0] == vertices->path[k])
                vertices->pebble_assign[k][0] = i;
            if (vertices->pebble_assign[k][1] == vertices->path[k])
                vertices->pebble_assign[k][1] = i;
        }
        i = k;
    }
}

int findPebble(Vertices *vertices, int i) {
    int found = 0;
    int x, y;

    vertices->seen[i] = 1;
    vertices->path[i] = -1;

    // Check for local pebble, take if possible
    if (vertices->pebbles[i] > 0) {
        found = 1;
        return found;
    } 
    // Check neighbor along first edge i has assigned a pebble

    else {
        x = vertices->pebble_assign[i][0];
        if (x < 0){
            x = -1;
        }

        if (!vertices->seen[x]) {
            vertices->path[i] = x;

            found = findPebble(vertices, x);
            if (found)
                return found;

        }
     // Check neighbor along second edge i has assigned a pebble

        y = vertices->pebble_assign[i][1];
        if (y < 0){
            y = -1;
            printf("Error on index %d, second\n",i);
            exit(0);
        }
        if (!vertices->seen[y]){
            vertices->path[i] = y;
        found = findPebble(vertices, y);
        if (found)
            return found;
        }
    }
    return found;
}

int enlargeCover(Vertices *vertices, int num_agents, int i, int j) {
    int success = 0;
    int k;
    int found;
    
// Initialize vertex variables for search
        
    for (k = 0; k < num_agents; k++) {
        vertices->seen[k] = 0;
        vertices->path[k] = -1;
    }
// Search graph for free pebble in path through i
    found = findPebble(vertices, i);
    if (found) {
        rearrangePebbles(vertices, i, j);
        success = 1;
        return success;
    }
// Search graph through j, if not already seen

    if (!vertices->seen[j]) {
        found = findPebble(vertices, j);
        if (found) {
            rearrangePebbles(vertices, j, i);
            success = 1;
            return success;
        }
    }
    return success;
}

int pebbleRigidity() {
    int i, j, k;
    int success;

    // Consider each edge for independence by attempting to enlarge the covering
    // when the edge is quadrupled.
    for (i = 0; i < NUM; i++) {
        for (j = i + 1; j < NUM; j++) {
      // Check for edge, skip if none
            if (!graph[i][j]) {
                continue;
            }
        // Attempt to enlarge cover by quadrupling new edge, or equivalently
        // running the cover enlargement 4 times for the new edge
        
            for (k = 0; k < 4; k++) {
                success = enlargeCover(&vrtx_strt, NUM, i, j);
                if (!success)
                    break;
            }

            // If covering found, add edge to independent set, otherwise remove
            // from covering consideration
        
            if (success) {
                ind_set[num_ind][0] = i;
                ind_set[num_ind][1] = j;
                num_ind++;

            // We are rigid, stop search and exit
                
                if (num_ind == 2 * NUM - 3) {
                    isRigid = 1;
                    return isRigid;
                }
/*
            % Fix the pebble assignments for the quadrupled edge, so future
            % assignments have proper numbers of free pebbles.  Since an
            % edge can only be covered by pebbles from its endpoints, we can
            % simply return 3 of the pebbles and leave one assigned to the
            % edge.  We arbitrarily choose to give 2 back to the first
            % endpoint and 1 to the second.
  */      
                vrtx_strt.pebbles[i] = 2;
                vrtx_strt.pebble_assign[i][0] = -1;
                vrtx_strt.pebble_assign[i][1] = -1;
                vrtx_strt.pebbles[j] = 1;
                vrtx_strt.pebble_assign[j][0] = i;
                
            } 
            /*
            % Since the covering failed we are no longer considering edge
            % (i,j) for future coverings.  Thus all pebbles assigned to it
            % during the search must be returned to the endpoints.  This
            % time as the covering failed, we only want to give back
            % pebbles that were assigned during the search, which will not
            % be all 4.
            */
            else {
                if(vrtx_strt.pebble_assign[i][0]==j)
                    vrtx_strt.pebbles[i]++;
                if(vrtx_strt.pebble_assign[i][1]==j)
                    vrtx_strt.pebbles[i]++;
                switch(vrtx_strt.pebbles[i])
                {
                    case 1:
                        vrtx_strt.pebble_assign[i][1]=-1;
                        break;
                    case 2:
                        vrtx_strt.pebble_assign[i][0]=-1;
                        break;
                    default:
                        break;
                               
                }
                
                if(vrtx_strt.pebble_assign[j][0]==i)
                    vrtx_strt.pebbles[j]++;
                if(vrtx_strt.pebble_assign[j][1]==i)
                    vrtx_strt.pebbles[j]++;
                switch(vrtx_strt.pebbles[j])
                {
                    case 1:
                        vrtx_strt.pebble_assign[j][1]=-1;
                        break;
                    case 2:
                        vrtx_strt.pebble_assign[j][0]=-1;
                        break;
                    default:
                        break;
                               
                }
            }

        }
    }
    return isRigid;
}

void init_rigidity_check() {
    int i;
    isRigid = 0;
    num_ind = 0;

    ind_set = calloc(2 * NUM - 3, sizeof (int*));
    for (i = 0; i < 2 * NUM - 3; i++) {
        ind_set[i] = calloc(2, sizeof (int));
    }
}

void close_rigidity_check() {
    int i;

    for (i = 0; i < 2 * NUM - 3; i++) {
        free(ind_set[i]);
    }
    free(ind_set);
}