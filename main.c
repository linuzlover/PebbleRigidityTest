/* 
 * File:   main.c
 * Author: sickboy
 *
 * Created on February 20, 2013, 1:32 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "external_facade.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int n=5;
    int **G;
    int i;
    int result;
    
    G=calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
        G[i]=calloc(n,sizeof(int));
    
    G[0][0]=0;
    G[0][1]=1;
    G[0][2]=1;
    G[0][3]=1;
    G[0][4]=0;
    
    G[1][0]=1;
    G[1][1]=0;
    G[1][2]=1;
    G[1][3]=1;
    G[1][4]=0;
    
    
    G[2][0]=1;
    G[2][1]=1;
    G[2][2]=0;
    G[2][3]=0;
    G[2][4]=1;
    
    G[3][0]=1;
    G[3][1]=1;
    G[3][2]=0;
    G[3][3]=0;
    G[3][4]=0;
    
    G[4][0]=0;
    G[4][1]=0;
    G[4][2]=1;
    G[4][3]=0;
    G[4][4]=0;
    
    
    initPebbleRigidity(n,G);
    
    result=verifyRigidity();
    
    printf("Result: %d\n",result);
    
    for(i=0;i<n;i++)
        free(G[i]);
    free(G);
    
    closePebbleRigidity();
    
    
    
    
}

