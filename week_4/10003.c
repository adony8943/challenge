#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cut_num, where_cut[55], memo_dp[55][55], bool_dp[55][55];
/* 初めはbool_where_cut[55]というどの場所が切られたのか判別する配列を
 * つくろうとしていたが、よく考えると、今回考えたdpでは切られた場所が
 * 再び選ばれることはありえなかった。
 */

extern int dp(int from, int to);
extern int min(int a, int b);

int dp(int from, int to) {
    int i, tmp;
    int ret = 999999;

    if (to - from <= 1)
        return 0;

    if(bool_dp[from][to]) 
        return memo_dp[from][to];
    
    bool_dp[from][to] = 1;

    for (i = from + 1; i < to; i++) {
        tmp = where_cut[to] - where_cut[from] + dp(from, i) + dp(i, to);
        ret = min(tmp, ret);
    }
    memo_dp[from][to] = ret;
    return ret;
}

int min(int a, int b) {
    if(a > b)
        return b;
    else 
        return a;
}

int main() {
    int i, j, k, total_length;
    while(1) {
        scanf("%d", &total_length);
        if(total_length == 0) 
            break;
        
        scanf("%d", &cut_num);

        where_cut[0] = 0;
        for(i = 1; i < cut_num + 1; i++) {
            scanf("%d", &where_cut[i]);
        }
        where_cut[cut_num + 1] = total_length;

        for (i = 0; i < 55; i++) {
            memset(bool_dp[i], 0, sizeof(bool_dp[i]));
            memset(memo_dp[i], 99999, sizeof(memo_dp[i]));
        }
        
        printf("The minimum cutting is %d.\n", dp(0, cut_num+1));
        fflush(stdin);
    }
    return 0;
}
