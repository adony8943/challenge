#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int id;
        int time;
        int ans_num;
} CONTESTANT;

void swap(CONTESTANT arr[], int a1, int a2) {
    CONTESTANT tmp = arr[a1];
    arr[a1] = arr[a2];
    arr[a2] = tmp;
}

void bubble_sort(CONTESTANT arr[], int arr_size) {
    int i;
    while (arr_size > 0) {
        for (i = 0; i < arr_size - 1; i++) {
            if (arr[i].ans_num < arr[i + 1].ans_num) {
                swap(arr, i, i + 1);
            } else if (arr[i].ans_num == arr[i + 1].ans_num) {
                if (arr[i].time > arr[i + 1].time) {
                    swap(arr, i, i + 1);
                }
            }
        }
        arr_size -= 1;
    }
}         

int main() {

    int repeat_num, i, j, k, player, question, time, flag;
    int who_solved[101][10], penalty[101][10], p_count[101];
    CONTESTANT contestant[101];
    char *tmp;
    char judge;

    if ((tmp = malloc(20)) == NULL) {
        printf("malloc_error\n");
        exit(1);
    }

    fgets(tmp, 20, stdin);
    sscanf(tmp, "%d", &repeat_num);
    getchar();

    while(repeat_num--) {
        /* reset */
        for (i = 0; i < 101; i++) {
            contestant[i].time = 0;
            contestant[i].id = 0;
            contestant[i].ans_num = 0;
            p_count[i] = 0;
            for (j = 0; j < 10; j++) {
                who_solved[i][j] = 0;
                penalty[i][j] = 0;
            }
        }
        k = 0;

        while(1) {
            fgets(tmp, 20, stdin);
            if (*tmp =='\x0A') break; /* if tmp == '\n', break */
            sscanf(tmp, "%d %d %d %c", &player, &question, &time, &judge);

            if (judge == 'C') {
                who_solved[player][question] = 1;
                penalty[player][question] += time;
            }else if (judge == 'I') {
                penalty[player][question] += 20;
            }

            /*count the number of players*/
            flag = 1;
            for (i = 0; i < k + 1; i++) {
                if (p_count[i] == player) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                p_count[k] = player;
                k++;
            }
        }

        for (i = 0; i < 101; i++) {
            for (j = 0; j < 10; j++) {
                if (who_solved[i][j] == 1) {
                    contestant[i].id = i;
                    contestant[i].time += penalty[i][j];
                    contestant[i].ans_num += 1;
                }
            }
        }

        bubble_sort(contestant, 101); /*0番目もソートして後ろに追いやる*/

        for (i = 0; i < k ; i++) {
            printf("%d %d %d\n", contestant[i].id, contestant[i].ans_num, contestant[i].time);
        }
        if (repeat_num == 0) break;
    }
    free(tmp);
    return 0;
}
