#include <stdio.h>
#include <stdlib.h>

int main() {
    char *tmp;
    int soldiers_num, report, i, j, left, right, buddy_left, buddy_right;
    int left_end(), right_end();

    /* the reason (tmp size 15) is why
     * max inputs are (100000 100000 + \n).
     * At most inputs will be total word is 14 */
    if ((tmp = malloc(15)) == NULL) {
        printf("malloc error\n");
        exit(1);
    }


    while(fgets(tmp, 15, stdin) != NULL) {
        sscanf(tmp, "%d %d", &soldiers_num, &report);
        if (soldiers_num == 0 && report == 0) 
            break;
        int l_num[soldiers_num], r_num[soldiers_num];

        for (i = 0; i < soldiers_num; i++) {
            r_num[i] = i + 2;
            l_num[i] = i;
        }
        
        for (i = 0; i < report; i++) {
            fgets(tmp, 15, stdin);
            sscanf(tmp, "%d %d", &left, &right);
            
            if (left <= 1 || right >= soldiers_num) {
                if (left <= 1) {
                    l_num[right] = 0;
                }
                if (right > soldiers_num) {
                    r_num[left - 1] = soldiers_num + 1;
                }

            } else {
                l_num[right] = l_num[left - 1];
                r_num[left - 2] = r_num[right-1];
            }

            for (j = left-1; j < right; j++) {
                l_num[j] = l_num[left-1];
                r_num[j] = r_num[right-1];
            }

            for (j = 0; j < soldiers_num; j++) {
                if (l_num[j] == right) {
                    l_num[j] = l_num[left-1];
                }
                if (l_num[j] == left) {
                    l_num[j] = l_num[right-1];
                }

                if (r_num[j] == left) {
                    r_num[j] = r_num[right-1];
                }
                if (r_num[j] == right) {
                    r_num[j] = r_num[left];
                }
            }
                             
            /* debug */
            /*printf("left = ");
            for (j = 0; j < soldiers_num; j++) {
                printf("%d ", l_num[j]);
            }
            printf("\n");

            printf("right = ");
            for (j = 0; j < soldiers_num; j++) {
                printf("%d ", r_num[j]);
            }
            printf("\n");*/

            if (l_num[soldiers_num-1] == 0 && r_num[0] == soldiers_num + 1) {
                printf("* *\n");
                break;
            }
           
            if (l_num[right] <= 0)
                printf("* ");
            else if (right == soldiers_num)
                printf("%d ", l_num[left - 1]);
            else 
                printf("%d ", l_num[right]);
            
            if(left == 1) {
                printf("%d\n", r_num[right-1]);
            } else  if (r_num[left-1] > soldiers_num) {
                printf("*\n");
            }
            else { 
                printf("%d\n", r_num[left-2]);
            }
        }
        printf("-\n");
    }
    free(tmp);
    return 0;
}
