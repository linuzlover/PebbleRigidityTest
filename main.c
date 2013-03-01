/* 
 * File:   main.c
 * Author: sickboy
 *
 * Created on February 20, 2013, 1:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "pebble_external_facade.h"
#define FILE_IN "./INPUT.TXT"
/*
 * 
 */
int main(int argc, char** argv) {

    int n=5;
    int **G;
    int i,j;
    int result;
    FILE* in=fopen(FILE_IN,"r");
    fscanf(in,"%d\n",&n);
        
    
    G=calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
        G[i]=calloc(n,sizeof(int));
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
                fscanf(in,"%d\t",&G[i][j]);
        }
        fscanf(in,"%d\n",&G[i][j]);
    }
    
    
    initPebbleRigidity(n);
    
    assignAdjacencyMatrix(G);
    
    result=verifyRigidity();
    
    
    
    printf("Result: %d\n",result);
    
    for(i=0;i<n;i++)
        free(G[i]);
    free(G);
    
    closePebbleRigidity();
    
    fclose(in);
    
    
}

