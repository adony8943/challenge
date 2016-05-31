#include <stdio.h>
#include <stdlib.h>

int main() {
    int min_num, max_num, count, tmp_num, i_num, max_count;
    char *tmp;
    if ((tmp = malloc(10000)) == NULL) {
        printf("malloc\n");
        exit(1);
    }

    /* while(fgets(tmp, 100, stdin) != NULL) {
        if (sscanf(tmp, "%d %d", &min_num, &max_num) < 2) 
            //unless less two arguments exist, program finishes  
            break;*/
    /* input is a series of pairs. so I can't use fgets*/

    ;
    while (((scanf("%d %d", &min_num, &max_num)) == 2) && min_num > 0 && max_num > 0) {
        max_count = 0;
        printf("%d %d ", min_num, max_num); /*print before swap*/
        if (min_num > max_num) { /* swap to keep (min_num < max_num)*/
            tmp_num = min_num;
            min_num = max_num;
            max_num = tmp_num;
        }
    
        for (i_num = min_num; i_num <= max_num; i_num++) {
            count = 1;
            tmp_num = i_num;
            while (tmp_num > 1) {
                if (tmp_num % 2 == 1)
                    tmp_num = 3 * tmp_num + 1;
                else 
                    tmp_num /= 2;
                count++;
            }
            if (count > max_count)
                max_count = count;
        }
        printf("%d\n", max_count);
    }

    return 0;
}
