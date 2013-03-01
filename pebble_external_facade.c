#include "pebble_external_facade.h"
#include "globals.h"


int** getIndependentSet()
{
    return ind_set;
}

int getIndependentSetSize()
{
    return num_ind;
}

void assignAdjacencyMatrix(int **Gnew) {
    int i, j;
    
    for (i = 0; i < NUM; i++) {
        for (j = 0; j < NUM; j++) {
            graph[i][j] = Gnew[i][j];
        }
    }
    reinit_vertices();
    reinit_rigidity_check();
}

void initPebbleRigidity(int n) {
    int i, j;
    //Assigning the number of agents
    NUM = n;
    
    /*Init the graph structure*/

    graph = calloc(NUM, sizeof (int*));
    if (!graph) {
        printf("Error in memory allocation for graph\n");
        exit(1);
    }

    for (i = 0; i < NUM; i++) {
        graph[i] = calloc(NUM, sizeof (int));
        if (!graph[i]) {
            printf("Error in memory allocation for graph\n");
            exit(1);
        }
    }

    //for (i = 0; i < NUM; i++) {
    //    for (j = 0; j < NUM; j++) {
    //        graph[i][j] = Gnew[i][j];
    //    }
    //}

    init_vertices();
    init_rigidity_check();
}

int verifyRigidity() {
    return pebbleRigidity();
}

void closePebbleRigidity() {
    int i;
    for (i = 0; i < NUM; i++) {
        free(graph[i]);
    }
    free(graph);
    close_rigidity_check();
    close_vertices();
}

