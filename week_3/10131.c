#include <stdio.h>
#include <stdlib.h>

void swap(int array[], int a, int b) {
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

void bubble_sort(int arr[],int arr_2[], int arr_3[], int arr_length) {
    int length = arr_length;
    int i, j, k;
    while(length) {
        for(i = 0; i < length; i++) {
            if(arr[i] <= arr[i + 1]) {
                swap(arr, i, i + 1);
                swap(arr_2, i, i + 1);
                swap(arr_3, i, i + 1);
            }
        }
        length--;
    }
}

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int main() {
    char *tmp;
    int i, j, k, root, max_LIS, max_p, elephant_num, weight[1020], IQ[1020],
        LIS[1020], link[1020], default_num[1020];
    
    if((tmp = malloc(100)) == NULL) {
        perror("tmp");
        exit(1);
    }

    elephant_num = 0;
    max_LIS = 0;
    
    while(fgets(tmp, 100, stdin) != NULL) {
        if (*tmp == '\n') break;
        sscanf(tmp, "%d %d", &weight[elephant_num], &IQ[elephant_num]);
        /*printf("weight = %d, IQ = %d\n", weight[elephant_num], IQ[elephant_num]);*/
        elephant_num++;
    }
    elephant_num += 1;
    /*printf("ele_num = %d\n", elephant_num);*/

    for (i = 0; i < elephant_num; i++) {
        LIS[i] = 1;
        link[i] = -1;
        default_num[i] = i;
        /*default_num records default elephant's order*/
    }

    bubble_sort(weight, IQ, default_num, elephant_num);

    for (i = 1; i < elephant_num; i++) {
        for (j = 0; j < i; j++) {
            if((IQ[i] > IQ[j]) && LIS[i] <= LIS[j] && weight[i] != weight[j]) {
                LIS[i] = LIS[j] + 1;
                if(max_LIS < LIS[i]) {
                    max_p = i;
                    max_LIS = LIS[i];
                }
                link[i] = j;
            }
        }
    } 
    
    printf("%d\n", max_LIS);
    root = max_p;
    while(1) {
        /*printf("weight = %d, IQ = %d\n", weight[root], IQ[root]);*/
        printf("%d\n", default_num[root] + 1);
        if (link[root] == -1) break;
        else root = link[root];
    }
    free(tmp);
    return 0;
}

