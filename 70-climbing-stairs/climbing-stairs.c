int fib(int n, int *memo) {
    if(memo[n] != 0)
        return memo[n];
    if(n==1) return 1;
    else if(n==2) return 2;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int climbStairs(int n) {
    int *memo;

    memo = (int*) malloc(sizeof(int)*(n+1));
    for(int i=0; i<n+1; i++)
        memo[i] = 0;

    int ret = fib(n, memo);
    free(memo);
    return ret;
}