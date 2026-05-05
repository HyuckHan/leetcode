/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #include<stdlib.h>

int* countBits(int n, int* returnSize) {
    int i;
    int *ret;
    *returnSize = n+1;

    ret = (int*)malloc(sizeof(int)*(n+1));

    ret[0] = 0;

    for(i=1; i<n+1; i++){
        ret[i] = ret[i/2] + i%2;
    }

    return ret;
}