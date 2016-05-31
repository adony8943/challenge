#include <stdio.h>
#include <stdlib.h>

int main() {
    char *tmp;
    int big_size, small_size, i, j, k, l;
    int count_0, count_90, count_180, count_270;

    if((tmp = malloc(10)) == NULL) {
        printf("malloc error\n");
        exit(1);
    }

    while (fgets(tmp, 10, stdin) != NULL) {
        sscanf(tmp, "%d %d", &big_size, &small_size);
        if (big_size == 0 && small_size == 0) break;
        
        count_0 = 0; count_90 = 0; count_180 = 0; count_270 = 0;

        char big_arr[big_size * big_size], small_arr[small_size * small_size];
        
        for (i = 0; i < big_size; i++) {
            for (j = 0; j < big_size; j++) {
                big_arr[i * big_size + j] = getchar();
            }
            getchar();
        }

        for (i = 0; i < small_size; i++) {
            for (j = 0; j < small_size; j++) {
                small_arr[i * small_size + j] = getchar();
            }
            getchar();
        }
        
        /* spin 0 */
        for (i = 0; i < big_size; i++) {
            for (j = 0; j < big_size; j++) {
                int flag = 1;
                for (k = 0; k < small_size; k++) {
                    if (big_arr[i * big_size + j] != small_arr[k]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1 && big_size - i >= small_size) {
                    int check = 1;
                    for (k = 0; k < small_size; k++) {
                        for (l = 0; l < small_size; l++) {
                            if (big_arr[(i + k) * big_size + j + l] != small_arr[k * small_size + l]) {
                                check = 0;
                                break;
                            }
                        }
                    }
                    if (check == 1)
                        count_0++;
                }
            }
        }
        printf("count_0 = %d\n", count_0);
    }
    free(tmp);
    return 0;
}
