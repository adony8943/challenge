#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row, column, dp[1000][1000], matrix[1000][1000], ashiato[1000][1000];
int last_ashiato;

int min(int a, int b, int c) {
    if(a >= c && b >= c)
        return c;
    else if (b >= a && c >= a)
        return a;
    else 
        return b;
}

int route_dp(int n_column, int n_row) {
    if (n_row > row)
        return 0;

    if (n_column >= column)
        n_column = 0;
    else if (n_column < 0)
        n_column = column - 1;

    if (dp[n_column][n_row] != 99999)
        return dp[n_column][n_row];

    int a = route_dp(n_column + 1, n_row + 1); 
    int b = route_dp(n_column    , n_row + 1); 
    int c = route_dp(n_column - 1, n_row + 1); 
 
    if(a >= c && b >= c) {
        dp[n_column][n_row] = c;
        ashiato[n_column][n_row] = n_column - 1;
    } else if (b >= a && c >= a) {
        dp[n_column][n_row] = a;
        ashiato[n_column][n_row] = n_column + 1;
    } else { 
        dp[n_column][n_row] = b;
        ashiato[n_column][n_row] = n_column;
    } 

    dp[n_column][n_row] += matrix[n_column][n_row];
    if (n_row == row) 
        last_ashiato = n_column;
    /*dp[n_column][n_row] = min(route_dp(n_column + 1, n_row + 1), 
                              route_dp(n_column, n_row + 1), 
                              route_dp(n_column - 1, n_row + 1))
                          + matrix[n_column][n_row];*/
       

    return dp[n_column][n_row];
}

int main() {
    char *tmp;
    int i, j, k, min_point;
    int min_row1 = 999999;
    
    if((tmp = malloc(1000)) == NULL) {
        perror("tmp");
        exit(1);
    }

    for(i = 0; i < 1000; i++)
        for(j = 0; j < 1000; j++)
            dp[i][j] = 99999;


    while (fgets(tmp, 1000, stdin) != NULL) {
        if (*tmp == '\n') break;

        sscanf(tmp, "%d %d", &column, &row);
        /*int matrix[column][row];*/

        for (i = 0; i < column; i++) {
            matrix[i][0] = 0;
        }

        for (i = 0; i < column; i++) {
            for (j = 1; j < row + 1; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        /*clear buffer*/
        while (getchar() != '\n');       
        
        int ret = route_dp(0, 0);

        printf("%d", last_ashiato);
        while (row-- > 1) {
            printf(" %d", ashiato[last_ashiato][row]);
            last_ashiato = ashiato[last_ashiato][row];
        }
        printf("\n");
        printf("ret = %d\n", ret);

    }
    free(tmp);
    return 0;
}

