#include "pebbleRigidity.h"
#include "vertices.h"

void rearrangePebbles(Vertices *vertices, int i,int j)
{
    
}

int findPebble(Vertices *vertices, int i)
{
    
}

int enlargeCover(Vertices *vertices,int num_agents,int i,int j)
{
    
}

void pebbleRigidity()
{
    int i,j,k;
    int success;
    
    for(i=0;i<NUM;i++)
    {
        for(j=i+1;j<NUM;j++)
        {
            if(graph[i][j]==0)
            {
                continue;
            }
            
            for(k=0;k<4;k++)
            {
                success=enlargeCover(&vrtx_strt,NUM,i,j);
                if(!success)
                    break;
            }
            
        }
    }
    
}

void init_rigidity_check()
{
    int i;
    isRigid=0;
    num_ind=0;
    
    ind_set=calloc(2*NUM-3,sizeof(int*));
    for(i=0;i<2*NUM-3;i++)
    {
        ind_set[i]=calloc(2,sizeof(int));
    }
}

void close_rigidity_check()
{
    int i;
    
    for(i=0;i<2*NUM-3;i++)
    {
        free(ind_set[i]);
    }
    free(ind_set);
}