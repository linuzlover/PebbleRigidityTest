#include "pebbleRigidity.h"
#include "globals.h"
#include "vertices.h"


void rearrangePebbles(Vertices *vertices, int i, int j) {
    int index, k;

    if (vertices->path[i] == -1) {
        index = 2 - vertices->pebbles[i];

        if (index >= 0 && index < 2) {
            vertices->pebble_assign[i][index] = j;
            vertices->pebbles[i]--;
        }
        return;
    } else {
        if (vertices->pebble_assign[i][0] == vertices->path[i])
            vertices->pebble_assign[i][0] = j;
        if (vertices->pebble_assign[i][1] == vertices->path[i])
            vertices->pebble_assign[i][1] = j;
    }

    while (vertices->path[i] != -1) {
        k = vertices->path[i];
        if (vertices->path[k] == -1) {
            index = 2 - vertices->pebbles[k];

            if (index >= 0 && index < 2) {
                vertices->pebble_assign[k][index] = i;
                vertices->pebbles[k]--;
            }

        } else {
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

    vertices->seen[i] = 0;
    vertices->path[i] = -1;

    if (vertices->pebbles[i] > 0) {
        found = 1;
        return found;
    } else {
        x = vertices->pebble_assign[i][0];
        if (x < 1)
            x = 0;
        if (!vertices->seen[x]) {
            vertices->path[i] = x;
            found = findPebble(vertices, x);
            if (found)
                return found;

        }
        y = vertices->pebble_assign[i][1];
        if (y < 1)
            y = 0;
        if (!vertices->seen[y])
            vertices->path[i] = y;
        found = findPebble(vertices, y);
        if (found)
            return found;
    }
    return found;
}

int enlargeCover(Vertices *vertices, int num_agents, int i, int j) {
    int success=0;
    int k;
    int found;
    
    for(k=0;k<num_agents;k++)
    {
        vertices->seen[k]=0;
        vertices->path[k]=-1;
    }
    
    found=findPebble(vertices,i);
    if(found)
    {
        rearrangePebbles(vertices,i,j);
        success=1;
        return success;
    }
    
    if(!vertices->seen[j])
    {
        found=findPebble(vertices,j);
        if(found)
        {
            rearrangePebbles(vertices,j,i);
            success=1;
            return success;
        }
    }
    return success;
}

void pebbleRigidity() {
    int i, j, k;
    int success;

    for (i = 0; i < NUM; i++) {
        for (j = i + 1; j < NUM; j++) {
            if (graph[i][j] == 0) {
                continue;
            }

            for (k = 0; k < 4; k++) {
                success = enlargeCover(&vrtx_strt, NUM, i, j);
                if (!success)
                    break;
            }

        }
    }

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