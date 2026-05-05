#include<stdlib.h>

int minCostClimbingStairs(int* cost, int costSize) {
    int *df;
    int i;
    
    df = (int*) malloc(sizeof(int)*costSize);
    df[0] = cost[0];
    df[1] = cost[1];

    for(i=2; i<costSize; i++) {
        df[i] = (df[i-1]<df[i-2])?df[i-1]:df[i-2];
        df[i] += cost[i]; 
    }   
    i = df[costSize-1]<df[costSize-2]?df[costSize-1]:df[costSize-2];
    free(df);
    return i;
}