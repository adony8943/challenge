#include <stdio.h>

int length, bar_num, bar_length[25], dp[25][2000];

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int memo_dp(int i, int j) {
    int memo;
    if (j < 0) {
        return 0;
    }
    if (dp[i][j] != -1) 
        return dp[i][j];

    if (i == bar_num)
        memo = 0;
    else if (j - bar_length[i] < 0) {
        memo = memo_dp(i + 1, j);
    } else {
        memo = max(memo_dp(i + 1, j),
                   (memo_dp(i + 1, j - bar_length[i]) + bar_length[i]));
    }
    dp[i][j] = memo;
    /* test 
     * printf("dp[%d][%d] = %d\n", i, j, memo);
     */
    return memo;
}

int main() {
    int i, j, k, trial;
    
    scanf("%d", &trial);
    for (i = trial; i > 0; i--) {
        scanf("%d", &length);
        scanf("%d", &bar_num);

        for (j = 0; j < 20; j++) 
            bar_length[j] = 0;

        for (j = 0; j < bar_num; j++) {
            scanf("%d", &bar_length[j]);
        }     
        for (j = 0; j < 20; j++) {
            for (k = 0; k < 2000; k++) {
                dp[j][k] = -1;
            }
        }

        if (memo_dp(0, length) == length) 
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}
