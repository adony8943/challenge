#include <stdio.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else 
        return b;
}

int main() {
    int i, j, k, sum, ans, tmp_start, start, end, trial, route;
    
    scanf("%d", &trial);
    for (i = 0; i < trial; i++) {
        scanf ("%d", &route);

        int stops[route];
        for (j = 0; j < route - 1; j++) {
            scanf("%d", &stops[j]);
        }

        ans = 0;
        sum = 0;
        start = 1;
        tmp_start = 1;

        for (j = 0; j < route - 1; j++) {
            sum += stops[j];
            
            if (sum < 0) {
                tmp_start = j + 2;
                sum = 0;
            }

            if (ans < sum) {
                start = tmp_start;
                end = j + 2;
            }

            /* ans と sum は等しいがバスに乗っている時間だけ差があるとき*/
            if (ans == sum && j + 2 - tmp_start > end - start) {
                start = tmp_start;
                end = j + 2;
            }

            ans = max(ans, sum);
        }

        if (ans > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", i + 1, start, end);
        else
            printf("Route %d has no nice parts\n", i + 1);
    }
    return 0;
}

