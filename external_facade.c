#include "external_facade.h"
#include "globals.h"
#include "pebbleRigidity.h"

void initPebbleRigidity(int n, int **Gnew) {
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

    for (i = 0; i < NUM; i++) {
        for (j = 0; j < NUM; j++) {
            graph[i][j] = Gnew[i][j];
        }
    }

    init_vertices(n);
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

