#include "external_facade.h"
#include "globals.h"

void initPebbleRigidity(int n, int **G)
{
    int i,j;
    //Assigning the number of agents
    NUM=n;
    
    /*Init the graph structure*/
    
    graph=calloc(NUM,sizeof(int*));
    
    for(i=0;i<NUM;i++)
    {
        graph[i]=calloc(NUM,sizeof(int));
    }
    
    for(i=0;i<NUM;i++)
    {
        for(j=0;j<NUM;j++)
        {
            graph[i][j]=G[i][j];
        }
    }
}

void closePebbleRigidity()
{
    int i;
    
    NUM=-1;
    for(i=0;i<NUM;i++)
    {
        free(graph[i]);
    }
    free(graph);
}