#include<stdlib.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int i, j, m, ret;
    int *bucket;

    if(coinsSize == 0)
        return -1;


    for(i=0; i<coinsSize-1; i++)
        for(j=0; j<coinsSize-i-1; j++)
            if(coins[j]>coins[j+1]) {
                m = coins[j];
                coins[j] = coins[j+1];
                coins[j+1] = m;
        }

    bucket = malloc(sizeof(int)*(amount+1));
    for(i=0; i<=amount; i++) {
        bucket[i] = 0;
    }

    for(i=1; i<=amount; i++) {
        int min = amount + 1;
        for(j=0; j<coinsSize; j++) {
            int t = i - coins[j];
            if(t<0)
                continue;
            if(bucket[t] != -1 && min>bucket[t]+1)
                min = bucket[t]+1;
        }
        if(min==amount+1)
            bucket[i] = -1;
        else
            bucket[i] = min;

    }
    ret = bucket[amount];
    free(bucket);
    return ret;
}